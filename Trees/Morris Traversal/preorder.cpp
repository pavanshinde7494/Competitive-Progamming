// Time Complexity = O(n)
// Space Complexity = O(1)
// Even stack also is not used




void morrisPreorder(Node* root){
    vector<int>preorder;
    Node* curr = root;
    while(curr != NULL){
      
        // if left doesn't exists
        if(curr->left == NULL){
            preoder.push_back(curr->data);
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
                rightMost->right = NULL;
                curr=curr->right;
            }
            else{
                preoder.push_back(curr->data);
                rightMost->right = curr;
                curr=curr->left;
            }
        }
    }
}
