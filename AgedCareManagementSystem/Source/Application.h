#pragma once

//External Includes
#include <string_view>

class MemberManagement;

class Application
{
public:
    Application();
    ~Application();
    
    void Run();

private:
    void Menu();

    void Input();

    std::string text;
    
    bool applicationRunning = true;

    MemberManagement* memberManagement = nullptr;
};
