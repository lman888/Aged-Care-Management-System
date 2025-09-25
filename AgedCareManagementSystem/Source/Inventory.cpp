#include "Inventory.h"

#include <vector>
#include <string>
#include <print>
#include <iostream>

Inventory::Inventory() {
    Item item1;
    item1.name = "Syringe";
    item1.cost = 10;
    item1.desc = "painful";
    item1.room = "2";
    item1.quantity = 4;
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

void Inventory::HandleInput(const std::string Input) {
    if (Input == "0") {
        DisplayAllItems();
    }
    if (Input == "1") {
        AddItem();
    }
    if (Input == "2") {
        UpdateItem();
    }
    if (Input == "3") {
        RemoveItem();
    }
}

void Inventory::Menu()
{
	std::println("Welcome to the Inventory Management!");
	std::println("Here are the options:");
	std::println("[0] - Display all items");
    std::println("[1] - Add New Item");
    std::println("[2] - Update Item");
    std::println("[3] - Remove Item");

    std::println("Type in [Back] to navigate to the Aged CareMain Menu");
}

void Inventory::DisplayAllItems() {
    for (Item item : items) {
        std::println("---------------------------------------------------------------");
        std::println("Item name: {}", item.name);
        std::println("Description: {}", item.desc);
        std::println("Cost: ${}", item.cost);
        std::println("Room Number: {}", item.room);
        std::println("Quantity: {}", item.quantity);
    }
}

void Inventory::AddItem() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // ask them for the item name
    std::println("Enter Item Name: ");
    std::string name;
    std::getline(std::cin, name);

    bool found = false;
    // look through the inventory to find the item
    for (Item& item : items) {
        // if the item is found
        if (item.name == name) {
            std::println("Item already exists");
            return; // do nothing else
        }
    }

    if (!found) {
        // ask them to enter the details
        std::println("Enter Item Description: ");
        std::string desc;
        std::getline(std::cin, desc);

        std::println("Enter Item Cost: ");
        std::cin >> textInput;
        const int cost = std::stoi(textInput);

        std::println("Enter Room Number: ");
        std::cin >> textInput;
        const std::string room = textInput;

        std::println("Enter Item Quantity: ");
        std::cin >> textInput;
        const int quantity = std::stoi(textInput);

        Item item;
        item.name = name;
        item.cost = cost;
        item.desc = desc;
        item.room = room;
        item.quantity = quantity;

        items.push_back(item);

        std::println("Item Added");
    }
}

void Inventory::UpdateItem() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // ask them for the item name
    std::println("Enter Item Name: ");
    std::string name;
    std::getline(std::cin, name);

    bool found = false;
    // look through the inventory to find the item
    for (Item& item : items) {
        // if the item is found
        if (item.name == name) {
            // ask them to enter the new details
            std::println("Enter Item Description: ");
            std::string desc;
            std::getline(std::cin, desc);

            std::println("Enter Item Cost: ");
            std::cin >> textInput;
            const int cost = std::stoi(textInput);

            std::println("Enter Room Number: ");
            std::cin >> textInput;
            const std::string room = textInput;

            std::println("Enter Item Quantity: ");
            std::cin >> textInput;
            const int quantity = std::stoi(textInput);

            // update the item details
            item.cost = cost;
            item.desc = desc;
            item.room = room;
            item.quantity = quantity;
           
            std::println("Item Updated");
            return; // do nothing else
        }
    }

    if (!found) {
        // tell them the item wasn't found
        std::println("Item Not Found!");
    }
}

    void Inventory::RemoveItem() {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // ask them to enter the item name
        std::println("Enter Item Name: ");
        std::string name;
        std::getline(std::cin, name);

        bool found = false;
        // go through all of the items
        for (auto it = items.begin(); it != items.end(); ++it) {
            // if the item is found
            if (it->name == name) {
                items.erase(it);
                found = true;
                std::println("Item Removed");
                return;
            }
        }

        if (!found) {
            // tell them the item wasn't found
            std::println("Item not Found");
        }
    }

void Inventory::addRoom(const std::string& name) {
    Room newroom;
    newroom.name = name;

    rooms.push_back(newroom);
}


void Inventory::addItemToRoom(Room room, Item item, int quantity = 1) {
    room.items.push_back({ item, quantity });
}
