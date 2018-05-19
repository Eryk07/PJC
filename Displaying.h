#include "CHumans.h"

void ShowHumans(const int N, CHumans humans[], HDC hdc,HWND hWnd) {
	HDC hdcNowy;
	HBITMAP hbmOld;
	
	for (int i = 0; i <N ; i++) {


		hdcNowy = CreateCompatibleDC(hdc);
		hbmOld = (HBITMAP)SelectObject(hdcNowy, humans[i].bitmap);
		BITMAP bmInfo;
		//LPTSTR buff=(LPTSTR)marki[i].name;
		GetObject(humans[i].bitmap, sizeof(bmInfo), &bmInfo);
		SelectObject(hdcNowy, humans[i].bitmap);

		string str = humans[i].name;

		TextOut(hdc, (i + 1)* humans[i].x, (i + 1)* humans[i].y - 20, str.c_str(), str.length());

		hdc = GetDC(hWnd);
		BitBlt(hdc, (i + 1)* humans[i].x, (i + 1)* humans[i].y, bmInfo.bmWidth, bmInfo.bmHeight, hdcNowy, 0, 0, SRCCOPY);
	}
}