class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int result = -1;
        unordered_map<int, vector<int>> M;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
            M[nums[i]].push_back(i);
        for(auto const& [key, value]: M)
            if (value.size() > 2)
            {
                int const N = value.size();
                for (int i = 0; i + 2 < N; ++i)
                {
                    int current = abs(value[i] - value[i + 1]) + abs(value[i + 1] - value[i + 2]) + abs(value[i] - value[i + 2]);
                    if (result == -1 || result > current)
                        result = current;
                }
            }
        return result;
    }
};
