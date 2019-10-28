class Solution {
public:
    int find_position( const vector<string>& wordList, const string& word )
    {
        return distance( wordList.begin(), lower_bound( wordList.begin(), wordList.end(), word ) );
    }
    int ladderLength( string beginWord, string endWord, vector<string> wordList ) {
        if (find( wordList.begin(), wordList.end(), endWord ) == wordList.end())
            return 0;
        if (find( wordList.begin(), wordList.end(), beginWord ) == wordList.end())
            wordList.push_back( beginWord );
        sort( wordList.begin(), wordList.end() );
        int n = wordList.size();
        vector<list<int>> connectivity( n );
        for(int i = 0; i < n - 1; ++i)
            for(int j = i + 1; j < n; ++j)
            {
                int diff_count = 0;
                if (equal( wordList[i].begin(), wordList[i].end(), wordList[j].begin(), wordList[j].end(),
                           [&diff_count]( char a, char b ) -> bool
                           {
                               diff_count += a != b;
                               return  diff_count <= 1;
                           }) )
                {
                    connectivity[i].push_front( j );
                    connectivity[j].push_front( i );
                }
            }
        vector<int> distances( n, INT_MAX );
        int begin_position = find_position( wordList, beginWord );
        int end_position = find_position( wordList, endWord );
        distances[begin_position] = 1;
        list<int> not_visited;
        for (int i = 0; i < n; ++i)
            not_visited.push_front( i );
        for (int k = 0; k < n; ++k)
        {
            auto it = min_element( not_visited.begin(), not_visited.end(),
                                   [&distances]( int a, int b ) -> bool
                                   {
                                       return distances[a] < distances[b] || distances[a] == distances[b] && a < b;
                                   } );
            int current_index = *it;
            not_visited.erase( it );
            int current_distance = distances[current_index];
            for (const auto& connection : connectivity[current_index])
                if (distances[connection] > current_distance + 1)
                    distances[connection] = current_distance + 1;
            if (distances[end_position] < INT_MAX)
                return distances[end_position];
        }
        return 0;
    }
};
