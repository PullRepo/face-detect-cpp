
#ifndef FACE_DETECT_HPP
#define FACE_DETECT_HPP

#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;

class FaceDetect {
public:
    FaceDetect(int camera_index);
    ~FaceDetect();

    int get_frame();
    int detect();

    void show();

private:
    Mat frame;
    Mat gray_frame;

    VideoCapture camera;
    CascadeClassifier face_cascade;

    std::vector<Rect> faces;
};

#endif // FACE_DETECT_HPP