#pragma once
class Res
{
private:
	wstring m_strKey; // ���ҽ� Ű
	wstring m_strRelativePath; // ���ҽ� �����
public:
	Res();
	~Res();
public:
	void SetKey(const wstring& _strKey) { m_strKey = _strKey; }
	void SetRelativePath(const wstring& _strPath) { m_strRelativePath = m_strRelativePath; }
	const wstring& GetKey() { return m_strKey; }
	const wstring& GetRelativePath() { return m_strRelativePath; }
};

