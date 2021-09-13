#include <bits/stdc++.h>
#include "doublelinkedlist.h"

using namespace std;

int main() {
    DoubleList<int> l;
    l.insert(9);
    l.insert(11);
    l.insert(11);
    l.insert(11);
    l.insert(11);
    l.print();
    cout<<endl;
    l.printLP();

    return 0;
}