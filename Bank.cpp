#include <iostream>
#include <string>
using namespace std;

// Class to manage bank accounts
class BankAccount {
private:
    string accountHolderName;
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, string number, double initialBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = initialBalance;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful! Current balance: " << balance << endl;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful! Remaining balance: " << balance << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        }
        else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }

    // Function to display account details
    void displayDetails() {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Main function
int main() {
    // Create a bank account
    string name, number;
    double initialBalance;

    cout << "Enter Account Holder Name: ";
    getline(cin, name);
    cout << "Enter Account Number: ";
    cin >> number;
    cout << "Enter Initial Balance: ";
    cin >> initialBalance;

    BankAccount account(name, number, initialBalance);

    int choice;
    do {
        cout << "\n--- Bank Account Management ---\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Display Account Details\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            double depositAmount;
            cout << "Enter amount to deposit: ";
            cin >> depositAmount;
            account.deposit(depositAmount);
            break;
        }
        case 2: {
            double withdrawAmount;
            cout << "Enter amount to withdraw: ";
            cin >> withdrawAmount;
            account.withdraw(withdrawAmount);
            break;
        }
        case 3:
            account.displayDetails();
            break;
        case 4:
            cout << "Exiting the program. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
