// This file was generated by generate-gltf-classes.
// DO NOT EDIT THIS FILE!
#pragma once

#include "DoubleJsonHandler.h"
#include "ExtensibleObjectJsonHandler.h"

namespace CesiumGltf {
  struct CameraOrthographic;

  class CameraOrthographicJsonHandler : public ExtensibleObjectJsonHandler {
  public:
    void reset(IJsonHandler* pHandler, CameraOrthographic* pObject);
    CameraOrthographic* getObject();
    virtual void reportWarning(const std::string& warning, std::vector<std::string>&& context = std::vector<std::string>()) override;

    virtual IJsonHandler* Key(const char* str, size_t length, bool copy) override;

  protected:
    IJsonHandler* CameraOrthographicKey(const char* str, CameraOrthographic& o);

  private:

    CameraOrthographic* _pObject;
    DoubleJsonHandler _xmag;
    DoubleJsonHandler _ymag;
    DoubleJsonHandler _zfar;
    DoubleJsonHandler _znear;
  };
}
