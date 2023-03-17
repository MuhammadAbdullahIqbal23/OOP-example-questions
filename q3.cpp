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
    }
    String(char *str)
    {
        data = str;
    }
    String(const String &str)
    {
    }
    int stringLength()
    {
        return size;
    }
    void clear()
    {
    }
    bool isEmpty()
    {
    }
    int charAt(char c)
    {
    }
};
using namespace std;
int main()
{
    return 0;
}
