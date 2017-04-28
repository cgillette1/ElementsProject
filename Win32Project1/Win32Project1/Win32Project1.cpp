// Win32Project1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Win32Project1.h"
#include <string>
#include <fstream>
#include "Element.h"
#include "commctrl.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HWND groupButton;

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//int main(int argc, char* argv[]) // SUBSYSTEM:CONSOLE
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
					 
{
	AllocConsole();
	AttachConsole(GetCurrentProcessId());
	freopen("CON", "w", stdout);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.
	Element elements[107];
	for (int i = 0; i < 107; i++) {
		elements[i].getFileData(i + 1);
	}
	/*for (int i = 0; i < 107; i++) {
		cout << elements[i].getAtomicNumber() << endl;
		cout << elements[i].getChemName() << endl;
		cout << elements[i].getChemSum() << endl;
		cout << elements[i].getGroup() << endl;
		cout << elements[i].getPeriod() << endl;
		cout << elements[i].getAtomicWeight() << endl;
		cout << elements[i].getMeltPt() << endl;
		cout << elements[i].getBoilPt() << endl;
		cout << elements[i].getHhBondL() << endl;
		cout << elements[i].getEConfig() << endl;
		cout << elements[i].getOxState() << endl;
		cout << elements[i].getFIonP() << endl;
		cout << elements[i].getEAffinity() << endl << endl;
	}*/

	for (int i = 0; i < 107; i++) {
	//	elements[i].searchbyGroup(1, elements);
	}

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WIN32PROJECT1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WIN32PROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, L"The Periodic Table of Elements", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{HWND title = CreateWindow(
		L"STATIC",  // Predefined class; Unicode assumed 
		L"Search By:",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | WS_BORDER | SS_CENTER,  // Styles 
		425,         // x position 
		20,         // y position 
		150,        // Button width
		20,        // Button height
		hWnd,     // Parent window
		NULL,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	}
	{HWND groupButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"GROUP",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		50,         // x position 
		100,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU)1,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	}
	{HWND periodButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"PERIOD",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		200,         // x position 
		100,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU)2,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	}
	{HWND weightButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Atomic Weight",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		350,         // x position 
		100,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU)3,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	}
	{HWND numberButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Atomic Number",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		500,         // x position 
		100,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU)4,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	}
	{HWND chemsymButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Chemical Symbol",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		650,         // x position 
		100,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU)5,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	}
	{HWND chemnameButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"Element Name",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		800,         // x position 
		100,         // y position 
		150,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU)6,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	}
	{HWND exitButton = CreateWindow(
		L"BUTTON",  // Predefined class; Unicode assumed 
		L"EXIT",      // Button text 
		WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
		450,         // x position 
		310,         // y position 
		100,        // Button width
		100,        // Button height
		hWnd,     // Parent window
		(HMENU)2,       // No menu.
		NULL,
		//(HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE),
		NULL);      // Pointer not needed.
	break;
	}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
		switch(LOWORD(wParam)) {
		case 1: 

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 7:

			break;
		}
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
