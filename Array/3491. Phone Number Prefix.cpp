class Solution {
public:
    bool phonePrefix(vector<string>& numbers) {
        int const N = numbers.size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (i != j && numbers[i].size() <= numbers[j].size() && numbers[j].substr(0, numbers[i].size()) == numbers[i])
                    return false;
        return true;
    }
};
