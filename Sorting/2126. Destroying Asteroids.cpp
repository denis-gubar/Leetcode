class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int N = asteroids.size();
        long long total = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < N; ++i)
            if (asteroids[i] <= total)
                total += asteroids[i];
            else
                return false;
        return true;
    }
};
