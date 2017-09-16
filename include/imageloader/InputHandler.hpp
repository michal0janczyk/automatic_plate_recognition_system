#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

class InputHandler
{
public:
    InputHandler();
    virtual ~InputHandler();

    virtual cv::Mat loadImage() = 0;
};

#endif // INPUTHANDLER_HPP
