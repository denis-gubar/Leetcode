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
    int lengthOfLIS(vector<int>& nums, int k) {
        vector<int> M(100'001);
        SegmentTree<int> ST(100'001);
        for (int x : nums)
        {
            M[x] = max(M[x], ST.Max(max(1, x - k), x - 1) + 1);
            ST.update(x, M[x]);
        }
        return *max_element(M.begin(), M.end());
    }
};
