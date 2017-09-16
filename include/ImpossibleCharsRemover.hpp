#ifndef IMPOSSIBLECHARSREMOVER_HPP
#define IMPOSSIBLECHARSREMOVER_HPP

#include "PossibleChar.hpp"

class ImpossibleCharsRemover
{
public:
    ImpossibleCharsRemover();
    ~ImpossibleCharsRemover();

    std::vector<PossibleChar> removeImpossibleChars(std::vector<PossibleChar> &vectorOfPossibleCharInScene);

private:
    const double MIN_DIAG_SIZE_MULTIPLE_AWAY = 0.1;
};

#endif // IMPOSSIBLECHARSREMOVER_HPP
