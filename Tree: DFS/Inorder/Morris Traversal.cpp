/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curNode = root;
        vector<int> nodes;
        
        while (curNode != NULL) 
        {
            if (curNode -> left) 
            {
				//Find the inorder predecessor of current
               //ifa) Make current as right child of the rightmost node in current's left subtree
                TreeNode* predecessor = curNode -> left;
                while (predecessor -> right && predecessor -> right != curNode) //second condition used when reverting
                    predecessor = predecessor -> right;
                
                if ((predecessor -> right)==NULL) 
                {
                    predecessor -> right = curNode;
                    curNode = curNode -> left; //ifb) Go to this left child
                }
                else 
                {
                    //Revert back the changes
                    predecessor -> right = NULL;
                    nodes.push_back(curNode -> val);
                    curNode = curNode -> right;
                }
            }
            else 
            {
                nodes.push_back(curNode -> val);  //ea)
                curNode = curNode -> right;  //eb)
            }
        }
        
        return nodes;
    }
};
