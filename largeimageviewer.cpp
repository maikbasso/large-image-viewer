#include "largeimageviewer.h"

LargeImageViewer::LargeImageViewer(cv::Mat &image, std::string windowName, int windowWidth, int windowHeight, bool showTrackbars){
    //get image
    this->image = image;
    //get window name
    this->windowName = windowName;
    //adjust window size
    if(windowHeight >= image.rows){
        this->windowHeight = image.rows-1;
    } else{
        this->windowHeight = windowHeight;
    }
    if(windowWidth >= image.cols){
        this->windowWidth = image.cols-1;
    } else{
        this->windowWidth = windowWidth;
    }
    //set center of the image
    this->centerX = (int)(image.cols/2);
    this->centerY = (int)(image.rows/2);
    //create window
    cv::namedWindow(this->windowName.c_str(), cv::WINDOW_NORMAL);
    //resize window
    cv::resizeWindow(this->windowName.c_str(), this->windowWidth, this->windowHeight);
    //trackbars
    this->showTrackbars = showTrackbars;
}

void LargeImageViewer::updateViewer(){

    int centerX = this->centerX-(this->windowWidth/2);
    int centerY = this->centerY-(this->windowHeight/2);
    int windowWidth = this->windowWidth;
    int windowHeight = this->windowHeight;

    if(centerX > (this->image.cols-this->windowWidth)-1){
        centerX = (this->image.cols-this->windowWidth)-1;
    }

    if(centerY > (this->image.rows-this->windowHeight)-1){
        centerY = (this->image.rows-this->windowHeight)-1;
    }

    if(centerX < 0){
        centerX = 0;
    }

    if(centerY < 0){
        centerY = 0;
    }

    //create visible image
    cv::Mat visibleImage = this->image( cv::Rect(centerX, centerY, windowWidth, windowHeight) );
    //show image
    cv::imshow(this->windowName.c_str(), visibleImage);
    //show trackbars if exists
    if(this->showTrackbars){
        cv::createTrackbar("X", this->windowName.c_str(), &this->centerX, this->image.cols-1);
        cv::createTrackbar("Y", this->windowName.c_str(), &this->centerY, this->image.rows-1);
    }
    //wait to image show
    cv::waitKey(1);
}

void LargeImageViewer::setCenter(int x, int y){
    if(this->showTrackbars == false){
        //set center of the image
        this->centerX = x;
        this->centerY = y;
    }
}
