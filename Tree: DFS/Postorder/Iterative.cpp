// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution{
    public:
    vector<int> postOrder(TreeNode* root) {
        // create a stack of pair of node* and int
        //ans vector to return
        //if state = 0, left subtree , proceed to state 1;
        //state =1, right subtree, proceed to state 2;
        //state= 3, work on self.
        
        stack<pair<TreeNode* , int>> st;
        vector<int> ans;
        if(root == NULL) return {};
        
        st.push({root,0});
        while(!st.empty()){
            TreeNode* cur = st.top().first;
            int state = st.top().second;
            st.pop();
            
            if(cur == NULL) continue;
            
            if(state == 0){
                
                st.push({cur,1});
                st.push({cur->left,0});
            }if(state==1){
                
                st.push({cur,2});
                st.push({cur->right,0});
            }if(state == 2){
                
                ans.push_back(cur->data);
            }
        }
        
        
        
        return ans;
    }
};
