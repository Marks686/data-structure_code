//965. 单值二叉树
//https://leetcode.cn/problems/univalued-binary-tree/
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }

    if (root->left && root->val != root->left->val)
    {
        return false;
    }

    if (root->right && root->val != root->right->val)
    {
        return false;
    }

    return isUnivalTree(root->left)
        && isUnivalTree(root->right);

}

//100. 相同的树
//https://leetcode.cn/problems/same-tree/
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }


    if (p == NULL || q == NULL)
    {
        return false;
    }

    if ((p->val != q->val))
    {
        return false;
    }



    return isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}

//572. 另一棵树的子树
//https://leetcode.cn/problems/subtree-of-another-tree/
//原树种每棵子树跟subRoot树比较
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }


    if (p == NULL || q == NULL)
    {
        return false;
    }

    if ((p->val != q->val))
    {
        return false;
    }



    return isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
    {
        return false;
    }

    if (isSameTree(root, subRoot))
    {
        return true;
    }

    return isSubtree(root->left, subRoot)
        || isSubtree(root->right, subRoot);
}