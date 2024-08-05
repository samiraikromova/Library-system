// u2310165 u2310096 u2310092 u2310187 u2310177
// 11 may 2024
// Project 1 OOP2

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Base Class
template<typename T>
class Book {
private:
    string title;
    string author;
    int yearPublished;
    string genre;
    double price;
    double deliveryPrice;

public:
    // Default Constructor
    Book() : title(""), author(""), yearPublished(0), genre(""), price(0.0), deliveryPrice(0.0) {}
    // Parameterized Constructor
    Book(const string& title, const string& author, int yearPublished, const string& genre, double price, double deliveryPrice)
        : title(title), author(author), yearPublished(yearPublished), genre(genre), price(price), deliveryPrice(deliveryPrice) {}

    // Getter and Setter Functions
    const string& getTitle() const { return title; }
    void setTitle(const string& title) { this->title = title; }

    const string& getAuthor() const { return author; }
    void setAuthor(const string& author) { this->author = author; }

    int getYearPublished() const { return yearPublished; }
    void setYearPublished(int yearPublished) { this->yearPublished = yearPublished; }

    const string& getGenre() const { return genre; }
    void setGenre(const string& genre) { this->genre = genre; }

    double getPrice() const { return price; }
    void setPrice(double price) { this->price = price; }

    double getDeliveryPrice() const { return deliveryPrice; }
    void setDeliveryPrice(double deliveryPrice) { this->deliveryPrice = deliveryPrice; }

    // Function that calculates total price by adding a delivery price to a price of the book
    double calculateTotal() const {
        return deliveryPrice + price;
    }

    //Function to display all Information about Book
    void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year Published: " << yearPublished << endl;
        cout << "Genre: " << genre << endl;
        cout << "Price of the Book: " << price << " UZS" << endl;
        cout << "Total Price including Delivery: " << calculateTotal() << " UZS" << endl;
        cout << endl;
    }
};

// Derived Class
template<typename T>
class Library {
private:
    vector<T> books;

public:
    // Default Constructor
    Library() {}

    // Function to add a book
    void showBook(const T& book) {
        books.push_back(book);
    }

    // Function to display all books
    void displayAllBooks() const {
        for (const T& book : books) {
            book.displayInfo();
        }
    }

};

int main() {

    Library<Book<string>> lib; // Using Book class with string as template parameter

    Book<string> b1("Pet sematary", "Stephen King", 1983, "Horror", 159.999, 30.000);
    Book<string> b2("Harry Potter", "J.K. Rowling", 1997, "Fantasy", 149.999, 25.000);
    Book<string> b3("The Picture of Dorian Gray", "Oscar Wilde", 1983, "Philosophical", 95.999, 20.000);
    Book<string> b4("The Girl with the Dragon Tattoo", "Stieg Larsson", 2005, "Psychological thriller", 149.999, 26.000);
    Book<string> b5("Amphibian Man", "Alexander Belyaev", 1928, "Science fiction adventure ", 79.999, 30.000);

    lib.showBook(b1);
    lib.showBook(b2);
    lib.showBook(b3);
    lib.showBook(b4);
    lib.showBook(b5);

    int choice, con;

    string searchTerm;
    string Bname;
    
    cout << "Main menu" << endl << endl;
    cout << "1) Show all books " << endl;
    cout << "2) Find a book " << endl;
    cout << "3) Exit " << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    
    switch (choice) {
    case 1:
        lib.displayAllBooks();
        cout << "1) Back to main menu" << endl ;
        cout << "2) Exit" << endl;
        cout << "Enter your choice: ";
        cin >> con;
        if (con == 1)
        {
        cout << endl;
        cout << "Main menu" << endl << endl;
        cout << "1) Show all books " << endl;
        cout << "2) Find a book " << endl;
        cout << "3) Exit " << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;  
        }
        else
        {
            break;
        }

    case 2:
        cout << "Choose a book name:" << endl;
        cout << "1) AmphibianMan.txt " << endl;
        cout << "2) HarryPotter.txt " << endl;
        cout << "3) PetCemetery.txt" << endl;
        cout << "4) PortraitOfDorianGray.txt" << endl;
        cout << "5) TheGirlWithTheDragonTattoo.txt" << endl;
        cout << "Enter the name of the file as it is displayed: ";
        cin >> Bname;
        cout << endl;
    default:
        cout << "See you!" << endl;
    }
    // Open a file in read mode

    string path = Bname;

    ifstream fin;
    fin.open(path);

    if (fin.is_open())
    {
        cout << "Here is your book" << endl << endl;

        char ch;
        while (fin.get(ch))
        {
            cout << ch;
        }
    }
    else {
        cout << "Finish!";
    }
    return 0;
}