#include <iostream>   // For standard input and output streams
#include <fstream>    // For file input/output operations
#include <string>     // For using the string class
#include <vector>     // For using the vector container
#include <stdexcept>  // For exception handling

// Class representing a product in the inventory
class Product {
private:
    std::string name;   // Name of the product
    double price;       // Price of the product
    int quantity;       // Quantity available in stock

public:
    Product(const std::string& name, double price, int quantity) 
        : name(name), price(price), quantity(quantity) {}
    
    ~Product() {}

    void display() const {
        std::cout << "Product Name: " << name 
                  << ", Price: $" << price 
                  << ", Quantity: " << quantity << std::endl;
    }

    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
};

// Class representing a customer in the system
class Customer {
private:
    std::string name;  // Customer's name
    std::string email; // Customer's email address

public:
    Customer(const std::string& name, const std::string& email) 
        : name(name), email(email) {}
    
    ~Customer() {}

    void display() const {
        std::cout << "Customer Name: " << name 
                  << ", Email: " << email << std::endl;
    }
};

// Class representing an order made by a customer
class Order {
private:
    Customer customer;               // The customer who made the order
    std::vector<Product> products;   // List of products in the order

public:
    Order(const Customer& customer) : customer(customer) {}
    
    void addProduct(const Product& product) {
        products.push_back(product);  // Add product to the vector of products 
    }

    void displayOrder() const {
        customer.display();  // Display customer details
        
        std::cout << "Ordered Products:" << std::endl;
        
        for (const auto& product : products) {
            product.display();  // Display each product in the order 
        }
    }
};

// Abstract class representing payment methods for orders.
class Payment {
public:
    virtual void processPayment(double amount) = 0;  // Pure virtual function for processing payment

protected:
    virtual ~Payment() {}  // Protected destructor for abstract class.
};

// Class representing credit card payment method, derived from Payment class.
class CreditCardPayment : public Payment {
public:
    void processPayment(double amount) override {  // Override pure virtual function from Payment class.
        std::cout << "Processing credit card payment of $" << amount << std::endl;
        // Implement payment processing logic here...
    }
};

// Function to save order details to a file
void saveToFile(const Order& order) {
   std::ofstream outFile("order.txt");
   if (!outFile) {
       throw std::runtime_error("Could not open file for writing.");
   }
   outFile << "Order Details:\n";
   outFile.close();
}

// Function to display the menu and handle user input
void displayMenu() {
    std::cout << "\n=== E-Commerce System Menu ===\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Create Customer\n";
    std::cout << "3. Create Order\n";
    std::cout << "4. View Orders\n";
    std::cout << "5. Exit\n";
}

int main() {
   // Vectors to store products and orders
   std::vector<Product> products;
   std::vector<Order> orders;
   int choice;  // Variable to store user's menu choice

   do {
       displayMenu();  // Display the menu options
       std::cout << "Enter your choice: ";
       std::cin >> choice;  // Get user's choice

       switch (choice) {
           case 1: {  // Add Product
               std::string name;
               double price;
               int quantity;

               // Prompt user for product details
               std::cout << "Enter product name: ";
               std::cin >> name;
               std::cout << "Enter product price: ";
               std::cin >> price;
               std::cout << "Enter product quantity: ";
               std::cin >> quantity;

               products.emplace_back(name, price, quantity);  // Add new product to vector
               std::cout << "Product added successfully!\n";
               break;
           }
           case 2: {  // Create Customer
               std::string name, email;

               // Prompt user for customer details
               std::cout << "Enter customer name: ";
               std::cin >> name;
               std::cout << "Enter customer email: ";
               std::cin >> email;

               Customer newCustomer(name, email);  // Create new customer object
               orders.emplace_back(newCustomer);     // Create an empty order for this customer
               break;
           }
           case 3: {  // Create Order
               if (orders.empty()) {  // Check if there are any customers available
                   std::cout << "No customers available. Please create a customer first.\n";
                   break;
               }

               int customerIndex = orders.size() - 1;  // Use last created customer for simplicity
               Order& currentOrder = orders[customerIndex];  // Reference to current order

               char addMore = 'y';  // Variable to control adding more products
               while (addMore == 'y') {
                   if (products.empty()) {  // Check if there are any products available
                       std::cout << "No products available. Please add a product first.\n";
                       break;
                   }

                   int productIndex = 0;
                   for (const auto& product : products) {  // Display available products
                       product.display();
                       productIndex++;
                   }

                   int selectedProductIndex;  // Variable to store user's selected product index
                   std::cout << "Select a product by index (0 to " << (productIndex - 1) << "): ";
                   std::cin >> selectedProductIndex;

                   if (selectedProductIndex >= 0 && selectedProductIndex < productIndex) {
                       currentOrder.addProduct(products[selectedProductIndex]);  // Add selected product to order
                       std::cout << "Product added to order!\n";
                   } else {
                       std::cout << "Invalid selection.\n";  // Handle invalid selection
                   }

                   // Ask user if they want to add another product
                   std::cout << "Add another product? (y/n): ";
                   std::cin >> addMore;
               }
               
               currentOrder.displayOrder();  // Display the order details after creation

               CreditCardPayment payment;  
               payment.processPayment(100.00);  // Dummy amount for demonstration

               saveToFile(currentOrder);  
               
               break;
           }
           case 4: {  // View Orders
               if (orders.empty()) {  // Check if there are any orders available
                   std::cout << "No orders available.\n";
                   break;
               }

               for (const auto& order : orders) {  
                   order.displayOrder();  // Display each order's details
                   std::cout << "\n";
               }
               
               break;
           }
           case 5: {  // Exit option
               std::cout << "Exiting program...\n";  
               break;  
           }
           default:
               std::cout << "Invalid choice! Please try again.\n";  
       }

   } while (choice != 5);  // Continue until user chooses to exit

   return 0;  
}
