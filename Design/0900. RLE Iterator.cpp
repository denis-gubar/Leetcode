class RLEIterator {
public:
	RLEIterator(vector<int> A): A(A), pos(0) {

	}

	int next(int n) {
		while (pos < A.size() && A[pos] < n)
		{
			n -= A[pos];
			pos += 2;
		}
		if (pos >= A.size())
			return -1;
		A[pos] -= n;
		return A[pos + 1];
	}
private:
	vector<int> A;
	int pos;
};