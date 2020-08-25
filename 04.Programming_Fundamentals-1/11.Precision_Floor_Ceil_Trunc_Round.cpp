/*
Precision of floating point numbers in C++ (floor(), ceil(), trunc(), round() and setprecision())
Last Updated: 29-05-2017
Decimal equivalent of 1/3 is 0.33333333333333…. An infinite length number would require infinite memory to store, and we typically have 4 or 8 bytes. Therefore, Floating point numbers store only a certain number of significant digits, and the rest are lost. The precision of a floating point number defines how many significant digits it can represent without information loss. When outputting floating point numbers, cout has a default precision of 6 and it truncates anything after that.

Given below are few libraries and methods which are used to provide precision to floating point numbers in C++:

floor(): Floor rounds off the given value to the closest integer which is less than the given value.
// C++ program to demonstrate working of floor()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x =1.411, y =1.500, z =1.711;
    cout << floor(x) << endl;
    cout << floor(y) << endl;
    cout << floor(z) << endl;

    double a =-1.411, b =-1.500, c =-1.611;
    cout << floor(a) << endl;
    cout << floor(b) << endl;
    cout << floor(c) << endl;
    return 0;
}
Output:

1
1
1
-2
-2
-2
ceil(): Ceil rounds off the given value to the closest integer which is more than the given value.

// C++ program to demonstrate working of ceil()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x = 1.411, y = 1.500, z = 1.611;
    cout << ceil(x) << endl;
    cout << ceil(y) << endl;
    cout << ceil(z) << endl;

    double a = -1.411, b = -1.500, c = -1.611;
    cout << ceil(a) << endl;
    cout << ceil(b) << endl;
    cout << ceil(c) << endl;
    return 0;
}
Output:

2
2
2
-1
-1
-1


trunc(): Trunc rounds removes digits after decimal point.

// C++ program to demonstrate working of trunc()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x = 1.411, y = 1.500, z = 1.611;
    cout << trunc(x) << endl;
    cout << trunc(y) << endl;
    cout << trunc(z) <<endl;

    double a = -1.411, b = -1.500, c = -1.611;
    cout << trunc(a) <<endl;
    cout << trunc(b) <<endl;
    cout << trunc(c) <<endl;
    return 0;
}
Output:

1
1
1
-1
-1
-1
round(): Rounds given number to the closest integer.

// C++ program to demonstrate working of round()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double x = 1.411, y = 1.500, z = 1.611;

    cout << round(x) << endl;
    cout << round(y) << endl;
    cout << round(z) << endl;

    double a = -1.411, b = -1.500, c = -1.611;
    cout << round(a) << endl;
    cout << round(b) << endl;
    cout << round(c) << endl;
    return 0;
}
Output:

1
2
2
-1
-2
-2


setprecision(): Setprecision when used along with ‘fixed’ provides precision to floating point numbers correct to decimal numbers mentioned in the brackets of the setprecison.

// C++ program to demonstrate working of setprecision()
// in C/C++
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double pi = 3.14159, npi = -3.14159;
    cout << fixed << setprecision(0) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(1) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(2) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(3) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(4) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(5) << pi <<" "<<npi<<endl;
    cout << fixed << setprecision(6) << pi <<" "<<npi<<endl;
}
Output:

3 -3
3.1 -3.1
3.14 -3.14
3.142 -3.142
3.1416 -3.1416
3.14159 -3.14159
3.141590 -3.141590
Note: When the value mentioned in the setprecision() exceeds the number of floating point digits in the original number then 0 is appended to floating point digit to match the precision mentioned by the user.
*/
