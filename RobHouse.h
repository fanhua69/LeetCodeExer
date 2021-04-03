
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

        int rob2(vector<int> &nums)
        {
            if(nums.size() == 1)
            {
                return nums[0];
            }

            if(nums.size() ==2 )
            {
                return std::max(nums[0], nums[0]);
            }

            vector<int> maxes(nums.size() + 1, 0);

            maxes[0] = nums[0];
            maxes[1] = nums[1];
            maxes[2] = nums[2] + nums[0];
            for (int i = 3; i < nums.size(); i++)
            {
                maxes[i] = std::max(nums[i] + maxes[i - 2], maxes[i - 1]);
            }

            return maxes[nums.size()-1];
        }
};