class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result = 0;
        for(int x : left)
            result = max(result, x);
        for(int x : right)
            result = max(result, n - x);
        return result;
    }
};