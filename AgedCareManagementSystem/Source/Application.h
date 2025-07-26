#pragma once

//Project Includes
#include "MasterManagement.cpp"

//External Includes
#include <string_view>

class MemberManagement;
class FacilityManagement;


class Application : public MasterManagement
{

public:
    Application();
    ~Application();
    
    void Run() override;

private:
    void Menu() override;

    void HandleInput(const std::string Input) override;

    std::string inputText;

    MemberManagement* memberManagement = nullptr;
    FacilityManagement* facilityManagment = nullptr;
};
