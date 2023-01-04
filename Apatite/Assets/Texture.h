#pragma once
#include <Apatite/AssetObject.h>


namespace apatite
{
    class Texture : public AssetObject
    {
        CORELIB_DEF_TYPE(AssemblyObject_Apatite, apatite::Texture, AssetObject);

    public:
        uint32_t get_tex_id() const { return tex_id_; }
        virtual int32_t get_width() const = 0;
        virtual int32_t get_height() const = 0;

    protected:
        uint32_t tex_id_ = 0;
    };
    CORELIB_DECL_SHORTSPTR(Texture);
}