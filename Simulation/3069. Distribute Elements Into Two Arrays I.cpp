class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> result, A, B;
        for (int x : nums)
        {
            if (A.empty())
                A.push_back(x);
            else if (B.empty())
                B.push_back(x);
            else if (A.back() > B.back())
                A.push_back(x);
            else
                B.push_back(x);
        }
        copy(A.begin(), A.end(), back_inserter(result));
        copy(B.begin(), B.end(), back_inserter(result));
        return result;
    }
};
