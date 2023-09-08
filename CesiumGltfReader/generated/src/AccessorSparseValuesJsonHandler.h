// This file was generated by generate-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include <CesiumGltf/AccessorSparseValues.h>
#include <CesiumJsonReader/ExtensibleObjectJsonHandler.h>
#include <CesiumJsonReader/IntegerJsonHandler.h>

namespace CesiumJsonReader {
class JsonReaderOptions;
}

namespace CesiumGltfReader {
class AccessorSparseValuesJsonHandler
    : public CesiumJsonReader::ExtensibleObjectJsonHandler {
public:
  using ValueType = CesiumGltf::AccessorSparseValues;

  AccessorSparseValuesJsonHandler(
      const CesiumJsonReader::JsonReaderOptions& options) noexcept;
  void reset(
      IJsonHandler* pParentHandler,
      CesiumGltf::AccessorSparseValues* pObject);

  virtual IJsonHandler* readObjectKey(const std::string_view& str) override;

protected:
  IJsonHandler* readObjectKeyAccessorSparseValues(
      const std::string& objectType,
      const std::string_view& str,
      CesiumGltf::AccessorSparseValues& o);

private:
  CesiumGltf::AccessorSparseValues* _pObject = nullptr;
  CesiumJsonReader::IntegerJsonHandler<int32_t> _bufferView;
  CesiumJsonReader::IntegerJsonHandler<int64_t> _byteOffset;
};
} // namespace CesiumGltfReader
