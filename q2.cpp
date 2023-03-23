#include <iostream>
#include <string>
using namespace std;

class Pizza
{
private:
    char *name;
    char *topping;
    char *size;
    bool is_ready;
    double price;

public:
    Pizza()
    {
        name = "";
        topping = "";
        size = "";
        is_ready = false;
        price = 0.0;
    }

    Pizza(char *toppingVal, double priceVal)
    {
        name = "";
        size = "";
        is_ready = false;
        setTopping(toppingVal);
        setPrice(priceVal);
    }

    Pizza(char *toppingVal, double priceVal, char *nameVal, char *sizeVal, bool ready_status)
    {
        setTopping(toppingVal);
        setPrice(priceVal);
        setName(nameVal);
        setSize(sizeVal);
        is_ready = ready_status;
    }

    Pizza(const Pizza &pizza)
    {
        setTopping(pizza.topping);
        setPrice(pizza.price);
        setName(pizza.name);
        setSize(pizza.size);
        is_ready = pizza.is_ready;
    }
    ~Pizza()
    {
    }
    void setTopping(char *toppingVal)
    {
        int counter = 1;
        for (int i = 0; toppingVal[i] == '\0'; i++)
        {
            counter++;
        }
        topping = new char[counter];
        for (int i = 0; i < counter; i++)
        {
            topping[i] = toppingVal[i];
        }
    }

    void setPrice(double priceVal)
    {
        price = priceVal;
    }

    void setName(char *nameVal)
    {
        int counter = 1;
        for (int i = 0; nameVal[i] == '\0'; i++)
        {
            counter++;
        }
        name = new char[counter];
        for (int i = 0; i < counter; i++)
        {
            name[i] = nameVal[i];
        }
    }

    void setSize(char *sizeVal)
    {
        int counter = 1;
        for (int i = 0; sizeVal[i] == '\0'; i++)
        {
            counter++;
        }
        size = new char[counter];
        for (int i = 0; i < counter; i++)
        {
            size[i] = sizeVal[i];
        }
    }

    char *getTopping()
    {
        return topping;
    }

    double getPrice()
    {
        return price;
    }

    char *getName()
    {
        return name;
    }

    char *getSize()
    {
        return size;
    }

    void makePizza()
    {
        if (topping == NULL)
        {
            is_ready = true;
        }
    }

    bool check_status()
    {
        return is_ready;
    }

    ~Pizza()
    {
    }
};