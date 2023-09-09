//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(TreeNode* root)
    {
        //we'll use a stack for that , to store addresses of elements and there state.
        // state 0 = inorder(root->left);
        // state 1 = cout<<data;
        // state 2 = inorder(root->right);
        stack<pair<TreeNode*,int>> st;
        vector<int> v;
        if(root == NULL) return {};
        st.push({root,0});
        while(!st.empty()){
            TreeNode* cur = st.top().first;
            int state = st.top().second;
            st.pop();
            
            if(cur == NULL){
                continue;
            }
            if(state == 0){
                st.push({cur,1});
                st.push({cur->left,0});
            }else if(state == 1){
                v.push_back(cur->data);
                st.push({cur,2});
            }else{
                st.push({cur->right,0});
            }
        }
        return v;
    }
};
