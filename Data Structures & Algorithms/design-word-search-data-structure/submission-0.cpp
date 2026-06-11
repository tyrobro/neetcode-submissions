class Node {
    public:
        vector<Node*> descend;
        bool word;

        Node(): descend(26, nullptr), word(false) {}
};

class WordDictionary {
public:
    Node* root;
    WordDictionary(): root(new Node()) {}
    
    void addWord(string word) {
        Node* cur = root;
        for(char c: word){
            if(cur->descend[c-'a'] == nullptr){
                cur->descend[c-'a'] = new Node();
            }

            cur = cur->descend[c-'a'];
        } 

        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    private:
        bool dfs(string word, int j, Node* root){
            Node* cur = root;
            int n = word.size();

            for(int i = j; i < n; i++){
                char c = word[i];
                if(c == '.') {
                    for(Node* child : cur->descend){
                        if(child != nullptr && dfs(word, i+1, child)) {
                            return true;
                        }
                    }

                    return false;
                } else {
                    if(cur->descend[c-'a'] == nullptr){
                        return false;
                    }
                    cur = cur->descend[c-'a'];
                }
            }

            return cur->word;
        }
};
