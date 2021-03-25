//
// Created by faruk on 19.03.21.
//
#include <iostream>
#include <vector>
#include "Producer.h"
#include "Consumer.h"


//=================================================
//Implementation of the constructor
Consumer::Consumer(vector<Producer> images_) : images_{images_} {
    //std::cout << "Constructor called"<<std::endl;
}

//=================================================
//Implementation of the dectructor
Consumer::~Consumer() {
    //std::cout << "Destructor called"<<std::endl;
}

//=================================================
//Implementation of the add_image method
//This method expects the image path with the name of image containing
//It will search the images_ vector to see if a image object already
//exists with the same name, If it does then return false since
//the image already exists. Othervise create a movie object from the
// provided information
bool Consumer::add_image(std::string image_path) {//, cv::Mat img_data, int width, int heigth) {
    for (const Producer &m: images_) {
        if (m.get_image_path() == image_path) {
            return false;
        }
    }
    Producer key = Producer{image_path}; //, cv::Mat(), width, heigth};
    images_.push_back(key);
    return true;

}

//=================================================
//Implementation of the display_images method
//This method uses the display method from the Producer class
//for each call the Producer display method so the image object
//displays itself
void Consumer::display_images() {
    std::cout << "\n=============================" << endl;
    //int num=0;
    if (!images_.empty()) {
        for (const Producer &m: images_) {
            //num++;
            m.display();
        }
        std::cout << "=============================\n" << endl;
    } else {
        std::cout << "Sorry no images to display\n" << std::endl;
    }
}

//=================================================
//Implementation of the free_the_buffer method
void Consumer::free_the_buffer() {
    //delete all the images
    images_.clear();
}
//=================================================