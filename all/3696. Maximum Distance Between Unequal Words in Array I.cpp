class Solution {
public:
    int maxDistance(vector<string>& words) {
        int result = 0;        
        int const N = words.size();
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                if (result < j - i + 1 && words[i] != words[j])
                    result = j - i + 1;
        return result;
    }
};
