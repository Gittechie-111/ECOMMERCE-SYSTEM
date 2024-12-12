🌟 *E-Commerce System* 🌟

🎯 *Description*  

This is a simple e-commerce system implemented in C++. The system allows customers to create orders containing multiple products, process payments via credit card, and save order details to a file. The code demonstrates key object-oriented programming concepts such as encapsulation, inheritance, polymorphism, and abstraction.

✨ *Features*  

- 🛒 *Product Management*: Create and manage products with attributes like name, price, and quantity.
- 
- 👤 *Customer Management*: Create customers with names and email addresses.
- 
- 📦 *Order Management*: Create orders for customers that can include multiple products.
- 
- 💳 *Payment Processing*: Simulate credit card payment processing.
- 
- 💾 *File I/O*: Save order details to a text file.
- 
- 🖥 *Command-Line Interface*: Interact with the system through a simple menu.
  

🔧 *Requirements*  
- C++11 or higher
- A C++ compiler (e.g., g++, clang++)
- Basic knowledge of command-line operations


📥 *Installation*  
1. Clone the repository:
 
   bash
   
   git clone https://github.com/yourusername/e-commerce system.git
   
3. Navigate to the project directory:
   
   bash
   
   cd e-commerce system
   
🛠 Compilation
To compile the program, use the following command:

bash

g++ -o ECommerceSystem e_commerce.cpp

🚀 Usage
Run the compiled program:

bash

./ECommerceSystem

Command-Line Interface (CLI)

When you run the program, you will be presented with a menu of options:
text

=== E-Commerce System Menu ===
1. Add Product
2. Create Customer
3. Create Order
4. View Orders
5. Exit

Enter your choice:

You can interact with the system by entering the corresponding number for each option:

Add Product: Enter product details (name, price, quantity) to add a new product to the inventory. 

Create Customer: Enter customer details (name and email) to create a new customer.

Create Order: Select an existing customer and add products to their order.

View Orders: Display all created orders along with their details.

Exit: Exit the program.

💬 Example Output
When you run the program, it will create a customer named "John Doe," add products to an order, display the order details, process a credit card payment, and save the order information to a file named order.txt.

📂 Code Structure

The code consists of a single file e_commerce.cpp that contains all class definitions and implementations:

🏷 Product: Represents a product with name, price, and quantity.

🧑‍🤝‍🧑 Customer: Represents a customer with name and email.

📃 Order: Represents an order that includes products and customer details.

🏦 Payment: An abstract class for payment methods.

💳 CreditCardPayment: A derived class that implements credit card payment processing.

🤝 Contributing
   Developed by Group N(Group 8) Year 2.1 students as an Assignment for coursework at Jkuat

👤 Gittechie-111

Building bridges between ideas and execution~Triza Museve



