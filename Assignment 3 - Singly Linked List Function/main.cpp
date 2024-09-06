//
//  main.cpp
//  SinglyLinkedList
//
//  Created by Ariel Katz on 2/7/23.
//

#include <iostream>
#include "SinglyLinkedList.h"


using namespace std;

int main() {
    
    SinglyLinkedList<int> list;
    list.insertFirst(2);
    list.insertFirst(3);
    list.insertFirst(5);
    /*list.insertLast(7);
    list.insertLast(11);
    list.insertLast(13);
    cout << "size: "  << list.length() << endl;*/
    list.print();
    cout << endl;
    
    list.deleteNode(5);
    list.print();
    cout << endl;
    /*
    //Test deleting first item
    list.deleteNode(13);
    list.print();
    cout << endl;
    
    //Test deleting last item
    list.deleteNode(2);
    list.print();
    cout << endl;
    */
    
    return 0;
}
