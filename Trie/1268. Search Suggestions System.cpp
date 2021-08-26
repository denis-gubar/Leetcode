class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
		int N = searchWord.size();
		int P = products.size();
		vector<vector<string>> result(N);
		sort(products.begin(), products.end());
		int pos = 0;
		for (int i = 0; i < N; ++i)
		{
			string word = searchWord.substr(0, i + 1);
			while (pos < P && products[pos] < word)
				++pos;
			for (int k = 0; k < 3 && pos + k < P && word == products[pos + k].substr(0, i + 1); ++k)
				result[i].push_back(products[pos + k]);
		}
		return result;
	}
};