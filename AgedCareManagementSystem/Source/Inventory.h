#pragma once

//Project Includes
#include "MasterManagement.cpp"

//External Includes
#include <string>
#include <vector>
#include <print>
#include <iostream>

struct Item {
    std::string name;
    std::string desc;
    int cost;
    std::string room;
    int quantity;
};

struct RoomItem {
    Item item;
    int quantity;
};

struct Room {
    std::string name;
    std::vector<RoomItem> items;
};

class Inventory : public MasterManagement
{
public:
    Inventory();
    ~Inventory();

    void Run() override;

private:
    void HandleInput(const std::string Input) override;
    void Menu() override;
    void DisplayAllItems();

    void AddItem();
    void UpdateItem();
    void RemoveItem();
    void addRoom(const std::string& name);
    void addItemToRoom(Room room, Item item, int quantity);

    std::vector<Item> items;
    std::vector<Room> rooms;
};
