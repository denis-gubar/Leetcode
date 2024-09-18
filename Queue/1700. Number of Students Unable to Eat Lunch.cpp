class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> Q;
        array A = {0, 0};
        for(int x : students)
            ++A[x], Q.push(x);
        reverse(sandwiches.begin(), sandwiches.end());
        while(!sandwiches.empty())
        {
            int x = Q.front(); Q.pop();
            if (x == sandwiches.back())
                --A[x], sandwiches.pop_back();
            else
                if (A[1 - x] == 0)
                    break;
                else
                    Q.push(x);
        }
        return A[0] + A[1];
    }
};