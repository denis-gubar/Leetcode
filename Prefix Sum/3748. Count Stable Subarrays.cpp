class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int const N = nums.size();
        int const Q = queries.size();
        vector<long long> result(Q, -1);
        vector<int> I(Q);
        int const K = sqrt(N);
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&queries, K](int a, int b)
            {
                if (queries[a][0] / K != queries[b][0] / K)
                    return queries[a][0] < queries[b][0];
                return queries[a][1] < queries[b][1];
            });
        deque<int> D;
        long long sum = 0;
        auto addLeft = [&nums, &D, &sum](int pos) -> void
            {
                int const& value = nums[pos];
                if (D.empty() || value > nums[pos + 1])
                    D.push_front(1);
                else
                    ++D.front();
                sum += D.front();
            };
        auto addRight = [&nums, &D, &sum](int pos) -> void
            {
                int const& value = nums[pos];
                if (D.empty() || nums[pos - 1] > value)
                    D.push_back(1);
                else
                    ++D.back();
                sum += D.back();
            };
        auto delLeft = [&nums, &D, &sum](int pos) -> void
            {
                int const& value = nums[pos];
                sum -= D.front();
                if (--D.front() == 0)
                    D.pop_front();
            };
        auto delRight = [&nums, &D, &sum](int pos) -> void
            {
                int const& value = nums[pos];
                sum -= D.back();
                if (--D.back() == 0)
                    D.pop_back();
            };
        int a = 1, b = 0;
        for (int i = 0; i < Q; ++i)
        {
            int const q = I[i];
            int const& L = queries[q][0];
            int const& R = queries[q][1];
            while (a > L)
            {
                addLeft(a - 1);
                --a;
            }
            while (b < R)
            {
                addRight(b + 1);
                ++b;
            }
            while (a < L)
            {
                delLeft(a);
                ++a;
            }
            while (b > R)
            {
                delRight(b);
                --b;
            }
            result[q] = sum;
        }
        return result;

    }
};
