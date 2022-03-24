    
bool isPairSum(Node *root, int sum, unordered_set<int> &s) 
    { 
        if(root==NULL)return false;
        
        if(isPairSum(root->left,sum,s)==true)
            return true;
            
        if(s.find(sum-root->key)!=s.end())  
            return true;
        else
            s.insert(root->key);
        return isPairSum(root->right,sum,s);
    } 

