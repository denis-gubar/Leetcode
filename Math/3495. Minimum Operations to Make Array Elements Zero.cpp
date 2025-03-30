class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long result = 0;
        for (vector<int> const& q : queries)
        {
            int L = q[0];
            int const& R = q[1];
            int x = 1;
            int count = 1;
            while (x < L)
                x <<= 2, ++count;
            long long current = 0;
            while (x <= R)
            {
                current += static_cast<long long>(x - L) * (count - 1);
                L = x;
                x <<= 2, ++count;
            }
            current += static_cast<long long>(R - L + 1) * (count - 1);
            result += (current + 1) / 2;
        }
        return result;
    }
};
