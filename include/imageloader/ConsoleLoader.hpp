#ifndef CONSOLELOADER_H
#define CONSOLELOADER_H

#include "InputHandler.hpp"
#include <iostream>

class ConsoleLoader : public InputHandler
{
public:
    ConsoleLoader();
    ~ConsoleLoader();

    cv::Mat loadImage() override;

protected:

private:
    cv::Mat inputImage;
    std::string fileName = "";
};

#endif // CONSOLELOADER_H
