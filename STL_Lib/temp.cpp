// queue::push / pop
#include <iostream>       // std::cin, std::cout
#include <queue>          // std::queue

int main()
{
    int A[10];
    int front = -1;
    int rear = -1;

    void IsEmpty() {
        if (front == -1) && rear == -1) return true;
        else return false;
    }

    void EnQueue() {
        int n = sizeof(A) / sizeof(A[0]);
        if (rear == n - 1)
            cout << "Queue is FUll! '\n'";
        else if
            IsEmpty();
            
    }

    return 0;
}