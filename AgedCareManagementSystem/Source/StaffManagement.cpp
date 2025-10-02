#include "StaffManagement.h"

// External Includes (C++23)
#include <print>
#include <format>
#include <iostream>
#include <limits>

StaffManagement::StaffManagement()
{
    // Seed with a couple of sample staff to demonstrate functionality
    Staff s1;
    s1.givenName = "Alice";
    s1.familyName = "Nguyen";
    s1.phoneNumber = "0412345678";
    s1.role = "Registered Nurse";
    s1.shiftNotes = "AM shift; Wing A";
    s1.certifications.push_back("AHPRA Registered");
    s1.certifications.push_back("First Aid");
    staffList.push_front(s1);

    Staff s2;
    s2.givenName = "Mark";
    s2.familyName = "Singh";
    s2.phoneNumber = "0498765432";
    s2.role = "PCA";
    s2.shiftNotes = "PM shift; Wing C";
    s2.certifications.push_back("Manual Handling");
    staffList.push_front(s2);
}

StaffManagement::~StaffManagement() {}

void StaffManagement::Run()
{
    while (true)
    {
        Menu();
        std::cin >> textInput;
        system("cls");

        if (textInput == "Back")
            break;

        HandleInput(textInput);
    }
}

void StaffManagement::HandleInput(const std::string input)
{
    if (input == "0") ShowAllStaff();
    if (input == "1") FindStaff();
    if (input == "2") AddStaff();
    if (input == "3") RemoveStaff();
    if (input == "4") UpdateStaffInformation();
}

void StaffManagement::Menu()
{
    std::println("Welcome to Staff Management!");
    std::println("Options:");
    std::println("[0] - Show All Staff");
    std::println("[1] - Search for Staff");
    std::println("[2] - Add Staff");
    std::println("[3] - Remove Staff");
    std::println("[4] - Update Staff Information");
    std::println("Type [Back] to return to the main menu");
}

void StaffManagement::ShowAllStaff() const
{
    for (const Staff& s : staffList)
    {
        std::println("---------------------------------------------------------------");
        std::println("Given Name: {}", s.givenName);
        std::println("Family Name: {}", s.familyName);
        std::println("Phone: {}", s.phoneNumber);
        std::println("Role: {}", s.role);
        std::println("Shift Notes: {}", s.shiftNotes);

        for (const std::string& cert : s.certifications)
            std::println("Certification: {}", cert);

        std::println("---------------------------------------------------------------");
    }
}

void StaffManagement::FindStaff()
{
    std::println("Enter Staff Given Name:");
    std::cin >> textInput;
    const std::string name = textInput;

    for (Staff& s : staffList)
    {
        if (s.givenName == name)
        {
            std::println("---------------------------------------------------------------");
            std::println("Given Name: {}", s.givenName);
            std::println("Family Name: {}", s.familyName);
            std::println("Phone: {}", s.phoneNumber);
            std::println("Role: {}", s.role);
            std::println("Shift Notes: {}", s.shiftNotes);

            for (const std::string& cert : s.certifications)
                std::println("Certification: {}", cert);

            std::println("---------------------------------------------------------------");
            return;
        }
    }

    std::println("No staff found with Given Name: {}", name);
}

void StaffManagement::AddStaff()
{
    Staff ns;

    std::println("Enter Given Name:");
    std::cin >> ns.givenName;

    std::println("Enter Family Name:");
    std::cin >> ns.familyName;

    std::println("Enter Phone Number:");
    std::cin >> ns.phoneNumber;

    std::println("Enter Role:");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, ns.role);

    std::println("Enter Shift Notes:");
    std::getline(std::cin, ns.shiftNotes);

    std::println("Number of Certifications:");
    std::cin >> textInput;
    const int count = std::stoi(textInput);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < count; ++i)
    {
        std::println("Enter Certification {}:", i + 1);
        std::string cert;
        std::getline(std::cin, cert);
        ns.certifications.push_back(cert);
    }

    staffList.push_front(ns);
    std::println("Staff added: {} {}", ns.givenName, ns.familyName);
}

void StaffManagement::RemoveStaff()
{
    std::println("Enter the Given Name of the Staff to remove:");
    std::cin >> textInput;

    for (auto it = staffList.begin(); it != staffList.end(); )
    {
        if (it->givenName == textInput)
        {
            std::println("Removed: {} {}", it->givenName, it->familyName);
            it = staffList.erase(it);
            return;
        }
        else ++it;
    }

    std::println("{} not found in staff list.", textInput);
}

void StaffManagement::UpdateStaffInformation()
{
    std::println("Enter Staff Given Name to update:");
    std::cin >> textInput;
    const std::string name = textInput;

    for (Staff& s : staffList)
    {
        if (s.givenName == name)
        {
            while (true)
            {
                std::println("Update Options:");
                std::println("Role [1]");
                std::println("Shift Notes [2]");
                std::println("Add Certification [3]");
                std::println("Phone Number [4]");
                std::println("Type [Back] to exit");
                std::cin >> textInput;

                if (textInput == "1")
                {
                    std::println("Enter new Role:");
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, s.role);
                }
                else if (textInput == "2")
                {
                    std::println("Enter new Shift Notes:");
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::getline(std::cin, s.shiftNotes);
                }
                else if (textInput == "3")
                {
                    std::println("Enter additional Certification:");
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string cert;
                    std::getline(std::cin, cert);
                    s.certifications.push_back(cert);
                }
                else if (textInput == "4")
                {
                    std::println("Enter new Phone Number:");
                    std::cin >> s.phoneNumber;
                }
                else if (textInput == "Back")
                {
                    break;
                }
            }
            return;
        }
    }

    std::println("No staff found with Given Name: {}", name);
}
