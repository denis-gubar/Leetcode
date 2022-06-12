class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int result = 0;
        int N = brackets.size();
        int prev = 0;
        for (int i = 0; income > 0 && i < N; ++i)
        {
            int const& upper = brackets[i][0];
            int const& percent = brackets[i][1];
            int delta = min(upper - prev, income);
            income -= delta;
            result += delta * percent;
            prev = upper;
        }        
        return result * 0.01;
    }
};
