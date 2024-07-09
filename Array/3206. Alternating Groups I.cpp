class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int result = 0;
        int N = colors.size();
        for (int i = 0; i < N; ++i)
            result += colors[(i + N - 1) % N] == colors[(i + 1) % N] && colors[(i + 1) % N] != colors[i];
        return result;
    }
};
