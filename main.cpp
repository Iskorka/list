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

    cout << "Elements ";

    for (int i=0; i<l.size(); ++i)
    {
        cout << l[i] << ' ';
    }

    cout<< "pushed to back: \n\t";
    l.show();

    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);
    l.pushFront(965);

    cout << endl << "\nElements ";

    for (int i=0; i<l.size()/2; ++i)
    {
        cout << l[i] << ' ';
    }

    cout<< "pushed to front: \n\t";
    l.show();

    l.insert(2, 1024);

    cout << "\n\nElement with value " << l[2] << " inserted into position 2: \n\t";
    l.show();

    cout<<endl;

    cout << endl << "Popping: \n";
    cout << "\tlist.popBack(): " << l.popBack() << "\n\t\t";

    l.show();
    cout << endl;

    cout << endl << "\tlist.popFront(): " << l.popFront() << "\n\t\t";

    l.show();
    cout<< endl;

    cout << endl << "\tlist.pop(1): " << l.pop(1) << "\n\t\t";

    l.show();
    cout<< endl;

    cout << endl << "List size: " << l.size() << endl;

    cout << endl << "Reversed output: \n";
    l.showReversed();

    cout<<endl<<endl;
    return 0;
}
