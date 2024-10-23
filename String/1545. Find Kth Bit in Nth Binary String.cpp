static bool isInit = false;
static string s;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        s.reserve(1 << 20);
        s += '0';
        for (int t = 2; t <= 20; ++t)
		{
			s.push_back('1');
			for (int pos = s.size() - 2; pos >= 0; --pos)
				s.push_back('0' + '1' - s[pos]);
		}
    }
}
class Solution {
public:
	char findKthBit(int n, int k) {
        init();
		return s[k - 1];
	}
};