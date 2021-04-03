
#include "headers.h"

class Solution
{
public:
    string reverseWords(string s)
    {
        stack <string> r;
        string word;
        for (int i = 0; i < s.size();i++)
        {
            if(s[i] == ' ')
            {
                if(!word.empty())
                {
                    r.push(word);
                    word.clear();
                }
            }
            else
            {
                word.push_back(s[i]);
            }
        }

        if(!word.empty())
        {
            r.push(word);
        }

        string re;
        while(!r.empty())
        {
            re+=r.top();
            r.pop();
            if(!r.empty())
            {
                re += " ";
            }
        }

        return re;
    }
};

