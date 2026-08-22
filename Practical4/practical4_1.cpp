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
void display()
{
    Patient* p = head;

    while(p != nullptr)
    {
        cout << p->name << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int choice;
    string name;
    do
    {
        cout << "\n1. Critical\n2. Routine\n3. Insert at Position\n0. Exit\n";
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
            case 0:
                break;
            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 0);

    return 0;
}
