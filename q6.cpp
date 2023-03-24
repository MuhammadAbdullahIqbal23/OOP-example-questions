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
        for (int i = 0; title[i] == '\0'; i++)
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

        this->quantity = quantity;
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
    if (index < 0 && index > 100)
    {
        return;
    }
    else
    {
        Library Book_at = books[index];
        return Book_at;
    }
}
void addBook(Library books[100], Library newBook)
{

    for (int i = 0; i < Library::getTotalBooks(); i++)
    {
        if (i == 100)
        {
            cout << "Library is full." << endl;
            exit(0);
        }
        if (Library::getTotalBooks() < 100)
        {
            if (books[i].getBookID() == 0)
            {
                books[i].setAuthor(newBook.getAuthor());
                books[i].setBookID(newBook.getBookID());
                books[i].setBookTitle(newBook.getBookTitle());
                books[i].setPrice(newBook.getPrice());
                books[i].setQuantity(newBook.getQuantity());
                books[i].setTotalBooks(Library::getTotalBooks() + newBook.getQuantity());
                return;
            }
        }
    }
}
void removeBook(Library books[100], int bookID)
{
    for (int i = 0; i < Library::getTotalBooks(); i++)
    {
        if (books[i].getBookID() == bookID)
        {
            books[i].setAuthor("");
            books[i].setBookID(-1);
            books[i].setBookTitle("");
            books[i].setPrice(0.0);
            books[i].setQuantity(0);
            books[i].setTotalBooks(Library::getTotalBooks() - 1);
            return;
        }
    }
}
void SortByTitle(Library books[100])
{
    for (int i = 0; i < Library::getTotalBooks() - 1; i++)
    {
        for (int j = 0; j < Library::getTotalBooks() - i - 1; j++)
        {
            if ((books[j].getBookTitle() > books[j + 1].getBookTitle()))
            {
                Library temp;
                temp.setBookTitle(books[j].getBookTitle());
                books[j].setBookTitle(books[j + 1].getBookTitle());
                books[j + 1].setBookTitle(temp.getBookTitle());
            }
        }
    }
}
void SortByAuthor(Library books[100])
{
    for (int i = 0; i < Library::getTotalBooks() - 1; i++)
    {
        for (int j = 0; j < Library::getTotalBooks() - i - 1; j++)
        {
            if ((books[j].getAuthor() > books[j + 1].getAuthor()))
            {
                Library temp;
                temp.setAuthor(books[j].getAuthor());
                books[j].setAuthor(books[j + 1].getAuthor());
                books[j + 1].setAuthor(temp.getAuthor());
            }
        }
    }
}
void SortByPrice(Library books[100])
{

    for (int i = 0; i < Library::getTotalBooks() - 1; i++)
    {
        for (int j = 0; j < Library::getTotalBooks() - i - 1; j++)
        {
            if ((books[j].getPrice() > books[j + 1].getPrice()))
            {
                Library temp;
                temp.setPrice(books[j].getPrice());
                books[j].setPrice(books[j + 1].getPrice());
                books[j + 1].setPrice(temp.getPrice());
            }
        }
    }
}
bool searchByTittle(Library books[10], char *titlename)
{
    bool flag;
    for (int i = 0; i < 10; i++)
    {
        if (books[i].getBookTitle() == &titlename[i])
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}
Library mostExpensiveBook(Library books[10])
{
    int mostExpensiveBook = 0;
    Library book;
    for (int i = 0; i < 10; i++)
    {
        if ((books[i].getPrice() < mostExpensiveBook))
        {
            mostExpensiveBook = books[i].getPrice();
            book.setBookTitle(books[i].getBookTitle());
        }
    }
    return book;
}