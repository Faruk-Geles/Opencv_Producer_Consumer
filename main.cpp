#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include "Consumer.h"
#include "Producer.h"

#include <queue>
#include <thread>
#include <memory>
#include <stdint.h>


#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

#include <fstream>
#include <filesystem>
#include <regex>


using namespace std;
using namespace cv;
namespace fs = std::filesystem;


//Function  prototypes
void add_image(Consumer & imgs, std::string image_path, int watched);



/****************************************************************************
* helper function: list_image_file_names
* It gives image paths with image names in an given folder
* it expects the path where the images are located
* In this case it looks only for png and jpg images but for other
* formats it can be easily exptended
* **************************************************************************/
vector<string> list_image_file_names(std::string dir_path) {

    fs::path current_dir(dir_path);
    vector<string> images_vec;

    // list all files containing an png extension
    for (auto &file : fs::recursive_directory_iterator(current_dir)) {
        if ((file.path().extension() == ".png") || (file.path().extension() == ".jpg")) {
            std::cout << dir_path+file.path().filename().string() << std::endl;
            images_vec.push_back(dir_path+file.path().filename().string());
        }
    }


    return images_vec;
}
//===========================================================================
/****************************************************************************
* helper function
* add_image expects a reference to a Image object
* and the name image path containing the image mame
* If the image was sussessfully added to the image object it displays a sussess
* message, otherwise the image was not added
* because the name of the image was already was already in images buffer
* **************************************************************************/
void add_image(Consumer & imgs, std::string image_path) {
    if (imgs.add_image(image_path)) {
        std::cout << image_path << " added" << std::endl;
    }else {
        std::cout << image_path << " already exist" << std::endl;
    }
}
//===========================================================================

int main()
{
    //Instantiation of a 16 bit image objects where the width and heigth gives the images
    //image dimensions
    Producer new_image(800, 800);
    Producer new_image2(600, 600);
    //The 16 image mages are produced  with rbg values are generated
    new_image.produce_image("../my_new_image.png",0, 25000, 0);
    new_image2.produce_image("../my_new_image2.png",65000, 65000, 0);

    // Instantiation of customer object
    Consumer my_images;
    //If we display the images in the buffer it will give us that there  are no images to display
    my_images.display_images();

    //find all images png or jpg images in the current folder
    string dir_path{"../"};
    while(true) {
        vector<string> images_path = list_image_file_names(dir_path);

        //Now we add four images into the buffer and display these images
        //If a picture is already in the buffer, the console output indicates it
        for (std::string new_path:images_path) {
            add_image(my_images, new_path);
        }
        my_images.display_images();
    }


    cout << endl;
    return 0;
}
