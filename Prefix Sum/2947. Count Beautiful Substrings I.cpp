static string const vowels = "aeiou";
class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int result = 0;
        int N = s.size();
        int B = 0;
        int K = 1;
        for (K = 1; K <= k; ++K)
            if (K * K % k == 0)
                break;
        K += K;
        vector<unordered_map<int, int>> M(K);
        ++M[K - 1][0];
        for (int i = 0; i < N; ++i)
        {
            bool isVowel = vowels.find(s[i]) != string::npos;
            B += (isVowel * 2) - 1;
            ++M[i % K][B];
        }
        for (int i = 0; i < K; ++i)
            for (auto [key, value] : M[i])
                result += 1LL * value * (value - 1) / 2;
        return result;
    }
};
