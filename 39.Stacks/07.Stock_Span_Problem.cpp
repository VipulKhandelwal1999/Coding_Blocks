//Stock Span Problem :- Given price of stock of n number of days.We have to calculate span of stock price of each day
//Span basically means the number of days the current price is highest
//In simple language woh index subtract karna hai jab usse bada past main jo bhi hoga uske index se
#include<bits/stdc++.h>
using namespace std;

void stockSpan(int price[], int n, int span[]){

    stack<int> s; // indices of the days
    s.push(0);
    span[0] = 1;

    //loop for the rest of the days -> O(N) -> Push and pop each element only once
    for(int i=1; i<=n-1; i++){
        int currentPrice = price[i];
        //topmost element that is higher then current prices
        while(!s.empty() && price[s.top()]<=currentPrice)
            s.pop();

        if(!s.empty()){
            int prev_highest = s.top();
            span[i] = i - prev_highest;
        }
        else{
            span[i] = i+1;
        }

        //push this element into the stack
        s.push(i);
    }

}

int main() {

    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices)/sizeof(int);
    int span[1000] = {0};

    stockSpan(prices, n, span);
    for(int i=0; i<n; i++){
        cout << span[i] << " ";
    }

    return 0;
}
