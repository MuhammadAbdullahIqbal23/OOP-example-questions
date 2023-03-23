#include <iostream>
using namespace std;
class StudentAccount
{
private:
    char *name;
    float annualInterestRate;
    double savingBalance;
    char *accountNum;

public:
    StudentAccount(char *n, float ir, double sb, char *an)
    {
        int size = 1;
        for (int i = 0; name[i] != '\0'; i++)
        {
            size++;
        }
        name = new char[size];
        name = n;
        annualInterestRate = ir;
        savingBalance = sb;
        accountNum = new char[size];
        accountNum = an;
    }
    ~StudentAccount()
    {
        delete[] name;
        delete[] accountNum;
    }
    void setSavingBalance(double sb)
    {
        savingBalance = sb;
    }
    double getSavingBalance() const
    {
        return savingBalance;
    }
    float calculateMonthlyInterest() const
    {
        return (savingBalance * annualInterestRate) / 12.0;
    }
    void modifyInterestRate(float ir)
    {
        annualInterestRate = ir;
    }
    char *getAccountNum() const
    {
        return accountNum;
    }
};

int main()
{
    return 0;
}