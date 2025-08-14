#include "FacilityManagement.h"

#include <fstream>
#include <iostream>
#include <print>

FacilityManagement::FacilityManagement()
{
    Facility testRoom;
	testRoom.roomNumber = 101;
	testRoom.utilities.push_back("Electricity");
	testRoom.utilities.push_back("Water");
	testRoom.reservationDetails = "Reserved for Doe, John";
	testRoom.reservationDate = "14-8-2025";
	testRoom.reservationEnd = "12-12-2025";
    testRoom.maintenanceStatus = "No maintenance required";
}

FacilityManagement::~FacilityManagement()
{
}

void FacilityManagement::Test()
{
	std::println("passed through test");
}

void FacilityManagement::Run()
{
    while (true)
    {

    }
}

void FacilityManagement::Menu()
{
    std::println("------------------------");
    std::println(" ");
    std::println("Welcome to the facility management system.");
    std::println("Please make a selection:");
    std::println("[0] - Room Managment.");
    std::println("[1] - Utility Management.");
    std::println("[2] - Reservation Managment.");
    std::println("[3] - Required Maintenance.");
    std::println("Type in [Exit] to quit out of the application.");
}

void FacilityManagement::HandleInput(const std::string Input)
{
    if (Input == "0")
    {
        std::println("Room Management Selected!");
        //
    }
    else if (Input == "1")
    {
        std::println("Utility Mangagement Selected");
        //
    }
    else if (Input == "2")
    {
        std::println("Reservation Management Selected");
        //
    }
    else if (Input == "3")
    {
        std::println("Maintenance Selected");
        //
    }
    else
    {
        std::println("ERROR: Invalid Input.");
        //
    }
}