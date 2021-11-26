// Time Complexity = O(n)
// Space Complexity = O(1)
// Even stack also is not used




void morrisInorder(Node* root){
    vector<int>inorder;
    Node* curr = root;
    while(curr != NULL){
      
        // if left doesn't exists
        if(curr->left == NULL){
            inoder.push_back(curr->data);
            curr = curr->right;
        }
      
        // if left exists
        else{
            Node* rightMost = curr->left;
            
            while(rightMost->right && rightMost->right != root){
                rightMost = rightMost->right;
            }
         // code that decides whether to go left or right
            if(rightMost->right == curr){
                inoder.push_back(curr->data);
                rightMost->right = NULL;
                curr=curr->right;
            }
            else{
                rightMost->right = curr;
                curr=curr->left;
            }
        }
    }
}
