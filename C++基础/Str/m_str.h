/*
�ļ��� 	:   m_str.h
������	:	XTT
����	:	��д�ַ�����


ʱ��	:	2020/01/10
*/ 
#ifndef __MY_STR_H
#define __MY_STR_H

#include <string>

char* m_strcpy(char*,const char*);									//�ַ�copy
char* m_strcpy_len(char* dest, const char* src,size_t len);	//�ַ�copy�ӳ���
void* m_memcpy(void* ,const void* , size_t n);						//�ڴ濽��
char* m_strcat(char* dest, const char* src);						//�ַ���ƴ��
size_t m_strlen(const char* str);									//�ַ�������
char* m_reverse(char* str);											//�ַ�����ת					
template<typename T> void swap(T&, T&);								//����
char* m_strstr(char* str, char* sub);								//�����Ӵ�
char* m_strchr(char* str, char ch);									//�����ַ�
unsigned int m_strchr_cout(char* str, char ch);						//�����ַ����ֵĴ���

#endif 

