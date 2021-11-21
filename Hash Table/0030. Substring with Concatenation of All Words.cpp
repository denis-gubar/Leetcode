class Solution {
public:
	template <int base = 29>
	struct HashString
	{
		const int MOD = 1'000'000'007;
		HashString(const string& s) : data(s), N(s.size()), prefixes(vector<int>(N + 1)), power(prefixes)
		{
			power[0] = 1;
			for (int i = 1; i <= N; ++i)
			{
				power[i] = 1LL * power[i - 1] * base % MOD;
				prefixes[i] = (1LL * prefixes[i - 1] * base + hash(s[i - 1])) % MOD;
			}
		}
		static int hash(char c)
		{
			return c - 'a' + 1;
		}
		int hash(int start, int length) const
		{
			return (prefixes[start + length] - 1LL * prefixes[start] * power[length] % MOD + MOD) % MOD;
		}
		int N;
		vector<int> prefixes;
		vector<int> power;
		string data;
	};
	using hash = int;
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		int W = words.size(), N = s.size(), K = words[0].size();

		string allWords;
		allWords.reserve(W * K);
		for (string const& word : words)
			allWords += word;
		HashString hashWords(allWords);
		HashString hashS(s);

		unordered_map<hash, vector<int>> wordIndex;
		int uniqueWordCount = 0;
		vector<string> uniqueWords;
		vector<int> target;
		for (int i = 0; i < W; ++i)
		{
			hash hashW = hashWords.hash(i * K, K);
			if (auto it = wordIndex.find(hashW); it == wordIndex.end())
			{
				wordIndex[hashW].push_back(uniqueWordCount);
				target.push_back(1);
				++uniqueWordCount;
				uniqueWords.push_back(words[i]);
			}
			else
			{
				vector<int>& bucket = it->second;
				string const& currentWord = words[i];
				if (auto it2 = find_if(bucket.begin(), bucket.end(),
					[&currentWord, &uniqueWords](int index)
					{
						return uniqueWords[index] == currentWord;
					});
					it2 == bucket.end())
				{
					bucket.push_back(uniqueWordCount);
					target.push_back(1);
					++uniqueWordCount;
					uniqueWords.push_back(words[i]);
				}
				else
					++target[*it2];
			}
		}
		int T = target.size();
		vector<int>	current(T);

		for (int delta = 0; delta < K; ++delta)
		{
			int a = delta, b = delta;
			fill(current.begin(), current.end(), 0);            
			while (N - a >= W * K && b + K <= N)
			{
				hash h = hashS.hash(b, K);
				b += K;
				if (auto it = wordIndex.find(h); it == wordIndex.end())
				{
					a = b;
					fill(current.begin(), current.end(), 0);
				}
				else
				{
					vector<int> const& bucket = it->second;                    
					for (int index : bucket)
						if (equal(uniqueWords[index].begin(), uniqueWords[index].end(), s.begin() + (b - K), s.begin() + b))
						{
							++current[index];
							while (current[index] > target[index])
							{
								vector<int> const& oldBucket = wordIndex[hashS.hash(a, K)];
								for (int oldIndex : oldBucket)
									if (equal(uniqueWords[oldIndex].begin(), uniqueWords[oldIndex].end(), s.begin() + a, s.begin() + a + K))
									{
										--current[oldIndex];
										a += K;
										break;
									}
							}
							if (b - a == W * K)
								result.push_back(a);
							break;
						}
				}
			}            
		}
		return result;
	}
};