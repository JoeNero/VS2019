#include "m_str.h"
/*
功能: 	- 自写字符拷贝
		@char* dest			目标地址
		@const char* src	源地址
		@param
描述	:
示例	:	 
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
功能: 	- 自写字符拷贝
		@char* dest			目标地址
		@const char* src	源地址
		@unsigned int len   字符长度
描述	:	
示例	:
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
功能: 	- 自写内存拷贝
		@void* dest			目标地址
		@const void* src	源地址
		@unsigned int len   拷贝长度
描述	:
示例	:
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
功能: 	- 自写拼接字符串
		@void* dest			目标地址
		@const void* src	源地址
		@
描述	:
示例	:
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
功能: 	- 自写字符长度
		@const void* str		字符串
		@
		@
描述	:
示例	:
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
功能: 	- 自写字符翻转
		@char* str		字符串
		@
		@
描述	:
示例	:
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
功能: 	- 自写查找子串
		@char* str		字符串
		@char* sub		字串
		@return (返回查找子串)
描述	:
示例	:
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
功能: 	- 自写查找字符
		@char* str		字符串
		@char  ch		字符
		@return (返回查找字符以及之后的字符)(未找到会报异常)
描述	:
示例	:
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
功能: 	- 自写查找字符出现的次数
		@char* str		字符串
		@char  ch		字符
		@return 返回查找字符出现的次数
描述	:
示例	:
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
功能: 	- swap模板
		@
描述	:
示例	: swap<char>(a,b);
*/
template<typename T>
void swap(T& a, T& b)
{
	T temp;

	temp = b;
	b = a;
	a = temp;
}