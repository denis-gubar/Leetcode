class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int N = s.size();
        if (N < k || k > 26)
            return 0;
        int result = 0;
        vector<int> A(26);
        int distinctCount = 0;
        for (int i = 0; i < N; ++i)
        {
            int j = s[i] - 'a';
            ++A[j];
            if (A[j] == 1)
                ++distinctCount;
            else if (A[j] == 2)
                --distinctCount;
            if (i >= k)
            {
                j = s[i - k] - 'a';
                --A[j];
				if (A[j] == 1)
					++distinctCount;
				else if (A[j] == 0)
					--distinctCount;
            }
            result += distinctCount == k;
        }
        return result;
    }
};
