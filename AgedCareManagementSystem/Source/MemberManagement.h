#pragma once

//Project Includes
#include "MasterManagement.cpp"

//External Includes
#include <string>
#include <vector>
#include <list>

struct Member
{
	std::string givenName;
	std::string familyName;
	int age;
	int phoneNumber;
	std::string carePlan;
	std::vector<std::string> accessibilityRequirements;
	std::vector<std::string> familyContacts;
};

class MemberManagement : public MasterManagement
{
public:
	MemberManagement();
	~MemberManagement();

	void Run() override;

protected:

private:
	void HandleInput(const std::string Input) override;
	void Menu() override;
	void ShowAllMembers() const;
	void FindMember();
	void AddMember();
	
	std::list<Member> memberList;
};