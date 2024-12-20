#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

class ATM {
private:
    string accountNumber;
    string pin;
    double balance;

public:
    ATM(string accountNumber, string pin, double balance) {
        this->accountNumber = accountNumber;
        this->pin = pin;
        this->balance = balance;
    }

    void displayMenu() {
        cout << "Welcome to ATM" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Withdraw Cash" << endl;
        cout << "3. Deposit Cash" << endl;
        cout << "4. Change PIN" << endl;
        cout << "5. Exit" << endl;
    }

    void checkBalance() {
        cout << "Your current balance is: " << balance << endl;
    }

    void withdrawCash() {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount > balance) {
            cout << "Insufficient balance" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Remaining balance: " << balance << endl;
        }
    }

    void depositCash() {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void changePIN() {
        string newPIN;
        cout << "Enter new PIN: ";
        cin >> newPIN;

        pin = newPIN;
        cout << "PIN changed successfully" << endl;
    }

    void authenticate() {
        string enteredPIN;
        cout << "Enter your PIN: ";
        cin >> enteredPIN;

        if (enteredPIN == pin) {
            cout << "Authentication successful" << endl;
        } else {
            cout << "Invalid PIN. Please try again." << endl;
            authenticate();
        }
    }

    void run() {
        authenticate();

        while (true) {
            displayMenu();
            int choice;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();                    
				break;
                
				case 2:
                    withdrawCash();
                    break;
                case 3:
                    depositCash();
                    break;
                case 4:
                    changePIN();
                    break;
                case 5:
                    cout << "Thank you for using our ATM" << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};
int main() {
    ATM atm("1234567890", "1234", 1000.0);
    atm.run();

    return 0;
}