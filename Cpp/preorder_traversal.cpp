#include <bits/stdc++.h>
#include <stack>
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
    /**
    // this is recursive solution
    void preOrder(Node *root) {
        if(!root)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }**/
    // this is non-recursive solution
    void preOrder(Node *root) {
        stack<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            Node* curr = nodes.top();
            nodes.pop();
            cout << curr->data << " ";
            if(curr->right)
                nodes.push(curr->right);
            if(curr->left)
                nodes.push(curr->left);
        }
    }

}; //End of Solution
