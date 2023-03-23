#include <iostream>
#include <string>
using namespace std;

class Pizza
{
private:
    string name;
    string topping;
    string size;
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

    Pizza(string toppingVal, double priceVal)
    {
        name = "";
        size = "";
        is_ready = false;
        setTopping(toppingVal);
        setPrice(priceVal);
    }

    Pizza(string toppingVal, double priceVal, string nameVal, string sizeVal, bool ready_status)
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
    void setTopping(string toppingVal)
    {
        topping = toppingVal;
    }

    void setPrice(double priceVal)
    {
        price = priceVal;
    }

    void setName(string nameVal)
    {
        name = nameVal;
    }

    void setSize(string sizeVal)
    {
        size = sizeVal;
    }

    string getTopping()
    {
        return topping;
    }

    double getPrice()
    {
        return price;
    }

    string getName()
    {
        return name;
    }

    string getSize()
    {
        return size;
    }

    void makePizza()
    {
        if (topping == "")
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