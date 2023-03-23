#include <iostream>
#include <string>
using namespace std;
class Integer
{
    int num;

public:
    Integer()
    {
        num = 0;
    }

    Integer(int num)
    {
        this->num = num;
    }

    Integer(string str)
    {
        }

    void set(int number)
    {
        num = number;
    }

    int get() const
    {
        return num;
    }

    int bitCount()
    {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((num >> i) & 1)
            {
                count++;
            }
        }
        return count;
    }

    int compareTo(Integer other)
    {
        if (num < other.get())
        {
            return -1;
        }
        else if (num > other.get())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    double doubleValue()
    {
        return static_cast<double>(num);
    }

    float floatValue()
    {
        return static_cast<float>(num);
    }

    Integer plus(const Integer other)
    {
        Integer val;
        val = num + other.get();
        return val;
    }

    Integer minus(const Integer other)
    {
        Integer val;
        val = num - other.get();
        return val;
    }

    Integer multiply(const Integer other)
    {
        Integer val;
        val = num * other.get();
        return val;
    }

    Integer divide(const Integer other)
    {
        if (other.get() == 0)
        {
            throw "Divide by zero exception";
        }
        Integer val;
        val = num / other.get();
        return val;
    }
};