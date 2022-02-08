
#include "headers.h"
#include "FunctionHeaders.h"
#include "FindPathNum.h"
#include "maxProduct.h"
#include "FindMinimumDuplicatedRotatedArray.h"
#include "BinaryTreeUpsideDown.h"
void diffWaysToComputeMain();
void solveNQueensMain();
void treeToDoublyListMain();

void pause()
{
    cout << "Paused, Press any key to continue..." << endl;
    char pause;
    cin >> pause;
}

class tt
{
    public:
    tt(int aa, int bb)
    {
        a = aa;
        b = bb;
    }

    int a;
    int b;
};
//template <class T >
class myless
{
public:
    myless(int a, int b)
    {}
    // bool operator()(const T &l, const T &r)
    // {
    //     return l < r;
    // }
};

void kkk();

int main()
{
    kkk();
    myless{1, 2};

    treeToDoublyListMain();
}