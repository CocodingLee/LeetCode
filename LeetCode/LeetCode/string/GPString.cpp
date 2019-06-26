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

/*
 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
 
 换句话说，第一个字符串的排列之一是第二个字符串的子串。
 
 示例1:
 
 输入: s1 = "ab" s2 = "eidbaooo"
 输出: True
 解释: s2 包含 s1 的排列之一 ("ba").
 
 
 示例2:
 
 输入: s1= "ab" s2 = "eidboaoo"
 输出: False
 
 
 注意：
 
 输入的字符串只包含小写字母
 两个字符串的长度都在 [1, 10,000] 之间
 
 参考：https://blog.csdn.net/qq_26410101/article/details/81042615
 */

bool checkInclusion(std::string s1, std::string s2)
{
    if (s2.empty()) {
        return false;
    }
    
    if (s2.length() < s1.length()) {
        return false;
    }
    
    
    std::vector<int> memo1(26, 0);
    std::vector<int> memo2(26, 0);
    
    for (int i = 0; i < s1.size(); i++) {
        ++ memo1[s1[i] - 'a'];
    }
    
    for (int i = 0; i < s2.size(); ++i) {
        char ch = s2[i];
        ++ memo2[ch - 'a'];
        
        if(i >= s1.size()) {
            std::string::size_type index = i-s1.size();
            char ch = s2[index];
            -- memo2[ch - 'a'];
        }
        
        if (memo1 == memo2) {
            return true;
        }
    }
    
    return false;
    
}

/*
 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 
 示例 1:
 
 输入: num1 = "2", num2 = "3"
 输出: "6"
 示例 2:
 
 输入: num1 = "123", num2 = "456"
 输出: "56088"
 说明：
 
 num1 和 num2 的长度小于110。
 num1 和 num2 只包含数字 0-9。
 num1 和 num2 均不以零开头，除非是数字 0 本身。
 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 
 参考：https://www.cnblogs.com/ariel-dreamland/p/9139468.html
 */

std::string multiply(std::string num1, std::string num2)
{
    if (num1 == "0" || num2 == "0") {
        return "0";
    }
    
    std::string res;
    double n1 = num1.size();
    double n2 = num2.size();
    double k = n1 + n2 - 2, carry = 0;
    
    std::vector<int> v(n1 + n2, 0);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            v[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    
    for (int i = 0; i < n1 + n2; ++i) {
        v[i] += carry;
        carry = v[i] / 10;
        v[i] %= 10;
    }
    
    double i = n1 + n2 - 1;
    while (v[i] == 0) --i;
    if (i < 0) return "0";
    
    while (i >= 0) res.push_back(v[i--] + '0');
    return res;
}

/*
 给定一个字符串，逐个翻转字符串中的每个单词。
 
 
 
 示例 1：
 
 输入: "the sky is blue"
 输出: "blue is sky the"
 示例 2：
 
 输入: "  hello world!  "
 输出: "world! hello"
 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 示例 3：
 
 输入: "a good   example"
 输出: "example good a"
 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
 
 说明：
 
 无空格字符构成一个单词。
 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 
 
 进阶：
 
 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 */

std::string reverseWords(std::string s)
{
    std::string::size_type storeIndex = 0, n = s.size();
    reverse(s.begin(), s.end());
    for (std::string::size_type i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            if (storeIndex != 0) {
                s[storeIndex++] = ' ';
            }
            
            std::string::size_type j = i;
            while (j < n && s[j] != ' ') {
                s[storeIndex++] = s[j++];
            }
            
            reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);
            i = j;
        }
    }
    
    s.resize(storeIndex);
    
    return s;
}
