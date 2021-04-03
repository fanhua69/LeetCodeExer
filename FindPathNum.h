
#include "headers.h"

class Solution
{
    public:
        int FindPathNum(vector<vector<int>> &m, int i, int j)
        {
            if( i == m.size()- 1 && j == m[0].size())
            {
                return 1;
            }

            if(i<0 || i >= m.size() || j < 0 || j >= m[0].size())
            {
                return 0;
            }

            if(m[i][j] == 0)
            {
                return 0;
            }

            return FindPathNum(m, i + 1, j) + FindPathNum(m, i, j + 1);
        }

        int FindPathNum(vector<vector<int>> &m)
        {
            return FindPathNum(m, 0, 0);
        }
};
