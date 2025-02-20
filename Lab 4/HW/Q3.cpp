#include <iostream>
using namespace std;

class Invoice {
    string partNumber;
    string partDescription;
    int quantity;
    double pricePerItem;

public:
    // Constructor
    Invoice(string pNum, string pDesc, int qty, double price) {
        partNumber = pNum;
        partDescription = pDesc;
        quantity = (qty > 0) ? qty : 0;  // Ensure quantity is not negative
        pricePerItem = (price > 0) ? price : 0.0;  // Ensure price is not negative
    }

    // Method to calculate total invoice amount
    double getInvoiceAmount() {
        return quantity * pricePerItem;
    }

    // Display invoice details
    void displayInvoice() {
        cout << "Part Number: " << partNumber << endl;
        cout << "Part Description: " << partDescription << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per Item PKR" << pricePerItem << endl;
        cout << "Total Invoice Amount: PKR" << getInvoiceAmount() << endl;
    }
};

int main() {
    // Creating an Invoice object
    Invoice inv("1234", "Hammer", 3, 9.99);
    
    // Display invoice details
    cout << "Invoice Details:\n";
    inv.displayInvoice();

    return 0;
}
