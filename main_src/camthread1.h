#ifndef CAMTHREAD1_H
#define CAMTHREAD1_H
#include <QMessageBox>
#include <QThread>
#include<thread>
#include <QImage>
#include <iostream>
#include<fstream>
#include<string>
#include<read_para.h>

#include <myFunction.h>
#include <KalmanTracker.h>
#include<ThingInterface.h>
#include "channel.h"
#include <opencv2/objdetect/objdetect.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;




class CamThread1 : public QThread
{
    Q_OBJECT
public:
    CamThread1();
    ~CamThread1();

    QImage qtImage;

    int CAMERA_WIDTH;
    int CAMERA_HEIGHT;
    int CAMERA_NUM;
    string VideoPath;
    bool CAMERA_STOP;
    const int fmMinue=15*60;
    //yolo长宽
    unsigned int yolo_width;
    unsigned int yolo_height;
    bool print_yolo_width_height_flag;
    //ROI
    Rect ppROI;
    Rect thROI;

    //Activity
    unsigned int ppCount;
    bool ppCrowded;
    bool ppRetent;
    int ppFlowIn;
    int ppFlowOut;
    int ppFlow30s;
    bool thRetent;


signals:
    void getImage1(QImage);
    void para_error();

protected:
    void run();
};

#endif // CAMTHREAD1_H
