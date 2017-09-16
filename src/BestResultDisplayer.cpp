#include "../include/BestResultDisplayer.hpp"

BestResultDisplayer::BestResultDisplayer()
{

}

BestResultDisplayer::~BestResultDisplayer()
{

}

std::string BestResultDisplayer::displayBestResult(std::vector<std::string> vectorOfResult)
{
    int maxCounter = 0;
    for(std::size_t i = 0; i < vectorOfResult.size(); i++)
    {
        int counter = 0;
        for(std::size_t j = 0; j < vectorOfResult.size(); j++)
        {
            if(i != j)
            {

                if(vectorOfResult[i].compare(vectorOfResult[j]) == 0)
                {
                    counter++;
                }
            }
        }
        if(counter > maxCounter)
        {
            maxCounter = counter;
            result = vectorOfResult[i];
        }
    }
    return result;
}
