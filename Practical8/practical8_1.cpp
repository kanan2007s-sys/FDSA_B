#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void levelorder(Node* root) {
    if (root == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {
    Node* root=new Node{1,nullptr,nullptr};
    Node* a=new Node{2,nullptr,nullptr};
    Node* b=new Node{3,nullptr,nullptr};
    Node* c=new Node{4,nullptr,nullptr};
    Node* d=new Node{5,nullptr,nullptr};
    Node* e=new Node{6,nullptr,nullptr};
    root->left=a;
    root->right=b;
    a->left=c;
    a->right=d;
    b->left=e;
    cout << "Inorder: ";
    inorder(root);
    cout << "\nPreorder: ";
    preorder(root);
    cout << "\nPostorder: ";
    postorder(root);
    cout << "\nLevel Order: ";
    levelorder(root);
    return 0;
}
