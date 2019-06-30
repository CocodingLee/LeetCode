//
//  GPArray.hpp
//  LeetCode
//
//  Created by fair wu on 2019/6/29.
//  Copyright © 2019 fair wu. All rights reserved.
//

#ifndef GPArray_hpp
#define GPArray_hpp

#include <stdio.h>
#include <vector>
//
// 找出所有满足条件且不重复的三元组
//
std::vector<std::vector<int>> threeSum(std::vector<int>& nums);

//
// 计算最大面积
//
int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

//
// 搜索旋转排序数组
//
int search(std::vector<int>& nums, int target);

//
// 最多装多少水
//
std::vector<int>::size_type trap(std::vector<int>& height);
#endif /* GPArray_hpp */
