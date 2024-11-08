class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
   //This approach is using recursion 
            // if(root== NULL) return NULL;

            // int cur = root->val;

            // if(cur<p->val && cur< q->val)
            //     return lowestCommonAncestor(root->right,p,q);
            // else if(cur>p->val && cur> q->val)
            //     return lowestCommonAncestor(root->left,p,q);
            // else 
            //     return root;    
    //This is done using while loop
            while(root){
                int cur = root->val;
                if(cur<p->val && cur< q->val)
                    root= root->right;
                else if(cur>p->val && cur> q->val)
                        root= root->left;
                else 
                    return root;
            }
            return NULL;
    }
};
