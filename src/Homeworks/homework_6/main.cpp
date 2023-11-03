#include <iostream>
#include <vector>

#include "List.h"
#include"Stack.h"
#include"Queue.h"
using namespace std;

void Queue_test() {
    Queue<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1;          // 1->2->3
    cout << s1.size_() << endl;

    Queue<int> s2 (s1), s3;

    s1.pop();
    s1.push(4);
    s1.push(5);

    s2.pop();
    s2.push(6);

    cout << s1;         // 2->3->4->5
    cout << s1.size_() << endl;

    cout << s2;         // 2->3->6
    cout << s2.size_() << endl;

    s3 = s1;

    s1.pop();
    s1.push(7);
    s1.push(8);

    s3.pop();
    s3.push(9);

    cout << s1;         // 3->4->5->7->8
    cout << s1.size_() << endl;

    cout << s2;         // 2->3->6
    cout << s2.size_() << endl;

    cout << s3;
    cout << s3.size_() << endl;  // 3->4->5->9
}

void Stack_test() {
    Stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

    cout << s1;         // 3->2->1
    cout << s1.size_() << endl;

    Stack<int> s2 (s1), s3;

    s1.pop();
    s1.push(4);
    s1.push(5);

    s2.pop();
    s2.push(6);

    cout << s1;         // 5->4->2->1
    cout << s1.size_() << endl;

    cout << s2;         // 6->2->1
    cout << s2.size_() << endl;

    s3 = s1;

    s1.pop();
    s1.push(7);
    s1.push(8);

    s3.pop();
    s3.push(9);

    cout << s1;         // 8->7->4->2->1
    cout << s1.size_() << endl;

    cout << s2;         // 6->2->1
    cout << s2.size_() << endl;

    cout << s3;         // 9->4->2->1
    cout << s3.size_() << endl;
}

int main() {
    cout << "Stack:" << endl;
    Stack_test();
    cout << "Queue:" << endl;
    Queue_test();
    return 0;
}
