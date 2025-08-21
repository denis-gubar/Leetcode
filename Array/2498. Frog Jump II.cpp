class Solution {
public:
    int maxJump(vector<int>& stones) {
        stones.push_back(stones.back());
        int const N = stones.size();
        vector<int> result(2, -1);
        for (int i = 2; i < N; ++i)
            result[i % 2] = max(result[i % 2], stones[i] - stones[i - 2]);
        if (min(result[0], result[1]) < 0)
            return stones.back();
        return max(result[0], result[1]);
    }
};
