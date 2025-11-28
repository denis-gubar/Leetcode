class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int result = 1;
        vector<bool> visited(k);
        int x = 1;
        while(true)
        {
            if (visited[x])
                return -1;
            visited[x] = true;
            if (x % k == 0)
                return result;
            ++result, x = (x * 10 + 1) % k;
        }
        return result;
    }
};