class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int const N = nums.size();
        vector<int> inv(N + 1);
        for (int i = 0; i < N; ++i)
            inv[nums[i]] = i;
        for (vector<int> const& seq : sequences)
        {
            int pos = -1;
            for (int x : seq)
            {
                if (inv[x] <= pos)
                    return false;
                pos = inv[x];
            }
        }
        vector<bool> A(N);
        int count = 0;
        for (vector<int> const& seq : sequences)
        {
            int pos = -2;
            for (int x : seq)
            {
                if (inv[x] == pos + 1)
                    if (!A[pos + 1])
                        A[pos + 1] = true, ++count;
                pos = inv[x];
            }
        }
        return count + 1 == N;
    }
};
