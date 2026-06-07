#include <iostream>
#include <fstream>
#include "Input_Parser.h"
#include <opencv2/opencv.hpp>

bool file_exists(std::string file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        return false;
    }
    return true;
}

int main(int argc, char** argv)
{
    
    std::cout << "CPBD" << std::endl;
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;

    InputParser ip(argc, argv);

    if (!ip.cmdOptionExists("-f")) {
        std::cout << "Path to image needs to be given as argument\nUsage: cpbd.exe -f <file_path>" << std::endl;
        return 1;
    }

    const std::string& filename = ip.getCmdOption("-f");

    if (!file_exists(filename)) {
        std::cout << filename << " does not exist" << std::endl;
        return 1;
    }

    cv::Mat image = imread(filename, cv::IMREAD_GRAYSCALE);

    return 0;
}