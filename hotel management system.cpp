#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Customer {
    int roomNumber;
    string name;
    string address;
    string phone;
    int days;
    float payment;
};

vector<Customer> hotel;

// Add customer
void addCustomer() {
    Customer c;
    cout << "\nEnter Room Number: ";
    cin >> c.roomNumber;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, c.name);
    cout << "Enter Address: ";
    getline(cin, c.address);
    cout << "Enter Phone Number: ";
    getline(cin, c.phone);
    cout << "Enter Number of Days Stay: ";
    cin >> c.days;
    cout << "Enter Payment Amount: ";
    cin >> c.payment;
    hotel.push_back(c);
    cout << "✅ Customer added successfully!\n";
}

// View all customers
void viewCustomers() {
    if (hotel.empty()) {
        cout << "❌ No customer records available.\n";
        return;
    }

    cout << "\n📋 Customer List:\n";
    cout << left << setw(10) << "Room"
         << setw(20) << "Name"
         << setw(20) << "Phone"
         << setw(10) << "Days"
         << setw(10) << "Payment" << endl;

    for (const auto& c : hotel) {
        cout << left << setw(10) << c.roomNumber
             << setw(20) << c.name
             << setw(20) << c.phone
             << setw(10) << c.days
             << "₹" << c.payment << endl;
    }
}

// Search by room number
void searchCustomer() {
    int room;
    cout << "\nEnter Room Number to Search: ";
    cin >> room;

    for (const auto& c : hotel) {
        if (c.roomNumber == room) {
            cout << "\n🔍 Customer Found:\n";
            cout << "Name: " << c.name
                 << "\nAddress: " << c.address
                 << "\nPhone: " << c.phone
                 << "\nDays Stay: " << c.days
                 << "\nPayment: ₹" << c.payment << endl;
            return;
        }
    }
    cout << "❌ Customer not found.\n";
}

// Edit customer info
void editCustomer() {
    int room;
    cout << "\nEnter Room Number to Edit: ";
    cin >> room;

    for (auto& c : hotel) {
        if (c.roomNumber == room) {
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, c.name);
            cout << "Enter New Address: ";
            getline(cin, c.address);
            cout << "Enter New Phone: ";
            getline(cin, c.phone);
            cout << "Enter New Days Stay: ";
            cin >> c.days;
            cout << "Enter New Payment: ";
            cin >> c.payment;
            cout << "✅ Customer updated successfully!\n";
            return;
        }
    }
    cout << "❌ Customer not found.\n";
}

// Delete customer
void deleteCustomer() {
    int room;
    cout << "\nEnter Room Number to Delete: ";
    cin >> room;

    for (auto it = hotel.begin(); it != hotel.end(); ++it) {
        if (it->roomNumber == room) {
            hotel.erase(it);
            cout << "✅ Customer record deleted.\n";
            return;
        }
    }
    cout << "❌ Customer not found.\n";
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n========= Hotel Management System =========\n";
        cout << "1. Add New Customer\n";
        cout << "2. View All Customers\n";
        cout << "3. Search Customer by Room\n";
        cout << "4. Edit Customer Info\n";
        cout << "5. Delete Customer Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: viewCustomers(); break;
            case 3: searchCustomer(); break;
            case 4: editCustomer(); break;
            case 5: deleteCustomer(); break;
            case 6: cout << "👋 Exiting... Thank you!\n"; break;
            default: cout << "⚠️ Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

