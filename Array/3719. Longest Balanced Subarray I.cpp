class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int const N = nums.size();
        int result = 0;
        for (int start = 0; start < N; ++start)
        {
            unordered_map<int, int> M;
            vector<int> count(2);
            for (int length = 1; start + length <= N; ++length)
            {
                int const& x = nums[start + length - 1];
                if (++M[x] == 1)
                    ++count[x % 2];
                if (count[0] == count[1] && result < length)
                    result = length;
            }
        }
        return result;
    }
};
