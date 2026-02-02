class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int K) {
        int const N = nums.size();
        vector<int> A;
        A.reserve(N);
        for (int x : nums)
            if (x >= 0)
                A.push_back(x);
        if (A.empty())
            return nums;
        int const M = A.size();
        rotate(A.begin(), A.begin() + K % M, A.end());
        reverse(A.begin(), A.end());
        for (int& x : nums)
            if (x >= 0)
                x = A.back(), A.pop_back();
        return nums;
    }
};
