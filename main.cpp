
#include "headers.h"
#include "FunctionHeaders.h"
#include "FindPathNum.h"
#include "maxProduct.h"

void MaxProductMain()
{
    vector<int> a({-1, -2, -9, -6});
    CMaxProduct s;
    int N = s.maxProduct(a);
    cout << N << endl;
}

void FindPathNumMain()
{
    vector<int> a({1, 1, 1});
    vector<int> b({1, 1, 1});
    vector<int> c({1, 0, 1});
    vector<vector<int>> m({a, b, c});
    Solution s;
    int N = s.FindPathNum(m);
    cout << "Path:" << N << endl;
}

void pause()
{
    cout << "Paused, Press any key to continue..." << endl;
    char pause;
    cin >> pause;
}

int main()
{
    MaxProductMain();
}
