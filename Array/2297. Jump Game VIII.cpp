static int nextMax[100'000];
static int nextMin[100'000];
static long long F[100'001];
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int const N = nums.size();
        costs.push_back(0);
        stack<int> sMax, sMin;
        for (int i = N - 1; i >= 0; --i)
        {
            while (!sMax.empty() && nums[sMax.top()] < nums[i])
                sMax.pop();
            nextMax[i] = sMax.empty() ? N : sMax.top();
            sMax.push(i);
            while (!sMin.empty() && nums[sMin.top()] >= nums[i])
                sMin.pop();
            nextMin[i] = sMin.empty() ? N : sMin.top();
            sMin.push(i);
        }
        memset(F, 1, sizeof(F));
        F[0] = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            F[i + 1] = min(F[i + 1], F[i] + costs[i + 1]);
            int ni = N;
            if (nums[i + 1] < nums[i])
                ni = nextMax[i];
            else
                ni = nextMin[i];
            F[ni] = min(F[ni], F[i] + costs[ni]);
        }
        return F[N - 1];
    }
};
