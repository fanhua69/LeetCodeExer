

#include "headers.h"

int myAtoi(string s)
{
    int sign = 1;
    int result = 0;

    int i = 0;
    while (s[i++] == ' ');

    if(s[i] == '-' || s[i] == '+')
    {
        sign = (s[i++] == '+') ? 1 : -1;
    }

    while(s[i] >= '0' && s[i] <= '9')
    {
        if(result > INT_MAX / 10 || (result == INT_MAX/10 && s[i] > INT_MAX %10))
        {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        result *= 10;
        result += s[i++]-'0';
    }

    return result * sign;
};