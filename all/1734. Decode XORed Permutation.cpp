class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int N = encoded.size();
        vector<int> result(N + 1);
        for (int i = N + 1; i > 0; --i)
            result[0] ^= i;
        for (int i = N - 1; i > 0; i -= 2)
            result[0] ^= encoded[i];
        for (int i = 0; i < N; ++i)
            result[i + 1] = result[i] ^ encoded[i];
        return result;
    }
};
