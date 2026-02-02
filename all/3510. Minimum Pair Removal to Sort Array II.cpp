class Solution {
public:
    template<class T, typename OP>
    struct SegmentTree
    {
        SegmentTree(unsigned int n, T neutral, OP const& op) : N(1 << bit_width(n - 1)), op(op), neutral(neutral)
        {
            Data = make_unique_for_overwrite<T[]>(2 * N - 1);
            fill(&Data[0], &Data[0] + (2 * N - 1), neutral);
        }
        void set(unsigned int idx, T value)
        {
            if (idx >= N) return;
            unsigned int pos = idx + N - 1;
            Data[pos] = value;
            while (pos != 0)
            {
                pos = (pos - 1) / 2;
                Data[pos] = op(Data[2 * pos + 1], Data[2 * pos + 2]);
            }
        }
        //op[left, right)
        T calc(unsigned int left, unsigned int right)
        {
            T Left = neutral;
            T Right = neutral;
            int L = left + N - 1;
            int R = right + N - 2;
            while (L <= R)
            {
                if (L % 2 == 0)
                    Left = op(Left, Data[L]);
                L /= 2;
                if (R % 2 != 0)
                    Right = op(Data[R], Right);
                R = R / 2 - 1;
            }
            return op(Left, Right);
        }
        int search()
        {
            unsigned int pos = 0;
            while (pos < N - 1)
                pos = 2 * pos + 1 + (Data[2 * pos + 1] > Data[0]);
            return pos + 1 - N;
        }
        unsigned int N;
        OP op;
        T neutral;
        unique_ptr<T[]> Data;
    };
    static long long const INF = 1LL << 50;
    int minimumPairRemoval(vector<int>& nums) {
        int result = 0;
        unsigned int const N = nums.size();
        if (N == 1) return 0;
        using LIT = list<pair<long long, int>>::iterator;
        unique_ptr<LIT[]> I = make_unique_for_overwrite<LIT[]>(N);
        list<pair<long long, int>> L;
        auto op = [](long long a, long long b) -> long long
            {
                return min(a, b);
            };
        SegmentTree<long long, decltype(op)> ST(N - 1, INF, op);
        int quality = 0;
        for (int i = 0; i < N; ++i)
        {
            if (i > 0)
                quality += nums[i - 1] > nums[i];
            L.push_back({ nums[i], i });
            I[i] = prev(L.end());
            if (i < N - 1)
                ST.set(i, nums[i] + nums[i + 1]);
        }
        auto get_minumum_pair = [&]() -> LIT
            {
                return I[ST.search()];
            };
        while (quality > 0)
        {
            LIT it = get_minumum_pair();
            long long new_val = it->first + next(it)->first;
            int quality_delta = (it != L.begin() ? (prev(it)->first > it->first) - (prev(it)->first > new_val) : 0) +
                (it->first > next(it)->first) + 
                (next(next(it)) != L.end() ? (next(it)->first > next(next(it))->first) - (new_val > next(next(it))->first) : 0);
            it->first = it->first + next(it)->first;
            if (it != L.begin())
                ST.set(prev(it)->second, prev(it)->first + it->first);
            if (next(next(it)) != L.end())
                ST.set(it->second, it->first + next(next(it))->first);
            else
                ST.set(it->second, INF);
            ST.set(next(it)->second, INF);
            L.erase(next(it));
            quality -= quality_delta;
            ++result;
        }
        return result;
    }
};
