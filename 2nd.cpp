#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTreeHelper(vector<int>& preOrder, vector<int>& inOrder, int preStart, int preEnd, int inStart, int inEnd){
    if(preOrder.empty() || inOrder.empty() || preStart > preEnd || inStart > inEnd){
        return NULL;
    }


    int root_val = preOrder[preStart];
    TreeNode* root = new TreeNode(root_val);
    int root_index = -1;

    for(int i = inStart; i <= inEnd; i++){
        if(inOrder[i] == root_val){
            root_index = i;
            break;
        }
    }

    if(root_index == -1)
        return NULL;

    // preorder now is from index = 1 to index = mid, both inclusive
    // inorder now is from beginning unitl mid, where mid is not included
    // root->left = buildTree();

    root->left = buildTreeHelper(preOrder, inOrder, preStart + 1, preStart + root_index - inStart, inStart, root_index - 1);

    // preorder is from index = mid + 1 to the end, mid+1 is included
    // inorder is from index = mid + 1 to the end, mid + 1 is included
    // root->right = buildTree();

    root->right = buildTreeHelper(preOrder, inOrder, preStart + root_index - inStart + 1, preEnd, root_index + 1, inEnd);

    return root;
}

TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder){
    return buildTreeHelper(preOrder, inOrder, 0, preOrder.size() - 1, 0, inOrder.size() - 1);
}

void treeToArray(TreeNode* root){
    vector<int> arr;
    
    if(!root)
        return ;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();

        if(curr){
            arr.push_back(curr->data);
            q.push(curr->left);
            q.push(curr->right);
        }else{
            arr.push_back(-1);
        }
    }

    while(!arr.empty() && arr.back() == -1){
        arr.pop_back();
    }

    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main()
{
    int n;

    cin>>n;

    vector<int> preOrder(n);
    vector<int> inOrder(n);

    for(int i = 0; i < n; i++){ 
        cin >> preOrder[i];
    }

    for(int i = 0; i < n; i++){
        cin >> inOrder[i];
    }

    TreeNode* root = buildTree(preOrder, inOrder);  

    treeToArray(root);
    return 0;
}
