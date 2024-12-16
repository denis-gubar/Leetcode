class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        vector<int> A, B;
        for (int i = 0; i < N; ++i)
            if (nums[i] == 0)
                A.push_back(i);
            else
                B.push_back(i);
        for(int dx = -1; dx <= 1; dx += 2)
            for (int x : A)
            {
                int d = dx;
                int pos = x;
                vector<int> X(nums);
                vector<int> Z(B);
                bool flag = true;
                while (!Z.empty())
                {
                    auto it = lower_bound(Z.begin(), Z.end(), pos);
                    if (d < 0 && it == Z.begin() && *it > pos || d > 0 && it == Z.end())
                    {
                        flag = false;
                        break;
                    }
                    if (d < 0 && (it == Z.end() || *it > pos))
                        pos = *prev(it);
                    else
                        pos = *it;
                    if (--X[pos] == 0)
                        Z.erase(lower_bound(Z.begin(), Z.end(), pos));
                    d = -d;
                    pos += d;
                }
                result += Z.empty() && flag;
            }
        return result;
    }
};
