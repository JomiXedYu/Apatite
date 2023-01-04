#pragma once

#include <Apatite/Assets/Texture.h>
#include <Apatite/IBindGPU.h>
#include "Texture.h"


namespace apatite
{

    class RenderTexture : public Texture
    {
        CORELIB_DEF_TYPE(AssemblyObject_Apatite, apatite::RenderTexture, Texture);

    public:
        RenderTexture();
        ~RenderTexture();
    public:
        // ͨ�� Texture �̳�
        virtual int32_t get_width() const override;
        virtual int32_t get_height() const override;

    public:
        // ͨ�� IBindGPU �̳�
        virtual void BindGPU() override;
        virtual void UnBindGPU() override;
        virtual bool GetIsBindGPU() override;

    };
}