class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long result = 0;
        int const N = arr.size();
        for (int i = 0; i < N; ++i)
            result += abs(arr[i] - brr[i]);
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        long long total = k;
        for (int i = 0; i < N; ++i)
            total += abs(arr[i] - brr[i]);
        result = min(result, total);
        return result;
    }
};
