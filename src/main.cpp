
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "face_detect.hpp"

int main(int argc, char** argv) {
    
    // Default index 0 (built-in webcam) has a busted driver on my machine
    // Using a USB webcam at index 1 instead
    FaceDetect face_detect = FaceDetect(1);

    std::cout << "Starting detection" << std::endl;

    while (true) {
        if (face_detect.get_frame() == 0) {
            face_detect.detect();

            face_detect.show();
            
            if (cv::waitKey(15) == 'q') {
                break;
            }
        }
    }

    return 0;
}
