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

    int sp = 0;
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

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }

    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=i; k<n; k++){
                for(int l=j; l<n; l++){
                    sum += pre[k][l];
                    if(i > 0)
                        sum -= pre[i-1][l];
                    if(j > 0)
                        sum -= pre[k][j-1];
                    if(i>0 && j>0)
                        sum += pre[i-1][j-1];
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}
