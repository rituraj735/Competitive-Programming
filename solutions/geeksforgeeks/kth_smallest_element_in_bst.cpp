// Problem @: https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1
//O(N) time and O(N) space complexity
class Solution {
  public:
    Node* _inorder( struct Node* root, int k, int& count){
    if(root==NULL) return NULL;
    Node* left = _inorder(root->left,k,count);
    if(left!= NULL) return left;
    count++;
    if(count==k)
      return root;
    return _inorder(root->right,k,count);
}

    int KthSmallestElement(Node *root, int K) {
         int count = 0;
    Node* kth = NULL;
    kth = _inorder(root,K,count);
    return kth != NULL ?  kth->data: -1;
    }
};

// O(N) time and O(1) space complexity : Morris Traversal

