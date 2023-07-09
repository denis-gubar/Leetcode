class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        int N = nums.size();
        int result = -1;
        int n = 1'000'001;
        vector<bool> isPrime(n, true);
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i < n; ++i)
            if (isPrime[i])
                for (int k = i * i; k < n; k += i)
                    isPrime[k] = false;
        vector<int> primes;
        for (int i = 2; i < n; ++i)
            if (isPrime[i])
                primes.push_back(i);
        int P = primes.size();
        unordered_map<int, int> M;
        for (int i = 0; i < P; ++i)
            M[primes[i]] = i;
        vector<vector<int>> A(P);
        for (int i = 0; i < N; ++i)
        {
            int x = nums[i];
            for (int k = 0; x > 1; ++k)
            {
                if (isPrime[x])
                {
                    if (A[M[x]].size() == 2)
                        A[M[x]].pop_back();
                    A[M[x]].push_back(i);
                    x = 1;
                    break;
                }
                if (x % primes[k] == 0)
                {
                    if (A[k].size() == 2)
                        A[k].pop_back();
                    A[k].push_back(i);
                    while (x % primes[k] == 0)
                        x /= primes[k];
                }                
            }
        }
        set<int> S;
        for (int i = 0; i < N - 1; ++i)
            S.insert(i);
        for(int i = 0; i < P; ++i)
            if (A[i].size() > 1)
            {
                int const& L = A[i][0];
                int const& R = A[i][1];
                auto it = S.lower_bound(L);
                while (it != S.end() && *it < R)
                    it = S.erase(it);
            }
        if (!S.empty())
            result = *S.begin();
        return result;
    }
};
