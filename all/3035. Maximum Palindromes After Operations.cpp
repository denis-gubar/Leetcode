class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int result = 0;
        int N = words.size();
        vector<int> M(26);
        vector<int> A(2);
        vector<int> L;
        for (int i = 0; i < N; ++i)
        {
            for (char c : words[i])
                ++M[c - 'a'];
            int x = words[i].size();            
            L.push_back(x);
        }
        for (int x : M)
        {
            if (x % 2 == 1)
                ++A[1];
            A[0] += x / 2 * 2;
        }
        sort(L.begin(), L.end());
        for(int length : L)
        {
            if (length % 2 == 1 && A[1] > 0 && length - 1 <= A[0])
                --A[1], A[0] -= length - 1, ++result;
            else if (length % 2 == 1 && A[1] == 0 && length <= A[0])
                A[0] -= length, ++result;
            if (length % 2 == 0 && length <= A[0])
                A[0] -= length, ++result;
        }
        return result;
    }
};
