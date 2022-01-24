#include <iostream>
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
    void PrintManual(ColorPair(*GetColorforPair)(int PairNumber) , void(*PrintColorPair)(int PairNumber, std::string ColorPair))
    {
        std::cout<<"PairNumber  -  ColorPair"<<std::endl;
        int i = 0;
        while(i<24)
        {
            std::string colorPair = GetColorforPair(i).ToString();
            if(!colorPair.empty())
            {
               PrintColorPair( i, colorPair);
               i++;
            }
            else
            {
                std::cout<<"Error in Pair"<< i <<std::endl;
                break;
            }
        }
    }
    void PrintColorPair(int PairNumber, std::string ColorPair)
    {  
       std::cout<<PairNumber<<"     -    "<<ColorPair<<std::endl;
    }
}
