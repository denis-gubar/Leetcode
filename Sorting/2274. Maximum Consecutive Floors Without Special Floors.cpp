class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int N = special.size();
        int result = 0;
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());
        for (int i = 1; i < N + 2; ++i)
            if (special[i] > bottom - 1 && special[i] <= top + 1)
                result = max(result, special[i] - special[i - 1] - 1);
        return result;
    }
};
