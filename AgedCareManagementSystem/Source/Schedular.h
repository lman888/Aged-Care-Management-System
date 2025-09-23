#pragma once

#include "MasterManagement.cpp"

#include <vector>


enum StaffType
{
    Administrative,
    Carer
};

inline std::string StaffTypeToString(StaffType type)
{
    switch (type)
    {
        case Administrative:
            return "Administrative";
        case Carer:
            return "Carer";
        
        default:
            return "Unknown";
    }
}

enum DayOfWeek
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

inline std::string DayToString(DayOfWeek day)
{
    switch (day)
    {
        case Monday:
            return "Monday";
        case Tuesday:
            return "Tuesday";
        case Wednesday:
            return "Wednesday";
        case Thursday:
            return "Thursday";
        case Friday:
            return "Friday";
        case Saturday:
            return "Saturday";
        case Sunday:
            return "Sunday";

        default:
            return "Unknown";
    }
}

struct SchedularEntry
{
    int StartTime = 0;
    int EndTime = 0;
    int Duration = 0;

    DayOfWeek Day;
    std::string StaffName;
    StaffType Type;
};

class Schedular : public MasterManagement
{
public:

    Schedular();
    ~Schedular();
    
    void Run() override;
    void Menu() override;
    void HandleInput(const std::string Input) override;

    void DisplayAllSchedules();
    void DisplayIndividualSchedule();
    void UpdateIndividualSchedule();
    void AddToSchedule();
    void RemoveFromSchedule();

private:

    std::vector<SchedularEntry> Schedules;
};
