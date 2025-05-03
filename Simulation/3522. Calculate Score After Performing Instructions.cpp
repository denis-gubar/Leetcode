class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int const N = instructions.size();
        long long result = 0;
        vector<bool> visited(N);
        int i = 0;
        while (true)
        {
            if (i < 0 || i >= N || visited[i])
                break;
            visited[i] = true;
            if (instructions[i] == "add")
            {                
                result += values[i], ++i;
                continue;
            }
            i += values[i];
        }
        return result;
    }
};
