
#include "headers.h"

class Solution
{
    public:
        vector<int> m_vMaxes;
        int findMax(vector<int> &nums, int i)
        {
            if(m_vMaxes[i] != -1)
            {
                return m_vMaxes[i];
            }

            if(i == 0)
            {
                return nums[i];
            }

            if(i == 1)
            {
                return std::max(nums[0], nums[1]);
            }

            int a = nums[i] + findMax(nums, i-2);
            int b = findMax(nums, i - 1);

            m_vMaxes[i] = std::max(a, b);
            return m_vMaxes[i];
        }

        int rob(vector<int> &nums)
        {
            int max = 0;
            m_vMaxes.resize(nums.size(), -1);
            return findMax(nums, nums.size() - 1);
        }
};