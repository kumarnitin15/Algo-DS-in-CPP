struct TrieNode {
     TrieNode *children[ALPHABET_SIZE];
     bool isEndOfWord;
};

TrieNode *getNode(void) { 
    TrieNode *pNode =  new TrieNode; 
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
}