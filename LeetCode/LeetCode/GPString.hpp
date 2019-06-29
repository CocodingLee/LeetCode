//
//  GPString.hpp
//  LeetCode
//
//  Created by fair wu on 2019/6/26.
//  Copyright © 2019 fair wu. All rights reserved.
//

#ifndef GPString_hpp
#define GPString_hpp

#include <stdio.h>
#include <string>
#include <vector>

//
// 查找最大不重复的子串长度
//
long findNoRepeatString(const std::string& input);

//
// 查找最大重复的头部字符串
//
std::string longestCommonPrefix(std::vector<std::string>& strs);

//
// 检查是否包含子串
//
bool checkInclusion(std::string s1, std::string s2);

//
// 字符串相乘
//
std::string multiply(std::string num1, std::string num2);

//
// 翻转字符串里的单词
//
std::string reverseWords(std::string s);

//
// 分割字符串
//
std::string simplifyPath(std::string path);

//
// 复原IP地址
//
std::vector<std::string> restoreIpAddresses(std::string s);



#endif /* GPString_hpp */
