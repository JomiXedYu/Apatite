#pragma once
#include <cstdint>

namespace apatite::detail
{
    namespace InputInterface
    {
        bool GetKey(const int& keyCode);
        bool GetMouseButton(const int& keyCode);
        void GetCursorPosition(int* out_x, int* out_y);
        void PollEvents();
    }
}