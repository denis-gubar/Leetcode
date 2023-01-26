class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
        for (int z = 0; z < 30; ++z)
        {
            vector<int> A(2);
            for (int x : nums)
                ++A[(x & (1 << z)) > 0];
            int x = 0;
            for(int i = 0; i < 2; ++i)
                if (A[i] > 0)
                    for(int j = 0; j < 2; ++j)
                        if (A[j] > 0)
                            for(int k = 0; k < 2; ++k)
                                if (A[k] > 0)
                                {
                                    if ((A[i] % 2) * (A[j] % 2) * (A[k] % 2) > 0 &&
                                        ((i | j) & k) > 0)
                                        result |= 1 << z;
                                }
        }
        return result;
    }
};
