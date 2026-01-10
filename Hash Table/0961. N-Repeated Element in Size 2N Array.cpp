class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
        unordered_set<int> S;
        for(int x : A)
            if (!S.insert(x).second)
                return x;
        return -1;
	}
};