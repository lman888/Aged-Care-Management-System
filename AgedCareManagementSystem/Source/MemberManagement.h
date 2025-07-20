#pragma once

//External Includes
#include <string>
#include <vector>
#include <list>

struct Member
{
	std::string memberName;
	int memberAge;
	int memberPhoneNumber;
	std::string carePlan;
	std::vector<std::string> accessibilityRequirements;
	std::vector<std::string> familyContacts;
};

class MemberManagement
{
public:
	MemberManagement();
	~MemberManagement();

	void ShowAllMembers();
	void FindMember(const std::string MemberName);
	void AddMember();

protected:

private:
	
	std::list<Member> memberList;
};