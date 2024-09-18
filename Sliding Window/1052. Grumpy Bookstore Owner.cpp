class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int result = 0;
        int N = customers.size();
        int bonus = 0, current = 0;
        for (int i = 0; i < N; ++i)
        {
            if (i >= minutes && grumpy[i - minutes])
                current -= customers[i - minutes];
            if (grumpy[i])
                current += customers[i];
            else
                result += customers[i];
            bonus = max(bonus, current);
        }
        result += bonus;
        return result;
    }
};
