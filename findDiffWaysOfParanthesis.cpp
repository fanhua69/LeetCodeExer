
#include "headers.h"

int calc(int d1,char o, int d2)
{
    int n = 0;
    if(o == '+')
    {
        n = d1+d2;
    }
    else if(o == '-')
    {
        n = d1 - d2;
    }
    else 
    {
        n = d1*d2;
    }
    return n;
}
    
vector<int> diffWaysToCompute(string expression) 
{
    vector<int> r;

    if(std::all_of(expression.begin(),expression.end(),[](char c)->bool{return std::isdigit(c);}))
    {
        int n = std::stoi(expression);
        r.push_back(n);
        return r;
    }

    vector<pair<int,char>> os;
    int i = 0;
    for(char c : expression)
    {
        if(!isdigit(c))
        {
            os.push_back(make_pair(i, c));
        }
        i++;
    }

    for (int i = 0; i < os.size();i++)
    {
        string sLeft = expression.substr(0, os[i].first);
        string sRight = expression.substr(os[i].first + 1);
        vector<int> left = diffWaysToCompute(sLeft);
        vector<int> right = diffWaysToCompute(sRight);
        for (int j = 0;  j<left.size(); j++)
        {
            for (int k = 0; k < right.size();k++)
            {
                r.push_back(calc(left[j], os[i].second, right[k]));
            }
        }
    }
    
    return r;
}

void diffWaysToComputeMain()
{

    vector<int> r = diffWaysToCompute("1+2*3+4");
    for(int a: r)
    {
        cout << a << endl;
    }
}