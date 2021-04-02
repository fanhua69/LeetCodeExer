
#include "ZigZagConversion.h"

CZigZagConversion::CZigZagConversion()
{

}

string CZigZagConversion::convert(string s, int numRows)
{
    std::vector<string> vReturn(numRows);
    int iRow = 0;
    int nDirection = 1;
    for (int i = 0; i < s.size(); i++)
    {
        vReturn[iRow].push_back(s[i]);
        if(numRows==1)
        {
            nDirection = 0;
        }
        else
        {
            if (iRow == numRows - 1)
            {
                nDirection = -1;
            }
            if (iRow == 0)
            {
                nDirection = 1;
            }
        }

        iRow += nDirection;
    }

    string sOut;
    for (int i = 0; i < vReturn.size();i++)
    {
        sOut += vReturn[i];
    }

    return sOut;
}

void ZigZagConverionMain()
{
    CZigZagConversion c;
    string s = c.convert("PAYPALISHIRING", 1);
    cout << s << endl;
}