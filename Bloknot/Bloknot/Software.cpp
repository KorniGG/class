#include <Windows.h>
#include "SoftwareDefinitions.h"
#include <string>



int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	WNDCLASS SoftwareMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_HAND), hInst, LoadIcon(NULL, IDI_QUESTION),
		L"MainWndClass", SoftwareMainProcedure);

	if (!RegisterClassW(&SoftwareMainClass)) { return -1; }
	MSG SoftwareMainMessage = { 0 };

	CreateWindow(L"MainWndClass", L"Ferst c++ window", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 700, 500, NULL, NULL, NULL, NULL);
	while (GetMessage(&SoftwareMainMessage, NULL, NULL, NULL)) {
		TranslateMessage(&SoftwareMainMessage);
		DispatchMessage(&SoftwareMainMessage);
	}
	return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASS NWC = { 0 };

	NWC.hCursor = Cursor;
	NWC.hIcon = Icon;
	NWC.hInstance = hInst;
	NWC.lpszClassName = Name;
	NWC.hbrBackground = BGColor;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK SoftwareMainProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {
		case OnMenuHelp:
			MessageBoxA(hWnd, "I also need HELP!", "HEEELP", MB_OK);
			break;
		case OnButtonField:
			SetWindowTextA(hEditControl, "");
			break;
		case OnReadField:
			CharsRead = GetWindowTextA(hEditControl, Buffer, TextBufferSize);
			SetWindowTextA(hEditControl, Buffer);
			//SetWindowTextA(hEditControl, ("size: " + std::to_string(CharsRead)).c_str());
			//num = GetDlgItemInt(hWnd, DlgIndexNumber, NULL, false);
			SetWindowTextA(hNumberControl, std::to_string(CharsRead).c_str());
			break;
		case OnSaveFile:
			if (GetSaveFileNameA(&ofn)) { SaveData(filename); }
			break;
		case OnLoadFile:
			if (GetOpenFileNameA(&ofn)) { LoadData(filename); }
			break;
		case OnExitSoftware:
			PostQuitMessage(0);
			break;

		default: break;
		}
		break;
	case WM_CREATE:
		MainWndAddMenus(hWnd);
		MainWndAddWidgets(hWnd);
		SetOpenFileParams(hWnd);

		break;
	case WM_SIZE:
	{
		int width = LOWORD(lp);  // Новая ширина окна
		int height = HIWORD(lp); // Новая высота окна

		// Обновляем размеры элементов
		MoveWindow(hEditControl, 5, 40, width - 10, height - 90, TRUE);
		//MoveWindow(hStaticControl, (width - 100) / 2, 5, 100, 30, TRUE);

		// Перемещаем hNumberControl к нижнему краю окна
		MoveWindow(hNumberControl, 135, height - 50, 120, 30, TRUE);

		// Перемещаем кнопку Read слева от hNumberControl
		MoveWindow(GetDlgItem(hWnd, OnReadField), 5, height - 50, 120, 30, TRUE);
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default: return DefWindowProc(hWnd, msg, wp, lp);
	}
}


void MainWndAddMenus(HWND hWnd) {
	HMENU RootMenu = CreateMenu();
	HMENU SubMenu = CreateMenu();

	
	AppendMenu(SubMenu, MF_STRING, OnButtonField, L"Clear");
	AppendMenu(SubMenu, MFT_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenu, MF_STRING, OnSaveFile, L"Save");
	AppendMenu(SubMenu, MF_STRING, OnLoadFile, L"Load");
	AppendMenu(SubMenu, MFT_SEPARATOR, NULL, NULL);
	AppendMenu(SubMenu, MF_STRING, OnExitSoftware, L"Exit");

	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)SubMenu, L"File");
	AppendMenu(RootMenu, MF_STRING, OnMenuHelp, L"Help");

	SetMenu(hWnd, RootMenu);
}

void MainWndAddWidgets(HWND hWnd){

	//hStaticControl = CreateWindowA("Static", "STATUS: c++ app", WS_VISIBLE | WS_CHILD | ES_CENTER, 200, 5, 100, 30, hWnd, NULL, NULL, NULL);
	hEditControl = CreateWindowA("edit", "This is EDIT control", WS_VISIBLE | WS_CHILD | ES_MULTILINE | WS_VSCROLL, 5, 40, 470, 120, hWnd, NULL, NULL, NULL);
	hNumberControl = CreateWindowA("edit", "0", WS_VISIBLE | WS_CHILD | ES_CENTER | ES_NUMBER, 5, 170, 120, 30, hWnd, (HMENU)DlgIndexNumber, NULL, NULL);

	CreateWindowA("button", "Clear!", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 5, 120, 30, hWnd, (HMENU)OnButtonField, NULL, NULL);
	CreateWindowA("button", "Read", WS_VISIBLE | WS_CHILD | ES_CENTER, 130, 5, 50, 30, hWnd, (HMENU)OnReadField, NULL, NULL);

}

void SaveData(LPCSTR path) {
	HANDLE FileToSave = CreateFileA(
		path,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	int saveLenth = GetWindowTextLengthA(hEditControl) + 1;
	char* data = new char[saveLenth];

	saveLenth = GetWindowTextA(hEditControl, data, saveLenth);

	DWORD bytesIterated;
	WriteFile(FileToSave, data, saveLenth, &bytesIterated, NULL);

	CloseHandle(FileToSave);
	delete[] data;

}

void LoadData(LPCSTR path) {
	HANDLE FileToLoad = CreateFileA(
		path,
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	DWORD bytesIterated;
	ReadFile(FileToLoad, Buffer, TextBufferSize, &bytesIterated, NULL);

	SetWindowTextA(hEditControl, Buffer);

	CloseHandle(FileToLoad);

}

void SetOpenFileParams(HWND hWnd) {
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = hWnd;
	ofn.lpstrFile = filename;
	ofn.nMaxFile = sizeof(filename);
	ofn.lpstrFilter = "*.txt";
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = "C:\\Users\\aisha\\OneDrive\\Рабочий стол\\Bloknot";
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
}