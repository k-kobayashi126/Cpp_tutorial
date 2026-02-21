#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    private:
        string accountName;
        int balance;
    public:
        BankAccount(string n, int b);
        void deposit(int amount);
        void showInfo();
};

BankAccount::BankAccount(string n, int b) {
    accountName = n;
    balance = b;
}

void BankAccount::deposit(int amount) {
    balance += amount;
    cout << amount << "円預け入れました" << endl;
}

void BankAccount::showInfo() {
    cout << "名前：" << accountName << ", 残金：" << balance << endl;
}

class SavingsAccount: public BankAccount
{
    private:
        double interestRate;
    public:
        SavingsAccount(string n, int b, double x);
        void addInterest();
};

SavingsAccount::SavingsAccount(string n, int b, double x) : BankAccount(n, b) {
    interestRate = x;
}

void SavingsAccount::addInterest() {
    deposit(interestRate);
}

int main()
{
    SavingsAccount account = SavingsAccount("小林", 1000000, 10);
    account.addInterest();
    account.showInfo();

    return 0;
}