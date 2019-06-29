//
//  GPArray.cpp
//  LeetCode
//
//  Created by fair wu on 2019/6/29.
//  Copyright © 2019 fair wu. All rights reserved.
//

#include "GPArray.hpp"


/*
 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 
 注意：答案中不可以包含重复的三元组。
 
 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 
 满足要求的三元组集合为：
 [
 [-1, 0, 1],
 [-1, -1, 2]
 ]
 
 https://www.cnblogs.com/wmx24/p/8989800.html
 首先对数组从小到大排序，从一个数开始遍历，若该数大于0，后面的数不可能与其相加和为0，所以跳过；否则该数可能是满足要求的第一个数，这样可以转化为求后面数组中两数之和为该数的相反数的问题。定义两个指针一前一后，若找到两数之和满足条件则加入到解集中；若大于和则后指针向前移动，反之则前指针向后移动，直到前指针大于等于后指针。这样遍历第一个数直到数组的倒数第3位。注意再求和过程中首先判断该数字是否与前面数字重复，保证解集中没有重复解。
 */
std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    // 排除边界值
    if(nums.empty()
       || nums.back() < 0
       || nums.front() > 0
       || nums.size() < 3) {
        return {};
    }
    
    typedef double size_type;
    std::vector<std::vector<int>> res;
    // 排序，从小到大
    std::sort(nums.begin(),nums.end());
    
    // 从第一位开始
    for(size_type k=0 ; k<nums.size() ; ++k) {
        int n1 = nums[k];
        
        // 三个数和，第一位及不可大于零
        if(n1 > 0) {
            break;
        }
        
        // 跟上一个相同
        if (k > 0) {
            int n2 = nums[k-1];
            if(k > 0 && n1==n2) {
                continue;
            }
        }
        
        size_type target = 0-nums[k];
        size_type i = k+1;
        size_type j = nums.size()-1;
        
        while(i<j)
        {
            size_type temp = nums[i]+nums[j];
            if(temp == target) {
                res.push_back({nums[k],nums[i],nums[j]});
                
                while(i<j&&nums[i]==nums[i+1]) {++i;}
                while(i<j&&nums[j]==nums[j-1]) {--j;}
                
                ++i;
                --j;
                
            } else if(temp < target) {
                ++i;
            } else {
                --j;
            }
            
            
        }
    }
    return res;
}
