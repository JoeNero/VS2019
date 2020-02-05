/*
文件名 	:   m_str.h
创建者	:	XTT
功能	:	自写字符操作


时间	:	2020/01/10
*/ 
#ifndef __MY_STR_H
#define __MY_STR_H

#include <string>

char* m_strcpy(char*,const char*);									//字符copy
char* m_strcpy_len(char* dest, const char* src,size_t len);	//字符copy加长度
void* m_memcpy(void* ,const void* , size_t n);						//内存拷贝
char* m_strcat(char* dest, const char* src);						//字符串拼接
size_t m_strlen(const char* str);									//字符串长度
char* m_reverse(char* str);											//字符串翻转					
template<typename T> void swap(T&, T&);								//交换
char* m_strstr(char* str, char* sub);								//查找子串
char* m_strchr(char* str, char ch);									//查找字符
unsigned int m_strchr_cout(char* str, char ch);						//查找字符出现的次数

#endif 

