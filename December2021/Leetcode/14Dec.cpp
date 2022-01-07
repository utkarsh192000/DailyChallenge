#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

int rangeSumBST(TreeNode*root,int low,int high){
    if(root==NULL){
        return 0;
    }
    // whenever we reach to the leaf node it simply means its a base condition therefore it must return 0; also 
    // there is no node 
    if(root->val>high){
        return rangeSumBST(root->left,low,high);
        // since the root's value itself greater than high; which means all value right of the root will be even greater ; 
        // so no use of searching toward right ; so just search toward left of it  
    }
    if(root->val<low){
        return rangeSumBST(root->right,low,high);
        //// since the root's value itself less than low; which means all value left of the root will be even smalller; 
        // ans they will not come in our range  
        // so no use of searching toward left ; so just search toward right of it  

    }
    return (root->val)+rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high);
    // but the third case can be when values are in the range ; so we need to take that value along with all the result
    //  that has came from left of it and right of it ans return it 
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

int main()
{

    TreeNode *root = new TreeNode(11);
    TreeNode *n1 = new TreeNode(6);
    TreeNode *n2 = new TreeNode(12);
    TreeNode *n3 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(9);
    TreeNode *n5 = new TreeNode(13);
    TreeNode *n6 = new TreeNode(8);
    TreeNode *n7 = new TreeNode(10);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = NULL;
    n2->right = n5;

    n3->left = NULL;
    n3->right = NULL;

    n4->left = n6;
    n4->right = n7;

    n5->left = NULL;
    n5->right = NULL;

    n6->left = NULL;
    n6->right = NULL;

    n7->left = NULL;
    n7->right = NULL;

    inorder(root);
    cout << endl;

    int low,high;
    cin>>low>>high;

    cout<<rangeSumBST(root,low,high)<<endl;



    return 0;
}


/*


Q) we take this tree as a example 

                        11
                      /    \
                    6       12
                  /  \      /  \
                5     9        13 
                    /  \               
                   8   10 

    For example lets take low=6 , high=11 ; the answer would be 11+6+9+8+10 =44

    check 11 ; case 3 ; take the value go to left go to right  


   

*/
