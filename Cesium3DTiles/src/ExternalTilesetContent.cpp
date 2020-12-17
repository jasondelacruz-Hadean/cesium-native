#include "Cesium3DTiles/ExternalTilesetContent.h"
#include "CesiumUtility/Json.h"
#include "Cesium3DTiles/Tile.h"
#include "Cesium3DTiles/Tileset.h"
#include "Uri.h"
#include "spdlog.h"

namespace Cesium3DTiles {

    /*static*/ std::unique_ptr<TileContentLoadResult> ExternalTilesetContent::load(
        std::shared_ptr<spdlog::logger> pLogger,
        const TileContext& context,
        const TileID& /*tileID*/,
        const BoundingVolume& /*tileBoundingVolume*/,
        double /*tileGeometricError*/,
        const glm::dmat4& tileTransform,
        const std::optional<BoundingVolume>& /*tileContentBoundingVolume*/,
        TileRefine tileRefine,
        const std::string& url,
        const gsl::span<const uint8_t>& data
    ) {
        std::unique_ptr<TileContentLoadResult> pResult = std::make_unique<TileContentLoadResult>();
        pResult->childTiles.emplace(1);

        pResult->pNewTileContext = std::make_unique<TileContext>();
        TileContext* pContext = pResult->pNewTileContext.get();
        pContext->pTileset = context.pTileset;
        pContext->baseUrl = url;
        pContext->requestHeaders = context.requestHeaders;
        pContext->version = context.version;
        pContext->failedTileCallback = context.failedTileCallback;

        using nlohmann::json;

        json tilesetJson;
        try
        {
            tilesetJson = json::parse(data.begin(), data.end());
            context.pTileset->loadTilesFromJson(pResult->childTiles.value()[0], tilesetJson, tileTransform, tileRefine, *pContext);
        }
        catch (const json::parse_error& error)
        {
            SPDLOG_LOGGER_ERROR(pLogger, "Error when parsing external tileset content: {}", error.what());
        }
        return pResult;
    }

}
