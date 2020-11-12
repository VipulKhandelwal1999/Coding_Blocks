/****************************** Money Splitwise Algorithm ******************************

                                Sample Input:-  
                                    3 3
                                Vipul Anurag 100
                                Anurag Neha 50
                                Neha Vipul 40

                                Sample Output:-
                                Vipul will pay 50 to Anurag
                                Vipul will pay 10 to Neha
                                Total Transactions: 2
*****************************************************************************************/

#include<iostream>
#include<set>
#include<map>
using namespace std;

//custom comparator to sort person according to their values
class person_compare{
public:
    bool operator()(pair<string, long long> p1, pair<string, long long> p2){
        return p1.second < p2.second;
    }
};


int main(){

    long long no_of_transactions, friends;
    cin >> no_of_transactions >> friends;

    string x,y;
    long long amount;

    map<string,long long> net;

    while(no_of_transactions--){
        cin >> x >> y >> amount;
        if(net.count(x)==0){
            net[x] = 0;
        }
        if(net.count(y)==0){
            net[y] = 0;
        }
        net[x] -= amount;
        net[y] += amount;
    }

    //Iterate over the persons, add those person in the multiset who have non zero net

    multiset<pair<string,long long>, person_compare> m;

    for(auto p:net){
        string person = p.first;
        long long amount = p.second;

        if(net[person]!=0){
            m.insert(make_pair(person,amount));
        }
    }

    //3. settlements (start & end)
    long long count = 0;
    while(!m.empty()){
        auto low = m.begin();
        auto high = prev(m.end());

        long long debit = low->second;
        string debit_person = low->first;

        long long credit = high->second;
        string credit_person = high->first;

        //Pop them out
        m.erase(low);
        m.erase(high);

        long long settled_amount = min(-debit,credit);
        debit += settled_amount;
        credit -= settled_amount;

        //Print the Transaction between people
        cout << debit_person << " will pay " << settled_amount << " to " << credit_person << endl;

        if(debit != 0){
            m.insert(make_pair(debit_person,debit));
        }
        if(credit != 0){
            m.insert(make_pair(credit_person,credit));
        }
        count += 1;

    }
    cout << "Total Transactions: " << count << endl;

    return 0;
}