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

// Main function demonstrating usage of classes and file operations
int main() {
   try {
       Customer customer("John Doe", "john@example.com");  
       Order order(customer);  
        
       order.addProduct(Product("Laptop", 999.99, 1));  
       order.addProduct(Product("Mouse", 19.99, 2));

       order.displayOrder();  

       CreditCardPayment payment;  
       payment.processPayment(1019.97);  

       saveToFile(order);  

   } catch (const std::exception& e) {  
       std::cerr << "Error: " << e.what() << std::endl;  
       return 1;  
   }

   return 0;  
}