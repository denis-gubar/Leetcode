class Solution {
public:
	vector<int> processQueries(vector<int>& queries, int m) {
		list<int> A(m);
		vector<int> result;
		iota(A.begin(), A.end(), 1);
		for (int q: queries)
		{
			int i = 0;
			auto it = A.begin();
			while (*it != q)
				++it, ++i;
			result.push_back(i);
			A.erase(it);
			A.push_front(q);
		}
		return result;
	}
};