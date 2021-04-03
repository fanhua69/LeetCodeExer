
#include "maxProduct.h"

void CMaxProduct::maxProduct(vector<int> &nums, int i)
{
    if (i == 0)
    {
        maxp[0] = nums[0];
        maxn[0] = nums[0];
        return;
    }

    maxp[i] = std::max(nums[i], nums[i] * maxp[i-1]);
    maxp[i] = std::max(maxp[i], nums[i] * maxn[i-1]);
    maxn[i] = std::min(nums[i], nums[i] * maxp[i-1]);
    maxn[i] = std::min(maxn[i], nums[i] * maxn[i - 1]);
}

int CMaxProduct::maxProduct(vector<int> &nums)
{
    if (nums.size() < 1)
    {
        return 0;
    }

    maxp.resize(nums.size(), 0);
    maxn.resize(nums.size(), 0);
    for (int i = 0; i < nums.size(); i++)
    {
        maxProduct(nums, i);
    }

    int m = maxp[0];
    for (int i = 0; i < maxp.size(); i++)
    {
        m = std::max(m, maxp[i]);
    }

    return m;
}