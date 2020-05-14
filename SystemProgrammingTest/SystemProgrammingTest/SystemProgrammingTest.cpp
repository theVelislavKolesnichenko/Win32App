// SystemProgrammingTest.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SystemProgrammingTest.h"
#include <string>
#include <cwchar>
#include <ctime>
#include <commctrl.h>
#include <sstream>

using namespace std;
#define MAX_LOADSTRING 100
#define TIMER1 500

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc(HWND, UINT, WPARAM, LPARAM);

LRESULT CALLBACK    DialogProc1(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc2(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc3(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc4(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc5(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc6(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc7(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc8(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc9(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc10(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc11(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc12(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    DialogProc13(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SYSTEMPROGRAMMINGTEST, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SYSTEMPROGRAMMINGTEST));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SYSTEMPROGRAMMINGTEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = //MAKEINTRESOURCEW(IDR_MENU2); 
		MAKEINTRESOURCEW(IDC_SYSTEMPROGRAMMINGTEST);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
			case ID_TEST_PROBLEM:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG1, hWnd, (DLGPROC)DialogProc);
				break;
			case ID_DRAW_1:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc1);
				break;
			case ID_DRAW_2:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc2);
				break;
			case ID_DRAW_3:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc3);
				break;
			case ID_DRAW_4:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc4);
				break;
			case ID_DRAW_5:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc5);
				break;
			case ID_DRAW_6:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc6);
				break;
			case ID_DRAW_7:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc7);
				break;
			case ID_DRAW_8:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc8);
				break;
			case ID_DRAW_9:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc9);
				break;
			case ID_DRAW_10:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG2, hWnd, (DLGPROC)DialogProc10);
				break;
			case ID_DRAW_11:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG3, hWnd, (DLGPROC)DialogProc11);
				break;
			case ID_DRAW_12:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG6, hWnd, (DLGPROC)DialogProc12);
				break;
			case ID_DRAW_13:
				DialogBox(hInst, (LPCWSTR)IDD_DIALOG7, hWnd, (DLGPROC)DialogProc13);
				break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...

			TCHAR str[MAX_LOADSTRING];
			RECT rt;
			GetClientRect(hWnd, &rt);

			LoadString(hInst, IDS_STRING104, str, MAX_LOADSTRING);
			int height = DrawText(hdc, str, wcslen(str), &rt, DT_CENTER);

			OffsetRect(&rt, 0, height);

			LoadString(hInst, IDS_STRING105, str, MAX_LOADSTRING);
			DrawText(hdc, str, wcslen(str), &rt, DT_CENTER);

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

// Message handler for about box.
LRESULT CALLBACK DialogProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		srand(time(NULL));
		for (int i = 1; i <= 10; i++)
		{
			wstringstream wss;
			wss << rand() % 100 + 1;
			SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, i, (LPARAM)wss.str().c_str());

			//std::wstring text = std::to_wstring(std::rand() % 100 + 1);
			//SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, i, (LPARAM)text.c_str());
		}
		return TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		case IDC_BUTTON1:
		{
			int i = 0;
			int count = -1;
			std::wstring text;// = std::to_wstring(i);
			
			//do
			//{
			//	i += 5;
			//	text = std::to_wstring(i);
			//	count = count++;
			//} while ((SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)text.c_str()) > -1));

			count = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCOUNT, 0, 0);
			TCHAR buff[500];
			for (int o =0; o < count; o++) 
			{
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCOUNT, o, (LPARAM)buff);
				MessageBox(hDlg, buff, L"Title", MB_OK);
			}

			//do
			//{
			//	i += 5;
			//	text = std::to_wstring(i);
			//	count = count++;
			//} while ((SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)text.c_str()) > -1));

			text = std::to_wstring(count);
			MessageBox(hDlg, text.c_str(), L"Title", MB_OK);
		}
		break;
		default:
			break;
		}
	break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE: 
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT: 
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...
		SelectObject(hdc, GetStockObject(ANSI_VAR_FONT));

		for (int i = 0; i < 17; i++)
		{
			if (i == 0)
			{
				TextOut(hdc, 130, 20, std::to_wstring(20).c_str(), wcslen(std::to_wstring(20).c_str()));
				TextOut(hdc, 150, 0, std::to_wstring(160).c_str(), wcslen(std::to_wstring(160).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else if (i == 7)
			{
				TextOut(hdc, 130, 90, std::to_wstring(90).c_str(), wcslen(std::to_wstring(90).c_str()));
				TextOut(hdc, 230, 0, std::to_wstring(230).c_str(), wcslen(std::to_wstring(230).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else if (i == 14)
			{
				TextOut(hdc, 130, 160, std::to_wstring(160).c_str(), wcslen(std::to_wstring(160).c_str()));
				TextOut(hdc, 300, 0, std::to_wstring(300).c_str(), wcslen(std::to_wstring(300).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else
			{
				MoveToEx(hdc, 150, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 20, NULL); LineTo(hdc, 150 + i * 10, 170);
			}

		}
		POINT pp[4];
		pp[0].x = 210; pp[0].y = 110;
		pp[1].x = 200; pp[1].y = 120;
		pp[2].x = 270; pp[2].y = 120;
		pp[3].x = 260; pp[3].y = 110;

		Polygon(hdc, pp,4);
		
		Rectangle(hdc, 210, 120, 260, 160);//2

		Rectangle(hdc, 160, 150, 170, 160);//3
		Rectangle(hdc, 140, 160, 260, 220);//1

		Ellipse(hdc, 150, 200, 190, 240);
		Ellipse(hdc, 210, 200, 250, 240);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;
	case WM_CTLCOLORDLG:
		return (LONG)CreateSolidBrush(RGB(255, 255, 255));
	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...

		SelectObject(hdc, GetStockObject(ANSI_VAR_FONT));

		for (int i = 0; i < 18; i++)
		{
			if (i == 0)
			{
				TextOut(hdc, 130, 20, std::to_wstring(20).c_str(), wcslen(std::to_wstring(20).c_str()));
				TextOut(hdc, 150, 0, std::to_wstring(160).c_str(), wcslen(std::to_wstring(160).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 320, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 190);
			}
			else if (i == 8)
			{
				TextOut(hdc, 130, 90, std::to_wstring(100).c_str(), wcslen(std::to_wstring(100).c_str()));
				TextOut(hdc, 230, 0, std::to_wstring(240).c_str(), wcslen(std::to_wstring(240).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 320, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 190);
			}
			else if (i == 16)
			{
				TextOut(hdc, 130, 160, std::to_wstring(180).c_str(), wcslen(std::to_wstring(180).c_str()));
				TextOut(hdc, 300, 0, std::to_wstring(320).c_str(), wcslen(std::to_wstring(320).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 320, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 190);
			}
			else
			{
				MoveToEx(hdc, 150, 20 + i * 10, NULL); LineTo(hdc, 320, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 20, NULL); LineTo(hdc, 150 + i * 10, 190);
			}

		}

		POINT pp[4];

		pp[0].x = 240;
		pp[0].y = 30;
		pp[1].x = 200;
		pp[1].y = 60;
		pp[2].x = 280;
		pp[2].y = 60;

		Polygon(hdc, pp, 3);

		Rectangle(hdc, 200, 60, 280, 160);

		pp[0].x = 230;
		pp[0].y = 160;
		pp[1].x = 210;
		pp[1].y = 180;
		pp[2].x = 270;
		pp[2].y = 180;
		pp[3].x = 250;
		pp[3].y = 160;

		Polygon(hdc, pp, 4);

		pp[0].x = 200;
		pp[0].y = 120;
		pp[1].x = 180;
		pp[1].y = 180;
		pp[2].x = 200;
		pp[2].y = 180;

		Polygon(hdc, pp, 3);

		pp[0].x = 280;
		pp[0].y = 120;
		pp[1].x = 300;
		pp[1].y = 180;
		pp[2].x = 280;
		pp[2].y = 180;

		Polygon(hdc, pp, 3);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc3(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;
	case WM_CTLCOLORDLG:
		return (LONG)CreateSolidBrush(RGB(255, 255, 255));

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...
		SelectObject(hdc, GetStockObject(ANSI_VAR_FONT));

		for (int i = 0; i < 16; i++)
		{
			if (i == 0) 
			{
				TextOut(hdc, 130, 20, std::to_wstring(20).c_str(), wcslen(std::to_wstring(20).c_str()));
				TextOut(hdc, 150, 0, std::to_wstring(160).c_str(), wcslen(std::to_wstring(160).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else if (i == 7)
			{
				TextOut(hdc, 130, 90, std::to_wstring(90).c_str(), wcslen(std::to_wstring(90).c_str()));
				TextOut(hdc, 230, 0, std::to_wstring(230).c_str(), wcslen(std::to_wstring(230).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else if (i == 14)
			{
				TextOut(hdc, 130, 160, std::to_wstring(160).c_str(), wcslen(std::to_wstring(160).c_str()));
				TextOut(hdc, 300, 0, std::to_wstring(300).c_str(), wcslen(std::to_wstring(300).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else
			{
				MoveToEx(hdc, 150, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 20, NULL); LineTo(hdc, 150 + i * 10, 170);
			}

		}


		POINT pp[4];
	
		Ellipse(hdc, 210, 30, 270, 60);

		pp[0].x = 240;
		pp[0].y = 60;
		pp[1].x = 210;
		pp[1].y = 140;
		pp[2].x = 270;
		pp[2].y = 140;

		Polygon(hdc, pp, 3);
		//SelectObject(hdc, CreateSolidBrush(RGB(255, 0, 255)));
		Rectangle(hdc, 190, 90, 230, 100);
		
		Rectangle(hdc, 250, 90, 290, 100);

		pp[0].x = 220;
		pp[0].y = 140;
		pp[1].x = 210;
		pp[1].y = 160;
		pp[2].x = 230;
		pp[2].y = 160;

		Polygon(hdc, pp, 3);

		pp[0].x = 260;
		pp[0].y = 140;
		pp[1].x = 250;
		pp[1].y = 160;
		pp[2].x = 270;
		pp[2].y = 160;

		Polygon(hdc, pp, 3);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc4(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;
	case WM_CTLCOLORDLG:
		return (LONG)CreateSolidBrush(RGB(255, 255, 255));
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		SelectObject(hdc, GetStockObject(ANSI_VAR_FONT));

		// TODO: Add any drawing code that uses hdc here...
		for (int i = 0; i < 16; i++)
		{
			if (i == 0)
			{
				TextOut(hdc, 130, 20, std::to_wstring(20).c_str(), wcslen(std::to_wstring(20).c_str()));
				TextOut(hdc, 150, 0, std::to_wstring(160).c_str(), wcslen(std::to_wstring(160).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else if (i == 7)
			{
				TextOut(hdc, 130, 90, std::to_wstring(90).c_str(), wcslen(std::to_wstring(90).c_str()));
				TextOut(hdc, 230, 0, std::to_wstring(230).c_str(), wcslen(std::to_wstring(230).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else if (i == 14)
			{
				TextOut(hdc, 130, 160, std::to_wstring(160).c_str(), wcslen(std::to_wstring(160).c_str()));
				TextOut(hdc, 300, 0, std::to_wstring(300).c_str(), wcslen(std::to_wstring(300).c_str()));
				MoveToEx(hdc, 130, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 0, NULL); LineTo(hdc, 150 + i * 10, 170);
			}
			else
			{
				MoveToEx(hdc, 150, 20 + i * 10, NULL); LineTo(hdc, 300, 20 + i * 10);
				MoveToEx(hdc, 150 + i * 10, 20, NULL); LineTo(hdc, 150 + i * 10, 170);
			}

		}
		POINT pp[4];

		pp[0].x = 240;
		pp[0].y = 60;
		pp[1].x = 210;
		pp[1].y = 140;
		pp[2].x = 270;
		pp[2].y = 140;

		Polygon(hdc, pp, 3);

		Rectangle(hdc, 220, 40, 260, 70);

		Ellipse(hdc, 190, 90, 230, 100);

		Ellipse(hdc, 250, 90, 290, 100);

		Rectangle(hdc, 220, 140, 230, 160);
		
		Rectangle(hdc, 250, 140, 260, 160);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc5(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...


		POINT pp[4];

		pp[0].x = 240;
		pp[0].y = 60;
		pp[1].x = 220;
		pp[1].y = 110;
		pp[2].x = 260;
		pp[2].y = 110;

		Rectangle(hdc, 210, 80, 240, 100);

		Rectangle(hdc, 240, 80, 270, 100);

		Polygon(hdc, pp, 3);

		Ellipse(hdc, 220, 40, 260, 70);

		pp[0].x = 220;
		pp[0].y = 110;
		pp[1].x = 260;
		pp[1].y = 110;
		pp[2].x = 240;
		pp[2].y = 140;

		Polygon(hdc, pp, 3);
		
		pp[0].x = 240;
		pp[0].y = 140;
		pp[1].x = 220;
		pp[1].y = 160;
		pp[2].x = 230;
		pp[2].y = 160;

		Polygon(hdc, pp, 3);

		pp[0].x = 240;
		pp[0].y = 140;
		pp[1].x = 250;
		pp[1].y = 160;
		pp[2].x = 260;
		pp[2].y = 160;

		Polygon(hdc, pp, 3);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc6(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...

		POINT pp[4];
		pp[0].x = 210;
		pp[0].y = 110;
		pp[1].x = 200;
		pp[1].y = 120;
		pp[2].x = 270;
		pp[2].y = 120;
		pp[3].x = 260;
		pp[3].y = 110;

		Polygon(hdc, pp, 4);

		Rectangle(hdc, 210, 120, 260, 160);

		Rectangle(hdc, 160, 150, 170, 160);
		Rectangle(hdc, 140, 160, 260, 220);

		Ellipse(hdc, 150, 200, 190, 240);
		Ellipse(hdc, 210, 200, 250, 240);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc7(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...

		POINT pp[4];
		pp[0].x = 210;
		pp[0].y = 110;
		pp[1].x = 200;
		pp[1].y = 120;
		pp[2].x = 270;
		pp[2].y = 120;
		pp[3].x = 260;
		pp[3].y = 110;

		Polygon(hdc, pp, 4);

		Rectangle(hdc, 210, 120, 260, 160);

		Rectangle(hdc, 160, 150, 170, 160);
		Rectangle(hdc, 140, 160, 260, 220);

		Ellipse(hdc, 150, 200, 190, 240);
		Ellipse(hdc, 210, 200, 250, 240);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc8(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...

		POINT pp[4];
		pp[0].x = 210;
		pp[0].y = 110;
		pp[1].x = 200;
		pp[1].y = 120;
		pp[2].x = 270;
		pp[2].y = 120;
		pp[3].x = 260;
		pp[3].y = 110;

		Polygon(hdc, pp, 4);

		Rectangle(hdc, 210, 120, 260, 160);

		Rectangle(hdc, 160, 150, 170, 160);
		Rectangle(hdc, 140, 160, 260, 220);

		Ellipse(hdc, 150, 200, 190, 240);
		Ellipse(hdc, 210, 200, 250, 240);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc9(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...

		POINT pp[4];
		pp[0].x = 210;
		pp[0].y = 110;
		pp[1].x = 200;
		pp[1].y = 120;
		pp[2].x = 270;
		pp[2].y = 120;
		pp[3].x = 260;
		pp[3].y = 110;

		Polygon(hdc, pp, 4);

		Rectangle(hdc, 210, 120, 260, 160);

		Rectangle(hdc, 160, 150, 170, 160);
		Rectangle(hdc, 140, 160, 260, 220);

		Ellipse(hdc, 150, 200, 190, 240);
		Ellipse(hdc, 210, 200, 250, 240);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc10(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);

	}
	break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...

		POINT pp[4];
		pp[0].x = 210;
		pp[0].y = 110;
		pp[1].x = 200;
		pp[1].y = 120;
		pp[2].x = 270;
		pp[2].y = 120;
		pp[3].x = 260;
		pp[3].y = 110;

		Polygon(hdc, pp, 4);

		Rectangle(hdc, 210, 120, 260, 160);

		Rectangle(hdc, 160, 150, 170, 160);
		Rectangle(hdc, 140, 160, 260, 220);

		Ellipse(hdc, 150, 200, 190, 240);
		Ellipse(hdc, 210, 200, 250, 240);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc11(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int a = 0;

	switch (message)
	{
	case WM_INITDIALOG:
		SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, 100, 0);

		//for (int i =0; i<24;i++) 
		//{
		//	std::wstring text = std::to_wstring((int)(i%12));
		//	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)text.c_str());
		//}

		return TRUE;

	case WM_RBUTTONDOWN:
	{
		HMENU hMenu = LoadMenu(hInst, (LPCWSTR)IDR_MENU1);
		HMENU hSubMenu = GetSubMenu(hMenu, 0);
		POINT pt = { LOWORD(lParam), HIWORD(lParam) };
		ClientToScreen(hDlg, &pt);
		TrackPopupMenu(hSubMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hDlg, NULL);
		DestroyMenu(hMenu);
	}
	break;

	case WM_TIMER:
	{
		a = a + 1;
		if (a == 5) 
		{
			MessageBox(hDlg, L"a = 5", L"MessageBox", MB_OK | MB_ICONINFORMATION);
			KillTimer(hDlg, TIMER1);
		}
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		case ID_POP_POP:
		{
			int result = MessageBox(hDlg, L"Select", L"MessageBox", MB_YESNO | MB_ICONQUESTION);
			if (result == IDYES)
			{
				MessageBox(hDlg, L"Start Timer", L"MessageBox", MB_OK | MB_ICONINFORMATION);
				SetTimer(hDlg, TIMER1, 20, NULL);
			}
		}
		break;

		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc12(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int a = 0;
	static int step = 20;
	switch (message)
	{
	case WM_INITDIALOG:
		SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, 50, 0);

		//for (int i =0; i<24;i++) 
		//{
		//	std::wstring text = std::to_wstring((int)(i%12));
		//	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)text.c_str());
		//}

		return TRUE;

	case WM_TIMER:
	{
		if (SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0) > 0)
		{
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, -20, 0);
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
		}
		else
		{
			KillTimer(hDlg, TIMER1);
		}
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		case IDC_BUTTON4:
			{
			SetTimer(hDlg, TIMER1, 20, NULL);
			}
			break;
		case IDC_BUTTON1:
		{
			if (IsDlgButtonChecked(hDlg, IDC_RADIO1)) SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"1");
			if (IsDlgButtonChecked(hDlg, IDC_RADIO2)) SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"2");
			if (IsDlgButtonChecked(hDlg, IDC_RADIO3)) SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"3");
			if (IsDlgButtonChecked(hDlg, IDC_RADIO4)) SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"4");
			if (IsDlgButtonChecked(hDlg, IDC_RADIO5)) SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"5");
			if (IsDlgButtonChecked(hDlg, IDC_RADIO6)) SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"6");
			if (IsDlgButtonChecked(hDlg, IDC_RADIO7)) SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)"7");

		}
		break;
		case IDC_BUTTON2:
		{
			TCHAR buff[100], *st;
			int count = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCOUNT, 0, 0);
			int counts[7] = { 0, 0, 0, 0, 0, 0, 0};
			for (int i = 0; i < count; i++) 
			{
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETLBTEXT, i, (LPARAM)buff);
				int day = _tcstod(buff, &st);
				counts[( day - 1)]++;
			}

			for (int i = 0; i < 7; i++)
			{
				wstringstream wss, wss1;
				wss << counts[i];
				wss1 << i + 1;
				MessageBox(hDlg, wss.str().c_str(), wss1.str().c_str(), MB_OK);
			}
		}
		break;
		case IDC_BUTTON3:
		{
			int cbIndex = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCURSEL, 0, 0);
			if (cbIndex > -1)
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_DELETESTRING, cbIndex, 0);
		}
		break;
		case IDC_BUTTON5:
		{
			TCHAR buff[100], *st;
			int cbIndex = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCURSEL, 0, 0);
			if (cbIndex > -1)
			{
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETLBTEXT, cbIndex, (LPARAM)buff);
				int b = _tcstod(buff, &st);
				int a = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, TRUE);
				switch (a%b)
				{
				case 1:
					MessageBox(hDlg, L"Monday", L"Day", MB_OK);
					break;
				case 2:
					MessageBox(hDlg, L"Tuesday", L"Day", MB_OK);
					break;
				case 3:
					MessageBox(hDlg, L"Wednesday", L"Day", MB_OK);
					break;
				case 4:
					MessageBox(hDlg, L"Thursday", L"Day", MB_OK);
					break;
				case 5:
					MessageBox(hDlg, L"Friday", L"Day", MB_OK);
					break;
				case 6:
					MessageBox(hDlg, L"Saturday", L"Day", MB_OK);
					break;
				case 7:
					MessageBox(hDlg, L"Ponedelnik", L"Day", MB_OK);
					break;
				default:
					break;
				}
			}
		}
		break;
		}
		break;
	}
	return FALSE;
}

LRESULT CALLBACK DialogProc13(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int a = 0;

	switch (message)
	{
	case WM_INITDIALOG:
		SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, 100, 0);

		//for (int i =0; i<24;i++) 
		//{
		//	std::wstring text = std::to_wstring((int)(i%12));
		//	SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)text.c_str());
		//}

		return TRUE;

	case WM_RBUTTONDOWN:
	{
		HMENU hMenu = LoadMenu(hInst, (LPCWSTR)IDR_MENU1);
		HMENU hSubMenu = GetSubMenu(hMenu, 0);
		POINT pt = { LOWORD(lParam), HIWORD(lParam) };
		ClientToScreen(hDlg, &pt);
		TrackPopupMenu(hSubMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hDlg, NULL);
		DestroyMenu(hMenu);
	}
	break;

	case WM_TIMER:
	{
		a = a + 1;
		if (a == 5)
		{
			MessageBox(hDlg, L"a = 5", L"MessageBox", MB_OK | MB_ICONINFORMATION);
			KillTimer(hDlg, TIMER1);
		}
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK: case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		case ID_POP_POP:
		{
			int result = MessageBox(hDlg, L"Select", L"MessageBox", MB_YESNO | MB_ICONQUESTION);
			if (result == IDYES)
			{
				MessageBox(hDlg, L"Start Timer", L"MessageBox", MB_OK | MB_ICONINFORMATION);
				SetTimer(hDlg, TIMER1, 20, NULL);
			}
		}
		break;

		}
		break;
	}
	return FALSE;
}