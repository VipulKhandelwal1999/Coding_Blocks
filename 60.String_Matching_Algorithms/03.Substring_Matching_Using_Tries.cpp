#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)
struct Trie{    
    Trie *nxt[26];
};
struct Trie *getNode(void){ 
    struct Trie *pNode =  new Trie;
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
}
bool search(struct Trie *root, string key){ 
    struct Trie *pCrawl = root; 
    loop(i,0,key.size()){
        ll index = key[i]-'a'; 
        if(!pCrawl->nxt[index]) 
            return false;
        pCrawl = pCrawl->nxt[index]; 
    }
    return (pCrawl!=NULL); 
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
        //Using trie to find substring
        struct Trie *root = new Trie();
        string text = "abaacadbacad";
        string pat = "abaacadbacad";
        ll n=text.size(), m=pat.size();
        for(ll i=0; i<n; i++){
            insert(root, text.substr(i));
        }
        if(search(root, pat)){
            cout << "Found" << endl;
        }
        else{
            cout << "Not Found" << endl;
        }
    }
    return 0;
}