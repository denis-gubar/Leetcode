class Solution {
public:
    long long waysToBuyPensPencils(long long total, long long cost1, long long cost2) {
        long long result = 0;
        for (int x = 0; x <= total; ++x)
        {
            long long rest = total - cost1 * x;
            if (rest < 0)
                break;
            result += rest / cost2 + 1;
        }
        return result;
    }
};
