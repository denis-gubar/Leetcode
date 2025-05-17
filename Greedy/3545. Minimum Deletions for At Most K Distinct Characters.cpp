class Solution {
public:
    int minDeletion(string s, int K) {
        int result = 0;
        unordered_map<char, int> M;
        for (char c : s)
            ++M[c];
        vector<int> A;
        for (auto [key, value] : M)
            A.push_back(value);
        sort(A.begin(), A.end(), greater{});
        while (A.size() > K)
            result += A.back(), A.pop_back();
        return result;
    }
};
