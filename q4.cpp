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

    char *getName()
    {
        return name;
    }
    float getAnnualInterestRate()
    {
        return annualInterestRate;
    }

    double getSavingBalance()
    {
        return savingBalance;
    }

    char *getAccountNum()
    {
        return accountNum;
    }

    void setAnnualInterestRate(float AnnualInterestRate)
    {
        annualInterestRate = AnnualInterestRate;
    }

    void setSavingBalance(double SavingBalance)
    {
        savingBalance = SavingBalance;
    }
};
void OpenCustomerAccount(StudentAccount *savers[], int accountsOpen, char *NameVal, double balance)
{
}
float calculateMonthlyInterest(StudentAccount *saver)
{
    float MonthlyInterest;
    MonthlyInterest = saver->getSavingBalance() * saver->getAnnualInterestRate() / 12.0;
    return MonthlyInterest;
}
void modifyInterestRate(StudentAccount *saver, float newValue)
{
    saver->setAnnualInterestRate(newValue);
}
int SearchCustomer(StudentAccount *savers[], int accountsOpen, char *accountNum)
{
    for (int i = 0; i < accountsOpen; i++)
    {
        if (savers[i]->getAccountNum() == accountNum)
        {
            return i;
        }
    }

    return -1;
}
bool UpdateAccountBalance(StudentAccount *savers[], int accountsOpen, char *accountNumVal, double balanceVal)
{
}
