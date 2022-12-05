// 21winapiframework.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "21winapiframework.h"
#include "BWindow.h"
#include "Core.h"
//#include <crtdbg.h>
#define MAX_LOADSTRING 100

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
 //   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
 //    _CrtSetBreakAlloc(207);
 //   int* a = new int[10];
    BWindow game;
    game.Run(hInstance, lpCmdLine, nCmdShow);
}

