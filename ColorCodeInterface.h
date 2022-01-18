#include <iostream>
#include "ColorCodeDefines.h"
#include "ColorPair.h"

namespace TelCoColorCoder
{
    ColorPair GetColorFromPairNumber(int pairNumber)
    {
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = 
            (MajorColor)(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor =
            (MinorColor)(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) 
    {
        return major * numberOfMinorColors + minor + 1;
    }    
    void ReadManual()
    {
       std::cout<<"PairNumber  -  ColorPair"<<std::endl;
       for(int PairNumber =1; PairNumber<=25;PairNumber++)
       {
          TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(PairNumber);
          std::cout<<PairNumber<<"     -    "<<colorPair.ToString()<<std::endl;
       }
    }
}
