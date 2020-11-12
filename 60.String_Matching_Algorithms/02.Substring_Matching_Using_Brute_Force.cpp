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
        //Brute force way to find substring
        string text = "abaacadbacad";
        string pat = "aaca";
        //O(n)
        ll n=text.size(), m=pat.size();
        for(ll i=0; i<=n-m; i++){
            //O(m)
            if(text.substr(i,m)==pat){ 
                cout << "Yes found at index" << i;
                return 0;
            }
        }
        //O(n*m)
        cout << "Not found" << endl;
    }
    return 0;
}