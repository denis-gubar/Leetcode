class FileSystem {
public:
    vector<string> split(const string& s, char delimeter = '/')
    {
        vector<string> result;
        istringstream ss(s);
        for (string token; !ss.eof(); )
        {
            getline(ss, token, delimeter);
            result.push_back(token);
        }
        return result;
    }
    struct Directory
    {
        string name;
        map<string, string> files;
        vector<Directory> childDirectories;
    };
    FileSystem() : root{ "", {}, {} } {
        
    }
    
    vector<string> ls(string path) {
        vector<string> result;
		vector<string> elements = split(path);
		Directory* node = &root;
		int N = elements.size();
        for (int i = 1; i < N; ++i)
        {
            bool found = false;
            for (Directory& dir : node->childDirectories)
                if (dir.name == elements[i])
                {
                    node = &dir;
                    found = true;
                    break;
                }
            if (!found)
            {
                if (i + 1 == N)
                {
                    auto it = node->files.find(elements.back());
                    if (it != node->files.end())
                    {
                        return { elements.back() };
                    }
                }
                else
                    return {};
            }
        }
        for (Directory& dir : node->childDirectories)
            result.push_back(dir.name);
		for (auto& [key, value] : node->files)
			result.push_back(key);
        sort(result.begin(), result.end());
        return result;
    }
    
    void mkdir(string path) {
        vector<string> elements = split(path);
        Directory* node = &root;
        int N = elements.size();
        for(int i = 1; i < N; ++i)
        {
            bool found = false;
            for(Directory& dir : node->childDirectories)
                if (dir.name == elements[i])
                {
                    node = &dir;
                    found = true;
                    break;
                }
            if (!found)
            {
                node->childDirectories.push_back({ elements[i], {}, {} });
                node = &node->childDirectories.back();
            }
        }
    }
    
    void addContentToFile(string filePath, string content) {
		vector<string> elements = split(filePath);
		Directory* node = &root;
		int N = elements.size();
		for (int i = 1; i < N - 1; ++i)
		{
			bool found = false;
			for (Directory& dir : node->childDirectories)
				if (dir.name == elements[i])
				{
					node = &dir;
					found = true;
					break;
				}
            if (!found)
            {
                node->childDirectories.push_back({ elements[i], {}, {} });
                node = &node->childDirectories.back();
            }
		}
        node->files[elements.back()] += content;
    }
    
    string readContentFromFile(string filePath) {
		vector<string> elements = split(filePath);
		Directory* node = &root;
		int N = elements.size();
		for (int i = 1; i < N - 1; ++i)
		{
			bool found = false;
			for (Directory& dir : node->childDirectories)
				if (dir.name == elements[i])
				{
					node = &dir;
					found = true;
					break;
				}
            if (!found)
            {
                node->childDirectories.push_back({ elements[i], {}, {} });
                node = &node->childDirectories.back();
            }
		}
        return node->files[elements.back()];
    }
    Directory root;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
