class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> A(2'001);
        for (int i = 0; i < N; ++i)
            A[nums[i]].push_back(i);
        int result = 0;
        unordered_set<int> S(nums.begin(), nums.end());
        int K = S.size();
        int current = 0;
        int a = 0, b = 0;
        while (b < N)
        {
            current += A[nums[b]][0] == b;
            ++b;
            if (current == K)
                break;
        }        
        while (true)
        {
            result += N - b + 1;
            int x = nums[a];
            auto it = upper_bound(A[x].begin(), A[x].end(), a);
            if (it == A[x].end())
                break;
            ++a;
            b = max(b, *it + 1);
        }
        return result;
    }
};
