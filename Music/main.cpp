/*
������	:	XTT
����	:	mciSendString��������
			������û��������������Ƶ���棬ɾ���Ϳ���(��Mp3tag)

ʱ��	:	2020/01/31
*/

#include <graphics.h>
#include <conio.h>

#pragma comment(lib,"Winmm.lib")		//�����������

void main()
{
	initgraph(640, 480);

	// ������
	mciSendString(_T("open 1.mp3 alias mymusic"), NULL, 0, NULL);

	outtextxy(0, 0, _T("���������ʼ����"));
	_getch();

	// ��������
	mciSendString(_T("play mymusic"), NULL, 0, NULL);

	outtextxy(0, 0, _T("�������ֹͣ����"));
	_getch();

	// ֹͣ���Ų��ر�����
	mciSendString(_T("stop mymusic"), NULL, 0, NULL);
	mciSendString(_T("close mymusic"), NULL, 0, NULL);

	outtextxy(0, 0,_T("��������˳�����"));
	_getch();
	closegraph();
}
