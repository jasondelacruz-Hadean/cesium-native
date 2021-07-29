// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "CesiumGltf/ExtensibleObject.h"
#include "CesiumGltf/Library.h"
#include "CesiumUtility/JsonValue.h"
#include <cstdint>
#include <optional>
#include <string>

namespace CesiumGltf {
/**
 * @brief A class property.
 */
struct CESIUMGLTF_API ClassProperty final : public ExtensibleObject {
  static inline constexpr const char* TypeName = "ClassProperty";

  /**
   * @brief The name of the property, e.g. for display purposes.
   */
  std::optional<std::string> name;

  /**
   * @brief The description of the property.
   */
  std::optional<std::string> description;

  /**
   * @brief The property type. If `ENUM` is used, then `enumType` must also be
   * specified. If `ARRAY` is used, then `componentType` must also be specified.
   * `ARRAY` is a fixed-length array when `componentCount` is defined, and
   * variable-length otherwise.
   */
  std::string type;

  /**
   * @brief An enum ID as declared in the `enums` dictionary. This value must be
   * specified when `type` or `componentType` is `ENUM`.
   */
  std::optional<std::string> enumType;

  /**
   * @brief When `type` is `ARRAY` this indicates the type of each component of
   * the array. If `ENUM` is used, then `enumType` must also be specified.
   */
  CesiumUtility::JsonValue componentType;

  /**
   * @brief The number of components per element for `ARRAY` elements.
   */
  std::optional<int64_t> componentCount;

  /**
   * @brief Specifies whether integer values are normalized. This applies both
   * when `type` is an integer type, or when `type` is `ARRAY` with a
   * `componentType` that is an integer type. For unsigned integer types, values
   * are normalized between `[0.0, 1.0]`. For signed integer types, values are
   * normalized between `[-1.0, 1.0]`. For all other types, this property is
   * ignored.
   */
  bool normalized = false;

  /**
   * @brief Maximum allowed values for property values. Only applicable for
   * numeric types and fixed-length arrays of numeric types. For numeric types
   * this is a single number. For fixed-length arrays this is an array with
   * `componentCount` number of elements. The `normalized` property has no
   * effect on these values: they always correspond to the integer values.
   */
  CesiumUtility::JsonValue max;

  /**
   * @brief Minimum allowed values for property values. Only applicable for
   * numeric types and fixed-length arrays of numeric types. For numeric types
   * this is a single number. For fixed-length arrays this is an array with
   * `componentCount` number of elements. The `normalized` property has no
   * effect on these values: they always correspond to the integer values.
   */
  CesiumUtility::JsonValue min;

  /**
   * @brief A default value to use when the property value is not defined. If
   * used, `optional` must be set to true. The type of the default value must
   * match the property definition: For `BOOLEAN` use `true` or `false`. For
   * `STRING` use a JSON string. For a numeric type use a JSON number. For
   * `ENUM` use the enum `name`, not the integer value. For `ARRAY` use a JSON
   * array containing values matching the `componentType`.
   */
  CesiumUtility::JsonValue defaultProperty;

  /**
   * @brief If true, this property is optional.
   */
  bool optional = false;

  /**
   * @brief An identifier that describes how this property should be
   * interpreted. The semantic cannot be used by other properties in the class.
   */
  std::optional<std::string> semantic;
};
} // namespace CesiumGltf