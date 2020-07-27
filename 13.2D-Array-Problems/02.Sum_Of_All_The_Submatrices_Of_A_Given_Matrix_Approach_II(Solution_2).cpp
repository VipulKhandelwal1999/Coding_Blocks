#include <iostream>
using namespace std;
int main() {
    int r,c;
    cin>>r>>c;
    long long int a[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<r;i++){
        for(int j=1;j<c;j++){
            a[i][j]+=a[i][j-1];
        }
    }
    for(int j=0;j<c;j++){
        for(int i=1;i<r;i++){
            a[i][j]+=a[i-1][j];
        }
    }
    cout<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    long long int sum=0;
    for(int li=0;li<r;li++){
        for(int lj=0;lj<c;lj++){
            for(int bi=li;bi<r;bi++){
                for(int bj=lj;bj<c;bj++){
                    sum+=a[bi][bj];
                    if(li>0)
                        sum-=a[li-1][bj];
                    if(lj>0)
                        sum-=a[bi][lj-1];
                    if(li>0 && lj>0)
                        sum+=a[li-1][lj-1];
                }
            }
        }
    }

    cout<<sum;
}
