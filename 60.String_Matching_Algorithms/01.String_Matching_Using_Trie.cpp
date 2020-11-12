#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)

struct Trie{    
    Trie *nxt[26];
    bool ended;
};
struct Trie *getNode(void){ 
    struct Trie *pNode =  new Trie;
    pNode->ended = false; 
    loop(i,0,26)
        pNode->nxt[i] = NULL;
    return pNode; 
}
void insert(struct Trie *root, string key){ 
    struct Trie *pCrawl = root;
    loop(i,0,key.size()){
        ll index = key[i]-'a';
        if(!pCrawl->nxt[index]) 
            pCrawl->nxt[index] = getNode();
        pCrawl = pCrawl->nxt[index]; 
    }
    pCrawl->ended = true; 
}
bool search(struct Trie *root, string key){ 
    struct Trie *pCrawl = root; 
    loop(i,0,key.size()){
        ll index = key[i]-'a'; 
        if(!pCrawl->nxt[index]) 
            return false;
        pCrawl = pCrawl->nxt[index]; 
    }
    return (pCrawl!=NULL && pCrawl->ended); 
} 

void FasIO(){  
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int main(){
    FasIO();
    ll t=1;
    cin >> t;
    loop(i,1,t+1){
        //String matching is basically the complete string is there or not
        //For example if we have many names and we used trie to store them
        //So if string matching is there it means whether there is complete 
        //string or not in that trie in time O(M) where M is length of string
        string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" }; 
        ll n = sizeof(keys)/sizeof(keys[0]);
        struct Trie *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) 
            insert(root, keys[i]);
        // Search for different keys 
        search(root, "the")? cout << "Yes\n" : cout << "No\n"; 
        search(root, "these")? cout << "Yes\n" : cout << "No\n"; 
    }

    return 0;
}