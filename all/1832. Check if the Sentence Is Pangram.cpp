class Solution {
public:
	bool checkIfPangram(string sentence) {
		sort(sentence.begin(), sentence.end());
		sentence.resize(unique(sentence.begin(), sentence.end()) - sentence.begin());
		return sentence.size() == 26;
	}
};