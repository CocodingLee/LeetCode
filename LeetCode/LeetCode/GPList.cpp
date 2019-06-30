//
//  GPList.cpp
//  LeetCode
//
//  Created by fair wu on 2019/6/30.
//  Copyright © 2019 fair wu. All rights reserved.
//

#include "GPList.hpp"

/*
 反转一个单链表。
 
 示例:
 
 输入: 1->2->3->4->5->NULL
 输出: 5->4->3->2->1->NULL
 进阶:
 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
 
 */

ListNode* reverseList(ListNode* head)
{
    // 就是要构建一个双向列表
    
    // 当前节点
    ListNode* pCurrNodel = head;
    // 当前节点前一个节点
    ListNode* pPreviewNodel = nullptr;
    // 当前节点的后一个节点
    ListNode* pNextNodel = nullptr;
    // 尾部节点
    ListNode* pTrailNodel = nullptr;
    
    while (pCurrNodel) {
        
        // 先保存下一步的节点
        pNextNodel = pCurrNodel->next;
        if (!pNextNodel) {
            pTrailNodel = pCurrNodel;
        }
        
        // 没有找到尾部，翻转指针
        pCurrNodel->next = pPreviewNodel;
        pPreviewNodel = pCurrNodel;
        pCurrNodel = pNextNodel;
    }
    
    return pTrailNodel;
}


ListNode* reverseList_dfs(ListNode* head)
{
    //如果链表为空或者链表中只有一个元素
    if(!head || !head->next) {
        return head;
    } else {
        //先反转后面的链表，走到链表的末端结点
        ListNode *newhead = reverseList(head->next);
        //再将当前节点设置为后面节点的后续节点
        head->next->next = head;
        head->next = nullptr;
        
        return newhead;
    }
}
