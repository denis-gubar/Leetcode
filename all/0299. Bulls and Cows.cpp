class Solution {
public:
	string getHint(string secret, string guess) {
		string result;
		int a = 0, b = 0;
		for (int i = 0; i < secret.size(); ++i)
			a += secret[i] == guess[i];
		sort(secret.begin(), secret.end());
		sort(guess.begin(), guess.end());
		string delta;
		set_intersection(secret.begin(), secret.end(), guess.begin(), guess.end(), back_inserter(delta));
		b = delta.size();
		result = to_string(a) + "A" + to_string(b - a) + "B";
		return result;
	}
};