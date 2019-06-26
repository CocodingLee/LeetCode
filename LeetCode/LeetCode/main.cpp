//
//  main.cpp
//  LeetCode
//
//  Created by fair wu on 2019/6/26.
//  Copyright © 2019 fair wu. All rights reserved.
//

#include <iostream>
#include "string/GPString.hpp"

int main(int argc, const char * argv[])
{

    long output1 = findNoRepeatString("abcabcbb");
    std::cout << "abcabcbb repeat = " << output1  << "\n";
    

    long output2 = findNoRepeatString("bbbbb");
    std::cout << "bbbbb repeat = " << output2  << "\n";
    
    long output3 = findNoRepeatString("pwwkew");
    std::cout << "pwwkew repeat = " << output3  << "\n";

    
    long output4 = findNoRepeatString("dvdf");
    std::cout << "dvdf repeat = " << output4  << "\n";

    return 0;
}
