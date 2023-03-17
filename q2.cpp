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

int main()
{
    string topping, name, size;
    double price;
    bool ready_status;

    cout << "Enter pizza topping: ";
    getline(cin, topping);

    cout << "Enter pizza price: ";
    cin >> price;
    cin.ignore();

    cout << "Enter pizza name: ";
    getline(cin, name);

    cout << "Enter pizza size (regular, medium, large): ";
    getline(cin, size);

    cout << "Is the pizza ready? (1 for yes, 0 for no): ";
    cin >> ready_status;

    Pizza p1(topping, price, name, size, ready_status);
    p1.makePizza();

    cout << "Pizza topping: " << p1.getTopping() << endl;
    cout << "Pizza size: " << p1.getSize() << endl;
    cout << "Pizza price: " << p1.getPrice() << endl;
    cout << "Pizza status: " << p1.check_status() << endl;
    return 0;
}
