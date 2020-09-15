#pragma once

#include <string>
#include <map>
#include <vector>
#include <gsl/span>
#include <gsl/string_span>
#include "Cesium3DTiles/Library.h"

namespace Cesium3DTiles {

    /// <summary>
    /// A completed response for a 3D Tiles asset.
    /// </summary>
    class CESIUM3DTILES_API IAssetResponse {
    public:
        virtual ~IAssetResponse() = default;

        virtual uint16_t statusCode() const = 0;
        virtual std::string contentType() const = 0;
        //virtual const std::map<std::string, std::string>& headers() = 0;
        virtual gsl::span<const uint8_t> data() const = 0;
    };

}
