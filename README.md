# Face Detection
A simple face detection app using the default Haar Cascade data provided by OpenCV.

## Environment

A C++ compiler and cmake must be installed. The program was developed for Ubuntu 22.04 LTS, some modification may be necessary for other operating systems.

Must install libopencv:

`$ sudo apt install libopencv-dev`

## Building and running

Follow these steps starting from the project root:

    $ mkdir build && cd build
    $ cmake ..
    $ make
    $ cd ..
    $ ./build/face_detect

*Note: The face_detect program must be executed from the project root directory.

*Note: To exit the program, press 'q' with the video streaming window in context.

*Note: The camera device has been hard-coded to instance 1, rather than 0. To change to default, edit the arguement passed to the FaceDetect constructor in [main.cpp](src/main.cpp).

## License
Please see [LICENSE](LICENSE) file for usage information.
