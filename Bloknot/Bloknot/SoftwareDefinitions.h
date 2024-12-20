#pragma once

#define OnMenuAction1	1
#define OnMenuAction2	2

#define OnMenuHelp		3
#define OnExitSoftware	4
#define OnButtonField	5
#define OnReadField		6
#define OnSaveFile		7
#define OnLoadFile		8

#define DlgIndexNumber	200

#define TextBufferSize	250

char Buffer[TextBufferSize];
int CharsRead;
//unsigned num;

//HWND hStaticControl;
HWND hEditControl;
HWND hNumberControl;

char filename[260];
OPENFILENAMEA ofn;

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);

void MainWndAddMenus(HWND hWnd);
void MainWndAddWidgets(HWND hWnd);
void SetOpenFileParams(HWND hWnd);
void SaveData(LPCSTR path);
void LoadData(LPCSTR path);
