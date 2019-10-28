class FileSystem {
public:
	FileSystem() {
		M.clear();
	}

	string getParent(string path)
	{
		reverse(path.begin(), path.end());
		path += '/';
        path = path.substr(path.find('/') + 1);
		path.pop_back();
		reverse(path.begin(), path.end());
		return path;
	}

	bool create(string path, int value) {
		if (M.find(path) == M.end())
		{
			string parent = getParent(path);
			if (parent == "" || M.find(parent) != M.end())
			{
				M[path] = value;
				return true;
			}
		}
		return false;
	}

	int get(string path) {
		if (M.find(path) == M.end())
			return -1;
		return M[path];
	}
	map<string, int> M;
};