//
//  GPStack.hpp
//  LeetCode
//
//  Created by fair wu on 2019/7/6.
//  Copyright © 2019 fair wu. All rights reserved.
//

#ifndef GPStack_hpp
#define GPStack_hpp

#include <stdio.h>
#include <stack>

/*
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 
 push(x) -- 将元素 x 推入栈中。
 pop() -- 删除栈顶的元素。
 top() -- 获取栈顶元素。
 getMin() -- 检索栈中的最小元素。
 示例:
 
 MinStack minStack = new MinStack();
 minStack.push(-2);
 minStack.push(0);
 minStack.push(-3);
 minStack.getMin();   --> 返回 -3.
 minStack.pop();
 minStack.top();      --> 返回 0.
 minStack.getMin();   --> 返回 -2.
 
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st_.push(x);
        
        //
        // 这里有可能里面没有一个节点，所以要判断一下，为空直接添加
        // 如果是小于，那么就要插入进去；
        //
        if(minst_.empty() || x <= minst_.top())   {
            minst_.push(x);
        }
    }
    
    void pop() {
        
        // 先判断两个是否相等；
        if(st_.top() == minst_.top()) {
            // 相等，就将_minst，删除；
            minst_.pop();
        }
        
        // st_它是每一次都要删；
        st_.pop();
    }
    
    int top() {
        return st_.top();
    }
    
    int getMin() {
        return minst_.top();
    }
    
private:
    std::stack<int> st_;
    std::stack<int> minst_;
};

#endif /* GPStack_hpp */
