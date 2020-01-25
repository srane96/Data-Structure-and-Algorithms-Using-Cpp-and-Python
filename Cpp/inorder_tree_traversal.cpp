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
/* Node is defined as  
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
    // This is recursive solution
    void inOrder(Node *root) {
        if(!root)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }*/
    // This is non recursive solution
    void inOrder(Node *root) {
        stack<Node*> nodes;
        Node* curr = root;
        while(curr || !nodes.empty()) {
            // keep adding curr to stack until you reach left bottom
            while(curr) {
                nodes.push(curr);
                curr = curr->left;
            }
            // now curr is NULL means, we have reached bottom, now go one step
            // up i.e. get latest node from stack
            curr = nodes.top();
            nodes.pop();
            // print it's value
            cout << curr->data << " ";
            curr = curr->right;
        }
    }
};
