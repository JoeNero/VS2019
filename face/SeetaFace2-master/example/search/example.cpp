#include <stdio.h>
#include <seeta/FaceLandmarker.h>
#include <seeta/FaceRecognizer.h>
#include <seeta/Struct_cv.h>
#include <seeta/Struct.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <seeta/QualityAssessor.h>
#include <seeta/FaceDetector.h>
#include <seeta/FaceDatabase.h>
#include <iostream>

using namespace std;

int main()
{
	seeta::FaceDetector FD(seeta::ModelSetting("./model/fd_2_00.dat"));
	seeta::FaceDetector FD2(seeta::ModelSetting("./model/fd_2_00.dat"));
	seeta::FaceLandmarker FL(seeta::ModelSetting("./model/pd_2_00_pts5.dat"));
	seeta::FaceLandmarker FL2(seeta::ModelSetting("./model/pd_2_00_pts5.dat"));
	seeta::FaceDatabase FDB(seeta::ModelSetting("./model/fr_2_10.dat"));
	seeta::FaceRecognizer FR(seeta::ModelSetting("./model/fr_2_10.dat"));
	seeta::cv::ImageData image1 = cv::imread("C:\\Users\\Administrator\\Desktop\\pic\\1.jpg");
	seeta::cv::ImageData image2 = cv::imread("C:\\Users\\Administrator\\Desktop\\pic\\1.jpg");
	SeetaFaceInfoArray faces1 = FD.detect(image1);
	SeetaFaceInfoArray faces2 = FD2.detect(image2);

	std::vector<SeetaPointF> points1 = FL.mark(image1, faces1.data[0].pos);
	std::vector<SeetaPointF> points2 = FL2.mark(image2, faces2.data[0].pos);

	/*测试两张图的5点是否可以打印*/
	for (int i = 0; i < 5; i++) 
	{
		printf("图1：点%d---x:%f---y:%f\n", i, points1[i].x, points1[i].y);
	}
	for (int i = 0; i < 5; i++) 
	{
		printf("图2：点%d---x:%f---y:%f\n", i, points2[i].x, points2[i].y);
	}
	for (int i = 0 ; i < 5; i++)
	{
		float sss = FDB.Compare(image1, &points1[i], image2, &points2[i]);
		cout << "sss= " << sss << endl;
	}

	return 0;
}
