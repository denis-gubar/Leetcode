class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int N = nums.size();
        int result = N / 2;
        unordered_map<int, vector<int>> M;
        for (int i = 0; i < N; ++i)
            M[nums[i]].push_back(i);
        for (auto& [key, value] : M)
        {
            if (value.size() == 1)
                continue;
            int current = 0;
            int V = value.size();
            for (int i = 0; i < V; ++i)
                current = max(current, 
                    min((value[(i - 1 + V) % V] - value[i] + N) % N , 
                        (value[(i + 1) % V] - value[i] + N) % N) / 2);
            result = min(result, current);
        }
        return result;
    }
};
