class Solution {
public:
	int compress(vector<char>& chars) {
		int pos = 0;
		char prev = '$';
		int count = 0;
		for (char c : chars)
			if (c != prev)
			{
				if (count > 1)
				{
                    chars[pos] = prev;
					++pos;
					string t{ to_string(count) };
					for (char z : t)
						chars[pos] = z, ++pos;
				}
				else if (count == 1)
					chars[pos] = prev, ++pos;
				count = 1;
				prev = c;
			}
			else
				++count;
        if (count > 1)
        {
            chars[pos] = prev;
            ++pos;
            string t{ to_string(count) };
            for (char z : t)
                chars[pos] = z, ++pos;
        }
        else if (count == 1)
            chars[pos] = prev, ++pos;       
		return pos;
	}
};