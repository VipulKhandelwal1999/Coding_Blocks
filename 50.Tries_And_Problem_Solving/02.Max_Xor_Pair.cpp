#include<bits/stdc++.h>
using namespace std;

class node {
public:
    node* left; //for 0
    node* right; //for 1
};

class trie{
    node* root;

    public:
        trie(){
            root = new node();
        }
        //insert function
        //5 = 00000101 [32 bit integer]

        void insert(int n){
            node* temp = root;

            //loop
            for(int i=31; i>=0; i--){
                int bit = (n>>i)&1;
                if(bit == 0){
                    if(temp->left != NULL){
                        temp->left = new node();
                    }
                    temp = temp->left;
                }
                else{
                    //current bit is 1
                    if(temp->right == NULL){
                        temp->right = new node();
                    }
                    temp = temp->right;
                }
            }
        }
        //helper function to find xor
        int max_xor_helper(int value){

            node* temp = root;
            int current_ans = 0;
            for(int j=31; j>=0; j--){
                int bit = (value>>j)&1;
                if(bit == 0){
                    //find a complementary
                    if(temp->right != NULL){
                        temp = temp->right;
                        current_ans += (1<<j);
                    }
                    else{
                        temp = temp->left;
                    }
                }
                else{
                    //current bit is 1
                    if(temp->left != NULL){
                        temp = temp->left;
                        current_ans += (1<<j);
                    }
                    else{
                        temp = temp->right;
                    }
                }
            }
            return current_ans;
        }

        int max_xor(int* input, int n){
            int max_xor = 0;

            for(int i=0; i<n; i++){
                int val = input[i];
                insert(val);
                int current_xor = max_xor_helper(val);
                cout << current_xor << " ";
                max_xor = max(current_xor, max_xor);
            }
            return max_xor;
        }
};

int main(){

    //max xor pair
    int input[] = {3, 10, 5, 25, 2, 8};
    trie t;
    cout << t.max_xor(input, 6) << endl;

    return 0;
}
