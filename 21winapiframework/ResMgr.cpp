#include "pch.h"
#include "ResMgr.h"
#include "PathMgr.h"
#include "Image.h"
ResMgr::ResMgr()
{
}

ResMgr::~ResMgr()
{
	map<wstring, Image*>::iterator iter;
	for (iter = m_mapImg.begin(); iter != m_mapImg.end(); iter++)
	{
		delete iter->second;
	}
}

Image* ResMgr::ImgLoad(const wstring& _strKey, const wstring& _strRelativePath)
{
	Image* pImg = ImgFind(_strKey);
	if (nullptr != pImg)
	{
		return pImg;
	}
	wstring strFilePath = PathMgr::GetInst()->GetResPath();
	strFilePath += _strRelativePath;
	pImg = new Image;
	pImg->Load(strFilePath);
	pImg->SetKey(_strKey);
	pImg->SetRelativePath(_strRelativePath);
	m_mapImg.insert({_strKey, pImg});
	return pImg;
}

Image* ResMgr::ImgFind(const wstring& _strKey)
{
	map<wstring, Image*>::iterator iter = m_mapImg.find(_strKey);
	if (iter == m_mapImg.end())
	{
		return nullptr;
	}
	return iter->second;
}
