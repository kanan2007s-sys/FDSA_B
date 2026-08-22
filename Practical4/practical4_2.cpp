#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    string name;
    Patient* next;
};

Patient* head = nullptr;

void critical(string n)
{
    Patient* newnode = new Patient;
    newnode->name = n;
    newnode->next = head;
    head = newnode;
}

void routine(string n)
{
    Patient* newnode = new Patient;
    newnode->name = n;
    newnode->next = nullptr;

    if(head == nullptr)
    {
        head = newnode;
        return;
    }

    Patient* p = head;
    while(p->next != nullptr)
        p = p->next;
    p->next = newnode;
}

void occasionally(string n)
{
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    if(pos <= 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Patient* newnode = new Patient;
    newnode->name = n;

    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    Patient* p = head;
    for(int i = 1; i < pos - 1 && p != nullptr; i++)
        p = p->next;

    if(p == nullptr)
    {
        cout << "Invalid position!" << endl;
        delete newnode;
        return;
    }
    newnode->next = p->next;
    p->next = newnode;
}

void deletePatient(string n)
{
    if(head == nullptr)
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    if(head->name == n)
    {
        Patient* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Patient* p = head;
    while(p->next != nullptr && p->next->name != n)
        p = p->next;
    if(p->next == nullptr)
    {
        cout << "Patient not found!" << endl;
        return; }

    Patient* temp = p->next;
    p->next = temp->next;
    delete temp;
}

void display()
{
    Patient* p = head;
    cout << "Front to Back: ";
    while(p != nullptr)
    {
        cout << p->name << " ";
        p = p->next;
    }
    cout << endl;
}

void reversePrint(Patient* p)
{
    if(p == nullptr)
        return;

    reversePrint(p->next);
    cout << p->name << " ";
}

int main(){
    string name;
    int choice;

    do{
            cout << "\n1. Critical\n2. Routine\n3. Insert at Position\n4. Delete\n5. Forward Display\n6. Reverse Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice)
        {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                critical(name);
                display();
                break;

            case 2:
                cout << "Enter patient name: ";
                cin >> name;
                routine(name);
                display();
                break;
            case 3:
                cout << "Enter patient name: ";
                cin >> name;
                occasionally(name);
                display();
                break;
            case 4:
                cout << "Enter patient name to delete: ";
                cin >> name;
                deletePatient(name);
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                cout << "Back to Front: ";
                reversePrint(head);
                cout << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 0);
    return 0;
}
