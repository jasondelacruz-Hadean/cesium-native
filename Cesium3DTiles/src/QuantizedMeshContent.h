#pragma once

#include "Cesium3DTiles/Library.h"
#include "Cesium3DTiles/GltfContent.h"
#include <string>
#include <memory>

namespace Cesium3DTiles {

    class CESIUM3DTILES_API QuantizedMeshContent : public GltfContent {
    public:
        static std::string CONTENT_TYPE;

        QuantizedMeshContent(const Tile& tile, const gsl::span<const uint8_t>& data, const std::string& url);

        virtual void finalizeLoad(Tile& tile) override;

    private:
        struct LoadedData;
        static LoadedData load(const Tile& tile, const gsl::span<const uint8_t>& data);

        QuantizedMeshContent(const Tile& tile, LoadedData&& loadedData, const std::string& url);

        double _minimumHeight;
        double _maximumHeight;
    };

}
