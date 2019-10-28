// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    Solution(): smallbufCount(0), rest(smallbuf) {}
    int read(char *buf, int n) {
        int result = 0, count = 0;
        while(result < n && smallbufCount > 0)
        {
            buf[result] = *rest;
            --smallbufCount; ++result; ++rest;
        }
        if (result == n)
            return result;
        while(result + 4 <= n)
        {
            count = read4(buf + result);
            result += count;
            if (count < 4 || result == n)
                return result;
        }        
        smallbufCount = read4(smallbuf);
        rest = smallbuf;
        while(result < n && smallbufCount > 0)
        {
            buf[result] = *rest;
            --smallbufCount; ++result; ++rest;
        }           
        return result;
    }
    char smallbuf[4];
    int smallbufCount;
    char* rest;
};