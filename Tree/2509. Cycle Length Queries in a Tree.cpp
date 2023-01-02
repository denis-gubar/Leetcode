class Solution {
public:
    vector<int> cycleLengthQueries(int N, vector<vector<int>>& queries) {
        vector<int> result;
        for (vector<int> const& q : queries)
        {
            int A = q[0];
            int B = q[1];
            result.push_back(1);
            while (A != B)
            {
                if (A < B)
                    B /= 2;
                else
                    A /= 2;
                ++result.back();
            }
        }
        return result;
    }
};
