#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Medicine {
    int id;
    string name;
    int quantity;
    float price;
};

vector<Medicine> pharmacy;

// Add new medicine
void addMedicine() {
    Medicine m;
    cout << "\nEnter Medicine ID: ";
    cin >> m.id;
    cin.ignore();
    cout << "Enter Medicine Name: ";
    getline(cin, m.name);
    cout << "Enter Quantity: ";
    cin >> m.quantity;
    cout << "Enter Price per unit: ";
    cin >> m.price;
    pharmacy.push_back(m);
    cout << "✅ Medicine added successfully!\n";
}

// Display all medicines
void displayMedicines() {
    if (pharmacy.empty()) {
        cout << "❌ No medicines in inventory.\n";
        return;
    }
    cout << "\n📋 Medicine List:\n";
    cout << left << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price\n";
    for (const auto& m : pharmacy) {
        cout << left << setw(10) << m.id
             << setw(20) << m.name
             << setw(10) << m.quantity
             << "₹" << m.price << endl;
    }
}

// Search medicine by ID
void searchMedicine() {
    int id;
    cout << "\nEnter Medicine ID to search: ";
    cin >> id;
    for (const auto& m : pharmacy) {
        if (m.id == id) {
            cout << "\n🔍 Medicine Found:\n";
            cout << "ID: " << m.id
                 << "\nName: " << m.name
                 << "\nQuantity: " << m.quantity
                 << "\nPrice: ₹" << m.price << endl;
            return;
        }
    }
    cout << "❌ Medicine not found.\n";
}

// Update medicine info
void updateMedicine() {
    int id;
    cout << "\nEnter Medicine ID to update: ";
    cin >> id;
    for (auto& m : pharmacy) {
        if (m.id == id) {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, m.name);
            cout << "Enter New Quantity: ";
            cin >> m.quantity;
            cout << "Enter New Price: ";
            cin >> m.price;
            cout << "✅ Medicine updated successfully!\n";
            return;
        }
    }
    cout << "❌ Medicine not found.\n";
}

// Delete medicine
void deleteMedicine() {
    int id;
    cout << "\nEnter Medicine ID to delete: ";
    cin >> id;
    for (auto it = pharmacy.begin(); it != pharmacy.end(); ++it) {
        if (it->id == id) {
            pharmacy.erase(it);
            cout << "✅ Medicine deleted successfully!\n";
            return;
        }
    }
    cout << "❌ Medicine not found.\n";
}

// Show summary details
void showSummary() {
    int totalMedicines = pharmacy.size();
    int totalStock = 0;
    float totalValue = 0;

    for (const auto& m : pharmacy) {
        totalStock += m.quantity;
        totalValue += m.quantity * m.price;
    }

    cout << "\n📊 Inventory Summary:\n";
    cout << "Total Different Medicines: " << totalMedicines << endl;
    cout << "Total Units in Stock: " << totalStock << endl;
    cout << "Total Inventory Value: ₹" << totalValue << endl;
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n====== Pharmacy Management System ======\n";
        cout << "1. Add New Medicine\n";
        cout << "2. Display All Medicines\n";
        cout << "3. Search Medicine by ID\n";
        cout << "4. Update Medicine Info\n";
        cout << "5. Delete Medicine\n";
        cout << "6. Show Summary Details\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: updateMedicine(); break;
            case 5: deleteMedicine(); break;
            case 6: showSummary(); break;
            case 7: cout << "\n👋 Exiting... Thank you!\n"; break;
            default: cout << "⚠️ Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}

