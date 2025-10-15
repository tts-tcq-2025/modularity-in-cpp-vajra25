#pragma once
#include "ColorPair.h"
#include <vector>
#include <string>

namespace TelCoColorCoder
{
    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    std::vector<std::string> GetColorCodeReference();
}
