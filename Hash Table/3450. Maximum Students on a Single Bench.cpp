class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        int result = 0;
        unordered_map<int, unordered_set<int>> M;
        for (vector<int> const& s : students)
        {
            int const& student_id = s[0], bench_id = s[1];
            M[bench_id].insert(student_id);
        }
        for (auto const& [key, value] : M)
            if (result < value.size())
                result = value.size();
        return result;
    }
};
