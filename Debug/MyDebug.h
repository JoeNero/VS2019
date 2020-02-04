#ifndef __MYDEBUG_H
#define __MYDEBUG_H

#include <iostream>
#include <tchar.h>
#include <cstdarg>
#include <atltrace.h>

void TracePrint(TCHAR* format, ...);

void TracePrint(const TCHAR* format, ...);

void TracePrint(char* format, ...);

void TracePrint(const char* format, ...);

#endif 
