#include "Schedular.h"

#include <iostream>
#include <print>

Schedular::Schedular()
{
    SchedularEntry TestEntry;
    TestEntry.Day = DayOfWeek::Friday;
    TestEntry.Type = StaffType::Administrative;
    TestEntry.StartTime = 9;
    TestEntry.EndTime = 18;

    //This needs to be replaced with a Staff name in StaffManagement when Xander implements it
    TestEntry.StaffName = "Bob"; 
    TestEntry.Duration = TestEntry.EndTime - TestEntry.StartTime;

    Schedules.push_back(TestEntry);
}

Schedular::~Schedular()
{
}

void Schedular::Run()
{
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

void Schedular::Menu()
{
    std::println("Welcome to the Member Management!");
    std::println("Here are the options:");
    std::println("[0] - Display All Staff Schedules");
    std::println("[1] - Search for and Display a Single Staff Schedule");
    std::println("[2] - Add a Staff to the Schedule");
    std::println("[3] - Remove a Staff from the Schedule");
    std::println("[4] - Update Scheduler for a Staff Member");
    std::println("Type in [Back] to navigate to the Aged CareMain Menu");
}

void Schedular::HandleInput(const std::string Input)
{
    if (Input == "0")
    {
        DisplayAllSchedules();
    }

    if (Input == "1")
    {
        DisplayIndividualSchedule();
    }

    if (Input == "2")
    {
        AddToSchedule();
    }

    if (Input == "3")
    {
        RemoveFromSchedule();
    }

    if (Input == "4")
    {
        UpdateIndividualSchedule();
    }
}

void Schedular::DisplayAllSchedules()
{
    for (SchedularEntry Entry : Schedules)
    {
        std::println("---------------------------------------------------------------");
        std::println("Staff Name: {}", Entry.StaffName);
        std::println("Start Time: {}", Entry.StartTime);
        std::println("End Time: {}", Entry.EndTime);
        std::println("Shift Duration: {} Hours", Entry.Duration);
        std::println("Staff Role: {}", StaffTypeToString(Entry.Type));
        std::println("Day: {}", DayToString(Entry.Day));
        std::println("---------------------------------------------------------------");
    }
}

void Schedular::DisplayIndividualSchedule()
{
}

void Schedular::UpdateIndividualSchedule()
{
}

void Schedular::AddToSchedule()
{
}

void Schedular::RemoveFromSchedule()
{
}
