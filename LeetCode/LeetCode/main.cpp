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
#if 0
    {
        long output1 = findNoRepeatString("abcabcbb");
        std::cout << "abcabcbb repeat = " << output1  << "\n";
        
        long output2 = findNoRepeatString("bbbbb");
        std::cout << "bbbbb repeat = " << output2  << "\n";
        
        long output3 = findNoRepeatString("pwwkew");
        std::cout << "pwwkew repeat = " << output3  << "\n";
        
        long output4 = findNoRepeatString("dvdf");
        std::cout << "dvdf repeat = " << output4  << "\n";
    }
    
    {
        std::vector<std::string> tmp;
        tmp.push_back("fl234ower");
        tmp.push_back("fl234ow");
        tmp.push_back("fl234ight");
        
        std::string long_prefix = longestCommonPrefix(tmp);
        std::cout << long_prefix << "\n";
    }
    
    {
        std::string s1 = "ab";
        std::string s2 = "eidbaooo";
        bool is = checkInclusion(s1, s2);
        std::cout << is << "\n";
    }
    
    {
        std::string num = multiply("0", "0");
        std::cout << num << "\n";
    }
#endif
    
    {
        std::string re = reverseWords("a good   example");
        std::cout << re << "\n";
    }
    return 0;
}
