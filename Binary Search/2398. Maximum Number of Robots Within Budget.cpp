class Solution {
public:    
    template <typename T>
    struct SegmentTree
    {
        SegmentTree(int N) : N(1 << log2(N)), Tree(vector<T>((2 << log2(N)) + 1))
        {
        }
        void update(int pos, T value)
        {
            update(pos, value, 1, 0, N - 1);
        }
        T Max(int L, int R) const
        {
            return Max(L, R, 1, 0, N - 1);
        }
    private:
        int N;
        vector<T> Tree;
        static int log2(int x)
        {
            int result = 0;
            while (x)
            {
                x /= 2;
                ++result;
            }
            return result;
        }
        void update(int pos, T value, int root, int left, int right)
        {
            if (left == right)
                Tree[root] = value;
            else
            {
                int middle = (left + right) / 2;
                if (pos <= middle)
                    update(pos, value, root * 2, left, middle);
                else
                    update(pos, value, root * 2 + 1, middle + 1, right);
                Tree[root] = max(Tree[root * 2], Tree[root * 2 + 1]);
            }
        }
        T Max(int L, int R, int root, int left, int right) const
        {
            if (L > R)
                return 0;
            if (L == left && R == right)
                return Tree[root];
            int middle = (left + right) / 2;
            return max(Max(L, min(middle, R), root * 2, left, middle),
                Max(max(L, middle + 1), R, root * 2 + 1, middle + 1, right));
        }
    };
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int N = chargeTimes.size();
        int a = 0, b = N + 1;
        SegmentTree<int> ST(N);
        for (int i = 0; i < N; ++i)
            ST.update(i, chargeTimes[i]);
        auto calc = [&chargeTimes, &runningCosts, budget, N, &ST](int k)
        {
            long long sum = 0;
            for (int i = 0; i < k; ++i)
                sum += runningCosts[i];
            long long maximum = ST.Max(0, k - 1);
            if (maximum + k * sum <= budget)
                return true;
            for (int i = k; i < N; ++i)
            {
                sum -= runningCosts[i - k];
                sum += runningCosts[i];
                long long maximum = ST.Max(i - k + 1, i);
                if (maximum + k * sum <= budget)
                    return true;
            }
            return false;
        };
        while (a + 1 < b)
        {
            int m = (a + b) / 2;
            if (calc(m))
                a = m;
            else
                b = m;
        }
        return a;
    }
};

