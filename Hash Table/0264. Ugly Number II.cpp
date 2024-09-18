class Solution {
public:
    int nthUglyNumber(int n) {
        array primes{2, 3, 5};        
        size_t P = primes.size();
        vector<int> A(P, -1);
        vector<size_t> F{1};
        F.reserve(n);
        set<pair<size_t, size_t>> S;
        for(size_t i = 0; i < P; ++i)
            S.emplace(1, i);
        --n;
        while(n > 0)
        {
            for(auto it = S.lower_bound({F.back(), 0}); it != S.end() && it->first == F.back(); it = S.erase(it))
            {
                size_t const& i = it->second;                
                S.emplace(F[++A[i]] * primes[i], i);                
            }
            F.push_back(S.begin()->first);
            --n;
        }
        return F.back();
    }
};