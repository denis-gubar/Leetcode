/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        unordered_set<string> S;
        queue<string> Q;
        Q.push(startUrl);
        S.insert(startUrl);
        if (startUrl.back() != '/')
            startUrl.push_back('/');
        int N = startUrl.find('/', 8);
        while(!Q.empty())
        {
            string url = Q.front(); Q.pop();
            vector<string> urls = htmlParser.getUrls(url);
            for(string const& childUrl : urls)
                if (childUrl.size() >= N && equal(startUrl.begin(), startUrl.begin() + N, childUrl.begin(), childUrl.begin() + N) && (childUrl.size() == N || childUrl[N] == '/') && S.insert(childUrl).second)
                    Q.push(childUrl);
        }
        return vector<string>(S.begin(), S.end());
    }
};