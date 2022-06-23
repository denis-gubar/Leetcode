class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        size_t P = primes.size();
        vector<size_t> F{1};  // DP array stores all n ugly numbers
        F.reserve(n);
        vector<int> A(P, -1); // A[i] stores indices such that F[A[i]] % primes[i] == 0 || A[i] == 0.
                              // Sequence of F[A[i]] values corresponds to P virtual sequences
                              // where all elements are subsequence of F and divisible by primes[i] or equal 1.
                              // Anytime we store only the last element of virtual sequence.
                              // -1 initial values means reference before sequence start F[-1]
                              // On the first iteration A[i] values become 0, so each of P sequences starts from 1
        set<pair<size_t, size_t>> S; // Logical priority queue/container
                                     // to speed up merge of all P virtual sequences,
                                     // maintains pairs of (F[A[i]], i) for all i
        for(size_t i = 0; i < P; ++i)
            S.emplace(1, i);
        --n;
        auto it = S.begin(); // it always refers to S.begin()
        while(n > 0)
        {
            // Every element in S are unique anytime, no iterator invalidation
            // it always refers to S.begin()
            for(; it->first == F.back(); it = S.erase(it))
            {
                size_t const& i = it->second;
                S.emplace(F[++A[i]] * primes[i], i);
            }
            // it always refers to S.begin(), minimum element to be inserted into F
            F.push_back(it->first);
            --n;
        }
        return F.back();
    }
};