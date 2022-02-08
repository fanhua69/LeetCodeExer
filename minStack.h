

#include "headers.h"


class MinStack
{
public:
    /** initialize your data structure here. */
    std::vector<pair<int,int>> m_vData;

    MinStack();
    void push(int val);
    void pop();
    int top();
    int getMin();
};
