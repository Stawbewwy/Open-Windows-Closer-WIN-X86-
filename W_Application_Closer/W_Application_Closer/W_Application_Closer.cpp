#include <windows.h>
#include <stdio.h>
#include <iostream>

BOOL CALLBACK EnumWindowsProc(HWND hWnd, long lParam) {

	//TCHAR actually stands for "Type Char". Able to convert itself to either the regular old ASCII charset (char), or into unicode charset (wchar) 
	//This will be used for a wchar (unicode char)
	TCHAR windowTitle[300];

	//With the window @hWnd, if it's a visible process, we want to print it out.
	if (IsWindowVisible(hWnd)) {
		GetWindowText(hWnd, (LPWSTR)windowTitle, 254);

		//cout does NOT work as desired with unicode set, so we use wcout to work properly with unicode strings (wchar strings).
		std::wcout << windowTitle << std::endl;

	}

	return TRUE;
}

int main() {
	EnumWindows(EnumWindowsProc, 0);
	return 0;
}
