//
//  GPList.hpp
//  LeetCode
//
//  Created by fair wu on 2019/6/30.
//  Copyright © 2019 fair wu. All rights reserved.
//

#ifndef GPList_hpp
#define GPList_hpp

#include <stdio.h>
#include <vector>

//
// 反转一个单链表。
//

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head);
// 迭代
ListNode* reverseList_dfs(ListNode* head);

//
// 两数相加
//
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

//
// 合并数组
//
ListNode* mergeKLists(std::vector<ListNode*>& lists);

#endif /* GPList_hpp */
