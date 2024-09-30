class Solution {
public:
    vector<int> op;
    char calc(long long k, int shift_count = 0)
    {
        if (k == 0)
            return 'a' + (shift_count % 26);
        long long half = 1LL << (op.size() - 1);
        if (k >= half)
        {
            shift_count += op.back();
            op.pop_back();
            return calc(k - half, shift_count);
        }
        op.pop_back();
        return calc(k, shift_count);
    }
    char kthCharacter(long long k, vector<int>& operations) {
        long long x = 1;
        int count = 0;
        --k;
        while (x <= k)
        {
            op.push_back(operations[count]);
            x <<= 1, ++count;
        }
        return calc(k);
    }
};
