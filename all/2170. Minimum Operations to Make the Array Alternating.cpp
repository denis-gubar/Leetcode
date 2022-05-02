class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int N = nums.size();
        if (N < 2)
            return 0;
        int result = N;
        unordered_map<int, int> odd, even;
        for (int i = 0; i < N; ++i)
            if (i % 2 == 0)
                ++even[nums[i]];
            else
                ++odd[nums[i]];
        vector<pair<int, int>> A, B;
        for (auto [key, value] : odd)
            A.push_back({ value, key });
		for (auto [key, value] : even)
			B.push_back({ value, key });
        int y = N / 2;
        int x = N - y;
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        sort(B.begin(), B.end());
        reverse(B.begin(), B.end());
        if (A.size() > 2)
            A.resize(2);
        if (B.size() > 2)
            B.resize(2);
        for (auto pa : A)
            for (auto pb : B)
                if (pa.second != pb.second)
                    result = min(result, x - pa.first + y - pb.first);
        if (A.size() == B.size() && A.size() == 1 && A[0].second == B[0].second)
            result = y;
        return result;
    }
};
