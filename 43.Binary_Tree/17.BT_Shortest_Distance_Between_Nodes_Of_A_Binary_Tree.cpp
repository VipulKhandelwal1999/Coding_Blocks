#include<bits/stdc++.h>
using namespace std;
#define ll long long

//assumption both a and b are present in the tree, all keys are unique
node* lca(node* root, int a, int b){
    if(root == NULL)
        return NULL;

    if(root->data == a or root->data == b)
        return root;

    //search in left and right subtrees
    node* leftans = lca(root->left, a, b);
    node* rightans = lca(root->right, a, b);

    if(leftans != NULL and rightans != NULL)
        return root;

    if(leftans != NULL)
        return leftans;

    return rightans;
}
//finding the level of a given node from the root node/any given node
int search(node *root, int key, int level){
    if(root == NULL){
        return -1;
    }

    if(root->data == key){
        return level;
    }

    int left = search(root->left, key, level+1);

    if(left != -1){
        return left;
    }
    return search(root->right, key, level+1);
}

//function to find distance between two nodes
int findDistance(node* root, int a, int b){

    node* lca_node = lca(root, a, b);

    int l1 = search(lca_node, a, 0);
    int l2 = search(lca_node, b, 0);

    return l1 + l2;
}

int main(){



    return 0;
}
