class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int result = 0;
        unordered_map<int, int> M;
        for (int x : tasks)
            ++M[x];
        for (auto [key, value] : M)
        {
            if (value == 1)
                return -1;
            result += (value + 2) / 3;
        }
        return result;
    }
};
