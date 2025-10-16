class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long result = 1LL << 40;
        int N = beans.size();
        sort(beans.begin(), beans.end());
        vector<int> A(beans);
        vector<long long> P(N + 1);
        for (int i = 0; i < N; ++i)
            P[i + 1] = P[i] + beans[i];
        A.resize(unique(A.begin(), A.end()) - A.begin());
        int pos = 0;
        long long total = 0;
        for (int x : A)
        {
            while (pos < N && beans[pos] < x)
            {
                total += beans[pos];
                ++pos;
            }
            long long current = total + (P[N] - P[pos]) - 1LL * (N - pos) * x;
            result = min(result, current);
            if (total > result)
                break;
        }
        return result;
    }
};
