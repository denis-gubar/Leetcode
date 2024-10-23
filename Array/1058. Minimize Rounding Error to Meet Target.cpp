class Solution {
public:
    int read(string const& price) const
    {
        int result = 0;
        for (char c : price)
            if (c != '.')
                result = result * 10 + (c - '0');
        return result;
    }
    string minimizeError(vector<string>& prices, int target) {
        int const P = prices.size();
        int lwm = 0;
        vector<int> R;
        R.reserve(P);
        for (string const& price : prices)
        {
            int const x = read(price);
            lwm += x / 1000;
            if (x % 1000 > 0)
                R.push_back(x % 1000);
        }
        int const N = R.size();
        if (target < lwm || lwm + N < target)
            return "-1";
        int K = target - lwm;
        sort(R.begin(), R.end(), greater{});
        int total = 0;
        for (int i = 0; i < N; ++i)
            if (i < K)
                total += 1000 - R[i];
            else
                total += R[i];
        return to_string(total / 1000) + "." + to_string(1000 + total % 1000).substr(1);
    }
};
