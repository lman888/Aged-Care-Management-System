#pragma once

//Project Includes
#include "MasterManagement.cpp"

class MemberManagement;
class FacilityManagement;
class StaffManagement;
class Schedular;
class Inventory;

class Application : public MasterManagement
{

public:
    Application();
    ~Application();
    
    void Run() override;

private:
    void Menu() override;

    void HandleInput(const std::string Input) override;

    MemberManagement* memberManagement = nullptr;
    FacilityManagement* facilityManagment = nullptr;
    StaffManagement* staffManagement = nullptr;
    Schedular* schedular = nullptr;
    Inventory* inventory = nullptr;
};
