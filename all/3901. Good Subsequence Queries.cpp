using sint = unsigned short;
static vector<sint> primes;
class Solution {
public:
    template<class T, typename OP>
    struct SegmentTree
    {
        template<class Iterator>
        SegmentTree(Iterator first, Iterator last, T neutral, OP const& op) : op(op), neutral(neutral)
        {
            unsigned int distance = last - first;
            N = 1 << bit_width(distance - 1);
            Data = make_unique_for_overwrite<T[]>(2 * N - 1);
            copy(first, last, &Data[0] + (N - 1));
            fill(&Data[0] + (N - 1) + distance, &Data[0] + (2 * N - 1), neutral);
            unsigned int pos = N - 1;
            while (pos > 0)
            {
                --pos;
                Data[pos] = op(Data[2 * pos + 1], Data[2 * pos + 2]);
            }
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
                if (R % 2 != 0)
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
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        int result = 0;
        vector<sint> divs;
        sint const N = nums.size();
        sint K = 0;
        auto op = [p](sint a, sint b) -> sint
            {
                return gcd(a % p == 0 ? a : 0, b % p == 0 ? b : 0);
            };
        SegmentTree<sint, decltype(op)> ST(nums.begin(), nums.end(), 0, op);
        unordered_multiset<sint> S;
        for (int x : nums)
            if (x % p == 0)
                S.insert(x);
        for (vector<int> const& q : queries)
        {
            int const& IND = q[0];
            int const& VAL = q[1];
            if (nums[IND] % p == 0)
                S.erase(S.find(nums[IND]));
            nums[IND] = VAL;
            if (nums[IND] % p == 0)
                S.insert(nums[IND]);
            ST.set(IND, VAL);
            if (ST.Data[0] == p)
            {
                if (N < 10 && S.size() == N)
                {
                    bool flag = false;
                    vector<sint> A(S.begin(), S.end());
                    int M = A.size();
                    for (int i = 0; i < N; ++i)
                    {
                        int k = 0;
                        for (int j = 0; j < N; ++j)
                            if (i != j)
                                k = gcd(k, A[j]);
                        if (k == p)
                        {
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                        continue;
                }
                ++result;
            }
        }
        return result;
    }
};
