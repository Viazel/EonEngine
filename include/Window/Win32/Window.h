#pragma once

namespace eon
{
    class Window
    {
    public:
        Window();
        virtual ~Window();

    private:
        void *m_handle{};
    };
}