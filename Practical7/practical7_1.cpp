#include <iostream>
using namespace std;
class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;
public:
    Queue(int n) {
        capacity = n;
        arr = new int[n];
        front = 0;
        rear = -1;
        size = 0;
    }
    void join(int token) {
        if (size == capacity) {
            cout << "Error: Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = token;
        size++;
        cout << "Front token: " << arr[front] << endl;
    }
    void serve() {
        if (size == 0) {
            cout << "Error: Queue is empty" << endl;
            return;
        }
        cout << "Served token: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
        if (size > 0)
            cout << "Front token: " << arr[front] << endl;
        else
            cout << "Queue is empty" << endl;
    }
};
int main() {
    int n;
    cout << "Enter queue capacity: ";
    cin >> n;
    int case=0;
    switch(case)
    {
        cout<<"Enter 1 to join or 2 to serve or 0 to exit : ";
        cin>>case;
    case 1:
            int value=0;
            cout<<"Enter value to join: ";
            cin>>value;
            q.join(value);
            break;
    case 2:
        {
            q.serve();
            break;
        }
    case 0:
        {
            break;
        }
    }
    return 0;
}
