class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3 || A[0] >= A[1])
            return false;
        int state = 0;
        for(int i = 1; i < A.size(); ++i)
        {
            if (state == 0)
            {
                if (A[i] == A[i - 1])
                    return false;
                if (A[i] < A[i - 1])
                    state = 1;
            }
            else if (state == 1)
            {
                if (A[i] >= A[i - 1])
                    return false;
            }
        }
        return state == 1;
    }
};