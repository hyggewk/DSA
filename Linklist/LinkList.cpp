// using iteration to implement "insert" ,"delete" and "reverse" (traverse forward)
#include "LinkList.hpp"

int main()
{
    Linklist list1;

    list1.insert(1, 2);
    list1.print();
    cout << "________" << endl;
    list1.insert(2, 6);
    list1.insert(3, 4);
    list1.insert(4, 8);
    list1.insert(5, 4);
    list1.print();
    cout << "________" << endl;

    list1.insert(4, 7);
    list1.print();
    cout << "________" << endl;

    list1.del(2);
    list1.print();
    cout << "________" << endl;

    list1.reverse();
    list1.print();
    cout << "________" << endl;

    list1.reverseB(list1.head);
    list1.print();
    cout << "________" << endl;

    list1.printB(list1.head);

    return 0;
}
