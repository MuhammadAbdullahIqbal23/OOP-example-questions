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
        return static_cast<double>(num);
    }

    float floatValue()
    {
        return static_cast<float>(num);
    }

    Integer plus(const Integer obj)
    {
        int val;
        val = this->num + obj.num;
        return val;
    }

    Integer minus(const Integer obj)
    {
        int val;
        val = this->num - obj.num;
        return val;
    }

    Integer multiply(const Integer obj)
    {
        int val;
        val = this->num * obj.num;
        return val;
    }

    Integer divide(const Integer obj)
    {
        int val;
        val = num / obj.num;
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