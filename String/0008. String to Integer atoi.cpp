class Solution {
public:
	int myAtoi( string str ) {
		long long result = 0;
		int sign = 1;
		int n = str.size();
		int k = 0;
		while (k < n && (str[k] == ' ' || str[k] == '	' || str[k] == '\r' || str[k] == '
'))
			++k;
		if (k < n && str[k] == '-')
		{
			sign = -1; ++k;
		}
		else if (k < n && str[k] == '+')
			++k;
		if (k == n || !isdigit( str[k] ))
			return 0;
		while (k < n && isdigit( str[k] ))
		{
			result = result * 10 + (str[k] - '0');
			if (sign == 1 && result > INT_MAX )				
				return INT_MAX;
			if (sign == -1 && -result < INT_MIN)
				return INT_MIN;
			++k;
		}
		if (sign == -1)
			return -result;
		return result;
	}
};