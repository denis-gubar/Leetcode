class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long result = 1;
        sort(damage.begin(), damage.end());
        damage.back() = max(0, damage.back() - armor);
        for (int x : damage)
            result += x;
        return result;
    }
};
