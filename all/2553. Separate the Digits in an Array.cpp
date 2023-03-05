class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;
        for (int k : nums)
        {
            int x = k;
            vector<int> A;
            if (x == 0)
                A.push_back(x);
            while (x > 0)
            {
                A.push_back(x % 10);
                x /= 10;
            }
            reverse(A.begin(), A.end());
            copy(A.begin(), A.end(), back_inserter(result));
        }
        return result;
    }
};
