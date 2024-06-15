class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int N = nums.size();
        vector<long long> result(N);
        unordered_map<int, long long> M;
        set<pair<long long, int>> S;
        for (int i = 0; i < N; ++i)
        {
            if (M.find(nums[i]) != M.end())
                S.erase({ -M[nums[i]], nums[i] });
            M[nums[i]] += freq[i];
            if (M[nums[i]] == 0)
                M.erase(nums[i]);
            else
                S.emplace(-M[nums[i]], nums[i]);
            if (!S.empty())
                result[i] = -S.begin()->first;
        }
        return result;
    }
};
