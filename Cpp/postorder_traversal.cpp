#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
#include <stack>
/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};
*/
    void postOrder(Node *root) {
        /** Recursive solution
        if(!root)
            return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
        **/
        /*
        // Iterative solution
        */
        stack<Node*> node_stack;
        Node* curr = root;
        while(curr || !node_stack.empty()) {
            while(curr) {
                if(curr->right)
                    node_stack.push(curr->right);
                node_stack.push(curr);
                curr = curr->left;
            }
            // Now curr is NULL 
            curr = node_stack.top();
            node_stack.pop();
            if(!node_stack.empty()) {
                if(curr->right && curr->right == node_stack.top()) {
                    node_stack.pop();
                    node_stack.push(curr);
                    curr = curr->right;
                }
                else {
                    cout << curr->data << " ";
                    curr = NULL;
                }
            } else{
                cout << curr->data;
                curr = NULL;
            }
        }
    }
}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.postOrder(root);
    return 0;
}
