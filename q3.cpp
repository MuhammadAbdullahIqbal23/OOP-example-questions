#include <iostream>
#include <cstring>
#include <string>
class String
{
private:
    char *data;
    int size;

public:
    String()
    {
        data = "";
        size = -1;
    }
    String(int length)
    {
        size = length;
        data = new char[size];
    }
    String(char *str)
    {
        data = str;
        data = new char[size];
    }
    String(const String &str)
    {
        data = str.data;
    }
    ~String()
    {
        delete[] data;
    }
    int stringLength()
    {
        return size;
    }
    void clear()
    {
        delete[] data;
        data = nullptr;
        size = 0;
    }
    bool isEmpty()
    {
        if (size == 0)
        {
            return 0;
        }
        return 1;
    }

    int charAt(char c)
    {
        int i = 0;
        while (i < size)
        {
            if (data[i] == c)
            {
                return i;
            }
            i++;
        }
        return 0;
    }
    char *getdata()
    {
        return data;
    }
    bool isEqual(char *str)
    {
        bool val;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == str[i])
            {
                val = true;
            }
            else
            {
                val = false;
                return val;
            }
        }
    }
    bool equalsIgnoreCase(char *str)
    {
        for (int i = 0; i < size; i++)
        {
        }
    }
};
using namespace std;
int main()
{
    return 0;
}
