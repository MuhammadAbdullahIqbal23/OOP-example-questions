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
        size = 0;
    }
    int stringLength()
    {
        size = 1;
        for (int i = 0; data[i] == '\0'; i++)
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
            cout << "data is empty";
            return false;
        }
        return true;
        cout << "data is not empty";
    }

    int charAt(char c)
    {
        size = 1;
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
        int str1;
        int str2;
        int str3;
        bool flag;
        for (int i = 0; i < strSize; i++)
        {
            str1 = static_cast<int>(str[i]);
            str2 = static_cast<int>(str[i] + 32);
            str3 = static_cast<int>(str[i] - 32);
            if (str[i] != data[i])
            {
                if (str1 > 96 && str1 < 123)
                {
                    if (str1 != str2 && str1 != str3)
                    {
                        flag = false;

                        return flag;
                    }
                    else if (str1 > 64 && str1 < 91)
                    {
                        if (str1 != str2 && str1 != str3)
                        {
                            flag = false;
                            return flag;
                        }
                    }
                }
            }
            else
            {
                flag = true;
            }
        }
        return flag;
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
        for (int i = counter; i < endIndex; i++)
        {
            cout << substr[i];
        }
    }
};
