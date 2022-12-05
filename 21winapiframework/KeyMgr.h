#pragma once

struct tKeyInfo
{
	// enum class KEY => 
	KEY_STATE	eState; // Ű ���°�
	bool		bPrevCheck; // ���������� ���ȴ��� ����
};

class KeyMgr
{
private:
	vector<tKeyInfo> m_vecKey;
public:
	SINGLE(KeyMgr);
private:
	KeyMgr();
	~KeyMgr();
public:
	void	Init();
	void	Update();
	KEY_STATE	GetKey(KEY _eKey)
	{
		return m_vecKey[(int)_eKey].eState;
	}

};

