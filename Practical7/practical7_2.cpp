#include <iostream>
using namespace std;
struct Node {
    int patient;
    Node* next;
};

class Queue {
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void arrive(int x) {
        Node* newNode = new Node;
        newNode->patient = x;
        newNode->next = NULL;
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << endl;
    }

    void attend() {
        if (front == NULL) {
            cout << "Error: Queue is empty\n";
            return;
        }

        cout << "Attended patient: " << front->patient << endl;

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == NULL)
            rear = NULL;
        if (front != NULL)
            cout << "Front patient: " << front->patient << endl;
        else
            cout << "Queue is empty\n";
    }
};
int main() {
    Queue q;
    int choice, patient;
    for (int i = 0; i < 5; i++) {
        cout << "\n1. Arrive\n";
        cout << "2. Attend\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter patient number: ";
            cin >> patient;
            q.arrive(patient);
            break;
        case 2:
            q.attend();
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
    return 0;
}
