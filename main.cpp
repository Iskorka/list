#include "CList.h"
#include <iostream>

using namespace std;

int main()
{
    CList<int> l;

    l.pushBack(4);
    l.pushBack(5);
    l.pushBack(6);
    l.pushBack(142);

    cout << "Elements pushed to back: \n";
    l.show();

    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);
    l.pushFront(965);

    cout << endl << "\nElements pushed to front: \n";

    l.show();

    cout<<endl;

    cout << endl << "Popping: \n";
    cout << "list.popBack(): " << l.popBack() << endl;

    l.show();
    cout << endl;
    cout << endl << "list.popFront(): " << l.popFront() << endl;

    l.show();
    cout<< endl;

    cout << endl << "List size: " << l.size() << endl;

    cout << endl << "Reversed output: \n";
    l.showReversed();


    cout<<endl<<endl;

    return 0;
}
