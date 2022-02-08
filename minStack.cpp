


#include "minStack.h"

MinStack::MinStack()
{
}

void MinStack::push(int val)
{
    int iMin = val;
    if (m_vData.size() > 0)
    {
        iMin = std::min((m_vData.end() - 1)->second,val);
    }
    m_vData.push_back(std::make_pair(val,iMin));
}

void MinStack::pop()
{
    if (m_vData.size() > 0)
    {
        m_vData.erase(m_vData.end() - 1);
    }
}

int MinStack::top()
{
    if (m_vData.size() > 0)
    {
        return ((m_vData.end() - 1)->first);
    }
    return -1;
}

int MinStack::getMin()
{
    if(m_vData.size() > 0)
    {
        return (m_vData.end() - 1)->second;
    }
    return 0;
}