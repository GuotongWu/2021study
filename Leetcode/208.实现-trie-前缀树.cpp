/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// @lc code=start
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
public:
    /** Initialize your data structure here. */
    Trie(): children(26), isEnd(false) {}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie * node = this;
        for(auto ch : word){
            int u = ch - 'a';
            if(node->children[u] == nullptr)
                node->children[u] = new Trie();
            node = node->children[u];
        }
        node->isEnd = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie * node = this;
        for(auto ch : word){
            int u = ch - 'a';
            if(node->children[u] == nullptr)
                return false;
            node = node->children[u];
        }
        if(node->isEnd)
            return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie * node = this;
        for(auto ch : prefix){
            int u = ch - 'a';
            if(node->children[u] == nullptr)
                return false;
            node = node->children[u];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
int main(){
    Trie* obj = new Trie();
    return 0;
}