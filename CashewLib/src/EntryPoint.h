//
// Created by sohaibalam on 27/11/23.
//

#ifndef CASHEW_ENTRYPOINT_H
#define CASHEW_ENTRYPOINT_H


#ifdef _WIN32

extern Cashew::Application* Cashew::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Cashew {

    int Main(int argc, char** argv)
    {
        while (g_ApplicationRunning)
        {
            Cashew::Application* app = Cashew::CreateApplication(argc, argv);
            app->Run();
            delete app;
        }

        return 0;
    }

}

#ifdef WL_DIST

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return Cashew::Main(__argc, __argv);
}

#else

int main(int argc, char** argv)
{
    return Cashew::Main(argc, argv);
}

#endif // WL_DIST

#endif

#ifdef __linux__

extern Cashew::Application* Cashew::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace Cashew {

    int Main(int argc, char** argv)
    {
        while (g_ApplicationRunning)
        {
            Cashew::Application* app = Cashew::CreateApplication(argc, argv);
            app->Run();
            delete app;
        }

        return 0;
    }

}

int main(int argc, char** argv)
{
    return Cashew::Main(argc, argv);
}

#endif // WL_PLATFORM_LINUX
#endif //CASHEW_ENTRYPOINT_H