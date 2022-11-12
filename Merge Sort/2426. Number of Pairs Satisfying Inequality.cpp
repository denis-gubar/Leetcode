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
        T sum(int L, int R) const
        {
            return sum(L, R, 1, 0, N - 1);
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
                Tree[root] = Tree[root * 2] + Tree[root * 2 + 1];
            }
        }
        T sum(int L, int R, int root, int left, int right) const
        {
            if (L > R)
                return 0;
            if (L == left && R == right)
                return Tree[root];
            int middle = (left + right) / 2;
            return sum(L, min(middle, R), root * 2, left, middle) +
                sum(max(L, middle + 1), R, root * 2 + 1, middle + 1, right);
        }
    };
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        SegmentTree<int> ST(60'004);
        constexpr int DIFF = 30'001;
        long long result = 0;
        int N = nums1.size();
        vector<int> A(60'002);
        for (int j = 0; j < N; ++j)
        {
            int delta = nums2[j] - nums1[j];
            result += ST.sum(delta - diff + DIFF, DIFF * 2);
            ++A[delta + DIFF];
            ST.update(delta + DIFF, A[delta + DIFF]);
        }
        return result;
    }
};
