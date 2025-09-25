#include "MemberManagement.h"

#include <vector>
#include <string>

Inventory::Inventory() {
    Item item1;
    item1.name = "Syringe";
    item1.cost = 10;

    items.push_back(item1);

    Room room1;
    room1.name = "Bedroom";
    room1.items.push_back({ item1, 10 });
}

Inventory::~Inventory() {
}

void Inventory::Run() {
    while (true)
    {
        Menu();
        std::cin >> textInput;
        system("cls");

        if (textInput == "Back") {
            break;
        }

        HandleInput(textInput);
    }
}

void Inventory::HandleInput(const std::string& input) {
    if (input == "0") {
        DisplayAllItems();
    }
}

void Inventory::Menu()
{
	std::println("Welcome to the Inventory Management!");
	std::println("Here are the options:");
	std::println("[0] - Display all items");
    std::println("Type in [Back] to navigate to the Aged CareMain Menu");
}

void Inventory::DisplayAllItems() {
    for (Item item : items) {
        std::println("---------------------------------------------------------------");
        std::println("Item name: {}", item.name);
        std::println("Description: {}", item.desc);
        std::println("Cost: ${}", item.cost);
        std::println("---------------------------------------------------------------");
    }
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
