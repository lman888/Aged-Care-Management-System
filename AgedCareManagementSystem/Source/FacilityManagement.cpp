#include "FacilityManagement.h"

#include <fstream>
#include <iostream>
#include <print>
#include "MasterManagement.cpp"
#include <filesystem>

FacilityManagement::FacilityManagement()
{
    Facility testRoom;
	testRoom.roomNumber = 101;
	testRoom.utilities.push_back("Electricity");
	testRoom.utilities.push_back("Water");
	testRoom.reservationDetails = "Doe, John";
	testRoom.reservationDate = "14/08/2025";
	testRoom.reservationEnd = "12/12/2025";
    testRoom.maintenanceStatus = "None";
    facilityList.push_front(testRoom);

    Facility testRoom2;
    testRoom2.roomNumber = 103;
    testRoom2.reservationDetails = "Doe, Jane";
    testRoom2.reservationDate = "01/01/2025";
    testRoom2.reservationEnd = "12/12/2027";
    testRoom2.maintenanceStatus = "Furniture replacement required";
    facilityList.push_front(testRoom2);

    Facility testRoom3;
	testRoom3.roomNumber = 102;
	testRoom3.utilities.push_back("Electricity");
	testRoom3.utilities.push_back("Water");
	testRoom3.reservationDetails = "Smith, Will";
	testRoom3.reservationDate = "20/09/2024";
    testRoom3.reservationEnd = "20/09/2026";
    testRoom3.maintenanceStatus = "Air conditioning repair needed";
	facilityList.push_front(testRoom3);

	Facility testRoom4;
	testRoom4.roomNumber = 201;
	testRoom4.utilities.push_back("Electricity");
	testRoom4.utilities.push_back("Water");
	testRoom4.utilities.push_back("Internet");
	testRoom4.utilities.push_back("Electric Blanket");
	testRoom4.reservationDetails = "Cehack, Loran";
    testRoom4.reservationDate = "09/04/2024";
    testRoom4.reservationEnd = "09/04/2026";
	testRoom4.maintenanceStatus = "Furniture replacement";
	facilityList.push_front(testRoom4);
}

FacilityManagement::~FacilityManagement()
{
}

void FacilityManagement::Test()
{
    Run();
}

void FacilityManagement::Run()
{
    std::string textInput;
    while (true)
    {
        Menu();
		std::cin >> textInput;
        system("cls");
        if (textInput == "Back")
        {
            break;
        }
		HandleInput(textInput);
    }
}

//

std::string FacilityManagement::getDate(const std::string& label)
{
    int day, month, year;
    while (true) {
        std::print("Day:");
        if (std::cin >> day && day >= 1 && day <= 31) break;
        std::println("Please enter a number between 1 and 31.");
        std::cin.clear();
        std::cin.ignore();
    }
    while (true) {
        std::print("Month:");
        if (std::cin >> month && month >= 1 && month <= 12) break;
        std::println("Please enter a number between 1 & 12.");
        std::cin.clear();
        std::cin.ignore();
    }
    while (true) {
        std::print("Year:");
        if (std::cin >> year && year > 0) break;
        std::println("Please enter a year (in numerals).");
        std::cin.clear();
        std::cin.ignore();
    }
    std::string dayStr = (day < 10 ? "0" : "") + std::to_string(day);
    std::string monthStr = (month < 10 ? "0" : "") + std::to_string(month);
    return dayStr + "/" + monthStr + "/" + std::to_string(year);
}

void FacilityManagement::ShowRooms()
{
    if (facilityList.empty())
    {
        std::println("No room reservations found.");
        return;
    }
    for (Facility& facility : facilityList)
    {
        std::println("");
        std::println("------------------------");
        std::println("");
        std::println("Room {}:", facility.roomNumber);
        std::println("Reserved for: {}", facility.reservationDetails);
        std::println("Start date: {}", facility.reservationDate);
        std::println("End date: {}", facility.reservationEnd);
        std::println("Maintenance: {}", facility.maintenanceStatus);
        std::println("Utilities: ");
        for (const std::string& u : facility.utilities) std::print("{} | ", u);
        std::println("");                                                   //
        std::println("");
        std::println("------------------------");
        std::println("");
    }
}




void FacilityManagement::Menu()
{
    std::println("------------------------");
    std::println(" ");
    std::println("Welcome to the facility management system.");
    std::println("Please make a selection:");
    std::println("[0] - List all Rooms.");
	std::println("[1] - Indivudal Room Listing.");
    std::println("[2] - Utility Management.");
    std::println("[3] - Reservation Managment.");
    std::println("[4] - Required Maintenance.");
	std::println("[5] - Add Room Reservation");
    std::println("[6] - Remove Room");
    std::println("[Back] - return to the main menu.");
}

void FacilityManagement::HandleInput(const std::string Input)
{
    std::string textInput;
    if (Input == "0")
    {
        ShowRooms();
    }
    else if (Input == "1")
    {
        std::println("Enter room number:");
        std::cin >> textInput;
        std::cin.ignore();
        bool found = false;
        for (Facility& facility : facilityList)
        {
            if (std::to_string(facility.roomNumber) == textInput)
            {
                found = true;
                std::println("Room Number: {}", facility.roomNumber);
                std::println("Reserved for: {}", facility.reservationDetails);
                std::println("Start date: {}", facility.reservationDate);
                std::println("End date: {}", facility.reservationEnd);
                std::println("Utilities:");
                for (std::string& u : facility.utilities){
                    std::println("{}", u);
                }
                std::println("Maintenance: {}", facility.maintenanceStatus);
                break;
            }
        }
        if (!found) std::println("ERROR: Room not found!");
    }
    else if (Input == "2")
    {
        std::println("Enter room number:");
        std::cin >> textInput;
        std::cin.ignore();
        bool found = false;
        for (Facility& facility : facilityList)
        {
            if (std::to_string(facility.roomNumber) == textInput)
            {
                found = true;
                while (true)
                {
                    std::println("Current utilities:");
                    for (auto& u : facility.utilities)
                    {
                        std::println("{}", u);
                    }
                    std::println("[1] - Add utilities");
                    std::println("[2] - Remove Utilities");
                    std::println("[3] - Back to Main Menu");
                    std::string inputS;
                    std::cin >> inputS;
                    std::cin.ignore();
                    if (inputS == "1")
                    {
                        std::println("Enter utiliies. Type END to stop.");
                        std::string newUtil;
                        while (true)
                        {
                            std::getline(std::cin, newUtil);
                            if (newUtil == "END") break;
                            if (!newUtil.empty())
                            {
                                facility.utilities.push_back(newUtil);
                                std::println("Added {}", newUtil);
                            }
                        }
                    }
                    else if (inputS == "2")
                    {
                        std::println("Enter utility to remove:");
                        std::string remv;
                        std::getline(std::cin, remv);
                        bool removed = false;
                        for (auto& u : facility.utilities)
                        {
                            if (u == remv)
                            {
                                facility.utilities.remove(u);
                                std::println("Removed {}", remv);
                                removed = true;
                                break;
                            }
                        }
                        if (!removed)
                        {
                            std::println("ERROR: Utility '{}' not found!", remv);
                        }
                    }
                    else if (inputS == "3")
                    {
                        break;
                    }
                    else
                    {
                        std::println("ERROR: Invalid Input!");
                    }
                }
                break;
            }
        }
        if (!found) std::println("ERROR: Room not found!");
    }
    else if (Input == "3")
    {
        std::println("Enter room number:");
        std::cin >> textInput;
        std::cin.ignore();
        bool found = false;
        for (Facility& facility : facilityList)
        {
            if (std::to_string(facility.roomNumber) == textInput)
            {
                found = true;
                std::println("Current reservation: {}", facility.reservationDetails);
                std::string lastName, firstName;
                std::println("Enter resident last name:");
                std::getline(std::cin, lastName);
                std::println("Enter resident first name:");
                std::getline(std::cin, firstName);
                facility.reservationDetails = lastName + ", " + firstName;
                std::println("Enter new reservaition start date:");
                facility.reservationDate = getDate("new start date");
                std::println("Enter new reservation end date:");
                facility.reservationEnd = getDate("new end date");
                break;
            }
        }
        if (!found) std::println("ERROR: Room not found!");
    }
    else if (Input == "4")
    {
        std::println("Enter room number:");
        std::cin >> textInput;
        std::cin.ignore();
        bool found = false;
        for (Facility& facility : facilityList)
        {
            if (std::to_string(facility.roomNumber) == textInput)
            {
                found = true;
                std::println("Current maintenance required: {}", facility.maintenanceStatus);
                std::println("Enter new maintenance status:");
                std::getline(std::cin, facility.maintenanceStatus);
                break;
            }
        }
        if (!found) std::println("ERROR: Room not found!");
    }


    else if (Input == "5")
    {
        std::println("Add Room Reservation Selected");
        Facility newFacility;
        std::println("Enter Room Number:");
        int roomNumberTemp;
        std::string roomNoInput;
        std::cin >> roomNoInput;
        std::cin.ignore();
        while (true)
        {
            bool checkNo = !roomNoInput.empty() && std::all_of(roomNoInput.begin(), roomNoInput.end(), ::isdigit);
            if (!checkNo){
                std::println("Please enter a valid number!");
                std::getline(std::cin, roomNoInput);
                continue;
            }
            roomNumberTemp = std::stoi(roomNoInput);
            bool foundD = false;
            for (Facility& facility : facilityList){
                if (facility.roomNumber == roomNumberTemp){
                    foundD = true;
                    break;
                }
            }
            if (foundD){
                std::println("Room number {} has already been reserved.", roomNumberTemp);
                std::getline(std::cin, roomNoInput);
                continue;
            }
            break;
        }
        newFacility.roomNumber = roomNumberTemp;
        std::println("Enter resident last name:");
        std::string lastName;
        std::getline(std::cin, lastName);
        std::println("Enter resident first name:");
        std::string firstName;
        std::getline(std::cin, firstName);
        newFacility.reservationDetails = lastName + ", " + firstName;
        std::println("Enter reservation start date:");
        newFacility.reservationDate = getDate("reservation start date");
        std::println("Enter reservation end date:");
        newFacility.reservationEnd = getDate("reservation end date");
        std::println("Enter utilities (type END to finish):");
        std::string utilities;
        while (true)
        {
            std::getline(std::cin, utilities);
            if (utilities == "END") break;
            if (!utilities.empty())
                newFacility.utilities.push_back(utilities);
        }
        newFacility.maintenanceStatus = "None"; //set to ddefault for first creation
        facilityList.push_front(newFacility);
        std::println("Room {} added successfully.", newFacility.roomNumber);
        }
    else if (Input == "6")
    {
        std::println("Enter room number to remove:");
        std::cin >> textInput;
        std::cin.ignore();
        bool deleted = false;
        for (auto it = facilityList.begin(); it != facilityList.end(); ++it)
        {
            if (std::to_string(it->roomNumber) == textInput){
                int removedRoom = it->roomNumber;
                facilityList.erase(it);
                deleted = true;
                std::println("Removed room {}", removedRoom);
                break;
            }
        }
        if (!deleted) std::println("ERROR: Room number not found!");
    }
    else if (Input == "Exit")
    {
        std::println("Exiting the Facility Management System.");
        exit(0);
    }
    else
    {
        std::println("ERROR: Invalid Input.");
    }
}
