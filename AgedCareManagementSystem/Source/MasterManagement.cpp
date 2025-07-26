#pragma once

#include <string>

//This is an Abstract class that will hold functionality our base classes will implement due to them sharing a Menu, Input and so on
class MasterManagement
{
public:

	virtual ~MasterManagement() {};
	virtual void Run() = 0;
	virtual void Menu() = 0;
	virtual void HandleInput(const std::string Input) = 0;

	std::string textInput;
};