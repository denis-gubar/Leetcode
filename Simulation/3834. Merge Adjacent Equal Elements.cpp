class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long> result;
        int const N = nums.size();
        result.reserve(N);
        for (int x : nums)
        {
            result.push_back(x);
            int N = result.size();
            while (N > 1)
            {
                if (result.back() == result[N - 2])
                    result.pop_back(), result.back() *= 2, --N;
                else
                    break;
            }
        }
        return result;
    }
};
