/*
Design a data structure that supports adding new words and finding if a string matches any previously added string.
Implement the WordDictionary class:
WordDictionary() Initializes the object.
void addWord(word) Adds word to the data structure, it can be matched later.
bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.

Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]
Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True
*/


struct TrieNode{
    bool end;
    vector<TrieNode*> child = vector<TrieNode*> (26,NULL);
};

class WordDictionary {
public:
    TrieNode *root;
    WordDictionary() {
        root=new TrieNode();
    }
    void addWord(string word) {
        TrieNode *curr=root;
        for(char c: word){
            int index=c-'a';
            if(!curr->child[index]){
                curr->child[index]=new TrieNode();
            }
            curr=curr->child[index];
        }
        curr->end=true;
    }
    bool helper(string word, TrieNode *root, int index){
        if(index==word.size()) return root->end;
        TrieNode *node=root;
        char ch=word[index];
        int ix=ch-'a';
        if(ch=='.'){
            for(int i=0;i<26;i++){
                if(node->child[i]){
                bool search = helper(word,node->child[i],index+1);
                if(search) return true;
                }
            }
            return false;
        }
        else{
            if(!node->child[ix])return false;
            return helper(word,node->child[ix],index+1);
        }
    }
    bool search(string word) {
        return helper(word,root,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
