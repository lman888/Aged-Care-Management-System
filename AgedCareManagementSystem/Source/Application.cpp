#include "Application.h"

//Project Includes
#include "MemberManagement.h"

//External Includes
#include <iostream>
#include "print"


Application::Application()
{
    applicationRunning = true;

    memberManagement = new MemberManagement();
}

Application::~Application()
{
}

void Application::Run()
{
    while(applicationRunning)
    {
        Menu();
        Input();
        system("cls");
    }
}

void Application::Menu()
{
    std::println("Welcome to the Aged Care Management System!");
    std::println("Here are the Selections:");
    std::println("[0] - Member Management");
    std::println("[1] - Staff Management");
    std::println("[2] - Scheduling");
    std::println("[3] - Inventory Management");
    
    if (text == "Exit")
    {
        applicationRunning = false;
    }
}

void Application::Input()
{
    if (text == "0")
    {
        std::println("Selected Member Management!");
        memberManagement->ShowAllMembers();
    }

    if (text == "1")
    {
        std::println("Selected Staff Management!");
    }

    if (text == "2")
    {
        std::println("Scheduling!");
    }

    if (text == "3")
    {
        std::println("Selected Inventory Management!");
    }
    
    if (text != "Exit")
    {
        std::cin >> text;
    }
}