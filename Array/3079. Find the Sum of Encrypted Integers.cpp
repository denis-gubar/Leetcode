class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int result = 0;
        for (int x : nums)
        {
            string s = to_string(x);
            char c = *max_element(s.begin(), s.end());
            int N = s.size();
            result += stoi(string(N, c));
        }
        return result;
    }
};