class Solution {
public:
    int maxWeight(vector<int>& weights, int w1, int w2) {
        if (w1 > w2)
            swap(w1, w2);
        vector<bitset<301>> F1(w1 + 1), F2(w1 + 1);
        F1[0][0] = true;
        for (int x : weights)
        {
            for (int i = 0; i <= w1; ++i)
                F2[i] = F1[i] | (F1[i] << x);
            for (int i = 0; i + x <= w1; ++i)
                F2[i + x] |= F1[i];
            F1.swap(F2);
        }
        for (int sum = w1 + w2; sum >= 0; --sum)
        {
            for (int x = min(sum, w1); sum - x <= w2 && x >= 0; --x)
                if (F1[x][sum - x])
                    return sum;
        }
        return -1;
    }
};
