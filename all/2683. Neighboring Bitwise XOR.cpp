class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int N = derived.size();
        int x = 0;
        for (int i = 0; i < N; ++i)
            x = derived[i] ^ x;
        if (x == 0)
            return true;
        x = 1;
        for (int i = 0; i < N; ++i)
            x = derived[i] ^ x;
        if (x == 1)
            return true;
        return false;
    }
};
