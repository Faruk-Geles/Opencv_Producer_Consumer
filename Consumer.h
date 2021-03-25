//
// Created by faruk on 19.03.21.
//

#ifndef CLION_PROJECTS_CONSUMER_H
#define CLION_PROJECTS_CONSUMER_H


#include <iostream>
#include <vector>
#include "Producer.h"
#include <string>

class  Consumer {

private:
    vector<Producer> images_;

public:

    //constructor expect the movie collection as vector of image objects
    Consumer(vector<Producer>  images_);
    //constructor with no parameters
    Consumer(){};
    // Destructor
    ~Consumer();

    //add image to the image collection
    //bool add_image(std::string image_path, cv::Mat img_data, int width, int heigth);
    bool add_image(std::string image_path);

    //increment movie watched , 2 different ways of implementation
    //bool increment_watched(std::string image_path );

    //display method
    void display_images();

    //free the buffer and delete all the images in the buffer and make the buffer empty
    void free_the_buffer();

};

#endif //CLION_PROJECTS_CONSUMER_H
