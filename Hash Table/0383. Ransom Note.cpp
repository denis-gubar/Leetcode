class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		string result;
		sort(ransomNote.begin(), ransomNote.end());
		sort(magazine.begin(), magazine.end());
		set_intersection(magazine.begin(), magazine.end(), ransomNote.begin(), ransomNote.end(), back_inserter(result));
		return result == ransomNote;
	}
};