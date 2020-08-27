/*
Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

Input Format
N(integer) followed by N strings.

Constraints
N<=1000

Output Format
N lines each containing one string.

Sample Input
3
bat
apple
batman
Sample Output
apple
batman
bat
Explanation
In mathematics, the lexicographic or lexicographical order (also known as lexical order, dictionary order, alphabetical order or lexicographic(al) product) is a generalization of the way words are alphabetically ordered based on the alphabetical order of their component letters.

Logic:-

*/

#include <iostream>
#include <algorithm>
using namespace std;


int compareTo(string s1, string s2) {

        int i = 0;

        while (i < s1.length() && i < s2.length()) {

            if (s1[i] > s2[i]) {

                return 1;
            } else if (s1[i] < s2[i]) {
                return -1;
            }
            i++;

        }

        if (s1.length() > s2.length()) {
            return -1;
        } else {
            return 1;
        }

    }
void sortfunc(string arr[], int n) {

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n - i - 1; j++) {

                if (compareTo(arr[j], arr[j + 1]) > 0) {

                    string temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }

            }
        }

    }

int main()
{

    int n;
    cin>>n;
    string* str = new string[n];
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
    }
    sortfunc(str, n);
    for(int i=0;i<n;i++)
    {
        cout<<str[i]<<endl;
    }
}

