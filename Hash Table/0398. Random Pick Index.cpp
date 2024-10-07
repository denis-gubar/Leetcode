class Solution {
public:
    random_device rd;
    mt19937 gen;
    unordered_map<int, vector<int>> M;
    Solution(vector<int>& nums): gen(mt19937(rd())) {
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
            M[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        vector<int> const& V = M[target];
        uniform_int_distribution<int> distribution(0, V.size() - 1);
        return V[distribution(gen)];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
