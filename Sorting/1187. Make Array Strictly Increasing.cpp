class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int const INF = 1'000'000'001;
        sort(arr2.begin(), arr2.end());
        arr2.push_back(INF);
        int N = arr1.size(), M = arr2.size();
        vector<int> A;
        A.reserve(M + 1);
        A.push_back(-1);
        for (int i = 0; i < N; ++i)
            for (int K = A.size(), j = K - 1; j >= 0; --j)
                if (A[j] < INF)
                {
                    auto it = upper_bound(arr2.begin(), arr2.end(), A[j]);
                    if (j + 1 == K)
                        A.push_back(*it);
                    else
                        A[j + 1] = min(A[j + 1], *it);
                    if (arr1[i] > A[j])
                        A[j] = arr1[i];
                    else
                        A[j] = INF;
                }
        int result = -1;
        for (int K = A.size(), i = 0; i < K; ++i)
            if (A[i] != INF)
            {
                result = i;
                break;
            }
        return result;
    }
};
