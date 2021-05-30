#include <iostream>
using namespace std;
int main()
{
    int m;
    int ivert;
    cout << "Enter the m value for m-ary tree: ";
    cin >> m;
    cout << "Enter the number of internal vertices: ";
    cin >> ivert;
    cout << "The number of leaf nodes is: " << (ivert * (m - 1)) + 1;
}
