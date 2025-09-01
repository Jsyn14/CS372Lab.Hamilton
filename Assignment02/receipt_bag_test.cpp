
#include <iostream>
#include <string>
#include "ReceiptBag.hpp"

using namespace std;

int main() {
    cout << "ReceiptBag Class Test" << endl;
    cout << "====================" << endl;
    
    ReceiptBag<string> bag;
    
    // Insert items and store receipts
    cout << "Inserting items into bag..." << endl;
    int receipt1 = bag.insert("Apple");
    int receipt2 = bag.insert("Banana");
    int receipt3 = bag.insert("Cherry");
    int receipt4 = bag.insert("Date");
    
    cout << "Inserted Apple (receipt: " << receipt1 << ")" << endl;
    cout << "Inserted Banana (receipt: " << receipt2 << ")" << endl;
    cout << "Inserted Cherry (receipt: " << receipt3 << ")" << endl;
    cout << "Inserted Date (receipt: " << receipt4 << ")" << endl;
    
    cout << "\nBag size: " << bag.size() << endl;
    cout << "Is empty: " << (bag.empty() ? "Yes" : "No") << endl;
    
    // Remove items using receipts
    cout << "\nRemoving items..." << endl;
    try {
        string removed1 = bag.remove(receipt2);
        cout << "Removed: " << removed1 << " (using receipt " << receipt2 << ")" << endl;
        
        string removed2 = bag.remove(receipt4);
        cout << "Removed: " << removed2 << " (using receipt " << receipt4 << ")" << endl;
        
        cout << "\nBag size after removals: " << bag.size() << endl;
        
        // Try to remove with invalid receipt
        cout << "\nTrying to remove with invalid receipt..." << endl;
        string removed3 = bag.remove(999);
        cout << "Removed: " << removed3 << endl;
        
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    
    // Test receipt validation
    cout << "\nReceipt validation:" << endl;
    cout << "Receipt " << receipt1 << " is valid: " << (bag.isValidReceipt(receipt1) ? "Yes" : "No") << endl;
    cout << "Receipt " << receipt2 << " is valid: " << (bag.isValidReceipt(receipt2) ? "Yes" : "No") << endl;
    cout << "Receipt " << receipt3 << " is valid: " << (bag.isValidReceipt(receipt3) ? "Yes" : "No") << endl;
    
    return 0;
}
