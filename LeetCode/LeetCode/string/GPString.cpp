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

long findNoRepeatString(const std::string& s)
{
    std::size_t hash_map[256] = {0};
    std::size_t max_length = 0;
    std::size_t index_left = 0;
    
    for (std::size_t n = 0; n < s.length(); ++n) {
        char ch = s[n];
        std::size_t next_pos = hash_map[ch];
        
        // 遇到重复，则直接查看是否要跳转
        if (next_pos == 0 || next_pos < index_left) {
            max_length = std::max(max_length , n+1 - index_left);
        } else {
            index_left = next_pos;
        }
        
        // 记录当前字符串位置，+1 是表示长度，i=0开始计算。
        hash_map[ch] = n+1;
    }
    
    return max_length;
}
