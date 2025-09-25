#include <string_view>
#include <string>
#include <vector>
#include <list>

struct Item {
    std::string name;
    std::string desc;
    int cost;
};

struct RoomItem {
    Item item;
    int quantity;
};

struct Room {
    std::string name;
    std::vector<RoomItem> items;
};

#pragma once
class Inventory
{
public:
    Inventory();

    void Run();

    void addItem(const std::string& name, const std::string& desc, int cost);

    void addRoom(const std::string& name);

    void addItemToRoom(Room room, Item item, int quantity = 1);

private:
    std::vector<Item> items;
    std::vector<Room> rooms;
};