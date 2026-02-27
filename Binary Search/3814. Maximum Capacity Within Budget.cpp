class Solution {
public:
    template<class T, typename OP>
    struct SegmentTree
    {
        SegmentTree(unsigned int n, T neutral, OP const& op) : N(1 << bit_width(n - 1)), op(op), neutral(neutral)
        {
            Data = make_unique<T[]>(2 * N - 1);
            fill(&Data[0], &Data[0] + (2 * N - 1), neutral);
        }
        void set(unsigned int idx, T value)
        {
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
                if (R % 2 != 0 && (R >= 0 && R < 2 * N - 1))
                    Right = op(Data[R], Right);
                R = R / 2 - 1;
            }
            return op(Left, Right);
        }
        unsigned int N;
        OP op;
        T neutral;
        unique_ptr<T[]> Data;
    };
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int result = 0;
        int const N = costs.size();
        auto op = [](int a, int b) -> int
            {
                return max(a, b);
            };
        SegmentTree<int, decltype(op)> ST(100'001, 0, op);
        for (int i = 0; i < N; ++i)
        {
            if (costs[i] >= budget)
                continue;
            result = max(result, capacity[i] + ST.calc(0, budget - costs[i]));
            int const pos = costs[i] + ST.N - 1;
            if (ST.Data[pos] < capacity[i])
                ST.set(costs[i], capacity[i]);
        }
        return result;
    }
};
