class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long result = 0;
        int N = nums1.size();
        vector<int> A(N);
        iota(A.begin(), A.end(), 0);
        sort(A.begin(), A.end(), [&nums2](int a, int b)
            {
                return nums2[a] < nums2[b];
            });
        set<pair<int, int>> S, R;
        long long sum = 0;
        vector<pair<int, int>> B(N);
        for (int i = 0; i < N; ++i)
            B[i] = { nums1[A[i]], A[i] };
        sort(B.begin(), B.end());
        for (int i = N - k; i < N; ++i)
        {
            S.insert(B[i]);
            sum += B[i].first;
        }
        for (int i = 0; i < N - k; ++i)
            R.insert(B[i]);
        int prevI = 0, i = 0;
        while(true)
        {
            for (int j = prevI; j < i; ++j)
            {
                if (S.size() + R.size() < k)
                    break;
                if (S.find({ nums1[A[j]], A[j] }) != S.end())
                {
                    sum -= nums1[A[j]];
                    S.erase({ nums1[A[j]], A[j] });
                    if (R.empty())
                        break;
                    auto it = prev(R.end());
                    pair<int, int> P = *it;
                    R.erase(it);
                    S.insert(P);
                    sum += P.first;
                }
                else
                {
                    R.erase({ nums1[A[j]], A[j] });
                }
            }
            if (S.size() + R.size() < k)
                break;
            result = max(result, sum * nums2[A[i]]);
            prevI = i;
            int j = i;
            for (; j < N && nums2[A[i]] == nums2[A[j]]; ++j)
                ;
            i = j;
        }
        return result;
    }
};

