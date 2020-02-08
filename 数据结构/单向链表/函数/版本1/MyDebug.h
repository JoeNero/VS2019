#ifndef __MYDEBUG_H
#define __MYDEBUG_H

#include <iostream>
#include <tchar.h>
#include <cstdarg>
#include <atltrace.h>

#ifdef _DEBUG
#define new new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif

void EnableMemLeakCheck();

//Êä³ö´°¿Ú´òÓ¡
#ifdef __Trace
void TracePrint(TCHAR* format, ...);

void TracePrint(const TCHAR* format, ...);

void TracePrint(char* format, ...);

void TracePrint(const char* format, ...);
#endif
#endif 
