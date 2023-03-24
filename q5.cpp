#include <iostream>
#include <string>
using namespace std;
class Integer
{
    int num;
    string str;

public:
    Integer()
    {
        num = 0;
        string str = "";
    }

    Integer(int num)
    {
        this->num = num;
    }

    Integer(string str)
    {
        this->str = str;
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
    }

    int compareTo(Integer obj)
    {
        if (num < obj.get())
        {
            return -1;
        }
        else if (num > obj.get())
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
        double val;
        val = num;
        return val;
    }

    float floatValue()
    {
        float val;
        val = num;
        return val;
    }

    Integer plus(const Integer obj)
    {
        Integer val;
        val.set(num + obj.get());
        return val;
    }

    Integer minus(const Integer obj)
    {
        Integer val;
        val.set(this->num - obj.get());
        return val;
    }

    Integer multiply(const Integer obj)
    {
        Integer val;
        val.set(this->num * obj.get());
        return val;
    }

    Integer divide(const Integer obj)
    {
        Integer val;
        val.set(this->num / obj.get());
        return val;
    }
    static int numberOfLeadingZeros(int i)
    {
    }
    static int numberOfTrailingZeros(int i)
    {
    }
    static string toBinaryString(int i)
    {
    }
    static string toHexString(int i)
    {
    }
    static string toOctString(int i)
    {
    }
};