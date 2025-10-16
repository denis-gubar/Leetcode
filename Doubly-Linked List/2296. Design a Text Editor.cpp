class TextEditor {
public:
    TextEditor(): it(data.begin()) {
        
    }
    
    void addText(string text) {
        for (char c : text)
        {
            it = data.insert(it, c);
            ++it;
        }
    }
    
    int deleteText(int k) {
        int result = 0;
        while (k > 0)
        {
            if (it != data.begin())
                data.erase(prev(it)), ++result;
            else
                break;
            --k;
        }
        return result;
    }
    
    string cursorLeft(int k) {
        string result;
        while (k > 0)
        {
            if (it != data.begin())
                --it;
            else
                break;
            --k;
        }
        for (auto i = it; i != data.begin() && result.size() < 10; --i)
            result += *prev(i);
        reverse(result.begin(), result.end());
        return result;
    }
    
    string cursorRight(int k) {
        string result;
        while (k > 0)
        {
            if (it != data.end())
                ++it;
            else
                break;
            --k;
        }
        for (auto i = it; i != data.begin() && result.size() < 10; --i)
            result += *prev(i);
        reverse(result.begin(), result.end());
        return result;
    }
    list<char> data;
    list<char>::iterator it;
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
