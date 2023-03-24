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
    StudentAccount()
    {
        name = "";
        annualInterestRate = 0.0;
        savingBalance = 0.0;
        accountNum = "";
    }
    StudentAccount(char *n, float ir, double sb, char *an)
    {
        int size = 1;
        for (int i = 0; n[i] != '\0'; i++)
        {
            size++;
        }
        name = new char[size];
        for (int i = 0; i < size; i++)
        {
            name[i] = n[i];
        }
        annualInterestRate = ir;
        savingBalance = sb;
        size = 1;
        for (int i = 0; an[i] != '\0'; i++)
        {
            size++;
        }
        accountNum = new char[size];
        for (int i = 0; i < size; i++)
        {
            accountNum[i] = an[i];
        }
    }
    ~StudentAccount()
    {
        delete[] name;
        delete[] accountNum;
    }
};
void OpenCustomerAccount(StudentAccount *savers[], int accountsOpen, char *NameVal, double balance)
{
}
