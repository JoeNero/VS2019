#include "myDebug.h"

//�����ӡ��������ڿ��ַ�
void TracePrint(TCHAR* format, ...)
{
	TCHAR buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	wvsprintf(buffer, format, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
}

//�����ӡ��������ڿ��ַ�
void TracePrint(const TCHAR* format, ...)
{
	TCHAR buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	wvsprintf(buffer, format, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
}

//�����ӡ���������
void TracePrint(const char* format, ...)
{
	char buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);
	OutputDebugStringA(buffer);
}

//�����ӡ���������
void TracePrint(char* format, ...)
{
	char buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);
	OutputDebugStringA(buffer);
}
