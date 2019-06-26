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
 
 参考：https://www.cnblogs.com/ariel-dreamland/p/8668286.html
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


/*
 
 编写一个函数来查找字符串数组中的最长公共前缀。
 
 如果不存在公共前缀，返回空字符串 ""。
 
 示例 1:
 
 输入: ["flower","flow","flight"]
 输出: "fl"
 示例 2:
 
 输入: ["dog","racecar","car"]
 输出: ""
 解释: 输入不存在公共前缀。
 说明:
 
 所有输入只包含小写字母 a-z 。
 
 参考：https://blog.csdn.net/SoulOH/article/details/81877995
 */
std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    // 分而治之法则
    std::string longest_prefix = "";
    if (strs.empty()) {
        return "";
    } else if (strs.size() == 1) {
        return strs[0];
    } else if (strs.size() > 1) {
        std::size_t half = strs.size()/2;
        
        std::vector<std::string> left_strs = std::vector<std::string>(strs.cbegin() , strs.cbegin()+half);
        std::vector<std::string> right_strs = std::vector<std::string>(strs.cbegin()+half , strs.cend());
        std::string left_long_prefix = longestCommonPrefix(left_strs);
        std::string right_long_prefix = longestCommonPrefix(right_strs);
        
        std::size_t max_len = std::min(left_long_prefix.length(),right_long_prefix.length());
        for (std::size_t n = 0; n < max_len; ++n) {
            if (left_long_prefix[n] != right_long_prefix[n]) {
                break;
            }
            
            longest_prefix.append(1,left_long_prefix[n]);
        }
    }
    
    return longest_prefix;
    
}
