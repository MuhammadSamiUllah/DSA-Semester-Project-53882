#include <iostream>
#include <string>
using namespace std;

// Node for Menu (Linked List)
struct MenuNode {
    string name;
    int price;
    MenuNode* next;
};

// Node for Customer (Binary Search)
struct CustomerNode {
    int id;
    string name;
    CustomerNode* left;
    CustomerNode* right;
};

// Node for Table (Binary Search Tree)
struct TableNode {
    int tableNumber;
    bool isAvailable;
    TableNode* left;
    TableNode* right;
};

// Queue Node (for Orders)
struct QueueNode {
    string order;
    QueueNode* next;
};

// Stack Node (for Orders)
struct StackNode {
    string order;
    StackNode* next;
};

class RestaurantManagement {
    // Linked List for Menu
    MenuNode* menuHead;

    // Binary Search Tree for Customer Database
    CustomerNode* customerRoot;

    // Binary Search Tree for Table Organization
    TableNode* tableRoot;

    // Queue for Order Management
    QueueNode* queueFront;
    QueueNode* queueRear;

    // Stack for Order Management
    StackNode* stackTop;

public:
    RestaurantManagement() {
        menuHead = nullptr;
        customerRoot = nullptr;
        tableRoot = nullptr;
        queueFront = queueRear = nullptr;
        stackTop = nullptr;
    }

    // Menu Management (Linked List)
    void addMenuItem(string name, int price) {
        MenuNode* newNode = new MenuNode{name, price, nullptr};
        if (!menuHead) {
            menuHead = newNode;
        } else {
            MenuNode* temp = menuHead;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayMenu() {
        MenuNode* temp = menuHead;
        while (temp) {
            cout << "Item: " << temp->name << ", Price: " << temp->price << endl;
            temp = temp->next;
        }
    }

    // Order Management (Queue and Stack)
    void addOrderToQueue(string order) {
        QueueNode* newNode = new QueueNode{order, nullptr};
        if (!queueRear) {
            queueFront = queueRear = newNode;
        } else {
            queueRear->next = newNode;
            queueRear = newNode;
        }
    }

    string processOrderFromQueue() {
        if (!queueFront) return "No orders in the queue!";
        string order = queueFront->order;
        QueueNode* temp = queueFront;
        queueFront = queueFront->next;
        delete temp;
        return order;
    }

    void addOrderToStack(string order) {
        StackNode* newNode = new StackNode{order, nullptr};
        newNode->next = stackTop;
        stackTop = newNode;
    }

    string processOrderFromStack() {
        if (!stackTop) return "No orders in the stack!";
        string order = stackTop->order;
        StackNode* temp = stackTop;
        stackTop = stackTop->next;
        delete temp;
        return order;
    }

    // Binary Search for Customer Database
    void addCustomer(int id, string name) {
        customerRoot = insertCustomer(customerRoot, id, name);
    }

    CustomerNode* insertCustomer(CustomerNode* root, int id, string name) {
        if (!root) {
            return new CustomerNode{id, name, nullptr, nullptr};
        }
        if (id < root->id) {
            root->left = insertCustomer(root->left, id, name);
        } else if (id > root->id) {
            root->right = insertCustomer(root->right, id, name);
        }
        return root;
    }

    bool searchCustomer(int id) {
        return searchCustomerRecursive(customerRoot, id);
    }

    bool searchCustomerRecursive(CustomerNode* root, int id) {
        if (!root) return false;
        if (root->id == id) return true;
        return (id < root->id) ? searchCustomerRecursive(root->left, id) : searchCustomerRecursive(root->right, id);
    }

    // Binary Search Tree for Table Organization
    void addTable(int tableNumber, bool isAvailable) {
        tableRoot = insertTable(tableRoot, tableNumber, isAvailable);
    }

    TableNode* insertTable(TableNode* root, int tableNumber, bool isAvailable) {
        if (!root) {
            return new TableNode{tableNumber, isAvailable, nullptr, nullptr};
        }
        if (tableNumber < root->tableNumber) {
            root->left = insertTable(root->left, tableNumber, isAvailable);
        } else {
            root->right = insertTable(root->right, tableNumber, isAvailable);
        }
        return root;
    }

    void displayTableStatus() {
        displayTableRecursive(tableRoot);
    }

    void displayTableRecursive(TableNode* root) {
        if (!root) return;
        displayTableRecursive(root->left);
        cout << "Table " << root->tableNumber << " - " << (root->isAvailable ? "Available" : "Occupied") << endl;
        displayTableRecursive(root->right);
    }

    // Sorting Orders (Selection and Bubble Sort)
    void sortOrdersSelection() {
        // Implement selection sort for orders (or any array of orders)
    }

    void sortOrdersBubble() {
        // Implement bubble sort for orders
    }

    // Recursive Functions for Bill Calculation
    int calculateBillRecursive(int orderId, int discount) {
        // Placeholder for recursive bill calculation logic
        return 0;  // This function can be expanded for bill calculation with discounts
    }

    // Time Complexity Analysis
    void timeComplexityAnalysis() {
        cout << "Time complexity for addMenuItem: O(n)" << endl;
    }
};

int main() {
    RestaurantManagement rm;

    rm.addMenuItem("Burger", 1200);
    rm.addMenuItem("Pizza", 1500);
    rm.addMenuItem("Pasta", 1000);

    rm.displayMenu();

    rm.addOrderToQueue("Order 1");
    rm.addOrderToQueue("Order 2");

    cout << "Processing Order: " << rm.processOrderFromQueue() << endl;

    rm.addCustomer(101, "John Doe");
    rm.addCustomer(102, "Jane Smith");

    if (rm.searchCustomer(101)) {
        cout << "Customer found!" << endl;
    } else {
        cout << "Customer not found!" << endl;
    }

    rm.addTable(1, true);
    rm.addTable(2, false);

    rm.displayTableStatus();

    rm.timeComplexityAnalysis();

    return 0;
}
