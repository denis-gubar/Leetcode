class Solution {
public:
    long long findScore(vector<int>& nums) {
        int N = nums.size();
        nums.push_back(0);
        long long result = 0;
        set<pair<int, int>> S;
        for (int i = 0; i < N; ++i)
            S.insert({ nums[i], i });
        while (!S.empty())
        {
            pair<int, int> P = *S.begin();
            int const& score = P.first;
            int const& pos = P.second;
            S.erase(S.begin());
            result += score;
            nums[pos] = 0;
            if (pos > 0 && nums[pos - 1] > 0)
            {
                S.erase(S.find({ nums[pos - 1], pos - 1 }));
                nums[pos - 1] = 0;
            }
            if (nums[pos + 1] > 0)
            {
                S.erase(S.find({ nums[pos + 1], pos + 1 }));
                nums[pos + 1] = 0;
            }
        }
        return result;
    }
};
