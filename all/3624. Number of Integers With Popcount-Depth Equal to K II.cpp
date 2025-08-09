bool static isInit = false;
static unsigned char F[128];
static unsigned long long C[64][64];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        for (unsigned char i = 2; i < 128; ++i)
            F[i] = 1 + F[popcount(i)];
        memset(C, 0, sizeof(C));
        C[0][0] = 1LL;
        for (int N = 1; N < 64; ++N)
        {
            C[N][0] = 1;
            for (int K = 1; K < 64; ++K)
                C[N][K] = C[N - 1][K - 1] + C[N - 1][K];
        }
    }
}
class Solution {
public:
    int f(unsigned long long x)
    {
        if (x < 128)
            return F[x];
        return 1 + F[popcount(x)];
    }
    template<typename T>
    struct FenwickTree
    {
        FenwickTree(size_t N) : N(N)
        {
            tree.assign(N, {});
        }
        FenwickTree(vector<T> const& A) : FenwickTree(A.size())
        {
            for (size_t position = 0; position < N; ++position)
                add(position, A[position]);
        }
        void add(size_t position, T value)
        {
            for (size_t x = position; x < N; x |= x + 1)
                tree[x] += value;
        }
        // [0; position]
        T sum(size_t position)
        {
            T result{};
            for (size_t x = position; x > 0; x &= x - 1)
                result += tree[x - 1];
            return result;
        }
        // [left; right)
        T sum(size_t left, size_t right)
        {
            return sum(right) - sum(left);
        }
        size_t N;
        vector<T> tree;
    };
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        init();
        int const N = nums.size(), Q = queries.size();
        vector<int> result;
        result.reserve(Q);
        vector<FenwickTree<int>> FT(6, FenwickTree<int>(N));
        for (int i = 0; i < N; ++i)
            FT[f(nums[i])].add(i, 1);
        for (int q = 0; q < Q; ++q)
        {
            if (queries[q][0] == 2)
            {
                long long const& idx = queries[q][1];
                long long const& val = queries[q][2];
                FT[f(nums[idx])].add(idx, -1);
                nums[idx] = val;
                FT[f(nums[idx])].add(idx, 1);
                continue;
            }
            long long const& L = queries[q][1];
            long long const& R = queries[q][2];
            long long const& K = queries[q][3];
            result.push_back(FT[K].sum(L, R + 1));
        }
        return result;
    }
};
