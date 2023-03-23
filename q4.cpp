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
    }
    StudentAccount(char *n, float ir, double sb, char *an)
    {
        int size = 1;
        for (int i = 0; name[i] != '\0'; i++)
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
    char *getName() const
    {
        return name;
    }

    float getAnnualInterestRate() const
    {
        return annualInterestRate;
    }

    double getSavingBalance() const
    {
        return savingBalance;
    }

    char *getAccountNum() const
    {
        return accountNum;
    }

    void setName(const char *charr)
    {
        int size = 1;
        for (int i = 0; charr[i] == '\0'; i++)
        {
            size++;
        }
        name = new char[size];
        for (int i = 0; i < size; i++)
        {
            name[i] = charr[i];
        }
    }

    void setAnnualInterestRate(float AIR)
    {
        annualInterestRate = AIR;
    }

    void setSavingBalance(double SB)
    {
        savingBalance = SB;
    }

    void setAccountNum(const char *AN)
    {
        int size = 1;
        for (int i = 0; AN[i] == '\0'; i++)
        {
            size++;
        }
        accountNum = new char[size];
        for (int i = 0; i < size; i++)
        {
            accountNum[i] = AN[i];
        }
    }
};
