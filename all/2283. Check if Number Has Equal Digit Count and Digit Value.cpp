class Solution {
public:
    bool digitCount(string num) {
        vector<int> M(10);
        int N = num.size();
        for (char c : num)
            ++M[c - '0'];
        for (int i = 0; i < N; ++i)
            if (M[i] != num[i] - '0')
                return false;
        return true;
    }
};
