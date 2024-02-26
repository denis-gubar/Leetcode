class Solution {
public:
    struct Data
    {
        int x;
        int a;
        int b;
    };
    int maxSelectedElements(vector<int>& nums) {
        int result = 1;
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<Data> F;
        F.reserve(N);
        F.push_back({ nums[0], 1, 1 });
        for (int i = 1; i < N; ++i)
        {
            int x = nums[i];
            int k = F.size();
            if (k > 1 && x == F[k - 2].x)
                continue;
            Data next{ x, 1, 1 };
            for (int j = max(0, k - 3); j < k; ++j)
            {
                int prev = F[j].x;
                if (x == prev + 1)
                    next.a = max(next.a, 1 + F[j].a);
                if (x + 1 == prev + 1)
                    next.b = max(next.b, 1 + F[j].a);
                if (x == prev + 2)
                    next.a = max(next.a, 1 + F[j].b);
                if (x + 1 == prev + 2)
                    next.b = max(next.b, 1 + F[j].b);
            }
            F.push_back(next);
            result = max({ result, next.a, next.b });
        }
        return result;
    }
};
