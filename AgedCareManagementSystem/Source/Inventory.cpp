#include "Inventory.h"

#include <vector>
#include <string>
#include <print>
#include <iostream>

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

void Inventory::HandleInput(const std::string Input) {
    if (Input == "0") {
        DisplayAllItems();
    }
    if (Input == "1") {
        AddItem();
    }
}

void Inventory::Menu()
{
	std::println("Welcome to the Inventory Management!");
	std::println("Here are the options:");
	std::println("[0] - Display all items");
    std::println("[1] - Add New Item");

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

void Inventory::AddItem() {
    Item newItem;

    std::println("Enter Item Name: ");
    std::cin >> textInput;
    const std::string name = textInput;
    newItem.name = name;

    std::println("Enter Item Description: ");
    std::cin >> textInput;
    const std::string desc = textInput;
    newItem.desc = desc;

    std::println("Enter Item Cost: ");
    std::cin >> textInput;
    const int cost = std::stoi(textInput);
    newItem.cost = cost;
   

    items.push_back(newItem);
}

void Inventory::addRoom(const std::string& name) {
    Room newroom;
    newroom.name = name;

    rooms.push_back(newroom);
}

void Inventory::addItemToRoom(Room room, Item item, int quantity = 1) {
    room.items.push_back({ item, quantity });
}
