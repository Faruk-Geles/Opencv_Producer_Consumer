//
// Created by faruk on 19.03.21.
//

#include "Producer.h"
#include "Producer.h"
#include <iostream>

//int Producer::watched_count = 0;
//Implementation of the the parameter constructor
//=================================================
Producer::Producer() : Producer{"None",cv::Mat(),0, 0}{
    //std::cout <<"Constructor with 0 arg called" << endl;
}
//=================================================
//Implementation of the one parameter constructor
Producer::Producer(std::string image_path_) : Producer{image_path_,cv::Mat(),0, 0}{
    //std::cout <<"Constructor with 1 arg called" << endl;
}
//=================================================
//Implementation of the three parameter constructor
Producer::Producer(std::string image_path_, int width_, int heigth_) :
    Producer{image_path_,cv::Mat(),width_, heigth_}{
    //std::cout <<"Constructor with 1 arg called" << endl;
}
//=================================================
//Implementation of the three parameter constructor
Producer::Producer(int width_, int heigth_) :
        Producer{"None", cv::Mat(), width_, heigth_}{
    //std::cout <<"Constructor with 1 arg called" << endl;
}
//=================================================
//Implementation of the constructor
Producer::Producer(std::string image_path_, cv::Mat img_data_, int width_, int heigth_):
        image_path_{image_path_}, img_data_{img_data_}, width_{width_}, heigth_{heigth_} {
    //++watched_count;
    //std::cout <<"Constructor with 3 args called" << endl;
}

//==================================================
//Implementation of copy constructor
Producer::Producer(const Producer & source):
        Producer{source.image_path_, source.img_data_, source.width_, source.heigth_} {
    //std::cout <<"Copy Constructor called" << endl;
}
//==================================================
//Implementation of the display method
//should just insert the movie attributes to cout
void Producer::display() const {
    std::cout  << image_path_<<", ";
    std::cout << width_<<", ";
    std::cout << heigth_ << std::endl;


    std::string image_path = cv::samples::findFile(image_path_);
    cv::Mat img = cv::imread(image_path, cv::IMREAD_COLOR);
    cv::Mat imgGray;
    cv::Mat imgBlur;
    cv::Mat imgCanny;
    cv::cvtColor(img, imgGray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(img, imgBlur, cv::Size(5,5),5,0);
    cv::Canny(imgBlur, imgCanny,50, 75);



    if(!img.empty())
    {
        cv::imshow("Display window", img);
        //cv::imshow("Display window", imgGray);
        //cv::imshow("Display window", imgBlur);
        //cv::imshow("Display window", imgCanny);

    }else {
        std::cout << "Could not read the image: " << image_path << std::endl;
    }
    cv::waitKey(2000); // Wait for a keystroke in the window

}

void Producer::produce_image(std::string image_path, int rvalue, int gvalue, int bvalue) {
    // To create an image
    // CV_8UC3 depicts : (3 channels,8 bit image depth
    // Height  = 500 pixels, Width = 1000 pixels
    // (0, 0, 100) assigned for Blue, Green and Red plane respectively.
    // So the image will appear red as the red component is set to 100.

    width_ = get_width();
    heigth_ = get_heith();
    cv::Mat img(width_, heigth_, CV_16UC3, cv::Scalar(rvalue,gvalue, bvalue));

    // check whether the image is loaded or not
    if (img.empty())
    {
        cout << "\n Image not created. You have done something wrong. \n";
        //return cv::Mat();    // Unsuccessful.
    } else {
        imwrite(image_path, img);
        //return img;

    }
}


//==================================================
//Implementation of the destructor
Producer::~Producer() {
    //std::cout << "Destructor called"<<std::endl;
    //--watched_count;
}
//==================================================

