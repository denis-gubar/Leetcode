class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int N = s.size();
        for(vector<int> const& currentShift: shift)
        {
            int const& direction = currentShift[0];
            int step = currentShift[1];
            if (direction == 1)
                step = N - step;
            step %= N;
            if (step)
                rotate(s.begin(), s.begin() + step, s.end());
        }
        return s;
    }
};