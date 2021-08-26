class Solution {
public:
	int minPartitions(string n) {
		int result = *max_element(n.begin(), n.end()) - '0';
		return result;
	}
};