#include "myDebug.h"

//输出打印到输出窗口宽字符
void TracePrint(TCHAR* format, ...)
{
	TCHAR buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	wvsprintf(buffer, format, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
}

//输出打印到输出窗口宽字符
void TracePrint(const TCHAR* format, ...)
{
	TCHAR buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	wvsprintf(buffer, format, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
}

//输出打印到输出窗口
void TracePrint(const char* format, ...)
{
	char buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);
	OutputDebugStringA(buffer);
}

//输出打印到输出窗口
void TracePrint(char* format, ...)
{
	char buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);
	OutputDebugStringA(buffer);
}
