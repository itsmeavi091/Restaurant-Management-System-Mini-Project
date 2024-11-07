using System;
using System.Collections.Generic;

public class Table
{
    public int TableNumber { get; set; }
    public int Capacity { get; set; }
    public bool IsAvailable { get; set; }
    public float CurrentBill { get; set; }
    public Dictionary<string, int> Orders { get; set; }

    public Table(int tableNumber, int capacity)
    {
        TableNumber = tableNumber;
        Capacity = capacity;
        IsAvailable = true;
        CurrentBill = 0.0f;
        Orders = new Dictionary<string, int>();
    }
}

public class Restaurant
{
    private const int MaxTables = 50;
    private List<Table> tables = new List<Table>();
    private Dictionary<string, float> menu = new Dictionary<string, float>
    {
        {"Pasta", 12.99f},
        {"Pizza", 15.99f},
        {"Burger", 10.99f},
        {"Salad", 8.99f},
        {"Soda", 2.50f}
    };

    public void DisplayMenu()
    {
        Console.WriteLine("\nMenu:");
        foreach (var item in menu)
        {
            Console.WriteLine($"{item.Key}: ${item.Value}");
        }
    }

    public void AddTable(Table table)
    {
        if (tables.Count < MaxTables)
        {
            tables.Add(table);
            Console.WriteLine("Table added successfully!");
        }
        else
        {
            Console.WriteLine("Restaurant is at full capacity, cannot add more tables.");
        }
    }

    public void DisplayTables()
    {
        if (tables.Count == 0)
        {
            Console.WriteLine("No tables in the restaurant.");
            return;
        }

        Console.WriteLine("Tables in the Restaurant:");
        foreach (var table in tables)
        {
            Console.WriteLine($"Table Number: {table.TableNumber}, Capacity: {table.Capacity}, Available: {(table.IsAvailable ? "Yes" : "No")}, Current Bill: ${table.CurrentBill}");
        }
    }

    public void ReserveTable(int tableNumber)
    {
        var table = tables.Find(t => t.TableNumber == tableNumber);
        if (table != null)
        {
            if (table.IsAvailable)
            {
                table.IsAvailable = false;
                Console.WriteLine($"Table {tableNumber} has been reserved.");
            }
            else
            {
                Console.WriteLine($"Table {tableNumber} is already reserved.");
            }
        }
        else
        {
            Console.WriteLine("Table not found.");
        }
    }

    public void ReleaseTable(int tableNumber)
    {
        var table = tables.Find(t => t.TableNumber == tableNumber);
        if (table != null)
        {
            if (!table.IsAvailable)
            {
                table.IsAvailable = true;
                Console.WriteLine($"Table {tableNumber} has been released.");
            }
            else
            {
                Console.WriteLine($"Table {tableNumber} is already available.");
            }
        }
        else
        {
            Console.WriteLine("Table not found.");
        }
    }

    public void AddOrder(int tableNumber, string item, int quantity)
    {
        var table = tables.Find(t => t.TableNumber == tableNumber);
        if (table != null && !table.IsAvailable)
        {
            if (menu.ContainsKey(item))
            {
                float itemPrice = menu[item] * quantity;
                table.CurrentBill += itemPrice;

                if (table.Orders.ContainsKey(item))
                {
                    table.Orders[item] += quantity;
                }
                else
                {
                    table.Orders[item] = quantity;
                }

                Console.WriteLine($"Added {quantity} x {item} to table {tableNumber}");
                Console.WriteLine($"New bill for table {tableNumber}: ${table.CurrentBill}");
            }
            else
            {
                Console.WriteLine("Item not found in the menu.");
            }
        }
        else
        {
            Console.WriteLine(table == null ? "Table not found." : $"Table {tableNumber} is not reserved.");
        }
    }

    public void ViewOrderDetails(int tableNumber)
    {
        var table = tables.Find(t => t.TableNumber == tableNumber);
        if (table != null)
        {
            if (table.Orders.Count > 0)
            {
                Console.WriteLine($"Order details for table {tableNumber}:");
                foreach (var order in table.Orders)
                {
                    Console.WriteLine($"{order.Key} x {order.Value}");
                }
                Console.WriteLine($"Current total bill: ${table.CurrentBill}");
            }
            else
            {
                Console.WriteLine("No orders placed at this table yet.");
            }
        }
        else
        {
            Console.WriteLine("Table not found.");
        }
    }

    public void GenerateBill(int tableNumber)
    {
        var table = tables.Find(t => t.TableNumber == tableNumber);
        if (table != null)
        {
            Console.WriteLine($"Final bill for table {tableNumber}: ${table.CurrentBill}");
            table.CurrentBill = 0.0f;
            table.Orders.Clear();
        }
        else
        {
            Console.WriteLine("Table not found.");
        }
    }

    public int GetTableCount()
    {
        return tables.Count;
    }
}

public class Program
{
    static void AdminMenu(Restaurant restaurant)
    {
        int choice;
        do
        {
            Console.WriteLine("\nAdmin Menu");
            Console.WriteLine("1. Add Table");
            Console.WriteLine("2. Display Tables");
            Console.WriteLine("3. Reserve Table");
            Console.WriteLine("4. Release Table");
            Console.WriteLine("5. View Total Tables");
            Console.WriteLine("6. Exit");
            Console.Write("Enter your choice: ");
            choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    Console.Write("Enter table number: ");
                    int tableNumber = int.Parse(Console.ReadLine());
                    Console.Write("Enter table capacity: ");
                    int capacity = int.Parse(Console.ReadLine());
                    restaurant.AddTable(new Table(tableNumber, capacity));
                    break;

                case 2:
                    restaurant.DisplayTables();
                    break;

                case 3:
                    Console.Write("Enter table number to reserve: ");
                    tableNumber = int.Parse(Console.ReadLine());
                    restaurant.ReserveTable(tableNumber);
                    break;

                case 4:
                    Console.Write("Enter table number to release: ");
                    tableNumber = int.Parse(Console.ReadLine());
                    restaurant.ReleaseTable(tableNumber);
                    break;

                case 5:
                    Console.WriteLine($"Total tables in restaurant: {restaurant.GetTableCount()}");
                    break;

                case 6:
                    Console.WriteLine("Exiting admin menu...");
                    break;

                default:
                    Console.WriteLine("Invalid choice! Please try again.");
                    break;
            }
        } while (choice != 6);
    }

    static void CustomerMenu(Restaurant restaurant)
    {
        int choice;
        do
        {
            Console.WriteLine("\nCustomer Menu");
            Console.WriteLine("1. View Menu");
            Console.WriteLine("2. Add Order");
            Console.WriteLine("3. View Order Details");
            Console.WriteLine("4. Generate Bill");
            Console.WriteLine("5. Exit");
            Console.Write("Enter your choice: ");
            choice = int.Parse(Console.ReadLine());

            switch (choice)
            {
                case 1:
                    restaurant.DisplayMenu();
                    break;

                case 2:
                    Console.Write("Enter table number to add order: ");
                    int tableNumber = int.Parse(Console.ReadLine());
                    Console.Write("Enter item name: ");
                    string item = Console.ReadLine();
                    Console.Write("Enter quantity: ");
                    int quantity = int.Parse(Console.ReadLine());
                    restaurant.AddOrder(tableNumber, item, quantity);
                    break;

                case 3:
                    Console.Write("Enter table number to view order details: ");
                    tableNumber = int.Parse(Console.ReadLine());
                    restaurant.ViewOrderDetails(tableNumber);
                    break;

                case 4:
                    Console.Write("Enter table number to generate bill: ");
                    tableNumber = int.Parse(Console.ReadLine());
                    restaurant.GenerateBill(tableNumber);
                    break;

                case 5:
                    Console.WriteLine("Exiting customer menu...");
                    break;

                default:
                    Console.WriteLine("Invalid choice! Please try again.");
                    break;
            }
        } while (choice != 5);
    }

    public static void Main()
    {
        Restaurant restaurant = new Restaurant();
        int userType;

        do
        {
            Console.WriteLine("Welcome to the Restaurant Management System");
            Console.WriteLine("Select User Type:");
            Console.WriteLine("1. Admin");
            Console.WriteLine("2. Customer");
            Console.WriteLine("3. Exit");
            Console.Write("Enter your choice: ");
            userType = int.Parse(Console.ReadLine());

            switch (userType)
            {
                case 1:
                    AdminMenu(restaurant);
                    break;

                case 2:
                    CustomerMenu(restaurant);
                    break;

                case 3:
                    Console.WriteLine("Exiting the system...");
                    break;

                default:
                    Console.WriteLine("Invalid user type selected. Please try again.");
                    break;
            }
        } while (userType != 3);
    }
}
