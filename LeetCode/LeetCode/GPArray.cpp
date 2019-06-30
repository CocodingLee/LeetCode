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
        
        // 移动左侧
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


/*
 给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向 (水平或垂直) 的 1 (代表土地) 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
 
 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
 
 示例 1:
 
 [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
 对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
 
 示例 2:
 
 [[0,0,0,0,0,0,0,0]]
 对于上面这个给定的矩阵, 返回 0。
 
 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 */
int dfs_search(std::vector<std::vector<int>>& grid, int x, int y,std::vector<std::vector<bool>>& mark)
{
    if(x >=  grid.size() || y >= grid[0].size() || x < 0 || y < 0) {
        return 0;
    }
    
    if(mark[x][y] == true) {
        return 0;
    }
    
    if(grid[x][y] == 0) {
        return 0;
    }
    
    // 对于点[x,y]搜索上下左右4个点是否是岛屿
    // 即[x-1,y],[x+1,y],[x,y-1],[x,y+1]
    // 对于已经搜索过的点要进行标记
    
    mark[x][y] = true;
    
    return 1 + dfs_search(grid, x+1, y, mark)
    + dfs_search(grid, x-1, y, mark)
    + dfs_search(grid, x, y+1, mark)
    + dfs_search(grid, x, y-1, mark);
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
{
    if(grid.empty()) {
        return 0;
    }
    
    int res = 0;
    
    // 定义标记数组
    std::vector<std::vector<bool>> vecMark(grid.size() , std::vector<bool>(grid[0].size() , false));
    
    // 定义搜索边界
    auto mostDeep = grid.size();
    auto mostLeft = grid[0].size();
    
    //开始搜索
    for(int i = 0; i < mostDeep; ++i) {
        for(int j = 0;j < mostLeft;j++) {
            
            // 如果当前已经被计算过了，则不计算
            if(vecMark[i][j] == true) {
                continue;
            }
            
            int temp = dfs_search(grid, i, j, vecMark);
            res = std::max(res, temp);
        }
    }
    
    return res;
}


/*
 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 
 ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 
 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 
 你可以假设数组中不存在重复的元素。
 
 你的算法时间复杂度必须是 O(log n) 级别。
 
 示例 1:
 
 输入: nums = [4,5,6,7,0,1,2], target = 0
 输出: 4
 示例 2:
 
 输入: nums = [4,5,6,7,0,1,2], target = 3
 输出: -1
 
 https://www.cnblogs.com/ariel-dreamland/p/9138064.html
 二分搜索法的关键在于获得了中间数后，判断下面要搜索左半段还是右半段
 */

int search(std::vector<int>& nums, int target)
{
    if (nums.size() <= 0) {
        return -1;
    }
    
    typedef int size_type;
    
    size_type find_pos = -1;
    size_type left_index = 0;
    size_type right_index = (size_type)nums.size() - 1;
    
    while (left_index <= right_index) {
        
        // 每次都中间位置
        size_type mid = (left_index+right_index)/2;
        int mid_value = nums[mid];
        int right_value = nums[right_index];
        
        // 否则 如果中间位置小于最后位置
        if (mid_value == target) {
            find_pos = mid;
            break;
        }
        
        // 右半边有序
        else if (mid_value < right_value) {
            if (target > mid_value && target <= right_value) {
                left_index = mid+1;
            } else {
                right_index = mid-1;
            }
        }
        
        // 左半边有序
        else {
            
            int left_value = nums[left_index];
            if (target < mid_value && target >= left_value) {
                right_index = mid-1;
            } else {
                left_index = mid+1;
            }
        }
    }
    
    return find_pos;
    
}


/*
 班上有 N 名学生。其中有些学生互为朋友，有些则不是。他们的友谊具有是传递性。如果已知 A 是 B 的直接朋友，B 是 C 的直接朋友，那么我们可以认为 A 也是 C 的间接朋友。所谓的朋友圈，是指一组互为直接或间接朋友的学生的集合。
 
 给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。如果M[i][j] = 1，表示第 i 个和 j 个学生互为直接朋友关系，否则不是。你必须输出所有学生中的已知的朋友圈总数。
 
 样例
 输入:
 [[1,1,0],
 [1,1,0],
 [0,0,1]]
 输出: 2
 解释: 已知学生0和学生1互为直接朋友，他们在一个朋友圈。
 第2个学生自己在一个朋友圈。所以返回2。
 输入:
 [[1,1,0],
 [1,1,1],
 [0,1,1]]
 输出: 1
 解释: 已知学生0和学生1互为直接朋友，学生1和学生2互为直接朋友，所以学生0和学生2也是间接朋友。
 他们三个人都在一个朋友圈，所以返回1。
 注意
 N 的范围是 [1,200]。
 对于所有学生 M[i][i] = 1。
 如果 M[i][j] = 1，则 M[j][i] = 1。
 
 
 作者：wzc1995
 链接：https://www.acwing.com/solution/leetcode/content/427/
 来源：AcWing
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 
 https://www.acwing.com/solution/leetcode/content/427/
 */

std::vector<int>::size_type n;
std::vector<int> friends;

//
// 找到x的朋友
//
int find(int x)
{
    return x == friends[x] ? x : friends[x] = find(friends[x]);
}

int findCircleNum(std::vector<std::vector<int>>& M)
{
    n = M.size();
    friends = std::vector<int>(n);
    
    // 构建初始化集合，每个人的朋友圈都只有自己
    for (int i = 0; i < n; ++i) {
        friends[i] = i;
    }
    
    // 构建以自己为代表的朋友圈
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (M[i][j] == 1) {
                int fx = find(i), fy = find(j);
                if (fx != fy) {
                    friends[fx] = fy;
                }
            }
    
    // 计算朋友圈个数
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == find(i)) {
            ans++;
        }
    }
    
    return ans;
}

void findCircleNumCore(std::vector<std::vector<int>>& M, std::vector<bool> &visited, int i)
{
    for (int j = 0; j < M.size(); j++) {
        if (M[i][j] == 1 && visited[j] == 0) {
            visited[j] = 1;
            findCircleNumCore(M, visited, j);
        }
    }
}

int findCircleNumDFS(std::vector<std::vector<int>>& M)
{
    if (M.empty()) {
        return 0;
    }
    
    std::vector<bool> visited(M.size(), false);
    int count = 0;
    for (int i = 0; i < M.size(); i++) {
        if (visited[i] == 0) {
            findCircleNumCore(M,visited,i);
            
            //
            // 每一个人跟自己要不是朋友，要不就不是;
            // 没有被访问过，则直接添加一个朋友圈
            //
            count++;
        }
    }
    
    return count;
}


/*
 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 
 
 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
 
 示例:
 
 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 输出: 6
 
 https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1047/
 */

std::vector<int>::size_type trap(std::vector<int>& height)
{
    if (height.size() <= 0) {
        return 0;
    }
    
    typedef std::vector<int>::size_type size_type;
    size_type left_index = 0;
    size_type right_index = height.size() - 1;
    
    // 定义一个水平线，在水平线以下，则可以接水。
    size_type level = 0;
    size_type rains = 0;
    
    while (left_index < right_index) {
        int left_height = height[left_index];
        int right_height = height[right_index];
        
        // 短板才能决定装多少水
        int lower = std::min(left_height , right_height);
        lower == left_height ? ++left_index : --right_index;
        
        level = std::max((unsigned long)level, (unsigned long)lower);
        rains += level - lower;
    }
    
    return rains;
}
