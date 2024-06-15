class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int result = 0;
        int N = skills.size();
        k = min(k, N - 1);
        skills.reserve(2 * N);
        for (int i = 0; i < N; ++i)
            skills.push_back(skills[i]);
        int count = 0;
        for (int i = 0; i < 2 * N; ++i)
        {
            if (skills[i] > skills[i + 1])
            {
                ++count;
                if (count == k)
                    break;
                skills[i + 1] = skills[i];
            }
            else
            {
                count = 1;
                result = (i + 1) % N;
                if (count == k)
                    break;
            }
        }
        return result;
    }
};
