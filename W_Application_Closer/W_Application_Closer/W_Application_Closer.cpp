// W_Application_Closer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <iostream>

BOOL CALLBACK EnumWindowsProc(HWND hWnd, long lParam) {
	//char buff[255];
	TCHAR wndTitle[300];

	if (IsWindowVisible(hWnd)) {
		GetWindowText(hWnd, (LPWSTR)wndTitle, 254);

		//MessageBox(NULL, wndTitle,NULL, MB_OK);
		std::wcout << wndTitle << std::endl;
		//printf("%s\n", wndTitle);
		//system("pause");
	}

	return TRUE;
}

int main() {
	EnumWindows(EnumWindowsProc, 0);
	return 0;
}
