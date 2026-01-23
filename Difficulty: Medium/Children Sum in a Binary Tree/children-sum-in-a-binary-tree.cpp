class Solution {
public:
    bool isSumProperty(Node* root) {
        
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        
        int leftData = 0, rightData = 0;
        
        if (root->left != NULL)
            leftData = root->left->data;
        
        if (root->right != NULL)
            rightData = root->right->data;
        
        if (root->data == leftData + rightData &&
            isSumProperty(root->left) &&
            isSumProperty(root->right))
            return true;
        
        return false;
    }
};
