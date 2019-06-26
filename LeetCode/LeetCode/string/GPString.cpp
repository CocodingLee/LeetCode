//
//  GPString.cpp
//  LeetCode
//
//  Created by fair wu on 2019/6/26.
//  Copyright © 2019 fair wu. All rights reserved.
//

#include "GPString.hpp"
#include <vector>

/*
 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 
 示例 1:
 输入: "abcabcbb"
 输出: 3
 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 
 示例 2:
 输入: "bbbbb"
 输出: 1
 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 
 示例 3:
 输入: "pwwkew"
 输出: 3
 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 
 */

long findNoRepeatString(const std::string& input)
{
    
    std::vector<std::string> all_data;
    
    // 一条数据
    std::vector<char> one_data;
    // 遍历输入字符串
    for (long n = 0 ; n < input.length() ; ++n) {
        char ch = input[n];
        
        if (one_data.size() > 0) {
            
            // 遍历存在的字符串
            bool is_ch_exist = false;
            for (long t=0; t<one_data.size(); ++t) {
                char exist = one_data[t];
                
                // 存在则说明 已经重复
                if (ch == exist) {
                    is_ch_exist = true;
                    break;
                }
            }
            
            if (is_ch_exist) {
                std::string one(one_data.cbegin() , one_data.cend());
                all_data.push_back(one);
                one_data.clear();
            }
            
            one_data.push_back(ch);
            
        } else {
            one_data.push_back(ch);
        }
    }
    
    std::string output = "";
    for (long a = 0; a < all_data.size(); ++a) {
        std::string one = all_data[a];
        if (one.length() > output.length()) {
            output = one;
        }
    }
    
    return output.length();
}
