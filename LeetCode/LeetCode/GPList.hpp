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

#endif /* GPList_hpp */
