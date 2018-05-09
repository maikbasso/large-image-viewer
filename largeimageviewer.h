#ifndef LARGEIMAGEVIEWER_H
#define LARGEIMAGEVIEWER_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string.h>
#include <thread>


class LargeImageViewer {

private:
    cv::Mat image;
    int windowWidth;
    int windowHeight;
    std::string windowName;
    int centerY;
    int centerX;
    bool showTrackbars;

public:
    LargeImageViewer(cv::Mat &image, std::string windowName, int windowWidth, int windowHeight, bool showTrackbars);
    void updateViewer();
    void setCenter(int x, int y);

};

#endif // LARGEIMAGEVIEWER_H
