#pragma once

#include "Component.h"


namespace apatite
{
    class PlayableComponent : public Component
    {
        CORELIB_DEF_TYPE(AssemblyObject_Apatite, apatite::PlayableComponent, Component);

    public:
        bool get_interactive_playing() const { return enabled_; }
        void set_interactive_playing(bool value);
        virtual bool get_is_tickable() const;
    public:

        virtual void BeginInteractivePlay() {}
        virtual void EndInteractivePlay() {}

    private:
        bool enabled_;
    };
}