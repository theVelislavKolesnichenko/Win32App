// SoftwareSystems.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "SoftwareSystems.h"

/*#include <cwchar>*/ 


#include <string>
#include "atlstr.h"
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <commctrl.h>

using namespace std;

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

#pragma region Example 2
LRESULT CALLBACK    Example2DialogBox(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    Example2MessageBox(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

#pragma region Example 4
LRESULT CALLBACK    Example4Integer(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK    Example4Real(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

#pragma region Example 5
LRESULT CALLBACK Example5DialogBox(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

#pragma region Example 6
LRESULT CALLBACK Example6DialogBox(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

#pragma region Example 7
LRESULT CALLBACK Example7DialogBox(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

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
    LoadStringW(hInstance, IDC_SOFTWARESYSTEMS, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SOFTWARESYSTEMS));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SOFTWARESYSTEMS));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_SOFTWARESYSTEMS);
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
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, (DLGPROC)About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
#pragma region Example 2
				//Example 2
			case ID_EXAMPLE2_DIALOGBOX:
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG1, hWnd, (DLGPROC)Example2DialogBox);
				break;
			case ID_EXAMPLE2_MESSAGEBOX:
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG2, hWnd, (DLGPROC)Example2MessageBox);
				break;
#pragma endregion

#pragma region Example 3
			case ID_POP_OPEN:
			case ID_EXAMPLE3_OPENCTRL:
			case ID_MENUEXAMPLE_OPEN:
				MessageBox(hWnd, L"Open", L"Info", MB_OK | MB_ICONINFORMATION);
				break;
			case ID_POP_SAVE:
			case ID_MENUEXAMPLE_SAVE:
				MessageBox(hWnd, L"Save", L"Info", MB_OK | MB_ICONQUESTION);
				break;
			case ID_POP_CHECKEXAMPLE:
			case ID_MENUEXAMPLE_CHECKEXAMPLE:
			{
				HMENU hMenu = GetMenu(hWnd);
				UINT res = GetMenuState(hMenu, ID_MENUEXAMPLE_CHECKEXAMPLE, MF_BYCOMMAND);
				if (res & MF_CHECKED)
					CheckMenuItem(hMenu, ID_MENUEXAMPLE_CHECKEXAMPLE, MF_UNCHECKED);
				else
					CheckMenuItem(hMenu, ID_MENUEXAMPLE_CHECKEXAMPLE, MF_CHECKED);  
			}
			break;
			case ID_POP_DISABLEEXAMPLE:
			case ID_MENUEXAMPLE_DISABLEEXAMPLE:
			{
				HMENU hMenu = GetMenu(hWnd);
				EnableMenuItem(hMenu, ID_MENUEXAMPLE_DISABLEEXAMPLE, MF_DISABLED);
			}
			break;
			case ID_POP_ENABLEEXAMPLE:
			case ID_MENUEXAMPLE_ENABLEEXAMPLE:
			{
				HMENU hMenu = GetMenu(hWnd);
				UINT res = GetMenuState(hMenu, ID_MENUEXAMPLE_DISABLEEXAMPLE, MF_BYCOMMAND);
				if (res & MF_DISABLED)
					EnableMenuItem(hMenu, ID_MENUEXAMPLE_DISABLEEXAMPLE, MF_ENABLED);
				else
					EnableMenuItem(hMenu, ID_MENUEXAMPLE_DISABLEEXAMPLE, MF_DISABLED);
			}
			break;
			case ID_POP_ADDMENUITEM:
			{
				HMENU hMenu = LoadMenu(hInst, (LPCWSTR)IDR_MENU1);
				if (GetMenuState(hMenu, ID_POP_ADDMENUITEM + 1000, MF_BYCOMMAND) == -1) // or disable
				{
					MENUITEMINFO mii;
					ZeroMemory(&mii, sizeof(mii));
					mii.cbSize = sizeof(mii);
					mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
					mii.wID = ID_POP_ADDMENUITEM + 1000;
					mii.fType = MFT_STRING;
					mii.dwTypeData = TEXT("Delete &me");
					mii.fState = MFS_ENABLED;

					InsertMenuItem(hMenu, ID_POP_ADDMENUITEM, FALSE, &mii);
				}
			}
			break;
			case ID_MENUEXAMPLE_ADDMENUITEM:
			{
				HMENU hMenu = GetMenu(hWnd);

				if (GetMenuState(hMenu, ID_MENUEXAMPLE_ADDMENUITEM + 1000, MF_BYCOMMAND) == -1) // or disable
				{
					MENUITEMINFO mii;
					ZeroMemory(&mii, sizeof(mii));
					mii.cbSize = sizeof(mii);
					mii.fMask = MIIM_ID | MIIM_TYPE | MIIM_STATE;
					mii.wID = ID_MENUEXAMPLE_ADDMENUITEM + 1000;
					mii.fType = MFT_STRING;
					mii.dwTypeData = TEXT("Delete &me");
					mii.fState = MFS_ENABLED;

					InsertMenuItem(hMenu, ID_MENUEXAMPLE_ADDMENUITEM, FALSE, &mii);
				}
			}
			break;
			case ID_POP_ADDMENUITEM + 1000:
			case ID_MENUEXAMPLE_ADDMENUITEM + 1000:
			{
				HMENU hMenu = GetMenu(hWnd);
				DeleteMenu(hMenu, ID_MENUEXAMPLE_ADDMENUITEM + 1000, MF_BYCOMMAND);
			}
			break;
			case ID_POP_DOSOMETING:
				MessageBox(hWnd, L"Do Something", L"Message", MB_OK);
				break;
#pragma endregion

#pragma region Example 4
			case ID_EXAMPLE4_INTEGER:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG3, hWnd, (DLGPROC)Example4Integer);
			}
			break;
			case ID_EXAMPLE4_REAL:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG3, hWnd, (DLGPROC)Example4Real);
			}
			break;
#pragma endregion

#pragma region Example 5
			case ID_EXAMPLE5_OPEN:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG4, hWnd, (DLGPROC)Example5DialogBox);
			}
			break;
#pragma endregion

#pragma region Example 6
			case ID_EXAMPLE6_OPEN:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG5, hWnd, (DLGPROC)Example6DialogBox);
			}
			break;
#pragma endregion

#pragma region Example 7
			case ID_EXAMPLE7_OPEN:
			{
				DialogBox(hInst, (LPCTSTR)IDD_DIALOG6, hWnd, (DLGPROC)Example7DialogBox);
			}
			break;
#pragma endregion
#pragma endregion

            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;

#pragma region Example 3

		case WM_RBUTTONDOWN:
		{

			HMENU hMenu = LoadMenu(hInst, (LPCWSTR)IDR_MENU1);
			HMENU hSubMenu = GetSubMenu(hMenu, 0);
			POINT pt = { LOWORD(lParam), HIWORD(lParam) };
			ClientToScreen(hWnd, &pt);
			TrackPopupMenu(hSubMenu, TPM_RIGHTBUTTON, pt.x, pt.y, 0, hWnd, NULL);
			DestroyMenu(hMenu);
		}
		break;

#pragma endregion

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
#pragma region Example 1

			TCHAR str[MAX_LOADSTRING];
			RECT rt;
			GetClientRect(hWnd, &rt);
			LoadString(hInst, IDS_STRING104, str, MAX_LOADSTRING);
			DrawText(hdc, str, wcslen(str), &rt, DT_CENTER);

#pragma endregion



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
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		{
			TCHAR str[MAX_LOADSTRING];
			RECT rt;
			LoadString(hInst, IDS_STRING104, str, MAX_LOADSTRING);
			SetDlgItemText(hDlg, IDC_STATIC1, str);
		}
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

#pragma region Example 2

LRESULT CALLBACK Example2DialogBox(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	//int wmId, wmEvent;

	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDC_EDIT1, L"Example1");
		return TRUE;

	case WM_COMMAND:
		//wmId = LOWORD(wParam);
		switch (HIWORD(wParam))
		{
		case EN_CHANGE:
		{
			if (LOWORD(wParam) == IDC_EDIT1) {
				TCHAR buff[10000];
				GetDlgItemText(hDlg, IDC_EDIT1, buff, sizeof(buff));
				int lastIndex = _tcslen(buff);
				TCHAR lastValue = buff[lastIndex - 1];
				if (lastValue >= '0' && lastValue <= '9')
				{
					TCHAR newBuff[10000];
					_tcsncpy_s(newBuff, buff, (lastIndex - 2));
					SetDlgItemText(hDlg, LOWORD(wParam), newBuff);
				}
			}
		}
		break;
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
			break;
		case IDC_BUTTON1:
			MessageBox(hDlg, L"Message1", L"Hello", MB_ICONEXCLAMATION | MB_ICONEXCLAMATION);
			break;
		case IDC_BUTTON2:
			MessageBox(hDlg, L"Message2", L"Hello", MB_RETRYCANCEL | MB_ICONWARNING);
			break;
		case IDC_BUTTON3:
		{
			int msresult = 0;
			msresult = MessageBox(hDlg, L"Select Yes or NO", L"Select", MB_YESNO | MB_ICONINFORMATION);
			if (msresult == IDYES)
			{
				MessageBox(hDlg, L"Yes button was selected!!!", L"Hello World", MB_OK | MB_ICONASTERISK);
			}
			else
			{
				MessageBox(hDlg, L"No button was selected!!!", L"Hello World", MB_OK | MB_ICONQUESTION);
			}
		}
		break;
		case IDC_BUTTON4:
			TCHAR buff[10000];
			GetDlgItemText(hDlg, IDC_EDIT1, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Word", MB_OKCANCEL | MB_ICONSTOP);
			break;
		}
	break;
	}

	return FALSE;
}

LRESULT CALLBACK Example2MessageBox(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
			break;
		case IDC_BUTTON1:
			switch (MessageBox(hDlg, L"Message Box", L"MSG", MB_RETRYCANCEL | MB_ICONERROR))
			//switch (MessageBox(hDlg, L"Message Box", L"MSG", MB_YESNOCANCEL | MB_ICONERROR))

		{
			case IDRETRY: 
			case IDYES:
				MessageBox(hDlg, L"Yes", L"MSG", MB_HELP);
				break;
			case IDNO:
				MessageBox(hDlg, L"No", L"MSG", MB_OK);
				break;
			case IDCANCEL:
				MessageBox(hDlg, L"Cancel", L"MSG", MB_OK);
				break;
			}
			break;
		}
		break;
	}

	return FALSE;
}

#pragma endregion

#pragma region Example 4

LRESULT CALLBACK    Example4Real(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	double a, b, c, d;
	std::wstring s;

	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDC_EDIT1, L"1");
		SetDlgItemText(hDlg, IDC_EDIT2, L"2");
		SetDlgItemText(hDlg, IDC_EDIT3, L"3");
		SetDlgItemText(hDlg, IDC_EDIT4, L"4");
		SetDlgItemText(hDlg, IDC_EDIT5, L"5");
		SetDlgItemText(hDlg, IDC_EDIT6, L"6");
		SetDlgItemText(hDlg, IDC_EDIT7, L"7");
		SetDlgItemText(hDlg, IDC_EDIT8, L"8");
		SetDlgItemText(hDlg, IDC_EDIT9, L"9");
		SetDlgItemText(hDlg, IDC_EDIT10, L"10");
		SetDlgItemText(hDlg, IDC_EDIT11, L"11");
		SetDlgItemText(hDlg, IDC_EDIT12, L"12");
		return TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
			break;
		case IDC_ADDITION:
		{
			TCHAR buff[100], *stopstring;
			a = _tcstod(buff, &stopstring);
			char result[100],*end, t11[100];
			GetDlgItemText(hDlg, IDC_EDIT1, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			a = _tcstod(buff, &stopstring);
			//a = strtod(result, &end);
			GetDlgItemText(hDlg, IDC_EDIT2, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			b = _tcstod(buff, &stopstring);
			//b = strtod(result, &end);
			c = a + b;
			//std::string d = printf("%s\n", b);


			char str[20] = "";
			float f = 4.5;
			sprintf_s(str, "%f", f);

			std::wstring s = std::to_wstring(c);
			_gcvt_s(t11,  10, c, 5);

			//a = _wtof(str);
			//TCHAR str1[100];
			//swprintf_s(str1, L"%d", c);
			
			//char hexstring[10];

			//_snprintf_s(hexstring, 10, "%f", c);

			//SetDlgItemText(hDlg, IDC_EDIT3, l);
			//MessageBox(hDlg, l, L"Result:", MB_OK);
			//_tcscpy(buff, A2T(str));
			wstringstream wss;
			wss << c;
			MessageBox(hDlg, wss.str().c_str(), L"Result:", MB_OK);
		}
		break;
		case IDC_SUBTRACTION:
		{
			TCHAR buff[100], *stopstring;

			GetDlgItemText(hDlg, IDC_EDIT4, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			a = _tcstod(buff, &stopstring);
			GetDlgItemText(hDlg, IDC_EDIT5, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			b = _tcstod(buff, &stopstring);

			c = a - b;
			std::wstring s = std::to_wstring(c);

			SetDlgItemText(hDlg, IDC_EDIT6, s.c_str());
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		case IDC_MULTIPLICATION:
		{
			TCHAR buff[100], *stopstring;

			GetDlgItemText(hDlg, IDC_EDIT7, buff, sizeof(buff));
			//MessageBox(hDlg, buff, L"Result:", MB_OK);
			a = _tcstod(buff, &stopstring);
			GetDlgItemText(hDlg, IDC_EDIT8, buff, sizeof(buff));
			//MessageBox(hDlg, buff, L"Result:", MB_OK);
			b = _tcstod(buff, &stopstring);
			GetDlgItemText(hDlg, IDC_EDIT9, buff, sizeof(buff));
			//MessageBox(hDlg, buff, L"Result:", MB_OK);
			d = _tcstod(buff, &stopstring);
			c = a + sqrt(b)/(d-a);

			std::wstring s = std::to_wstring(c);

			//SetDlgItemText(hDlg, IDC_EDIT9, s.c_str());
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		case IDC_DIVISION:
		{
			TCHAR buff[100], *stopstring;

			GetDlgItemText(hDlg, IDC_EDIT10, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			a = _tcstod(buff, &stopstring);
			GetDlgItemText(hDlg, IDC_EDIT11, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			b = _tcstod(buff, &stopstring);

			c = a / b;
			std::wstring s = std::to_wstring(c);

			SetDlgItemText(hDlg, IDC_EDIT12, s.c_str());
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		case IDC_BUTTON1:
		{
			TCHAR buff[100], *stopstring;

			GetDlgItemText(hDlg, IDC_EDIT10, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			a = _tcstod(buff, &stopstring);
			GetDlgItemText(hDlg, IDC_EDIT11, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			b = _tcstod(buff, &stopstring);
			GetDlgItemText(hDlg, IDC_EDIT12, buff, sizeof(buff));
			MessageBox(hDlg, buff, L"Result:", MB_OK);
			c = _tcstod(buff, &stopstring);

			double d = ((a*a) / c) - (sqrt(b) / (c - b));

			std::wstring s = std::to_wstring(d);
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		}
		break;
	}

	return FALSE;
}

LRESULT CALLBACK    Example4Integer(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	int a, b, c;

	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemText(hDlg, IDC_EDIT1, L"1");
		SetDlgItemText(hDlg, IDC_EDIT2, L"1");
		SetDlgItemText(hDlg, IDC_EDIT3, L"1");
		SetDlgItemText(hDlg, IDC_EDIT4, L"1");
		SetDlgItemText(hDlg, IDC_EDIT5, L"1");
		SetDlgItemText(hDlg, IDC_EDIT6, L"1");
		SetDlgItemText(hDlg, IDC_EDIT7, L"1");
		SetDlgItemText(hDlg, IDC_EDIT8, L"1");
		SetDlgItemText(hDlg, IDC_EDIT9, L"1");
		SetDlgItemText(hDlg, IDC_EDIT10, L"1");
		SetDlgItemText(hDlg, IDC_EDIT11, L"1");
		SetDlgItemText(hDlg, IDC_EDIT12, L"1");
		return TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
			break;
		case IDC_ADDITION:
		{
			BOOL *LPt = NULL;
			BOOL SIG = true;
			a = GetDlgItemInt(hDlg, IDC_EDIT1, LPt, SIG);
			b = GetDlgItemInt(hDlg, IDC_EDIT2, LPt, SIG);
			c = a + b;

			SetDlgItemInt(hDlg, IDC_EDIT3, c, TRUE);

			std::wstring s = std::to_wstring(c);
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		case IDC_SUBTRACTION:
		{
			BOOL *LPt = NULL;
			BOOL SIG = true;
			a = GetDlgItemInt(hDlg, IDC_EDIT4, LPt, SIG);
			b = GetDlgItemInt(hDlg, IDC_EDIT5, LPt, SIG);
			c = a - b;

			SetDlgItemInt(hDlg, IDC_EDIT6, c, TRUE);

			std::wstring s = std::to_wstring(c);
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		case IDC_MULTIPLICATION:
		{
			BOOL *LPt = NULL;
			BOOL SIG = true;
			a = GetDlgItemInt(hDlg, IDC_EDIT7, LPt, SIG);
			b = GetDlgItemInt(hDlg, IDC_EDIT8, LPt, SIG);
			c = a * b;

			SetDlgItemInt(hDlg, IDC_EDIT9, c, TRUE);

			std::wstring s = std::to_wstring(c);
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		case IDC_DIVISION:
		{
			BOOL *LPt = NULL;
			BOOL SIG = true;
			a = GetDlgItemInt(hDlg, IDC_EDIT10, LPt, SIG);
			b = GetDlgItemInt(hDlg, IDC_EDIT11, LPt, SIG);
			c = a / b;

			SetDlgItemInt(hDlg, IDC_EDIT12, c, TRUE);

			std::wstring s = std::to_wstring(c);
			MessageBox(hDlg, s.c_str(), L"Result:", MB_OK);
		}
		break;
		}
		break;
	}

	return FALSE;
}

#pragma endregion

#pragma region Example 5

LRESULT CALLBACK	Example5DialogBox(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{

	TCHAR buff[100];

	TCHAR *comboBoxData[] = { L"Row 1 in Combo Box", L"Row 2 in Combo Box", L"Row 3 in Combo Box",L"Row 2 in Combo Box", L"Row 3 in Combo Box" };

	TCHAR *listBoxData[] = { L"List row 1", L"List row 2", L"List row 3" , L"List row 3" };

	int c_index, l_index, cbIndex, lbIndex;

	switch (message)
	{
	case WM_INITDIALOG:
	{
		int count = sizeof(*comboBoxData) - 1;
		for (int i = 0; i < count; i++)
		{
			SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, i, (LPARAM)comboBoxData[i]);
		}
		//c_index = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_INSERTSTRING, 0, (LPARAM)comboBoxData[0]);
		//c_index = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_INSERTSTRING, 1, reinterpret_cast<LPARAM>((LPCTSTR)L"Row 2 in Combo Box"));
		//c_index = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_INSERTSTRING, 2, reinterpret_cast<LPARAM>((LPCTSTR)L"Row 3 in Combo Box"));

		//SendDlgItemMessage(hDlg, IDC_COMBO1, CB_SELECTSTRING, -1, (LPARAM)comboBoxData[1]);
		  SendDlgItemMessage(hDlg, IDC_COMBO1, CB_SETCURSEL, 2, 0);

		count = sizeof(*listBoxData) - 1;
		for (int i = 0; i < count; i++)
		{
			SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)listBoxData[i]);
		}

		//l_index = SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR)L"List row 1"));
		//l_index = SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR)L"List row 2"));
		//l_index = SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, reinterpret_cast<LPARAM>((LPCTSTR)L"List row 3"));

		SendDlgItemMessage(hDlg, IDC_LIST1, LB_SETCURSEL, 1, 0);
	}
	return TRUE;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
			break;

		case IDC_BUTTON1:
		{
			if (!(IsDlgButtonChecked(hDlg, IDC_CHECK1) + IsDlgButtonChecked(hDlg, IDC_CHECK2)))
				MessageBox(hDlg, L"no checked added", L"asd", MB_OK);
			else
				GetDlgItemText(hDlg, IDC_EDIT1, buff, sizeof(buff));

			if (IsDlgButtonChecked(hDlg, IDC_CHECK1))
			{
				if (IsDlgButtonChecked(hDlg, IDC_RADIO1) && !(SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)buff)>-1))
				{
					c_index = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)buff);
					SendDlgItemMessage(hDlg, IDC_COMBO1, CB_SETCURSEL, c_index, 0);
					MessageBox(hDlg, L"added in combo box", L"asd", MB_OK);
				}

				if (IsDlgButtonChecked(hDlg, IDC_RADIO2) && (SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)buff)>-1))
				{
					l_index = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_FINDSTRING, 0, (LPARAM)buff);
					if (l_index > -1)
						SendDlgItemMessage(hDlg, IDC_COMBO1, CB_DELETESTRING, 0, (LPARAM)buff);
					//SendDlgItemMessage(hDlg, IDC_COMBO1, CB_SETCURSEL, c_index, 0);
					MessageBox(hDlg, L"deleted in combo box", L"asd", MB_OK);
				}

			}

			if (IsDlgButtonChecked(hDlg, IDC_CHECK2))
			{
				if (IsDlgButtonChecked(hDlg, IDC_RADIO1) && !(SendDlgItemMessage(hDlg, IDC_LIST1, LB_FINDSTRING, 0, (LPARAM)buff)>-1))
				{
					l_index = SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)buff);
					SendDlgItemMessage(hDlg, IDC_LIST1, LB_SETCURSEL, l_index, 0);
					MessageBox(hDlg, L"added in list box", L"asd", MB_OK);
				}

				if (IsDlgButtonChecked(hDlg, IDC_RADIO2) && (SendDlgItemMessage(hDlg, IDC_LIST1, LB_FINDSTRING, 0, (LPARAM)buff)>-1))
				{
					l_index = SendDlgItemMessage(hDlg, IDC_LIST1, LB_FINDSTRING, 0, (LPARAM)buff);
					if (l_index > -1)
						SendDlgItemMessage(hDlg, IDC_LIST1, LB_DELETESTRING, l_index, (LPARAM)buff);
					//SendDlgItemMessage(hDlg, IDC_LIST1, LB_SETCURSEL, l_index, 0);
					MessageBox(hDlg, L"Delete from list box", L"asd", MB_OK);
				}
			}
		}
		break;

		case IDC_BUTTON3:
		{
			cbIndex = SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETCURSEL, 0, 0);

			if (cbIndex > -1)
			{
				SendDlgItemMessage(hDlg, IDC_COMBO1, CB_GETLBTEXT, cbIndex, (LPARAM)buff);
				SetDlgItemText(hDlg, IDC_EDIT3, buff);
			}
		}
		break;

		case IDC_BUTTON4:
		{
			lbIndex = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, 0, 0);
			if (lbIndex>-1)
			{
				SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETTEXT, lbIndex, (LPARAM)buff);
				SetDlgItemText(hDlg, IDC_EDIT4, buff);
			}
		}
		break;

		case IDC_BUTTON2:
		{
			if (IsDlgButtonChecked(hDlg, IDC_RADIO1))
			{
				MessageBox(hDlg, L"IDC_RADIO1", L"asd", MB_OK);
			}

			if (IsDlgButtonChecked(hDlg, IDC_RADIO2))
			{
				MessageBox(hDlg, L"IDC_RADIO2", L"asd", MB_OK);
			}
		}
		break;

		}
		break;
	}

	return FALSE;
}
#pragma endregion

#pragma region Ecample 6
#define TIMER1 500

LRESULT CALLBACK	Example6DialogBox(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int step = 20;
	const int min_progress = 0;
	const int max_progress = 500;

	switch (message)
	{
	case WM_INITDIALOG:
		SetDlgItemInt(hDlg, IDC_EDIT3, 0, NULL);
		//InitCommonControls();
		SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETRANGE, 
			0, MAKELPARAM(min_progress, max_progress));
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, 100, 0);
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, 100, 0);
		return TRUE;

	case WM_TIMER:
	{
		int counter = GetDlgItemInt(hDlg, IDC_EDIT3, NULL, FALSE);
		counter += 5;
		SetDlgItemInt(hDlg, IDC_EDIT3, counter, TRUE);
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0);
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, step, 0);
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, max_progress, 0);
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, -500, 0);
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_STEPIT, 0, 0); akselerator
		if (step > 0) {			
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, step, 0);
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
			if (SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0) >= max_progress)
			{
				step = -20;
				SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, step, 0);
				//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, max_progress, 0);
				//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, -500, 0);
				break;
			}

		}
		else {			
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, step, 0);
			SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
			if (SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0) <= min_progress)
			{
				step = 20;
				SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, step, 0);
				//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETPOS, min_progress, 0);
				//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_DELTAPOS, 1000, 0);
				break;
			}

		}

		//if (step > 0 && (SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0) >= max_progress))
		//	{
		//		step = -20;
		//		break;
		//	}
		//else if (step < 0 && SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_GETPOS, 0, 0) <= min_progress)
		//	{
		//		step = 20;
		//		break;
		//	}

		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_SETSTEP, step, 0);
		//SendDlgItemMessage(hDlg, IDC_PROGRESS1, PBM_STEPIT, 0, 0);
	}
	break;

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		case IDC_BUTTON1:
			SetTimer(hDlg, TIMER1, 1, NULL);
			break;
		case IDC_BUTTON2:
		{
			KillTimer(hDlg, TIMER1);
		}
		break;
		case IDC_BUTTON3:
		{
			KillTimer(hDlg, TIMER1);
			SetDlgItemInt(hDlg, IDC_EDIT3, 0, NULL);
		}
		break;
		}
		break;

	case WM_MOUSEMOVE:
	{
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		SetDlgItemInt(hDlg, IDC_EDIT1, x, TRUE);
		SetDlgItemInt(hDlg, IDC_EDIT2, y, TRUE);
	}
	break;

	case WM_LBUTTONDOWN:
	{
		//if (IsDlgButtonChecked(hDlg, IDC_CHECK1))
		//	CheckDlgButton(hDlg, IDC_CHECK1, FALSE);
		//else
		//	CheckDlgButton(hDlg, IDC_CHECK1, TRUE);

		//if (wParam & MK_RBUTTON) {
		//	CheckDlgButton(hDlg, IDC_CHECK2, TRUE);
		//	CheckDlgButton(hDlg, IDC_CHECK3, FALSE);
		//	CheckDlgButton(hDlg, IDC_CHECK4, FALSE);
		//}
		//if (wParam & MK_CONTROL) {
		//	CheckDlgButton(hDlg, IDC_CHECK2, FALSE);
		//	CheckDlgButton(hDlg, IDC_CHECK3, TRUE);
		//	CheckDlgButton(hDlg, IDC_CHECK4, FALSE);
		//}
		//if (wParam & MK_SHIFT) {
		//	CheckDlgButton(hDlg, IDC_CHECK2, FALSE);
		//	CheckDlgButton(hDlg, IDC_CHECK3, FALSE);
		//	CheckDlgButton(hDlg, IDC_CHECK4, TRUE);
		//}

		CheckDlgButton(hDlg, IDC_CHECK1, !IsDlgButtonChecked(hDlg, IDC_CHECK1));
		CheckDlgButton(hDlg, IDC_CHECK2, (wParam & MK_RBUTTON));
		CheckDlgButton(hDlg, IDC_CHECK3, (wParam & MK_CONTROL));
		CheckDlgButton(hDlg, IDC_CHECK4, (wParam & MK_SHIFT));
	}
	break;
	}
	return FALSE;
}
#pragma endregion	

#pragma region Ecample 7

LRESULT CALLBACK	Example7DialogBox(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static int x = 0;
	static int y = 0;
	HDC hdc;
	POINT pp[4];
	switch (message)
	{
	case WM_INITDIALOG:
		return TRUE;

	case WM_CTLCOLORDLG:
		return (LONG)CreateSolidBrush(RGB(255,255,255));

	case WM_COMMAND:
		switch (wParam)
		{
		case IDOK:
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		break;

	case WM_LBUTTONDOWN:
		//MessageBox(hWnd, L"WM_LBUTTONDOWN", L"MSG", MB_OK);
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		hdc = BeginPaint(hDlg, &ps);
		// TODO: Add any drawing code that uses hdc here...

		SetBkColor(hdc, RGB(255, 255, 255));

		//DrawText
		TCHAR str[MAX_LOADSTRING];
		RECT rt;
		GetClientRect(hDlg, &rt);
		LoadString(hInst, IDS_STRING104, str, MAX_LOADSTRING);
		SetBkColor(hdc, RGB(120, 220, 180));
		int height = DrawText(hdc, str, wcslen(str), &rt, DT_TOP);
		//New Line
		OffsetRect(&rt, 0, height);
		LoadString(hInst, IDS_STRING105, str, MAX_LOADSTRING);
		DrawText(hdc, str, wcslen(str), &rt, DT_CENTER);
		TCHAR bla[] = L" I can paint ";
		SetTextColor(hdc, RGB(0x5F, 0x3F, 0x11));
		SetBkColor(hdc, RGB(0x48, 0xAB, 0xFF));  // yellow RGB(255,255,0)
		TextOut(hdc, 150, 100, bla, wcslen(bla));

		//Painting 2 rectangles	
		HBRUSH hBrush1 = CreateSolidBrush(RGB(0xFF, 0xFF, 0x00));
		SelectObject(hdc, hBrush1);
		Rectangle(hdc, 134, 456, 324, 190);
		HBRUSH hBrush2 = CreatePatternBrush(LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP1));
		SelectObject(hdc, hBrush2);
		Rectangle(hdc, 634, 456, 340, 190);

		//Fill ellipse with user witmap image
		HBITMAP hBmp = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP2);
		HBRUSH hBrush4 = CreatePatternBrush(hBmp);
		SelectObject(hdc, hBrush4);
		Ellipse(hdc, 134, 456, 324, 190);
		HBRUSH hBrush3 = CreateHatchBrush(HS_CROSS, RGB(0x88, 0x88, 0x20));
		SelectObject(hdc, hBrush3);
		Ellipse(hdc, 590, 410, 370, 230);
		
		//Poligon
		HBITMAP hBmp1 = LoadBitmap(hInst, (LPCWSTR)IDB_BITMAP3);
		HBRUSH hBrush14 = CreatePatternBrush(hBmp1);
		SelectObject(hdc, hBrush14);
		pp[0].x = 760; pp[0].y = 500;
		pp[1].x = 925; pp[1].y = 380;
		pp[2].x = 990; pp[2].y = 500;
		pp[3].x = 890; pp[3].y = 600;
		Polygon(hdc, pp, 4);


		hBrush1 = CreateSolidBrush(RGB(50, 50, 50));
		SelectObject(hdc, hBrush1);
		Ellipse(hdc, 0, 0, 80, 100);
		hBrush1 = CreateSolidBrush(RGB(255, 255, 255));
		SelectObject(hdc, hBrush1);
		pp[0].x = 20; pp[0].y = 20;
		pp[1].x = 10; pp[1].y = 30;
		pp[2].x = 30; pp[2].y = 30;
		Polygon(hdc, pp, 3);
		pp[0].x = 60; pp[0].y = 20;
		pp[1].x = 50; pp[1].y = 30;
		pp[2].x = 70; pp[2].y = 30;
		Polygon(hdc, pp, 3);
		Rectangle(hdc, 30, 60, 50, 70);

		EndPaint(hDlg, &ps);
	}
	break;

	case WM_MOUSEMOVE:
		// LEFT button -> curve following user	
		if (wParam == MK_LBUTTON)
		{
			hdc = GetDC(hDlg);
			COLORREF color = RGB(0x10, 0x10, 0xF0);
			HPEN hPen = CreatePen(PS_DASHDOT, 1, color);
			SelectObject(hdc, hPen);
			MoveToEx(hdc, x, y, NULL); // move graphical curcor to plase of pressin LB
			x = LOWORD(lParam);
			y = HIWORD(lParam);
			LineTo(hdc, x, y);
			//	ReleaseDC(hWnd, hdc);
		}
		break;

	}
	return FALSE;
}
#pragma endregion	