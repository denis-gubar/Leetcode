class Solution {
public:
    vector<int> decimalRepresentation(int N) {
        vector<int> result;
        long long P = 1;
        while (N > 0)
        {
            if (N % 10 != 0)
                result.push_back(P * (N % 10));
            N /= 10;
            P *= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
