
#include <iostream>

#include <string>
#include <vector>

#include "face_detect.hpp"

#include <opencv2/core/utility.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;

FaceDetect::FaceDetect(int camera_index) {
  // Initialize the face cascade
  String face_cascade_name = samples::findFile("data/haarcascade_frontalface_default.xml");
  face_cascade.load(face_cascade_name);

  // Initialize the camera
  camera.open(camera_index, CAP_V4L);
  if (!camera.isOpened()) {
    exit(-1);
  }
}

FaceDetect::~FaceDetect() {
  camera.release();
}

int FaceDetect::get_frame() {
  if (!camera.read(frame))
    return -1;

  return frame.empty() ? -1 : 0;
}

int FaceDetect::detect() {

  cvtColor(frame, gray_frame, COLOR_BGR2GRAY);

  this->face_cascade.detectMultiScale(gray_frame, faces, 1.1, 6, CASCADE_SCALE_IMAGE, Size(50, 50));

  for (std::vector<Rect>::iterator f = faces.begin(); f != faces.end(); f++) {
    rectangle(frame, *f, Scalar(255, 0, 0), 2);
  }

  return 0;
}

void FaceDetect::show() {
  imshow("Face Detector", frame);
}
