class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(N, -1);
        set<pair<int, int>> S1, S2;
        for (int i = 0; i < N; ++i)
        {
            while (!S2.empty() && S2.begin()->first < nums[i])
            {
                int j = S2.begin()->second;
                S2.erase(S2.begin());
                result[j] = nums[i];
            }
            while (!S1.empty() && S1.begin()->first < nums[i])
            {
                pair<int, int> P = *S1.begin();
                S1.erase(S1.begin());
                S2.insert(P);
            }
            S1.insert({ nums[i], i });
        }
        return result;
    }
};
