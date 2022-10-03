#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
struct node
{
    map<char, node *> mapero;
    string company;
    bool isWord;
    int level;
} * trie;

void init()
{
    trie = new node();
    trie->isWord = false;
}

void insertWord(string word)
{
    node *currentNode = trie;
    for (int i = 0; i < word.length(); i++)
    {
        if (currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            currentNode->mapero[word[i]] = new node();
            currentNode->mapero[word[i]]->isWord = false;
            currentNode->mapero[word[i]]->level = 0;
        }
        currentNode = currentNode->mapero[word[i]];
        currentNode->level++;
    }
    currentNode->isWord = true;
}

bool searchWord(string word)
{ // alto
    node *currentNode = trie;
    for (int i = 0; i < word.length(); i++)
    {
        int character = word[i]; // i = 0 'a'-'a' = 0
        if (currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            return false;
        }
        currentNode = currentNode->mapero[word[i]];
        cout << character << " -> " << currentNode->level << endl; // Para comprobar el nivel y el caracter
    }
    return currentNode->isWord;
}

void deleteWord(string word)
{
    if (searchWord(word))
    {
        node *currentNode = trie;
        bool betweenNodes = true;
        int character;
        for (int i = 0; i < word.length(); i++)
        {
            character = word[i]; // i = 0 'a'-'a' = 0
            if (currentNode->mapero[word[i]]->level == 1)
            {
                betweenNodes = false;
                break;
            }
            else
            {
                currentNode = currentNode->mapero[word[i]];
            }
            currentNode->level--;
        }
        if (betweenNodes)
        {
            currentNode->isWord = false;
        }
        else
        {
            currentNode->mapero.erase(character);
        }
    }
    else
    {
        cout << "La palabra no existe en el diccionario" << endl;
    }
}

int main()
{
    init();
    insertWord("paul");
    insertWord("pata");
    insertWord("pa");
    deleteWord("paul");
    cout << searchWord("pata") << endl;
    return 0;
}