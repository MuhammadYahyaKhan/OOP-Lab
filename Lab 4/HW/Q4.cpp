#include <iostream>
#include <vector>
using namespace std;

class Book {
    string author, title, publisher;
    double price;
    int stock;

public:
    // Constructor
    Book(string a, string t, string p, double pr, int s) {
        author = a;
        title = t;
        publisher = p;
        price = pr;
        stock = s;
    }

    // Function to display book details
    void display() {
        cout << "Title: " << title << "\nAuthor: " << author 
             << "\nPublisher: " << publisher << "\nPrice: $" << price 
             << "\nStock: " << stock << " copies\n";
    }

    // Function to check availability
    bool isAvailable(string t, string a) {
        return (title == t && author == a);
    }

    // Function to process book sale
    void sellBook(int quantity) {
        if (quantity <= stock) {
            cout << "Total Cost: $" << quantity * price << endl;
            stock -= quantity;
        } else {
            cout << "Required copies not in stock.\n";
        }
    }
};

int main() {
    vector<Book> books = {
        Book("Let us C", "ABC", "XYZ", 20.5, 10),
        Book("DSA", "ABC", "XYZ", 15.0, 5),
        Book("OOP", "ABC", "XYZ", 18.0, 8)
    };

    string searchTitle, searchAuthor;
    cout << "Enter book title: ";
    getline(cin, searchTitle);
    cout << "Enter author name: ";
    getline(cin, searchAuthor);

    bool found = false;
    for (auto &book : books) {
        if (book.isAvailable(searchTitle, searchAuthor)) {
            found = true;
            cout << "Book found!\n";
            book.display();

            int quantity;
            cout << "Enter number of copies required: ";
            cin >> quantity;

            book.sellBook(quantity);
            break;
        }
    }

    if (!found) {
        cout << "Book not available in stock.\n";
    }

    return 0;
}
