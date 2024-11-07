# Restaurant Management System

A simple console-based Restaurant Management System built in C# that allows both admins and customers to interact with the system. The system supports functionalities such as table reservations, ordering food, viewing menus, generating bills, and managing the restaurant's tables.

## Features

### Admin Features:
- **Add Tables**: Admins can add new tables to the restaurant, with a table number and capacity.
- **Display Tables**: View all the tables in the restaurant along with their current status (available or reserved) and the total bill for each table.
- **Reserve/Release Tables**: Admins can reserve or release tables based on availability.
- **View Total Tables**: Admins can see the total number of tables in the restaurant.

### Customer Features:
- **View Menu**: Customers can view the available food items and their prices.
- **Add Orders**: Customers can place orders at their reserved tables, specifying the item and quantity.
- **View Order Details**: Customers can view the details of the orders placed at their table.
- **Generate Bill**: Customers can generate the final bill for their table based on the items ordered.

## Technologies Used
- **C#**: The main programming language used for developing the system.
- **Console Application**: The system runs as a console-based application.

## Requirements
- .NET Core or .NET Framework to run the C# program.
- A terminal or command prompt to execute the program.

## How to Run

1. Clone the repository or download the files.
2. Open the project in Visual Studio or any other C# IDE.
3. Build and run the program.
4. Select the user type (Admin or Customer) and start interacting with the system.

## Code Explanation

- **Table Class**: Represents a table in the restaurant with properties like table number, capacity, availability, current bill, and orders.
- **Restaurant Class**: Handles the restaurant's operations like adding tables, displaying tables, reserving/releasing tables, adding orders, and generating bills.
- **Program Class**: The entry point of the program where the main menu logic is handled for both Admin and Customer.

### Admin Menu Options:
1. Add Table
2. Display Tables
3. Reserve Table
4. Release Table
5. View Total Tables
6. Exit

### Customer Menu Options:
1. View Menu
2. Add Order
3. View Order Details
4. Generate Bill
5. Exit
   
### Contributing
    Feel free to fork the repository and contribute by submitting pull requests. If you encounter any bugs or have suggestions for improvements, please open an issue in the GitHub repository.
## Authors
Avinash Kumar
