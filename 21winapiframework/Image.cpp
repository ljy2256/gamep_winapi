#include "pch.h"
#include "Image.h"
#include "Core.h"
Image::Image()
	: m_hBit(0)
	, m_hDC(0)
	, m_bitInfo{}
{
}

Image::~Image()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBit);
}

void Image::Load(const wstring& _strFilePath)
{
	m_hBit = (HBITMAP)LoadImage(nullptr, _strFilePath.c_str(), 
		IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
	assert(m_hBit);
	// 비트맵과 연결할 DC
	m_hDC = CreateCompatibleDC(Core::GetInst()->GetMainDC());
	SelectObject(m_hDC, m_hBit);
	//BITMAP tInfo = {};
	GetObject(m_hBit, sizeof(BITMAP), &m_bitInfo);
	//tInfo.bmWidth;
	//tInfo.bmHeight;
}
