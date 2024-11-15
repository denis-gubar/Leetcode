class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int const N = price.size(), S = special.size();
        int total = 0;
        for (int i = 0; i < N; ++i)
            total += price[i] * needs[i];
        int result = 0;
        vector<int> I, D(S);
        I.reserve(S);
        for (int i = 0; i < S; ++i)
        {
            bool isOk = true;
            for (int j = 0; j < N; ++j)
            {
                if (special[i][j] > needs[j])
                {
                    isOk = false;
                    break;
                }
                D[i] += price[j] * special[i][j];
            }
            if (isOk && D[i] > special[i][N])
                I.push_back(i), D[i] = D[i] - special[i][N];
        }
        sort(I.begin(), I.end(), [&D, &special, N](int a, int b)
            {
                return D[a] * special[b][N] > D[b] * special[a][N];
            });
        unordered_map<int, int> M;
        auto encode = [N](vector<int> const& A) -> int
            {
                int result = 0;
                for (int i = 0; i < N; ++i)
                    result |= A[i] << (4 * i);
                return result;
            };
        auto decode = [N](int hash) -> vector<int>
            {
                vector<int> result(N);
                for (int i = 0; i < N; ++i)
                    result[i] = hash & 15, hash >>= 4;
                return result;
            };
        int test = encode(needs);
        M[0] = 0;
        for (int pos : I)
        {
            unordered_map<int, int> NM;
            for (auto const [key, value] : M)
            {
                vector<int> A = decode(key);
                int gain = value;
                while (true)
                {
                    bool isOk = true;
                    gain += D[pos];
                    for (int i = 0; i < N; ++i)
                    {
                        A[i] += special[pos][i];
                        if (A[i] > needs[i])
                        {
                            isOk = false;
                            break;
                        }
                    }
                    if (!isOk) break;
                    int const hash = encode(A);
                    NM[hash] = max(NM[hash], gain);
                }
            }
            M.merge(NM);
            for (auto const [key, value] : NM)
                if (M[key] < value)
                    M[key] = value;
        }
        for (auto const [key, value] : M)
            result = max(result, value);
        return total - result;
    }
};
