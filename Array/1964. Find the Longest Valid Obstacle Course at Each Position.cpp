class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int const N = obstacles.size();
        vector<int> result;
        vector<int> M;
        M.reserve(N);
        result.reserve(N);
        for (int x : obstacles)
        {
            auto it = upper_bound(M.begin(), M.end(), x);
            result.push_back((it - M.begin()) + 1);
            if (it == M.end())
                M.push_back(x);
            else
                *it = x;
        }
        return result;
    }
};
