//144. 二叉树的前序遍历
//https://leetcode.cn/problems/binary-tree-preorder-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */
int TreeSize(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

void preorder(struct TreeNode* root, int* a, int* pi)
{
    if (root == NULL)
        return;

    a[(*pi)++] = root->val;

    preorder(root->left, a, pi);
    preorder(root->right, a, pi);

}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int n = TreeSize(root);
    int* a = (int*)malloc(sizeof(int) * n);

    int i = 0;
    preorder(root, a, &i);
    *returnSize = n;
    return a;
}