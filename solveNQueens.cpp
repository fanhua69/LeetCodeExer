
#include "headers.h"

class CLocation
{
public:
    int row;
    int col;
    CLocation(int r, int c)
    {
        row = r;
        col = c;
    }
};

void solveQueens(int n,
                 vector<vector<CLocation>> &all,
                 vector<CLocation> s,
                 int r,
                 int c)
{
    if (r >= n || c >= n )
    {
        return;
    }

    bool valid = true;
    for (int a = 0; a < s.size(); a++)
    {
        int ra = s[a].row;
        int ca = s[a].col;
        if (ra == r || ca == c || abs(ra - r) == abs(ca - c))
        {
            valid = false;
            break;
        }
    }

    if (c < n - 1)
    {
        solveQueens(n, all, s, r, ++c);
    }

    if (valid)
    {
        s.push_back(CLocation(r, c));
        solveQueens(n, all, s, ++r, 0);
    }

    return;
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<CLocation>> rv;
    vector<CLocation> s;
    solveQueens(n, rv, s, 0, 0);

    vector<vector<string>> rr;
    for (int i = 0; i < rv.size(); i++)
    {
        vector<string> rr1;
        for (int j = 0; j < rv[i].size(); j++)
        {
            string s(n, '.');
            s[rv[i][j].col] = 'Q';
            rr1.push_back(s);
        }
        rr.push_back(rr1);
    }

    return rr;
}

void solveNQueensMain()
{
    vector<vector<string>> v = solveNQueens(4);
    for (int i = 0; i < v.size(); i++)
    {
        cout << "Solution:" << i << endl;
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << endl;
        }
    }
}