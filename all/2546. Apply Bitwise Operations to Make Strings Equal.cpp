class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int N = s.size();
        int zero = 0, one = 0;
        for (char c : s)
            if (c == '0')
                ++zero;
            else
                ++one;
        int zeroTarget = 0, oneTarget = 0;
        for (char c : target)
            if (c == '0')
                ++zeroTarget;
            else
                ++oneTarget;
        if (one == 0)
            return oneTarget == 0;
        return oneTarget > 0;
    }
};
