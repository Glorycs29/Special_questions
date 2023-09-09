

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> curLevel;
            for(int i=0; i<size; i++){
                Node* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                for(Node* child : cur->children){
                    q.push(child);
                }
            }
            res.push_back(curLevel);
        }
        return res;
    }
};


//----------------------------------------------------------------------------------------------------------------------------------


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> curLevel;
            for(int i=0; i<size; i++){
                Node* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                for (int j = 0; j < cur->children.size(); ++j) {
                    if (cur->children[j])
                        q.push(cur->children[j]);
                }
            }
            res.push_back(curLevel);
        }
        return res;
    }
};
