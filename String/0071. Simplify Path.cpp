class Solution {
public:
    string simplifyPath( string path ) {
        string result = "/";
        path += "/";
        int n = path.size();
        int i = 0;
        while (path.find( '/', i + 1 ) != string::npos)
        {
            int j = path.find( '/', i + 1 );
            string s = path.substr( i + 1, j - i - 1 );
            if (s == string() || s == ".")
            {

            }
            else if (s == "..")
            {
                int k = result.size() - 1;
                while (k >= 0 && result[k] != '/')
                    --k;
                if (k > 0)
                    result = result.substr( 0, k );
                else
                    result = "/";
            }
            else
            {
                if (result.back() != '/')
                    result += "/";
                result += s;
            }
            i = j;
        }
        return result;
    }
};