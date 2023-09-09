
//User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;,
    Node* right;
};
*/
class Solution{
    public:
    // preorder(root->left)
    // preorder(root->right)
    // cout<<root->data;
    
    
    vector<int> preOrder(TreeNode* root)
    {
        vector<int> ans;
        stack<pair<TreeNode* ,int>> st;
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
                ans.push_back(cur->data);
                st.push({cur,1});
            }else if(state == 1){
                st.push({cur,2});
                st.push({cur->left ,0});
               
            }else{
                st.push({cur->right,0});
            }
            
            
        }
        
        return ans;
    }
};

