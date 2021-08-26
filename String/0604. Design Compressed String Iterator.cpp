class StringIterator {
public:
	StringIterator(string const& compressedString) {
		for (int i = 0; i < compressedString.size(); )
		{
			int digits = 0, j = i + 1;
			for (; j < compressedString.size() && isdigit(compressedString[j]); ++j)
				digits = min(digits * 10 + compressedString[j] - '0', 1000);
			for (int k = 0; k < digits; ++k)
				s += compressedString[i];
			i = j;
		}
		it = s.begin();
	}

	char next() {
        char result = ' ';
        if (it != s.end())
        {
		    result = *it;
		    ++it;
        }
		return result;
	}

	bool hasNext() {
		return it != s.end();
	}
	string s;
	string::iterator it;
};
