/*
fflush(stdout) in C++. () (If using prinf and scanf)
cout << flush; in C++. () (If using cin cout)
we can also use endl as:-
endl actually work as cout<<'\n'<<flush;
*/

/*
This is a bit unusual problem — here you need to implement the interactive communication with the testing system. It means you have to make queries and get responses online. As usual, standard input/output is used. After printing each query you need to use special function to flush the output stream, because it is possible that some part of your output is left in the buffer. For example, you can use fflush(stdout) in C++, System.out.flush() in Java, flush(output) in Pascal and stdout.flush() in Python.

In this problem there is some hidden number and you have to interactively guess it. The hidden number is always an integer from 1 and to 1 000 000.

You can make queries to the testing system. Each query is one integer from 1 to 1 000 000. Flush output stream after printing each query. There are two different responses testing program can provide:

string "<" (without quotes), if the hidden number is less than the integer in your query;
string ">=" (without quotes), if the hidden number is greater than or equal to the integer in your query.
When your program is sure that guessed the hidden number, print string "! x", where x is the answer, and terminate your program immediately after flushing the output stream.

Your program is allowed to make no more than 25 queries (not including printing the answer) to the testing system.

Input
Use standard input to read the responses to the queries.

The input will contain responses to your queries — strings "<" and ">=". The i-th string is a response to the i-th your query. When your program will guess the number print "! x", where x is the answer and terminate your program.

The testing system will allow you to read the response on the query only after your program print the query for the system and perform flush operation.

Output
To make the queries your program must use standard output.

Your program must print the queries — integer numbers x i (1 ≤ x i ≤ 106), one query per line. After printing each line your program must perform operation flush.

Each of the values x i mean the query to the testing system. The response to the query will be given in the input file after you flush output. In case your program guessed the number x, print string "! x", where x — is the answer, and terminate your program.

Examples
inputCopy
>=
<
>=
>=
<
<
outputCopy
8
20
11
12
13
16
! 12
inputCopy
<
<
>=
outputCopy
123
70
30
! 43
Note
In the first sample, the hidden number is 12. In the provided example of the communication process, you can see six queries. Note that the answer is known even after the fifth query but you are allowed to ask unnecessary queries (unless you exceed the limit of 25 queries).

In the second sample, the hidden number is 43. After the provided three queries there are many possible answers but it's fine to guess — if you guess correctly.
*/
#include<bits/stdc++.h>
using namespace std;

// x < middle "<" -> 1
// x >= middle "<" -> 2

int query(int middle){
    cout << middle << endl;
    string res;
    cin >> res;
    if(res == "<")
        return 1;
    else
        return 2;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int l = 1, r = 1e6, ans = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(query(mid) == 1){
            r = mid - 1;
        }
        else{
            ans = mid;
            l = mid + 1;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}
