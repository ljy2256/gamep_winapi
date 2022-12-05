#pragma once
#include "BWindow.h"
// �̱��� 2��° ���
class Core :public BWindow
{
public:
	SINGLE(Core);
	//static Core* GetInst()
	//{
	//	static Core core;
	//	return &core;
	//}
private:
	Core();
	~Core();
private:
	POINT	m_ptResolution; // ���� ������ �ػ�
	HDC		m_hDC;			// ���� �����쿡 Draw�� DC
	HDC		m_memDC;		// �纻�� DC
	HBITMAP	m_hBit;			// �纻�� ��Ʈ��
	HBRUSH  m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN    m_arrPen[(UINT)PEN_TYPE::END];

public:
	int		Init(HWND _hWnd, POINT _ptResolution);
	void    Progress();
private:
	void	Update();
	void	Render();
	void    CreateBrushPen();
public:
	const HWND& GetWndHandle() { return m_hWnd; }
	const HINSTANCE& GetInstanceHandle() { return m_hInstance; }
	POINT& GetResolution() { return m_ptResolution; }
	const HDC& GetMainDC() { return m_hDC; }

	HBRUSH GetBrush(BRUSH_TYPE _eType)
	{
		return m_arrBrush[(UINT)_eType];
	}
	HPEN GetPen(PEN_TYPE _eType)
	{
		return m_arrPen[(UINT)_eType];
	}
};
