#pragma once

#include "CesiumGeometry/Library.h"
#include "CesiumGeometry/QuadtreeTilingScheme.h"
#include "CesiumGeometry/QuadtreeTileID.h"
#include <gsl/span>
#include <vector>
#include <memory>
#include <byte>

namespace CesiumGeometry {

class CESIUMGEOMETRY_API QuadtreeSubtreeAvailability final {
public:
  struct Subtree {
    uint32_t levels;
    uint32_t maximumLevel;
    std::vector<std::byte> bitstream;
    gsl::span<const std::byte> tileAvailability;
    gsl::span<const std::byte> contentAvailability;
    gsl::span<const std::byte> subtreeAvailability;

    Subtree(void* data, uint32_t levels, uint32_t maximumLevel);
  };

  QuadtreeSubtreeAvailability(
      const QuadtreeTilingScheme& tilingScheme) noexcept;

  bool isTileAvailable(const QuadtreeTileID& tileID) const noexcept;

  bool addSubtree(
      const QuadtreeTileID& tileID, 
      Subtree&& subtree) noexcept;

private:
  struct Node {
    Subtree subtree;
    std::vector<std::unique_ptr<Node>> childNodes;

    Node(Subtree&& subtree_);
  };

  QuadtreeTilingScheme _tilingScheme;
  uint32_t _maximumLevel;
  std::unique_ptr<Node> _pRoot;
};

} // namespace CesiumGeometry