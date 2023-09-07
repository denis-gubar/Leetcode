class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int result = 0;
        for (int x : hours)
            result += x >= target;
        return result;
    }
};
