#include <bits/stdc++.h>

using namespace std;

struct node
{
    char currentCharacter;
    bool isWord;
    struct node *children[27]; // [null,null,null,......,null]
} * trie;

void init()
{
    trie = new node();
    trie->isWord = false; // Instanciar el objeto trie
}

void insertWord(string word)
{ // alba
    node *currentNode = trie;
    for (int i = 0; i < word.length(); i++)
    {                                            // alba
        int character = (int)word[i] - (int)'a'; // i = 0 'a'-'a' = 0
        if (currentNode->children[character] == NULL)
        {
            currentNode->children[character] = new node();
        }
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
    }
    currentNode->isWord = true;
}

bool searchWord(string word)
{ // alto
    node *currentNode = trie;
    for (int i = 0; i < word.length(); i++)
    {
        int character = (int)word[i] - (int)'a'; // i = 0 'a'-'a' = 0
        if (currentNode->children[character] == NULL)
        {
            return false;
        }
        currentNode = currentNode->children[character];
    }
    return currentNode->isWord;
}
int main()
{
    init();
    cout << "Hola" << endl;
    insertWord("ana");
    insertWord("analitico");
    insertWord("analizar");
    cout << searchWord("analizar") << endl;
}
