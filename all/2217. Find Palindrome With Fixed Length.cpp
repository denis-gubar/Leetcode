class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int N = queries.size();
        vector<long long> result(N, -1);
        vector<long long> D(16);
        D[0] = 1;
        for (int i = 1; i < 16; ++i)
            D[i] = D[i - 1] * 10;
        for (int i = 0; i < N; ++i)
        {
            int q = queries[i];
            int k = (intLength + 1) / 2;
            long long prefix = D[k - 1] + q - 1;
            if (prefix >= D[k])
                continue;
            string t(to_string(prefix));
			string s(t);
			reverse(s.begin(), s.end());
            if (intLength % 2 == 1)
                t.pop_back();
            t += s;
            result[i] = stoll(t);
        }
        return result;
    }
};
