#include<bits/stdc++.h>
using namespace std;

int printAtDistanceK(node *root, node* target, int k){

    //Base Case
    if(root == NULL){
        return -1;
    }

    //Reach the target the node
    if(root == target){
        printAtLevelK(target, k);
        return 0;
    }

    //next step - ancestor
    int DL = printAtDistanceK(root->left, target, k);

    if(DL != -1){

        //Again there are 2 cases
        //Ancestor itself or you need to go to the right ancestor
        if(DL + 1 == k){
            cout << root->data << " ";
        }
        else{
            printAtLevelK(root->right, k, k-2 - DL);
        }
    }
    int DR = printAtDistanceK(root->right, target, k);

    if(DR != -1){
        if(DR+1 == K){
            cout << root->data << " ";
        }
        else{
            printAtLevelK(root->left, K-2, DR);
        }
        return 1 + DR;
    }

    //Node was not present in left and right subtree of given

    return -1;
}

int main() {

    node *root = NULL;

    //take input the tree;
    cin >> root;
    node* root;
    node* target = root->left->left;

    //print the tree
    cout << root << endl;

    printAtDistanceK(root->left, target, 2);

    return 0;
}
