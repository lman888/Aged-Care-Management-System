#include "Application.h"

//Project Includes
#include "MemberManagement.h"
#include "FacilityManagement.h"

//External Includes
#include <iostream>
#include "print"


Application::Application()
{
    memberManagement = new MemberManagement();
    facilityManagment = new FacilityManagement();
}

Application::~Application()
{
    memberManagement = nullptr;
    facilityManagment = nullptr;
}

void Application::Run()
{
    while(true)
    {
        Menu();

        std::cin >> textInput;
        system("cls");

        if (textInput == "Exit")
        {
            break;
        }

        HandleInput(textInput);
    }
}

void Application::Menu()
{
    std::println("Welcome to the Aged Care Management System!");
    std::println("Here are the Selections:");
    std::println("[0] - Member Management.");
    std::println("[1] - Staff Management.");
    std::println("[2] - Scheduling.");
    std::println("[3] - Inventory Management.");
    std::println("[4] - Facility Management.");
    std::println("Type in [Exit] to quit out of the application.");
}

void Application::HandleInput(const std::string Input)
{
    if (Input == "0")
    {
        std::println("Selected Member Management!");
        memberManagement->Run();
    }

    if (Input == "1")
    {
        std::println("Selected Staff Management!");
    }

    if (Input == "2")
    {
        std::println("Scheduling!");
    }

    if (Input == "3")
    {
        std::println("Selected Inventory Management!");
    }

    if (Input == "4")
    {
        std::println("Selected Facility Management!");
        facilityManagment->Test();
    }
}