#include "m_str.h"
/*
����: 	- ��д�ַ�����
		@char* dest			Ŀ���ַ
		@const char* src	Դ��ַ
		@param
����	:
ʾ��	:	 
*/
char* m_strcpy(char* dest,const char* src)
{
	char* p = dest;
	if ((dest == NULL) || src == NULL)
	{
		throw "Invalid argument(s)";
	}
	while ((*dest++ = *src++)!='\0');
	dest = '\0';
	return p;
}

/*
����: 	- ��д�ַ�����
		@char* dest			Ŀ���ַ
		@const char* src	Դ��ַ
		@unsigned int len   �ַ�����
����	:	
ʾ��	:
*/
char* m_strcpy_len(char* dest,const char* src, size_t len)
{
	char* p = dest;
	if ((dest == NULL) || (src == NULL))
	{
		throw "Invalid argument(s)";
	}
	for (unsigned int i = 0; i < len; i++)
	{
		*dest++ = *src++;
	}
	*dest++ = '\0';
	return p;
}

/*
����: 	- ��д�ڴ濽��
		@void* dest			Ŀ���ַ
		@const void* src	Դ��ַ
		@unsigned int len   ��������
����	:
ʾ��	:
*/
void* m_memcpy(void* dest, const void* src,size_t count)
{
	char* pdest;
	const char* psrc;

	if (dest >((char*)src + count) || (dest < src))
	{
		pdest = (char*)dest;
		psrc = (char*)src;
		while (count--)
		{
			*pdest++ = *psrc++;
		}
	}
	else /* overlap */
	{
		pdest = (char*)dest + count - 1; /* offset of pointer is from 0 */
		psrc = (char*)src + count - 1;
		while (count--)
		{ 
			*pdest-- = *psrc--;
		}
	}
	return dest;
}

/*
����: 	- ��дƴ���ַ���
		@void* dest			Ŀ���ַ
		@const void* src	Դ��ַ
		@
����	:
ʾ��	:
*/
char* m_strcat(char* dest, const char* src)
{
	char* pdest = dest;
	if ((dest == NULL) || (src == NULL))
	{
		throw "Invalid argument(s)";
	}
	while (*pdest != '\0')pdest++;
	while (*src != '\0')*pdest++ = *src++;
	*pdest = '\0';
	return dest;
}

/*
����: 	- ��д�ַ�����
		@const void* str		�ַ���
		@
		@
����	:
ʾ��	:
*/
size_t m_strlen(const char* str)
{
	if (str == NULL)
	{
		throw "Invalid argument(s)";
	}
	size_t len = 0;
	while ((*str++) != '\0')
	{
		++len;
	}
	return len;

}

/*
����: 	- ��д�ַ���ת
		@char* str		�ַ���
		@
		@
����	:
ʾ��	:
*/
char* m_reverse(char* str)
{
	if (str == NULL)
	{
		throw "Invalid argument(s)";
	}
	const size_t length = m_strlen(str);
	for (size_t i = 0; i <= length/2; ++i)
	{
		swap<char>(str[length-1-i],str[i]);
	}
	while (*str++!='\0');
	return str;
}

/*
����: 	- ��д�����Ӵ�
		@char* str		�ַ���
		@char* sub		�ִ�
		@return (���ز����Ӵ�)
����	:
ʾ��	:
*/
char* m_strstr(char* str, char* sub)
{
	if ((str == NULL) || (sub ==NULL))
	{
		throw "Invalid agruement(s)";
	}
	char* pstr = NULL;
	char* psub = NULL;
	while(*str)
	{
		pstr=str;
		psub=sub;
		while(*pstr++==*psub++)
		{
			if(!*pstr)
				return str;
		}
		str+=1;
	}
	return NULL;
}

/*
����: 	- ��д�����ַ�
		@char* str		�ַ���
		@char  ch		�ַ�
		@return (���ز����ַ��Լ�֮����ַ�)(δ�ҵ��ᱨ�쳣)
����	:
ʾ��	:
*/
char* m_strchr(char* str, char ch)
{
	if ((str == NULL)||(ch == NULL))
	{
		throw "Invalid agruement(s)";
	}
	while (*str != '\0')
	{
		if (*str == ch)
			return str;
		str++;
	}
	return 0;
}

/*
����: 	- ��д�����ַ����ֵĴ���
		@char* str		�ַ���
		@char  ch		�ַ�
		@return ���ز����ַ����ֵĴ���
����	:
ʾ��	:
*/
unsigned int m_strchr_cout(char* str, char ch)
{
	unsigned int count = 0;
	if ((str == NULL) || (ch == NULL))
	{
		throw "Invalid agruement(s)";
	}
	while (*str != '\0')
	{
		if (*str == ch)
		{
			count++;
		}
		str++;
	}
	return count;
}
/*
����: 	- swapģ��
		@
����	:
ʾ��	: swap<char>(a,b);
*/
template<typename T>
void swap(T& a, T& b)
{
	T temp;

	temp = b;
	b = a;
	a = temp;
}