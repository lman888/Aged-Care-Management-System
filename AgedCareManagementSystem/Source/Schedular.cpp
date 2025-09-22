#include "Schedular.h"

#include <iostream>
#include <print>
#include <algorithm>

Schedular::Schedular()
{
    SchedularEntry TestEntry;
    TestEntry.Day = DayOfWeek::Friday;
    TestEntry.Type = StaffType::Administrative;
    TestEntry.StartTime = 9;
    TestEntry.EndTime = 18;

    //This needs to be replaced with a Staff name in StaffManagement when Erika implements it
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
    std::println("Please Enter the Staff Members First Name:");
    
    std::cin >> textInput;
    for (SchedularEntry Entry : Schedules)
    {
        if (textInput == Entry.StaffName)
        {
            std::println("---------------------------------------------------------------");
            std::println("Staff Name: {}", Entry.StaffName);
            std::println("Start Time: {}", Entry.StartTime);
            std::println("End Time: {}", Entry.EndTime);
            std::println("Shift Duration: {} Hours", Entry.Duration);
            std::println("Staff Role: {}", StaffTypeToString(Entry.Type));
            std::println("Day: {}", DayToString(Entry.Day));
            std::println("---------------------------------------------------------------");

            return;
        }
    }

    std::println("Staff not found.");
}

void Schedular::UpdateIndividualSchedule()
{
    std::println("Enter Staff Given Name we wish to update: ");
    std::cin >> textInput;

    for (SchedularEntry& Entry : Schedules)
    {
        if (Entry.StaffName == textInput)
        {
            std::println("Please Enter Day Staff is working:");
            std::println("Monday [0]");
            std::println("Tuesday [1]");
            std::println("Wednesday [2]");
            std::println("Thursday [3]");
            std::println("Friday [4]");
            std::println("Saturday [5]");
            std::println("Sunday [6]");
            std::cin >> textInput;
            switch (stoi(textInput))
            {
                case 0:
                    Entry.Day = DayOfWeek::Monday;
                
                case 1:
                    Entry.Day = DayOfWeek::Tuesday;
                
                case 2:
                    Entry.Day = DayOfWeek::Wednesday;
                
                case 3:
                    Entry.Day = DayOfWeek::Thursday;
                
                case 4:
                    Entry.Day = DayOfWeek::Friday;
                case 5:
                    Entry.Day = DayOfWeek::Saturday;
                case 6:
                    Entry.Day = DayOfWeek::Sunday;
                    
                default:
                    Entry.Day = DayOfWeek::Monday;
            }

            std::println("Please enter staff start time:");
            std::cin >> textInput;
            Entry.StartTime = stoi(textInput);

            std::println("Please enter staff end time:");
            std::cin >> textInput;
            Entry.EndTime = stoi(textInput);

            Entry.Duration = Entry.EndTime - Entry.StartTime;
        }
    }
    
}

void Schedular::AddToSchedule()
{
    //This will need to pull from the Staff Management list in future when it is implemented by Erika
    SchedularEntry newEntry;

    std::println("Enter Staff Given Name: ");
    std::cin >> textInput;
    const std::string givenName = textInput;
    newEntry.StaffName = givenName;

    std::println("Please Enter Day Staff is working:");
    std::println("Monday [0]");
    std::println("Tuesday [1]");
    std::println("Wednesday [2]");
    std::println("Thursday [3]");
    std::println("Friday [4]");
    std::println("Saturday [5]");
    std::println("Sunday [6]");
    std::cin >> textInput;
    switch (stoi(textInput))
    {
        case 0:
            newEntry.Day = DayOfWeek::Monday;
            
        case 1:
            newEntry.Day = DayOfWeek::Tuesday;
            
        case 2:
            newEntry.Day = DayOfWeek::Wednesday;
            
        case 3:
            newEntry.Day = DayOfWeek::Thursday;
            
        case 4:
            newEntry.Day = DayOfWeek::Friday;
        case 5:
            newEntry.Day = DayOfWeek::Saturday;
        case 6:
            newEntry.Day = DayOfWeek::Sunday;
            
            
        default:
            newEntry.Day = DayOfWeek::Monday;
    }


    std::println("Please Enter Staff Type:");
    std::println("Administrative [0]");
    std::println("Carer [1]");
    std::cin >> textInput;
    switch (stoi(textInput))
    {
        case 0:
            newEntry.Type = StaffType::Administrative;
        case 1:
            newEntry.Type = StaffType::Carer;
                
        default:
            newEntry.Type = StaffType::Carer;
    }

    std::println("Please enter staff start time:");
    std::cin >> textInput;
    newEntry.StartTime = stoi(textInput);

    std::println("Please enter staff end time:");
    std::cin >> textInput;
    newEntry.EndTime = stoi(textInput);

    newEntry.Duration = newEntry.EndTime - newEntry.StartTime;
    
    Schedules.push_back(newEntry);
}

void Schedular::RemoveFromSchedule()
{
    std::println("Please enter Staff Name:");
    std::cin >> textInput;

    for (auto iterator = Schedules.begin(); iterator != Schedules.end(); ++iterator)
    {
        if (iterator->StaffName == textInput)
        {
            Schedules.erase(iterator);
            return;
        }
    }
}