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
#endif /* GPString_hpp */
