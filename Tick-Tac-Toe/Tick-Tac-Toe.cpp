/**************************************
* Copyright(c) 2019 ICheng Chen 陳易成 E14046583
* All rights reserved.
***************************************/

#include "stdafx.h"
#include "GameWindow.h"

using namespace System;
using namespace TickTacToe;

int main(array<System::String ^> ^args)
{
    Console::WriteLine(L"Hello World");

	Application::Run(gcnew GameWindow());

    return 0;
}
