class Node {
private:
    Node* links[26];
    int start, end;
public:
    Node() {
        for (int i=0;i<26;i++) links[i] = NULL; 
        start = end = 0;
    }
    
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch) {
        links[ch-'a'] = new Node();
    }
    
    Node* get(char ch) {
        return links[ch-'a'];
    }
    
    void incStart() {
        start++;
    } 
    
    void decStart() {
        start--;
    }
    
    int numStart() {
        return start;
    }
    
    void incEnd() {
        end++;
    } 
    
    void decEnd() {
        end--;
    }
    
    int numEnd() {
        return end;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string &word){
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch);
            }
            node = node->get(ch);
            node->incStart();
        }
        node->incEnd();
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->numEnd();
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->get(ch);
        }
        return node->numStart();
    }

    void erase(string &word){
        Node* node = root;
        for (char ch : word) {
            node = node->get(ch);
            node->decStart();
        }
        node->decEnd();
    }
};


/*
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int a = obj->countWordsEqualTo(word);
 * int b = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
