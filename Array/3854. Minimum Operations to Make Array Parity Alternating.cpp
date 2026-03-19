class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int const N = nums.size();
        if (N == 1)
            return { 0, 0 };
        vector<int> result{ N + 2, -1 };
        for (int k = 0; k < 2; ++k)
        {
            vector<int> current{ 0, 0 };
            tuple<int, int, int> A{ nums[0], 0, 0 }, B{ nums[0], 0, 0 };
            for (int i = 0; i < N; ++i)
            {
                int delta = ((nums[i] + k + i) % 2 == 0);
                current[0] += delta;
                if (nums[i] < get<0>(A))
                    A = { nums[i], 0, 0 };
                if (nums[i] == get<0>(A))
                    if (!delta)
                        get<1>(A) = 1;
                    else
                        get<2>(A) = 1;
                if (nums[i] > get<0>(B))
                    B = { nums[i], 0, 0 };
                if (nums[i] == get<0>(B))
                    if (!delta)
                        get<1>(B) = 1;
                    else
                        get<2>(B) = 1;
            }
            current[1] = get<0>(B) - get<0>(A);
            if (get<2>(B) == 1 && get<1>(B) != 1)
                --current[1];
            if (get<2>(A) == 1 && get<1>(A) != 1)
                --current[1];
            current[1] = max(1, current[1]);
            if (result > current)
                result = current;
        }
        return result;
    }
};
