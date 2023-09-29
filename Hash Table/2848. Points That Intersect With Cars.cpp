class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int result = 0;
        vector<bool> visited(101);
        for (vector<int> const& n : nums)
        {
            int const& start = n[0];
            int const& end = n[1];
            for (int i = start; i <= end; ++i)
                visited[i] = true;
        }
        for (int i = 0; i <= 100; ++i)
            result += visited[i];
        return result;
    }
};
