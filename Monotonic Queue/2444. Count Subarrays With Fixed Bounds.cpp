class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int N = nums.size();        
        deque<int> maxPos, minPos;
        int a = -1, b = 0;
        while (b < N)
        {
            if (nums[b] == minK)
                minPos.push_back(b);
            if (nums[b] == maxK)
                maxPos.push_back(b);
            if (nums[b] >= minK && nums[b] <= maxK)
            {
                if (a == -1)
                    a = b;
                while (!maxPos.empty() && !minPos.empty())
                {
                    int x = min(maxPos.front(), minPos.front());
                    if (maxPos.back() < x && minPos.back() < x)
                    {
                        if (maxPos.front() == x)
                            maxPos.pop_front();
                        if (minPos.front() == x)
                            minPos.pop_front();
                    }
                    else
                        break;
                }
                if (!maxPos.empty() && !minPos.empty())
                {
                    int x = min(maxPos.back(), minPos.back());
                    result += x - a + 1;
                }
            }
            else
            {
                a = -1;
                minPos.clear();
                maxPos.clear();
            }
            ++b;
        }
        return result;
    }
};
