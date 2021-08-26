// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int result = 0, count = 0;
        while(result + 4 <= n)
        {
            count = read4(buf + result);
            result += count;
            if (count < 4 || result == n)
                return result;
        }        
        char smallbuf[4];
        count = read4(smallbuf);
        int i = 0;
        while(result < n && i < count)
        {
            buf[result] = smallbuf[i];
            ++i; ++result;
        }            
        return result;
    }
};