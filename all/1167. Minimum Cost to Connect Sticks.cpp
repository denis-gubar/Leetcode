class Solution {
public:
	int connectSticks(vector<int>& sticks) {
        int result = 0;
		multiset<int> S;
		for (int s : sticks)
			S.insert(s);
		while (S.size() > 1)
		{
			auto it1 = S.begin();
			int sum = *it1;
			S.erase(it1);
			it1 = S.begin();
			sum += *it1;
            S.erase(it1);
            result += sum;			
			S.insert(sum);
		}
		return result;
	}
};