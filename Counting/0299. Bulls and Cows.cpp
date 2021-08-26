class Solution {
public:
	string getHint(string secret, string guess) {
		string result;
		int N = secret.size();
		int bulls = 0, cows = 0;
		for (int i = 0; i < N; ++i)
			bulls += secret[i] == guess[i];
		sort(secret.begin(), secret.end());
		sort(guess.begin(), guess.end());
		string t;
		set_intersection(secret.begin(), secret.end(), guess.begin(), guess.end(), back_inserter(t));
		cows = t.size();
		cows -= bulls;
		result += to_string(bulls);
		result += 'A';
		result += to_string(cows);
		result += 'B';
		return result;
	}
};