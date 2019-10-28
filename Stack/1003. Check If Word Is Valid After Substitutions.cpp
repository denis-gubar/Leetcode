class Solution {
public:
	bool isValid(string S) {
		S = "^^^" + S + "###";
		list<char> L(S.begin(), S.end());
		auto it = L.begin();
		++it; ++it; ++it;
		auto it1 = it, it2 = it;
		++it1;
		++it2; ++it2;
		while (*it != '#')
		{
			if (*it == 'a' && *it1 == 'b' && *it2 == 'c')
			{
				L.erase(it2);
				L.erase(it1);
				it = L.erase(it);
				--it; --it; --it;
				it1 = it, it2 = it;
				++it1;
				++it2; ++it2;
			}
			++it; ++it1; ++it2;
		}
		string X(L.begin(), L.end());
		return X == "^^^###";
	}
};