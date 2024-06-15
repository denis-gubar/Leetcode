class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int N = energy.size();
        int result = *max_element(energy.begin(), energy.end());
        result = -(1 << 30);
        for (int i = 0; i < k; ++i)
        {
            int X = 0;
            for (int j = N - 1 - i; j >= 0; j -= k)
            {
                result = max(result, energy[j] + X);
                X = X + energy[j];
            }
        }
        return result;
    }
};
