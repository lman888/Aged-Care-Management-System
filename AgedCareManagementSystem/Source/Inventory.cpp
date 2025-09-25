#include <string_view>
#include <vector>
#include <string>
using namespace std;

class Inventory {
    Inventory::Inventory() {

        Item item1;
        item1.name = "Syringe";
        item1.cost = 10;

        items.push_back(item1);

        Room room1;
        room1.name = "Bedroom";
        room1.items.push_back({ item1, 10 });

        
    }
    void Inventory::Run() {
        std::println("Inventory");
    }

        void Inventory::addItem(const std::string& name, const std::string& desc, int cost) {
            Item newitem;
            newitem.name = name;
            newitem.desc = desc;
            newitem.cost = cost;

            items.push_back(newitem);


    }

        void Inventory::addRoom(const std::string& name) {
            Room newroom;
            newroom.name = name;

            rooms.push_back(newroom);
        }

        void Inventory::addItemToRoom(Room room, Item item, int quantity = 1) {
            room.items.push_back({ item, quantity });
        }

    //void addItem(const std::string& name, const std::string& room, int qty = 1) {
    //    // look through the inventory to see if there are any of the item there already
    //    for (Item& item : items) {
    //        // if the item is already there increase the quantity
    //        if (item.name == name) {
    //            item.quantity += qty;
    //            return; // do nothing else
    //        }
    //    }
    //    // add the item if it wasn't already there
    //    items.push_back({ name, room, qty });
    //}

    //void removeItem(const std::string& name, int qty = 1) {
    //    // go through all of the items
    //    for (ItemInfo it = items.begin(); it != items.end(); ++it) {
    //        // if the item is found
    //        if (it->name == name) {
    //            // reducce the quantity
    //            it->quantity -= qty;
    //            // warning message if item reaches 0
    //            if (it->quantity <= 0) std::cout << item.name << "WARNING: Zero stock!";
    //                //warning message if item reaches 5 or below
    //                if (it->quantity <= 5) std::cout << item.name << "Warning: Low stock!";
    //            return;
    //        }
    //    }
    //}

    //void print() const {
    //    // print out each item in the list
    //    for (const Item& item : items) {
    //        std::cout << item.name << ": " << item.quantity << " (" << item.room << ")\n";
    //    }
    //}
};

//int main() {
//    Inventory medicalEquipment;
//    Inventory medicine;
//    Inventory beds;
//
//    medicalEquipment.addItem("Medical1", "Room1", 5);
//    medicalEquipment.addItem("Medical2", "Room1", 1);
//
//    medicine.addItem("Morphine", "Room2", 500);
//    medicine.addItem("Panadol", "Room2", 1);
//
//    beds.addItem("Good bed", "Bedroom1", 1);
//    beds.addItem("Better bed", "Bedroom2", 10);
//
//    std::cout << "Equipment: \n";
//    medicalEquipment.print();
//
//    std::cout << "Medicine: \n";
//    medicine.print();
//
//    std::cout << "Beds: \n";
//    beds.print();
//
//    return 0;
//}