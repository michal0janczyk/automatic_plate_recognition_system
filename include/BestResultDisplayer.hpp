#ifndef BESTRESULTDISPLAYER_HPP
#define BESTRESULTDISPLAYER_HPP

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>

class BestResultDisplayer
{
public:
    BestResultDisplayer();
    ~BestResultDisplayer();
    std::string displayBestResult(std::vector<std::string> vectorOfResult);

private:
    std::string result = "";
};

#endif // BESTRESULTDISPLAYER_HPP
