/*Author: Shadi Othman*/
/*Major credit to the following resources: https://social.msdn.microsoft.com/Forums/vstudio/en-US/cf8e95f4-47e4-4c84-911c-aecf2c9d20e4/problem-with-printing-lptstr?forum=vclanguage */

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <aclapi.h>

BOOL CALLBACK EnumWindowsProc(HWND hWnd, long lParam) {

	//TCHAR actually stands for "Type Char". Able to convert itself to either the regular old ASCII charset (char), or into unicode charset (wchar) 
	//This will be used for a wchar (unicode char)
	TCHAR windowTitle[300];

	//With the window @hWnd, if it's a visible process, we want to print it out.
	if (IsWindowVisible(hWnd)) {
		//get the text of the open window!
		GetWindowText(hWnd, (LPWSTR)windowTitle, 254);

		
		if (wcslen(windowTitle)) {

			std::wcout << windowTitle << std::endl;
			std::cout << std::endl << "Would you like to terminate this process? y/n: ";

			char ans;
			std::cin >> ans;

			if (ans == 'y') {
				//need to retrieve the PID of the process
				DWORD current_win_pid;
				GetWindowThreadProcessId(hWnd, &current_win_pid);

				//Create a new handle to the target process
				HANDLE current_process = OpenProcess(PROCESS_TERMINATE, FALSE, current_win_pid);

				if( TerminateProcess(current_process, 0) == 0 ){
					std::cout << "Sucessfully Terminated!";
				}

				else {
					std::cout << "Sorry, I couldn't terminate that for you :(";
				}
				
			}

			std::cout << std::endl << std::endl;
		}
	}

	return TRUE;
}

int main() {
	EnumWindows(EnumWindowsProc, 0);
	return 0;
}
