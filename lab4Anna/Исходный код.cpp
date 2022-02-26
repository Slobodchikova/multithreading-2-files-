#include <Windows.h>
#include <tchar.h>
#include <fstream>
#include <CommCtrl.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);

TCHAR WinName[] = _T("MainFrame");

int WINAPI _tWinMain(HINSTANCE This,		 // ���������� �������� ���������� 
HINSTANCE Prev, 	// � ����������� �������� ������ 0 
LPTSTR cmd, 		// ��������� ������ 
int mode) 		// ����� ����������� ����
{ 
HWND hWnd;	// ���������� �������� ���� ��������� 
MSG msg; 		// ��������� ��� �������� ��������� 
WNDCLASS wc; 	// ����� ����
// ����������� ������ ���� 
wc.hInstance = This; 
wc.lpszClassName = WinName; 				// ��� ������ ���� 
wc.lpfnWndProc = WndProc; 					// ������� ���� 
wc.style = CS_HREDRAW | CS_VREDRAW; 			// ����� ���� 
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// ����������� ������ 
wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// ����������� ������ 
wc.lpszMenuName = NULL; 					// ��� ���� 
wc.cbClsExtra = 0; 						// ��� �������������� ������ ������ 
wc.cbWndExtra = 0; 						// ��� �������������� ������ ���� 
wc.hbrBackground = (HBRUSH) (COLOR_WINDOW+1); 	// ���������� ���� ����� ������ 


// ����������� ������ ����
if (!RegisterClass(&wc)) return 0; 	

// �������� ���� 
hWnd = CreateWindow(WinName,			// ��� ������ ���� 
_T("�������� � ����"), 		// ��������� ���� 
WS_OVERLAPPEDWINDOW, 		// ����� ���� 
CW_USEDEFAULT,				// x 
CW_USEDEFAULT, 				// y	 ������� ���� 
CW_USEDEFAULT, 				// width 
CW_USEDEFAULT, 				// Height 
HWND_DESKTOP, 				// ���������� ������������� ���� 
NULL, 						// ��� ���� 
This, 						// ���������� ���������� 
NULL); 					// �������������� ���������� ��� 

ShowWindow(hWnd, mode); 				// �������� ����


// ���� ��������� ��������� 
while(GetMessage(&msg, NULL, 0, 0)) 
{ 
TranslateMessage(&msg); 		// ������� ���������� ����� ������� ������� 
DispatchMessage(&msg); 		// �������� ��������� ������� WndProc() 
} 
return 0;
}

TCHAR *pStr; 

//������� ��� �������
HWND hProgBar, hProgBar2;
DWORD WINAPI ProgressBar(LPVOID param) 
{
            SendMessage((HWND)param, PBM_SETRANGE, 0, (LPARAM)MAKELONG(0,1000));
            SendMessage((HWND)param, PBM_SETSTEP, (WPARAM)1, 0);
            UpdateWindow(hProgBar);
			SendMessage(hProgBar2, PBM_SETRANGE, 0, (LPARAM)MAKELONG(0,1000));
            SendMessage(hProgBar2, PBM_SETSTEP, (WPARAM)1, 0);
            UpdateWindow(hProgBar2);
	return 0;
}
DWORD WINAPI Text1(LPVOID param) 
{
	HANDLE file;
	LPCTSTR str = _T("text1.txt");
	LPCTSTR error = _T("Could not open file");
	DWORD bite, buf;
	int m, k,s;

	file = CreateFile(str, GENERIC_WRITE, 0, NULL, /*OPEN_EXISTING*/ CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	if (file == INVALID_HANDLE_VALUE) 
	{ 
		MessageBox((HWND)param,error,NULL, MB_OK);
		return 0;
	}
	for(int i=1999; i>=0; i=i-2) 
	{
		m=i;
		s=1000;
		while (m>0)
		{
			if (m/s >0) 
			{
				// �������� ����������� 0, ��� ������ ������, 0 � ������ ���������, ��� ��� ���������????
				k= m/s;
				m= m % s;
				switch(k)
				{
					case 0: buf = 48;
						break;
					case 1: buf = 49;
						break;
					case 2: buf = 50;
						break;
					case 3: buf = 51;
						break;
					case 4: buf = 52;
						break;
					case 5: buf = 53;
						break;
					case 6: buf = 54;
						break;
					case 7: buf = 55;
						break;
					case 8: buf = 56;
						break;
					case 9: buf = 57;
						break;
				}
				WriteFile(file,&buf,sizeof(buf)/4,&bite,NULL );
			}
			else s = s/10;
		}
		buf = 32;
		WriteFile(file,&buf,sizeof(buf)/4,&bite,NULL );
		
		Sleep(100);
		SendMessage(hProgBar, PBM_STEPIT, 0, 0);
	}
	

	return 0;
}
DWORD WINAPI Text2(LPVOID param) 
{
	HANDLE file;
	LPCTSTR str = _T("text2.txt");
	LPCTSTR error = _T("Could not open file");
	DWORD bite, buf;
	int m, k,s;

	file = CreateFile(str, GENERIC_WRITE, 0, NULL, /*OPEN_EXISTING*/ CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL );
	if (file == INVALID_HANDLE_VALUE) 
	{ 
		MessageBox((HWND)param,error,NULL, MB_OK);
		return 0;
	}
	for(int i=2; i<=2000; i=i+2) 
	{
		m=i;
		s=1000;
		while (m>0)
		{
			if (m/s >0) 
			{
				// �������� ����������� 0, ��� ������ ������, 0 � ������ ���������, ��� ��� ���������????
				k= m/s;
				m= m % s;
				switch(k)
				{
					case 0: buf = 48;
						break;
					case 1: buf = 49;
						break;
					case 2: buf = 50;
						break;
					case 3: buf = 51;
						break;
					case 4: buf = 52;
						break;
					case 5: buf = 53;
						break;
					case 6: buf = 54;
						break;
					case 7: buf = 55;
						break;
					case 8: buf = 56;
						break;
					case 9: buf = 57;
						break;
				}
				WriteFile(file,&buf,sizeof(buf)/4,&bite,NULL );
			}
			else s = s/10;
		}
		buf = 32;
		WriteFile(file,&buf,sizeof(buf)/4,&bite,NULL );
		Sleep(300);
		SendMessage(hProgBar2, PBM_STEPIT, 0, 0);
	}
	return 0;
}

// ������� ������� ���������� ������������ ��������
// � �������� ��������� �� ������� ��� ������� ����������

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{ 

	PAINTSTRUCT ps;  
	
switch(message)		 // ���������� ���������
{ 
	case WM_CREATE:     
		hProgBar = CreateWindowEx(0, PROGRESS_CLASS, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
                  150, 150, 900, 30,hWnd,(HMENU)1, NULL, NULL);
		hProgBar2 = CreateWindowEx(0, PROGRESS_CLASS, NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
                  150, 200, 900, 30,hWnd,(HMENU)1, NULL, NULL);
		 CreateThread(NULL, 0, Text1, hWnd, 0, NULL);   
		 CreateThread(NULL, 0, Text2, hWnd, 0, NULL);  
         CreateThread(NULL, 0, ProgressBar,hProgBar,0, NULL); 
		 break; 
	case WM_LBUTTONDOWN:
           /* SendMessage(hProgBar, PBM_STEPIT, 0, 0);*/
         break;
	/*case WM_PAINT:      
		hdc = BeginPaint(hWnd, &ps);      
		TextOut(hdc, 0, 0, pStr, _tcslen(pStr));      
		EndPaint(hWnd, &ps);      
		break; */
	case WM_DESTROY : 
PostQuitMessage(0); 
break; 			// ���������� ��������� 
default : 			// ��������� ��������� �� ��������� 
return DefWindowProc(hWnd, message, wParam, lParam); 
} 
return 0;
}