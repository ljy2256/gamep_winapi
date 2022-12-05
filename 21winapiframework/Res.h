#pragma once
class Res
{
private:
	wstring m_strKey; // 리소스 키
	wstring m_strRelativePath; // 리소스 상대경로
public:
	Res();
	~Res();
public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = m_strRelativePath; }
	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }
};

