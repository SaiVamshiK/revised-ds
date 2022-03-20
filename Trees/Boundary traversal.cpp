bool isLeaf(Node *root){
        if((!root->left)&&(!root->right)){
            return true;
        }
        return false;
    }
    void leftBoundary(Node *root,vector<int> &leftBoundaryNodes){
        if(!root){
            return ;
        }
        if(isLeaf(root)){
            return ;
        }
        leftBoundaryNodes.push_back(root->data);
        if(root->left){
            leftBoundary(root->left,leftBoundaryNodes);
        }else{
            if(root->right){
                leftBoundary(root->right,leftBoundaryNodes);
            }
        }
    }
    void getLeafNodes(Node *root,vector<int> &leafNodes){
        if(root == nullptr){
            return ;
        }
        if(isLeaf(root)){
            leafNodes.push_back(root->data);
            return ;
        }
        getLeafNodes(root->left,leafNodes);
        getLeafNodes(root->right,leafNodes);
    }
    void rightBoundary(Node *root,vector<int> &rightBoundaryNodes){
        if(!root){
            return ;
        }
        if(isLeaf(root)){
            return ;
        }
        rightBoundaryNodes.push_back(root->data);
        if(root->right){
            rightBoundary(root->right,rightBoundaryNodes);
        }else{
            if(root->left){
                rightBoundary(root->left,rightBoundaryNodes);
            }
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root){
            return ans;
        }
        vector<int> leftBoundaryNodes;
        leftBoundary(root->left,leftBoundaryNodes);
        vector<int> leafNodes;
        getLeafNodes(root,leafNodes);
        vector<int> rightBoundaryNodes;
        rightBoundary(root->right,rightBoundaryNodes);
        ans.push_back(root->data);
        if(isLeaf(root)){
            return ans;
        }
        for(int i=0;i<leftBoundaryNodes.size();i++){
            ans.push_back(leftBoundaryNodes[i]);
        }
        for(int i=0;i<leafNodes.size();i++){
            ans.push_back(leafNodes[i]);
        }
        reverse(rightBoundaryNodes.begin(),rightBoundaryNodes.end());
        for(int i=0;i<rightBoundaryNodes.size();i++){
            ans.push_back(rightBoundaryNodes[i]);
        }
        return ans;
    }
