#pragma once
class PathMgr
{
public:
	SINGLE(PathMgr);
private:
	wchar_t m_szResPath[255];

private:
	PathMgr();
	~PathMgr();
public:
	void Init();
	const wchar_t* GetResPath() { return m_szResPath; }
};

