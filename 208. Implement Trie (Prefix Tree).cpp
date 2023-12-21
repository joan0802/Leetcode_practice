class TrieNode {
public:
    TrieNode* child[26];
    bool terminate;

    TrieNode() {
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
        this->terminate = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* p = root;
        for(auto c: word) {
            int index = c-'a';
            if(p->child[index] == NULL)
                p->child[index] = new TrieNode();
            p = p->child[index];
        }
        p->terminate = true;
    }
    bool search(string word, bool prefix = false) {
        TrieNode* p = root;
        for(auto c: word) {
            int index = c-'a';
            if(p->child[index] == NULL)
                return false;
            p = p->child[index];
        }
        if(prefix == false) return p->terminate;
        return true;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */