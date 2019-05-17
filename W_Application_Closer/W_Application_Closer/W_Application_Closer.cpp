// W_Application_Closer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <windows.h>
#include <stdio.h>
#include <iostream>

BOOL CALLBACK EnumWindowsProc(HWND hWnd, long lParam) {
	//char buff[255];

	//TCHAR actually stands for "Type Char". Able to convert itself to either the regular old ASCII charset (char), or into unicode charset (wchar) 
	//This will be used for a wchar (unicode char)
	TCHAR wndTitle[300];

	//With the window @hWnd, if it's a visible process, we want to print it out.
	if (IsWindowVisible(hWnd)) {
		GetWindowText(hWnd, (LPWSTR)wndTitle, 254);

		//cout does NOT work as desired with unicode set, so we use wcout to work properly with unicode strings (wchar strings).
		std::wcout << wndTitle << std::endl;

	}

	return TRUE;
}

int main() {
	EnumWindows(EnumWindowsProc, 0);
	return 0;
}
