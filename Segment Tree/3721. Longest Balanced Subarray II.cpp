class Solution {
public:
    template<class T, typename OP>
    struct SegmentTree
    {
        SegmentTree(unsigned int n, T neutral, OP const& op) : N(1 << bit_width(n - 1)), op(op), neutral(neutral)
        {
            Data = make_unique_for_overwrite<T[]>(2 * N - 1);
            fill(&Data[0], &Data[0] + (2 * N - 1), neutral);
            FMIN = make_unique_for_overwrite<T[]>(2 * N - 1);
            fill(&FMIN[0], &FMIN[0] + (2 * N - 1), neutral);
            FMAX = make_unique_for_overwrite<T[]>(2 * N - 1);
            fill(&FMAX[0], &FMAX[0] + (2 * N - 1), neutral);
        }
        T get(unsigned int idx)
        {
            unsigned int pos = idx + N - 1;
            T result = Data[pos];
            while (pos != 0)
            {
                pos = (pos - 1) / 2;
                result = op(result, Data[pos]);
            }
            return result;
        }
        //apply e = op(e, T) to each element e in [left, right)
        void add(unsigned int left, unsigned int right, T value)
        {
            add(left, right, value, 0, 0, N);
        }
        void add(unsigned int left, unsigned int right, T value, unsigned int Root, unsigned int L, unsigned int R)
        {
            if (L >= right || left >= R)
                return;
            if (left <= L && R <= right)
            {
                Data[Root] = op(Data[Root], value);
                FMIN[Root] = op(FMIN[Root], value);
                FMAX[Root] = op(FMAX[Root], value);
                return;
            }
            propagate(Root);
            unsigned int M = (L + R) / 2;
            add(left, right, value, 2 * Root + 1, L, M);
            add(left, right, value, 2 * Root + 2, M, R);
            FMIN[Root] = min(FMIN[2 * Root + 1], FMIN[2 * Root + 2]);
            FMAX[Root] = max(FMAX[2 * Root + 1], FMAX[2 * Root + 2]);
        }
        void propagate(unsigned int pos)
        {
            for (unsigned int childPos = 2 * pos + 1; childPos <= 2 * pos + 2; ++childPos)
                FMIN[childPos] = op(FMIN[childPos], Data[pos]),
                FMAX[childPos] = op(FMAX[childPos], Data[pos]),
                Data[childPos] = op(Data[childPos], Data[pos]);
            Data[pos] = neutral;
        }
        unsigned int search(unsigned int left, unsigned int right)
        {
            return search(left, right, 0, 0, N);
        }
        unsigned int search(unsigned int left, unsigned int right, unsigned int Root, unsigned int L, unsigned int R)
        {
            if (L >= right || left >= R || FMIN[Root] > 0 || FMAX[Root] < 0)
                return right;
            if (L + 1 == R)
                return Root + 1 - N;
            propagate(Root);
            unsigned int M = (L + R) / 2;
            unsigned int resultRight = search(left, right, 2 * Root + 2, M, R);
            if (resultRight != right)
                return resultRight;
            return search(left, right, 2 * Root + 1, L, M);
        }
        unsigned int N;
        OP op;
        T neutral;
        unique_ptr<T[]> Data;
        unique_ptr<T[]> FMIN;
        unique_ptr<T[]> FMAX;
    };
    int longestBalanced(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        unordered_map<int, int> M;
        auto op = [](int a, int b) -> int
            {
                return a + b;
            };
        SegmentTree<int, decltype(op)> ST(N, 0, op);
        for (int i = N - 1; i >= 0; --i)
        {
            int const& x = nums[i];
            int const sign = ((x & 1) << 2) - 2;
            if (auto it = M.find(x); it != M.end())
                ST.add(i, it->second, sign), it->second = i;
            else
                M[x] = i, ST.add(i, N, sign);
            if (unsigned int pos = ST.search(i, N); pos != N)
                result = max<int>(result, pos + 1 - i);
        }
        return result;
    }
};
