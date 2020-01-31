/*
创建者	:	XTT
功能	:	mciSendString播放声音
			播放弱没有声音，请检测音频封面，删除就可以(用Mp3tag)

时间	:	2020/01/31
*/

#include <graphics.h>
#include <conio.h>

#pragma comment(lib,"Winmm.lib")		//这个决不能少

void main()
{
	initgraph(640, 480);

	// 打开音乐
	mciSendString(_T("open 1.mp3 alias mymusic"), NULL, 0, NULL);

	outtextxy(0, 0, _T("按任意键开始播放"));
	_getch();

	// 播放音乐
	mciSendString(_T("play mymusic"), NULL, 0, NULL);

	outtextxy(0, 0, _T("按任意键停止播放"));
	_getch();

	// 停止播放并关闭音乐
	mciSendString(_T("stop mymusic"), NULL, 0, NULL);
	mciSendString(_T("close mymusic"), NULL, 0, NULL);

	outtextxy(0, 0,_T("按任意键退出程序"));
	_getch();
	closegraph();
}
