class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int N = nums.size();
        vector<bool> visited(k + 1);
        int total = k;
        int result = 0;
        while (total > 0)
        {
            ++result;
            int x = nums.back(); nums.pop_back();
            if (x <= k && !visited[x])
            {
                visited[x] = true; --total;
            }
        }
        return result;
    }
};
