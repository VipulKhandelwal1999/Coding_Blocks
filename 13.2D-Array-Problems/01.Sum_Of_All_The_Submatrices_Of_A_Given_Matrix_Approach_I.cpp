#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum = 0;
    int n;
    cin >> n;
    int arr[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
    //Extracting top left from first two loops
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

        //Extracting bottom right for all possible top left
            for(int k=i; k<n; k++){
                for(int l=j; l<n; l++){

                // Sum of current matrix
                    for(int z=i; z<=k; z++){
                        for(int y=j; y<=l; y++){
                            sum += arr[z][y];
                        }
                    }
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}
