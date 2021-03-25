//
// Created by faruk on 19.03.21.
//

#ifndef CLION_PROJECTS_PRODUCER_H
#define CLION_PROJECTS_PRODUCER_H


#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace std;
class Producer {
private:
    friend class Consumer;
    //std::string filename_;                              //name of the image file
    std::string image_path_;                              // the movie rating
    int width_;                                           // width of image
    int heigth_;                                          // height of image

    //static int watched_count;
    cv::Mat img_data_;

public:
    Producer();
    //Constructor - expects all 4 image attributes
    Producer(std::string image_path_, cv::Mat img_data_, int width_, int heigth_);
    //Constructor - expects 3 image attributes
    Producer(std::string image_path_, int width_, int heigth_);
    //Constructor - expects 2 image attributes
    Producer(int width_, int heigth_);
    //Constructor - expects one paramter
    Producer(std::string image_path_);
    //Copy constructor
    Producer(const Producer & source);
    //Destructor
    ~Producer();

    //basis getters and setters for private attributes
    //implement these inline and watch your const-correctness

    //setters
    //void set_name(std::string filename_) {this -> filename_=filename_;}
    void set_image_path(std::string image_path_) {this -> image_path_=image_path_;}
    void set_width(int width_) {this -> width_= width_;}
    void set_heigth(int heigth_) {this -> heigth_= heigth_;}
    //void set_watched(int watched_) {this -> watched_=watched_;}

    //getters
    std::string  get_image_path() const {return image_path_;}
    int get_width() const {return width_;}
    int get_heith() const {return heigth_;}


    //generate image
    void produce_image(std::string image_path, int rvalue, int gvalue, int bvalue);

    //read image
    cv::Mat read_image(std::string image_path);

    //simply display the image
    void display() const;


};


#endif //CLION_PROJECTS_PRODUCER_H
