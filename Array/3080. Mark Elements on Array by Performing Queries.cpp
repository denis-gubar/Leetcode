class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size(), Q = queries.size();
        long long total = 0;
        set<pair<int, int>> S;
        vector<bool> visited(N);
        for (int i = 0; i < N; ++i)
        {
            total += nums[i];
            S.emplace(nums[i], i);
        }
        auto remove = [&total, &nums, &S, &visited](int index)
            {
                total -= nums[index];
                visited[index] = true;
                S.erase(S.find({ nums[index], index }));
            };
        vector<long long> result(Q);
        for (int q = 0; q < Q; ++q)
        {
            int const& index = queries[q][0];
            int const& k = queries[q][1];
            if (!visited[index])
                remove(index);
            for (int j = 0, e = min<int>(k, S.size()); j < e; ++j)
                remove(S.begin()->second);
            result[q] = total;
        }
        return result;
    }
};
