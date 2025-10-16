class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int K) {
        int const N = nums.size();
        for (int j = -1; j < 2; j += 2)
        {
            vector<int> A = nums;
            int count = 0;
            for (int i = 1; i < N; ++i)
                if (A[i - 1] != j)
                    A[i - 1] = -A[i - 1], A[i] = -A[i], ++count;
            if (count <= K && A[N - 1] == j)
                return true;
        }
        return false;
    }
};
