class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> result(nums);
        auto calc = [&mapping](int a)
        {
            long long result = 0;
            string t(to_string(a));
            string s;
            for (char d : t)
                s += '0' + mapping[d - '0'];
            result = stoll(s);
            return result;
        };
        int N = nums.size();
        unordered_map<int, long long> M(N);
        for (int i = 0; i < N; ++i)
            M[nums[i]] = calc(nums[i]);
        stable_sort(result.begin(), result.end(), [&M](int a, int b)
            {
                return M[a] < M[b];
            });
        return result;
    }
};
