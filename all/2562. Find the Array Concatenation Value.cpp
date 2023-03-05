class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long result = 0;
        deque<int> D(nums.begin(), nums.end());
        while (!D.empty())
        {
            if (D.size() > 1)
            {
                string x = to_string(D.front()) + to_string(D.back());
                D.pop_front(); D.pop_back();
                result += stoll(x);
            }
            else
            {
                result += D.front();
                D.pop_front();
            }
        }
        return result;
    }
};
