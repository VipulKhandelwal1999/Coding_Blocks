#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int arr[n][n] = {0};
    int pre[n][n] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int q;
    cin >> q;

    int sp;

    for(int i=0; i<n; i++){
        sp = 0;
        for(int j=0; j<n; j++){
            sp += arr[i][j];
            pre[i][j] = sp;
        }
    }

    for(int i=0; i<n; i++){
        sp = 0;
        for(int j=0; j<n; j++){
            sp += pre[j][i];
            pre[j][i] = sp;
        }
    }
    while(q--){
        int tlx, tly, brx, bry;
        cin >> tlx >> tly >> brx >> bry;
        int sum = 0;
        sum += pre[brx][bry];
        if(tlx > 0)
            sum -= pre[tlx-1][bry];
        if(tly > 0)
            sum -= pre[brx][tly-1];
        if(tlx>0 && tly>0)
            sum += pre[tlx-1][tly-1];

        cout << sum << endl;
    }

    return 0;
}
