#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *CreatNode(int val)
{
    struct TreeNode *Newnode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    Newnode->val = val;
    Newnode->left = NULL;
    Newnode->right = NULL;
}

struct TreeNode *insertAt_left(struct TreeNode *root, int val)
{
    root->left = CreatNode(val);
    return root->left;
}

struct TreeNode *insertAt_right(struct TreeNode *root, int val)
{
    root->right = CreatNode(val);
    return root->right;
}

void preorder_traversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->val);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    printf("%d ", root->val);
    inorder_traversal(root->right);
}

void postorder_taversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    postorder_taversal(root->left);
    postorder_taversal(root->right);
    printf("%d ", root->val);
}

int main()
{
    struct TreeNode *root, *left_child, *right_child, *left_sibling1,
        *left_sibling2, *right_sibling1, *right_siblings;
    int val;
    printf("Enter the root of the Binery Tree:");
    scanf("%d", &val);
    root = CreatNode(val);
    printf("Enter the left children of root:");
    scanf("%d", &val);
    left_child = insertAt_left(root, val);
    printf("Enter the right children of root:");
    scanf("%d", &val);
    right_child = insertAt_right(root, val);
    printf("Enter the left sibling of the left child:");
    scanf("%d", &val);
    left_sibling1 = insertAt_left(left_child, val);
    printf("Enter the right sibling of the left child:");
    scanf("%d", &val);
    left_sibling2 = insertAt_right(left_child, val);
    printf("Enter the left sibling of right Child:");
    scanf("%d", &val);
    right_sibling1 = insertAt_left(right_child, val);
    printf("Enter the right sibling of left sibling of right child:");
    scanf("%d", &val);
    right_siblings = insertAt_right(right_sibling1, val);
    printf("\n Result after preordered traversal:");
    preorder_traversal(root);
    printf("\n Result after inorder traversal:");
    inorder_traversal(root);
    printf("\n Result after postorder traversal:");
    postorder_taversal(root);
    return 0;
}