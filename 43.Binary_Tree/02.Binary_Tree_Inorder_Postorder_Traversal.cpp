#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }

};

node* buildTree(){
    int d;
    cin >> d;

    if(d == -1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}
void print_pre(node *root){
    if(root == NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    cout << root->data << " ";
    print_pre(root->left);
    print_pre(root->right);
}

void print_in(node *root){
    if(root == NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    print_in(root->left);
    cout << root->data << " ";
    print_in(root->right);
}

void print_post(node *root){
    if(root == NULL){
        return;
    }
    //Otherwise, print root first followed by subtrees(children)
    print_post(root->left);
    print_post(root->right);
    cout << root->data << " ";
}

int height(node* root){
    if(root == NULL)
        return 0;

    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs) + 1;
}

int main(){

    node* root = buildTree();

    print_in(root);
    cout << endl;

    print_post(root);
    cout << endl;

    print_pre(root);

    cout << endl;

    cout << height(root) << endl;

    return 0;
}
