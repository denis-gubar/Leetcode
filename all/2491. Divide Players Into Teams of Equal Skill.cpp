class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long result = 0;
        int N = skill.size();
        sort(skill.begin(), skill.end());
        int L = 0, R = N - 1;
        while (L < R)
        {
            if (skill[L] + skill[R] != skill[0] + skill[N - 1])
                return -1;
            result += skill[L] * skill[R];
            ++L, --R;
        }
        return result;
    }
};
