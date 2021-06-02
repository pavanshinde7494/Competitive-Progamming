#include<bits/stdc++.h>
using namespace std;

int const SIZE = 26;

// Trie structure
struct  Node
{
    // No of string with given prefix
    int count;

    // End of word or not
    bool endOfWord;

    // Ways to form strings
    Node* arr[SIZE];
};


// Creating new trie node

Node* createNode()
{
    Node* n = new Node;
    n->count = 0;
    n->endOfWord = false;
    for (int i = 0; i < SIZE; i++)
        n->arr[i] = NULL;
    return n;
}

// Insertion new string to trie
void insert(Node* root , string str)
{
    Node* temp = root;
  
    // Incrementing prefix string count
    temp->count++;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if (temp->arr[index] == NULL)
        {

            // if particular node in path is not present
            // then create it
            temp->arr[index] = createNode();
        }
      
        // Incrementing prefix string count
        temp->arr[index]->count++;
      
        // moving forward 
        temp = temp->arr[index];
    }
    temp->endOfWord = true;
}

Node* search(Node* root , string str)
{
    Node* temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if (temp->arr[index] != NULL)
        {

            // if a character in path exists then move forward
            temp = temp->arr[index];
            continue;
        }
        else
        {

           // if a character in path is not exists then string not found
           return NULL;
        }
    }

    // if string found and it is word in trie then found else not found
    if (temp->endOfWord)
        return temp;
    return NULL;
}



void autoSuggesting(Node* root , string str , vector<string>& sugg)
{
  

    // If we are reaching place where the is end of word
    if (root->endOfWord)
        sugg.push_back(str);

    // Travesing for presence any possible occurance of character for in node of trie
    for (int i = 0; i < SIZE; i++)
    {
        if (root->arr[i] != NULL)
        {

            char strToTraverse = (char)('a' + i);
            string strTo  = str + strToTraverse;
            autoSuggesting(root->arr[i] , strTo , sugg);
        }
    }
}

vector<string> suggestions(Node* root , string str , vector<string>& sugg)
{

    // Upto line 113 : is just to check whether given str present in trie or not
    // if no return empty sugg vector
    // else recurse in autoSuggestion function
    Node* temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        int index = str[i] - 'a';
        if (temp->arr[index] != NULL)
        {
            temp = temp->arr[index];
            continue;
        }
        else
            return sugg;
    }

    // Making recursion in autoSuggestion function
    autoSuggesting(temp , str , sugg);
    return sugg;
}


int preFixes(Node* root , string str)
{
    
    // Just we have to go to given string in trie
    Node* temp = search(root , str);
  
    // If string doesn't exists in trie then just return 0 else just return count
    if (temp == NULL)
        return 0;
    return temp->count;
}


int main()
{
    Node* root;
    root = createNode();

    while (1)
    {
        int code;
        cin >> code;
        if (code == 1)
        {
            string str;
            cout << "\nEnter String to Insert :\n";
            cin >> str;
            insert(root, str);

        }
        else if (code == 2)
        {
            string str;
            cout << "\nEnter String to Search :\n";
            cin >> str;
            cout << search(root , str);
        }
        else if (code == 3)
        {
            string str;
            cout << "\nEnter String to Auto Suggest :\n";
            cin >> str;
            vector<string>sugg;
            suggestions(root , str , sugg);
            cout << "\nSuggetions:\n";
            for (int i = 0; i < sugg.size(); i++)
                cout << sugg[i] << "\n";
        }
        else if (code == 4)
        {
            string str;
            cout << "\nEnter String to Find no. of Prefixes :\n";
            cin >> str;
            cout << preFixes(root , str);
        }

        else
            break;
    }
}

