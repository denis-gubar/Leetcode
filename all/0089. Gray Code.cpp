class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n);
        for (int i = 1, x = 0; i < (1 << n); ++i)
        {            
            x ^= i ^ (i & (i - 1));
            result[i] = x;
        }
        return result;
    }
};
