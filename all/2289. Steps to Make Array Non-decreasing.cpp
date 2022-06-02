class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int result = 0;
        int N = nums.size();
        list<list<int>> A;
        A.push_back({ nums[0] });
        for (int i = 1; i < N; ++i)
        {
            if (nums[i - 1] > nums[i])
                A.push_back({ nums[i] });
            else
                A.back().push_back(nums[i]);
        }
        while (A.size() > 1)
        {
            for (auto nit = prev(A.end()); nit != A.begin(); )
            {
                auto it = prev(nit);
                if (it->back() > nit->front())
                    nit->pop_front();
                if (!nit->empty() && it->back() <= nit->front())
                    it->splice(it->end(), *nit);
                if (nit->empty())
                    A.erase(nit);
                nit = it;
            }
            ++result;
        }
        return result;
    }
};
