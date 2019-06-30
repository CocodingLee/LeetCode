//
//  main.cpp
//  LeetCode
//
//  Created by fair wu on 2019/6/26.
//  Copyright © 2019 fair wu. All rights reserved.
//

#include <iostream>
#include "GPString.hpp"
#include "GPArray.hpp"

// 快速排序解释 https://www.cnblogs.com/KuJo/p/8544775.html


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
    
    {
        std::string re = reverseWords("a good   example");
        std::cout << re << "\n";
    }
    
    {
        std::string re = simplifyPath("/a/./b/../../c/");
        std::cout << re << "\n";
    }
    
    {
        std::vector<std::string> v = restoreIpAddresses("010010");
        for (std::string const& ip : v) {
            std::cout << ip << "\n";
        }
    }
    
    {
        int a[] = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
        std::vector<int> nums(a , a+sizeof(a)/sizeof(a[0]));
        std::vector<std::vector<int>> res = threeSum(nums);
        for (std::vector<int> r : res) {
            std::string out = "[";
            for (std::vector<int>::size_type n = 0 ; n < r.size() ; ++n) {
                int value = r[n];
                out.append(std::to_string(value));
                if (n < r.size() - 1) {
                    out.append(", ");
                }
            }
            
            out.append("]");
            
            std::cout << out << "\n";
        }
    }

    {   
        int a[] = {5,1,3};
        std::vector<int> nums(a , a+sizeof(a)/sizeof(a[0]));
        std::vector<int>::size_type pos = search(nums, 5);
        std::cout << "seach pos = " << pos << "\n";
    }
    
#endif
    
    {
        int a [] = {0,1,0,2,1,0,1,3,2,1,2,1};
        std::vector<int> tmp(a,a+sizeof(a)/sizeof(a[0]));
        std::vector<int>::size_type count = trap(tmp);
        std::cout << "trap count = " << count << "\n";
    }
    return 0;
}
