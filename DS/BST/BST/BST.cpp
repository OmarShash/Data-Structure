// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "tree.cpp"

int main()
{
    BST<int> test;
    test.insert(31);
    test.insert(70);
    test.insert(10);
    test.insert(50);
    test.insert(22);
    test.insert(44);
    test.insert(4);
    test.insert(90);
    test.insert(18);
    test.insert(15);
    test.insert(35);
    test.insert(24);
    test.insert(66);
    test.insert(25);
    test.insert(12);

    test.print(1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
