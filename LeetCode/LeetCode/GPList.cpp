//
//  GPList.cpp
//  LeetCode
//
//  Created by fair wu on 2019/6/30.
//  Copyright © 2019 fair wu. All rights reserved.
//

#include "GPList.hpp"
#include <queue>

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

/*
 两数相加
 
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 
 示例：
 
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 https://www.jianshu.com/p/380936bd91fa
 */

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    // l1或者l2为空时，直接返回另一者。
    if (l1 == nullptr) {
        return l2;
    }
    
    if (l2 == nullptr) {
        return l1;
    }
    
    /*
     * 最开始：rs和out共用一个地址， 过程：不断操作rs，rs每次都是一个新的结点。在修改链表时，只修改rs这条链，
     * 最终：将链表结果传给out，out返回head则自动返回所有。 如果不声明rs，直接不断改变out，结果将不会返回一长链。
     */
    ListNode* out = new ListNode(0);
    // 初始化时，l1和l2的头结点分别赋值给p，q。后期不断修改rs
    ListNode *p = l1, *q = l2, *rs = out;
    // 进位 该位上和
    int carry = 0, sum = 0;
    while (p != nullptr || q != nullptr) {
        // l1和l2长度不一时，遍历p和q，可以使用三元运算符返回各自的x和y。
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        sum = x + y + carry;
        if (sum < 10) {
            //  8时，没有进位，不加0的话carry被认为1
            carry = 0;
            // rs存储值
            rs->next = new ListNode(sum % 10);
            rs = rs->next;
        } else {
            // 进位最多为1，9+9+1=19
            carry = 1;
            rs->next = new ListNode(sum % 10);
            rs = rs->next;
        }
        
        // 继续下一个，一个节点存储一位数字。
        if (p != nullptr) {
            p = p->next;
        }
        
        if (q != nullptr) {
            q = q->next;
        }
    }
    
    // 运行到最高位时，如果有进位，需要在加一个节点
    if (carry > 0) {
        rs->next = new ListNode(carry);
    }
    
    return out->next;
}


/*
 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 
 示例:
 
 输入:
 [
 1->4->5,
 1->3->4,
 2->6
 ]
 输出: 1->1->2->3->4->4->5->6
 
 */

struct cmp
{
    bool operator()(ListNode* l1,ListNode* l2) const {
        return l1->val > l2->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    std::priority_queue<ListNode*,std::vector<ListNode*>,cmp> pq;
    
    // 构建最小堆
    for(int i=0; i<lists.size(); ++i) {
        if(lists[i]) {
            pq.push(lists[i]);
        }
    }
    
    ListNode* ans = new ListNode(0);
    ListNode* temp = ans;
    while(!pq.empty()) {
        
        temp->next = pq.top();
        temp = temp->next;
        pq.pop();
        
        if(temp->next) {
            pq.push(temp->next);
        }
    }
    
    return ans->next;
}

/*
 最大子序和
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 
 示例:
 
 输入: [-2,1,-3,4,-1,2,1,-5,4],
 输出: 6
 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 进阶:
 
 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 
 */

int maxSubArray(std::vector<int>& nums)
{
    int current = nums[0];
    int sum = nums[0];
    
    //
    // 我们考虑如果全是负数，那么返回最大的负数，
    // 如果最后的和为正，那么就使用扫描法
    //
    for(int i=1 ; i<nums.size(); ++i) {
        
        //当前数小于0 肯定会舍去（否则将会影响接下来的和），换为下一个数
        if(current <= 0) {
            current = nums[i];
        } else {
            //如果当前数不小于0，那么他会对接下来的和有积极影响
            current += nums[i];
        }
        
        //
        // 这里既实现了负数返回最大也实现了扫描法
        // 这里其实已经隐式的列举了所有可能，保留了所有可能的最大值
        //
        if(current > sum) {
            sum = current;
        }
    }
    
    return sum;
}
