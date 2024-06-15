class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> M;
        for (char c : word)
            ++M[c];
        vector<int> A;
        for (auto [key, value] : M)
            A.push_back(value);
        sort(A.begin(), A.end());
        if (A[0] + k >= A.back())
            return 0;
        int N = word.size();
        int result = N;
        for (int i = A[0]; i <= A.back() - k; ++i)
        {
            int current = 0;
            for (int x : A)
                current += (x < i) * x + max(0, x - i - k);
            result = min(result, current);
        }
        return result;
    }
};
