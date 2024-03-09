#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <stdio.h>

cv::String imgtext;
cv::Rect button1;
cv::Rect button2;
cv::Rect button3;

cv::Mat imggui;
cv::Mat imgfruits;
cv::Mat imgclothing;
cv::Mat imganimals;

cv::Mat imggui_resized;
cv::Mat imgfruits_resized;
cv::Mat imgclothing_resized;
cv::Mat imganimals_resized;

std::vector <cv::Rect> buttons;
int hihi = 0;

void callBackFunc(int event, int x, int y, int flags, void* userdata){
    if (event == cv::EVENT_LBUTTONDOWN){

        for(int i=0; i<3;i++){
            if (buttons[i].contains(cv::Point(x, y))){
                if(buttons[i]==button1){
                    std::cout << "Fruits" << std::endl;
                    rectangle(imggui_resized(buttons[i]), buttons[i], cv::Scalar(0,0,255), 2);
                    hihi = 1;
                }
                if(buttons[i]==button2){
                    std::cout << "Clothing" << std::endl;
                    rectangle(imggui_resized(buttons[i]), buttons[i], cv::Scalar(0,0,255), 2);
                    hihi = 2;
                }
                if(buttons[i]==button3){
                    std::cout << "Animals" << std::endl;
                    rectangle(imggui_resized(buttons[i]), buttons[i], cv::Scalar(0,0,255), 2);
                    hihi = 3;
                }

            }
        }
    }
       // imshow(imgtext, imggui_resized);
       // cv::waitKey(1);
}

void makeButtons(cv::Mat image, int width, int height){

}

int main(int argc, char** argv){

    //load images
    imggui = cv::imread("../img/biggerscratch.png", cv::IMREAD_COLOR);
    imgfruits = cv::imread("../img/green/fruits.png", cv::IMREAD_COLOR);
    imgclothing = cv::imread("../img/green/clothing.png", cv::IMREAD_COLOR);
    imganimals = cv::imread("../img/green/animals.png", cv::IMREAD_COLOR);

    //check for empty matrix
    if (imggui.empty()||imgfruits.empty()||imgclothing.empty()||imganimals.empty()){
        std::cout << "Could not open or find the image" << std::endl;
        std::cin.get(); //wait for any key press
        return -1;
     }

    //resize background
    int imggui_width = 1400;
    int imggui_height = 800;
    cv::resize(imggui,imggui_resized, cv::Size(imggui_width, imggui_height), cv::INTER_LINEAR);

    //resize buttons
    int button_width = 150;
    int button_height = 150;
    cv::resize(imgfruits, imgfruits_resized, cv::Size(button_width, button_height), cv::INTER_LINEAR);
    cv::resize(imgclothing, imgclothing_resized, cv::Size(button_width, button_height), cv::INTER_LINEAR);
    cv::resize(imganimals, imganimals_resized, cv::Size(button_width, button_height), cv::INTER_LINEAR);

    //show program
    int button1_x = 300;
    int button1_y = 550;
    int button2_x = 500;
    int button2_y = 550;
    int button3_x = 700;
    int button3_y = 550;

    //clickable buttons
    button1 = cv::Rect(button1_x, button1_y, button_width, button_height);
    buttons.push_back(button1);

    button2 = cv::Rect(button2_x, button2_y, button_width, button_height);
    buttons.push_back(button2);

    button3 = cv::Rect(button3_x, button3_y, button_width, button_height);
    buttons.push_back(button3);

    //drawing button
    cv::Mat insertOrange(imggui_resized, button1);
    imgfruits_resized.copyTo(insertOrange);

    cv::Mat insertGrapes(imggui_resized, button2);
    imgclothing_resized.copyTo(insertGrapes);

    cv::Mat insertApple(imggui_resized, button3);
    imganimals_resized.copyTo(insertApple);


    imgtext = "Our GUI";
    cv::namedWindow(imgtext);
    cv::setMouseCallback(imgtext, callBackFunc);
    std::cout << hihi << std::endl;
    cv::imshow(imgtext, imggui_resized);




    switch(hihi){
        case 1:
            std::cout << "hej" << std::endl;
            imggui = cv::imread("../img/biggerscratch.png", cv::IMREAD_COLOR);
            cv::resize(imggui,imggui_resized, cv::Size(imggui_width, imggui_height), cv::INTER_LINEAR);

            cv::imshow(imgtext, imggui);






            break;
        case 2:

            break;

        case 3:

            break;

    }
    cv::waitKey(0);
    return 0;
}
