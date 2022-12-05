#pragma once
class BWindow
{
public:
	BWindow();
	~BWindow();
public:
	static LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
	int					Run(HINSTANCE hInstance, LPWSTR lpCmdLine, int nCmdShow);
	ATOM                MyRegisterClass();
	void				WindowCreate();
	void				WindowShow(int nCmdShow);
	void				WindowUpdate();
	int					Messageloop();
protected:
	HWND				m_hWnd;
	HINSTANCE			m_hInstance;
};

