class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int result = 1'000;
        for (vector<int> const& task : tasks)
        {
            int const& S = task[0];
            int const& T = task[1];
            result = min(result, S + T);
        }
        return result;
    }
};
