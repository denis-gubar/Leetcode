class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> result;
        string original(target);
        int M = stamp.size(), N = target.size();
        int nonStamped = N;

        vector<int> A(N - M + 1);
        set<pair<int, int>> S;
        for (int i = 0; i < N - M + 1; ++i)
        {
            for (int j = i, k = 0; k < M; ++j, ++k)
                A[i] += stamp[k] != target[j];
            S.insert({ A[i], i });
        }
        while (!S.empty())
        {
            auto [weight, i] = *S.begin();
            S.erase(S.begin());
            if (weight > 0)
                return {};
            if (A[i] == 0)
            {
                result.push_back(i);
                for (int j = i + M - 1; j >= i; --j)
                    if (target[j] != '?')
                    {
                        target[j] = '?';
                        for (int k = max(0, j - M + 1); k <= j && k <= N - M; ++k)
                            if (original[j] != stamp[j - k])
                            {
                                int value = A[k];
                                --A[k];
                                S.erase(S.find({ value, k }));
                                S.insert({ value - 1, k });
                            }
                        --nonStamped;
                    }
            }
        }
        if (nonStamped > 0)
            return {};
        reverse(result.begin(), result.end());
        return result;
    }
};
