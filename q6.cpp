#include <iostream>
using namespace std;
class Library
{
private:
    char *bookTitle;
    char *author;
    int bookID;
    int quantity;
    float price;
    static int totalBooks;

public:
    Library()
    {
        bookTitle = NULL;
        author = NULL;
        bookID = 0;
        quantity = 0;
        price = 0;
    }
    ~Library()
    {
        delete[] bookTitle;
        delete[] author;
    }
    char *getBookTitle()
    {
        return bookTitle;
    }

    char *getAuthor()
    {
        return author;
    }

    int getBookID()
    {
        return bookID;
    }

    int getQuantity()
    {
        return quantity;
    }

    float getPrice()
    {
        return price;
    }
    void setBookTitle(char *title)
    {
        int size = 1;
        for (int i = 0; bookTitle[i] == '\0'; i++)
        {
            size++;
        }
        for (int i = 0; i < size; i++)
        {
            bookTitle[i] = title[i];
        }
    }
    void setAuthor(char *authorName)
    {
        int size = 1;
        for (int i = 0; authorName[i] == '\0'; i++)
        {
            size++;
        }
        for (int i = 0; i < size; i++)
        {
            author[i] = authorName[i];
        }
    }
    void setBookID(int bookID)
    {
        this->bookID = bookID;
    }
    void setQuantity(int quantity)
    {
        if (quantity < 0)
        {
            cout << "Quantity cannot be negative. Setting to 0." << endl;
            this->quantity = 0;
        }
        else
        {
            this->quantity = quantity;
        }
    }
    void setPrice(float price)
    {
        this->price = price;
    }
    static void setTotalBooks(int totBooks)
    {
        totalBooks = totBooks;
    }
    void calcTotalPrice()
    {
        float totalPrice = quantity * price;
        cout << "The total price  is:" << totalPrice << endl;
    }
    static int getTotalBooks()
    {
        return totalBooks;
    }
};
Library getBook_at(Library books[100], int index)
{
    Library Book_at = books[index];
    return Book_at;
}
void addBook(Library books[100], Library newBook)
{
    for (int i = 0; i < 100; i++)
    {
        if (Library::getTotalBooks() < 100)
        {
            Library::setTotalBooks(Library::getTotalBooks() + 1);
        }
    }
}
void removeBook(Library books[100], int bookID)
{
    for (int i = 0; Library::getTotalBooks(); i++)
    {
        if (books[i].getBookID() == bookID)
        {
            Library::setTotalBooks(Library::getTotalBooks() - 1);
            break;
        }
    }
}
void SortByTitle(Library books[100])
{
}