class Node {
    public:
        unordered_map<char, Node*> descend;
        bool wordEnd = false;
};

class PrefixTree {
    Node* root;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;
        for(char c: word){
            if(cur->descend.find(c) == cur->descend.end()){
                cur->descend[c] = new Node();
            }
            cur = cur->descend[c];
        }
        cur->wordEnd = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(char c: word){
            if(cur->descend.find(c) == cur->descend.end()){
                return false;
            }
            cur = cur->descend[c];
        }

        return cur->wordEnd;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(char c: prefix){
            if(cur->descend.find(c) == cur->descend.end()){
                return false;
            }

            cur = cur->descend[c];
        }

        return true;
    }
};
