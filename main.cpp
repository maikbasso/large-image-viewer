#include <QCoreApplication>
#include "largeimageviewer.h"

int main(int argc, char *argv[]){
    QCoreApplication a(argc, argv);

    cv::Mat largeImage = cv::imread("/home/maik/Pictures/Firefox_wallpaper.png", CV_LOAD_IMAGE_COLOR);

    LargeImageViewer *liv = new LargeImageViewer(largeImage, "test", 600, 600, false);

    int x = 0,y = 0;

    while (true) {
        liv->setCenter(x++,y++);
        liv->updateViewer();
        cv::circle(largeImage,cv::Point(x,y), 10, cv::Scalar(0,0,0), -1, cv::LINE_8, 0);
    }

    return a.exec();
}
