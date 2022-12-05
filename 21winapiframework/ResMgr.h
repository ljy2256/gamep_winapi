#pragma once
class Image;
class ResMgr
{
private:
	map<wstring, Image*> m_mapImg;

public:
	SINGLE(ResMgr);
private:
	ResMgr();
	~ResMgr();
public:
	Image* ImgLoad(const wstring& _strKey, const wstring& _strRelativePath);
	Image* ImgFind(const wstring& _strKey);
};

