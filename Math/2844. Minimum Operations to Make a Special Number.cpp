class Solution {
public:
    int minimumOperations(string num) {
        int N = num.size();
        int result = N;
        int zeroCount = 0, nonZeroCount = 0;
        for (int i = N - 1; i >= 0; --i)
            if (num[i] == '0')
            {
                if (++zeroCount == 2)
                    break;
            }
            else
            {
                if (zeroCount == 1 && num[i] == '5')
                {
                    ++zeroCount;
                    break;
                }
                ++nonZeroCount;
            }
        result = min(result, nonZeroCount);
        bool fiveFound = false;
        nonZeroCount = 0;
        for (int i = N - 1; i >= 0; --i)
            if (num[i] == '5')
            {
                nonZeroCount += fiveFound;
                fiveFound = true;
            }
            else
            {
                if (fiveFound && string("27").find(num[i]) != string::npos)
                {
                    result = min(result, nonZeroCount);
                    break;
                }
                ++nonZeroCount;
            }
        return result;
    }
};
