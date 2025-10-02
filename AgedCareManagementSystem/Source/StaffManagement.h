#pragma once

// External Includes
#include <string>
#include <vector>
#include <list>

struct Staff
{
    std::string givenName;
    std::string familyName;
    std::string phoneNumber;
    std::string role;                 // e.g., Caretaker, Nurse, Cleaner, PCA
    std::string shiftNotes;           // e.g., "AM shift; Wing A"
    std::vector<std::string> certifications; // e.g., "First Aid", "Manual Handling"
};

class StaffManagement
{
public:
    StaffManagement();
    ~StaffManagement();

    void Run();

protected:

private:
    void HandleInput(const std::string Input);
    void Menu();
    void ShowAllStaff() const;
    void UpdateStaffInformation();
    void FindStaff();
    void AddStaff();
    void RemoveStaff();

    std::list<Staff> staffList;
    std::string textInput;
};

