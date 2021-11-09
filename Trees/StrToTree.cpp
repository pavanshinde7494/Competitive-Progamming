

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}



// Finding position of closing parenthesis
// corresponding to given opening parenthsis

int boundry(string& str, int si, int ei) {
    stack<char>stk;
    for (int i = si; i <= ei; i++) {
        if (str[i] == '(')
            stk.push('(');
        else if (str[i] == ')')
            stk.pop();
        if (stk.empty())return i;
    }
    return -1;
}


// 4(2(3)(1))(6(5))

Node* stringToTree(string& str, int si, int ei) {
    if (si > ei)return NULL;

    int curVal = (int)(str[si] - '0');

    Node* curNode = createNode(curVal);

    int index = boundry(str, si + 1, ei);
    if (index != -1) {

        // 4(  {2(3)(1)}  )(6(5))
        curNode->left = stringToTree(str, si + 2, index - 1);
        // 4(2(3)(1))(  {6(5)}  )
        curNode->right = stringToTree(str, index + 2, ei - 1);
    }
    return curNode;
}



void bfs(Node* root) {
    if (root == NULL)return;
    cout << root->data << " ";
    bfs(root->left);
    bfs(root->right);
}



int main() {
    fast_io;
    file();
    string str;
    cin >> str;
    Node* root = stringToTree(str, 0, str.length() - 1);

    bfs(root);

    return 0;
}
