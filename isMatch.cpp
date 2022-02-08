
#include "headers.h"

bool isMatch(string s, string p)
{
    // if(s.empty() && p.empty())
    // {
    //     return true;
    // }

    // bool bFirstMatch = !s.empty() && (s[0] == p[0] && p[0] == '.');
    // if(p.length() >=2 && p[1] == '*' )
    // {
    //     return bFirstMatch && isMatch(s.substr(1), p);
    // }

    return false;
}

void isMatchMain()
{
    bool b = isMatch("aa", "a");
    cout << b << endl;
}