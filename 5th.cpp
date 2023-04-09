#include <iostream>
#include <vector>
#include <stack>
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

int kthLargest(TreeNode* root, int k){
    int count = 0;
    stack<TreeNode*> st;
    TreeNode* temp = root;

    while(!st.empty() || temp != NULL){
        if(temp != NULL){
            st.push(temp);
            temp = temp->right;
        }else{
            temp = st.top();
            st.pop();
            count++;

            if(count == k)
                return temp->data;

            temp = temp->left;
        }
    }

    return -1;
}

int main()
{
    int n, k;
    vector<int> arr(n);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;

    TreeNode* root = NULL;

    for(int i = 0; i < n; i++){
        if(arr[i] == -1)
            continue;

        TreeNode* newNode = new TreeNode(arr[i]);
        if(!root)
            root = newNode;
        else{
            TreeNode* parent = root;
            while(true){
                if(arr[i] < parent->data){
                    if(!parent->left){
                        parent->left = newNode;
                        break;
                    }
                    parent = parent->left;
                }
                else{
                    if(!parent->right){
                        parent->right = newNode;
                        break;
                    }
                    parent = parent->right;
                }
            }
        }
    }

    cout << kthLargest(root, k) << endl;
    return 0;
}