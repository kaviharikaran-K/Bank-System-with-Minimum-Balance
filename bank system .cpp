#include <iostream>
using namespace std;

class Bank {
private:
    int accNo;
    string name;
    float balance;
    const float MIN_BAL = 500;

public:
    void createAccount() {
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Initial Balance: ";
        cin >> balance;

        if (balance < MIN_BAL) {
            cout << "Minimum balance should be 500. Setting to 500.\n";
            balance = MIN_BAL;
        }
    }

    void deposit() {
        float amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
        cout << "Deposited successfully!\n";
    }

    void withdraw() {
        float amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;

        if (balance - amt < MIN_BAL) {
            cout << "Cannot withdraw! Minimum balance of 500 must be maintained.\n";
        } else {
            balance -= amt;
            cout << "Withdrawal successful!\n";
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account No: " << accNo << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    Bank b;
    int choice;

    b.createAccount();

    do {
        cout << "\n--- BANK MENU ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Display\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: b.deposit(); break;
            case 2: b.withdraw(); break;
            case 3: b.display(); break;
            case 4: cout << "Thank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
