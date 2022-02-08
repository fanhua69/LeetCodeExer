
#include "FindMinimumDuplicatedRotatedArray.h"

int SolutionDup::findMin(vector<int> &nums, int i, int j)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    if (j == i)
    {
        return nums[i];
    }

    if (j == i + 1)
    {
        return std::min(nums[j], nums[i]);
    }

    int m = (i + j) / 2;
    if (nums[i] <= nums[m] && nums[m] <= nums[j])
    {
        return std::min(findMin(nums, i, m), findMin(nums, m, j));
    }
    else if (nums[i] <= nums[m])
    {
        return findMin(nums, m, j);
    }
    else
    {
        return findMin(nums, i, m);
    }
}

int SolutionDup::findMin(vector<int> &nums)
{
    return findMin(nums, 0, nums.size() - 1);
}