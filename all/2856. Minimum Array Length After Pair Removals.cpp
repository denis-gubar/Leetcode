class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int N = nums.size();
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        priority_queue<int> PQ;
        for (auto [key, value] : M)
            PQ.emplace(value);
        int x = PQ.top();
        return max(N % 2, N - (N - x) * 2);
    }
};
