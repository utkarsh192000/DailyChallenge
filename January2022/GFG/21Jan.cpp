#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// Returns true if the given tree node is a leaf; false otherwise
bool isLeaf(TreeNode *root)
{
    return root != NULL && root->left == NULL && root->right == NULL;
}

// Function to extract leaves of a binary tree into a doubly linked list
TreeNode *construct(TreeNode *root, TreeNode *&head, TreeNode *&prev)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }

    bool is_leaf = isLeaf(root);

    // recur for the left subtree
    root->left = construct(root->left, head, prev);

    // if the current node is a leaf
    if (is_leaf)
    {
        // This is true only for the leftmost leaf node
        if (head == NULL)
        {
            // point the head of the doubly linked list to the
            // current leaf node and initialize the prev pointer
            head = prev = root;
        }
        else
        {
            // set left pointer of the current node to the prev
            // of the doubly linked list
            root->left = prev;

            // set the right pointer of the prev to the current node
            prev->right = root;

            // update the prev
            prev = root;
        }

        // return null to remove the current node from the binary tree
        return NULL;
    }

    // recur for the right subtree
    root->right = construct(root->right, head, prev);

    // return the root node
    return root;
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void printDDL(TreeNode *head)
{
    while (head != NULL)
    {
        cout << head->val << ' ';
        head = head->right;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->right->left->left = new TreeNode(10);
    root->right->left->right = new TreeNode(11);

    // to keep track of the head of the doubly linked list
    TreeNode *head = NULL;

    // to keep track of the prev of the doubly linked list
    TreeNode *prev = NULL;

    TreeNode *newRoot = construct(root, head, prev);

    cout << "Extracted doubly linked list is ";
    printDDL(head);

    cout << "\nInorder traversal of the final tree is ";
    inorder(newRoot);

    return 0;
}