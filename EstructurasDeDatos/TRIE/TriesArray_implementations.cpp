#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

// Implementations for TRIE prefix tree:
// -> Delete words
// -> Search phrase
// -> Letters Soup
struct node
{
    char currentCharacter;
    bool isWord;
    node *children[27]; // [null,null,null,......,null]
    int level; // Atributo
} * trie;
// Inicializar

void init()
{
    trie = new node(); // Instanciar el objeto trie
    trie->isWord = false;
    trie->level = 0;
}

void insertWord(string word)
{
    node *currentNode;
    currentNode = trie;
    for (int i = 0; i < word.length(); i++)
    {                                          
        int character = (int)word[i] - (int)'a';
        if (currentNode->children[character] == NULL)
        {
            currentNode->children[character] = new node();
            currentNode->children[character]->isWord = false;
        }
        currentNode = currentNode->children[character];
        currentNode->currentCharacter = word[i];
        currentNode->level++;
    }
    currentNode->isWord = true;
}

bool searchWord(string word)
{
    node *currentNode = trie;
    for (int i = 0; i < word.length(); i++)
    {
        int character = word[i] - 'a';
        if (currentNode->children[character] == NULL)
        {
            return false;
        }
        currentNode = currentNode->children[character];
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
            character = word[i] - 'a'; // i = 0 'a'-'a' = 0
            if (currentNode->children[character]->level == 1)
            {
                betweenNodes = false;
                break;
            }
            else
            {
                currentNode = currentNode->children[character];
            }
            currentNode->level--;
        }
        if (betweenNodes)
        {
            currentNode->isWord = false;
        }
        else
        {
            currentNode->children[character] = NULL;
        }
    }
    else
    {
        cout << "La palabra no existe en el diccionario" << endl;
    }
}

// [paul, rata, como, no, mono]
//¿Se puede formar "comonopaul"?
//¿Se puede formar "comorata"?

bool searchPhrase(string word)
{
    word = " " + word;
    bool phrase[word.length()];
    memset(phrase, false, sizeof(phrase));
    phrase[0] = true;
    for (int i = 0; i < word.length(); i++)
    {
        node *currentNode = trie;
        if (phrase[i])
        {
            for (int j = i + 1; j < word.length(); j++)
            {
                int character = word[j] - 'a';
                if (currentNode->children[character] == NULL)
                {
                    break;
                }
                else
                {
                    currentNode = currentNode->children[character];
                    if (currentNode->isWord || phrase[j])
                    {
                        phrase[j] = true;
                    }
                    else
                    {
                        phrase[j] = false;
                    }
                }
            }
        }
    }
    return phrase[word.length() - 1];
}
// Dada una sopa dfe letrAS verifica si una palabra existe:
// Movimientos permitidos ->, <-, up, down

// DFS -> Todas las combinaciones posibles.
// Insert Word - > Todos los nodos son isWord = true.
// searchWord(word) - > Únicamente verificar si existe la palabra en el trie generado.\

// Main 1: Para el método deleteWord
/*
int main()
{
    init();
    insertWord("paul");
    insertWord("pata");
    insertWord("pa");
    deleteWord("paul");
    cout << searchWord("pa")<<endl;
    return 0;
}
*/
// Main 2: Para el método SearchPhrase
/*int main()
{
    init();
    insertWord("como");
    insertWord("co");
    insertWord("debian");
    insertWord("marta");
    insertWord("mono");
    insertWord("pata");
    insertWord("paul");
    cout << searchPhrase("debianpaul") << endl;
    // searchPhrase("mono");
    return 0;
}*/

// Main 3: Para el método lettersSoup

int main()
{
    input;
    int n, m;
    scanf("%d %d", &n, &m);
    char lettersS[n][m];
    int movf[4] = {1, 0, 0, -1};
    int movc[4] = {0, 1, -1, 0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> lettersS[i][j];
        }
    }
    string word;
    cin >> word;
    init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char letter = lettersS[i][j];
            if (word[0] == letter)
            {
                node *currentNode = trie;
                for (int k = 0; k < 4; k++)
                {
                    currentNode = trie;
                    int currentR = i;
                    int currentC = j;
                    while ((currentR < n && currentR >= 0) && (currentC < m && currentC >= 0))
                    {
                        letter = lettersS[currentR][currentC];
                        if (currentNode->children[letter - 'a'] == NULL)
                        {
                            currentNode->children[letter - 'a'] = new node();
                            currentNode->children[letter - 'a']->isWord = true;
                        }
                        currentNode = currentNode->children[letter - 'a'];
                        currentNode->currentCharacter = letter;
                        currentR = currentR + movf[k];
                        currentC = currentC + movc[k];
                    }
                }
            }
        }
    }
    cout << searchWord(word) << endl;
}
