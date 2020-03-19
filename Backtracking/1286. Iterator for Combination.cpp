class CombinationIterator {
public:
	CombinationIterator(string characters, int combinationLength) : A(vector<int>(characters.size(), 0)), s(characters), combinationLength(combinationLength), has_Next(true) {
		for (int k = 0; k < combinationLength; ++k)
			A[k] = -1;
	}

	string next() {        
		string result;
        for (int i = 0; i < A.size(); ++i)
			if (A[i])
				result += s[i];
		has_Next = next_permutation(A.begin(), A.end());		
		return result;
	}

	bool hasNext() {
		return has_Next;
	}
	vector<int> A;
	string s;
	bool has_Next;
	int combinationLength;
};