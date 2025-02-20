#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class MenuItem {
public:
    string name;
    string type;  // "food" or "drink"
    double price;

    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    // Constructor
    CoffeeShop(string shopName, vector<MenuItem> menuItems) {
        name = shopName;
        menu = menuItems;
    }

    // Add an order if available
    string addOrder(string itemName) {
        for (auto &item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    // Fulfill an order
    string fulfillOrder() {
        if (!orders.empty()) {
            string fulfilledItem = orders.front();
            orders.erase(orders.begin());
            return "The " + fulfilledItem + " is ready";
        }
        return "All orders have been fulfilled";
    }

    // List all orders
    vector<string> listOrders() {
        return orders;
    }

    // Calculate total amount due
    double dueAmount() {
        double total = 0.0;
        for (auto &order : orders) {
            for (auto &item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    // Get the cheapest item
    string cheapestItem() {
        if (menu.empty()) return "No items in menu";

        double minPrice = numeric_limits<double>::max();
        string cheapest;
        for (auto &item : menu) {
            if (item.price < minPrice) {
                minPrice = item.price;
                cheapest = item.name;
            }
        }
        return cheapest;
    }

    // Get all drinks
    vector<string> drinksOnly() {
        vector<string> drinks;
        for (auto &item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    // Get all food items
    vector<string> foodOnly() {
        vector<string> food;
        for (auto &item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    vector<MenuItem> menu = {
        MenuItem("Coffee", "drink", 2.5),
        MenuItem("Tea", "drink", 2.0),
        MenuItem("Sandwich", "food", 5.0),
        MenuItem("Cake", "food", 3.5)
    };

    CoffeeShop shop("Cafe Delight", menu);

    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Sandwich") << endl;
    cout << shop.addOrder("Burger") << endl;  // Not available

    cout << shop.fulfillOrder() << endl;
    cout << "Total Due: $" << shop.dueAmount() << endl;

    cout << "Cheapest Item: " << shop.cheapestItem() << endl;

    cout << "Drinks Only: ";
    for (auto &drink : shop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food Only: ";
    for (auto &food : shop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    return 0;
}
