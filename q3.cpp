#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class String
{
private:
    char *data;
    int size;

public:
    String()
    {
        data = NULL;
        size = -1;
    }
    String(int length)
    {
        size = length;
        data = new char[size];
    }
    String(char *str)
    {
        size = 1;
        for (int i = 0; str[i] == '\0'; i++)
        {
            size++;
        }
        data = new char[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = str[i];
        }
    }
    String(const String &str)
    {
        size = str.size;
        data = new char[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = str.data[i];
        }
    }
    ~String()
    {
        delete[] data;
    }
    int stringLength()
    {
        size = 1;
        for (int i = 0; data == '\0'; i++)
        {
            size++;
        }
        return size;
    }
    void clear()
    {
        delete[] data;
        data = NULL;
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
        int size = 1;
        for (int i = 0; data[i] == '\0'; i++)
        {
            size++;
        }
        for (int i = 0; i < size; i++)
        {
            if (data[i] == c)
            {
                return i;
            }
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
        return val;
    }
    bool equalsIgnoreCase(char *str)
    {
        int strSize = 1;
        for (int i = 0; *str == '\0'; i++)
        {
            strSize++;
        }
        if (size != strSize)
        {
            return false;
        }
        for (int i = 0; i < strSize; i++)
        {
            if (tolower(data[i]) != tolower(str[i]))
            {
                return false;
            }
        }
        return true;
    }
    char *substring(char *substr, int startIndex)
    {
        int strSize = 1;
        for (int i = 0; *substr == '\0'; i++)
        {
            strSize++;
        }
        int counter = startIndex;
        for (int i = startIndex; i < strSize; i++)
        {
            counter++;
            if (data[i] == substr[i])
            {
                break;
            }
        }
        for (int j = counter; j < strSize; j++)
        {
            cout << substr[j];
        }
    }
    char *substring(char *substr, int startIndex, int endIndex)
    {
        int strSize = 1;
        for (int i = 0; *substr == '\0'; i++)
        {
            strSize++;
        }
        int counter = startIndex;
        for (int i = startIndex; i < strSize; i++)
        {
            counter++;
            if (data[i] == substr[i])
            {
                break;
            }
        }
        for (int j = counter; j < endIndex; j++)
        {
            cout << substr[j];
        }
    }
};
