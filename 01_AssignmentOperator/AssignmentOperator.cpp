#include<iostream>
#include<cstring>

class CMyString
{
private:
	char* m_pData;
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();
	CMyString& operator= (const CMyString& str);
	void Print() { printf("%s", m_pData); }
};

CMyString::CMyString(char* pData) :m_pData {nullptr}
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str) :m_pData{nullptr}
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

//返回值是该类型的引用， 传入参数为常量引用
CMyString& CMyString::operator= (const CMyString& str)
{
	if (this == &str) return *this; // 本对象给自己复制，返回本对象

	delete[] m_pData; //释放已有内存，否则内存泄漏
	m_pData = nullptr;

	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);

	return *this;
}

int main()
{
	printf("Test1 begins:\n");

	char text[] = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
	return 0;
}