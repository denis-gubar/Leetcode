class Solution {
public:
	int timeRequiredToBuy(vector<int>& tickets, int k) {
		int result = 0;
		int N = tickets.size();
		int pos = 0;
		while (true)
		{
			
			if (tickets[pos] > 0)
				--tickets[pos], ++result;
            if (pos == k && tickets[pos] == 0)
				break;
			pos = (pos + 1) % N;
		}
		return result;
	}
};