#include "MemberManagement.h"

#include <print>
#include <iostream>

MemberManagement::MemberManagement()
{
	Member testMember;
	testMember.memberName = "John Doe";
	testMember.memberAge = 75;
	testMember.memberPhoneNumber = 0423654115;
	testMember.carePlan = "Daily exercise and medication management.";
	testMember.accessibilityRequirements.push_back("Wheelchair access");
	testMember.familyContacts.push_back("Jane Doe - Daughter");
	memberList.push_front(testMember);
}

MemberManagement::~MemberManagement()
{
}

void MemberManagement::ShowAllMembers()
{
	for (Member member : memberList)
	{
		std::println("Member Name: {}", member.memberName);
		std::println("Member Age: {}", std::to_string(member.memberAge));

		std::println("Member Care Plan: {}", member.carePlan);

		for (const std::string& accessibility : member.accessibilityRequirements)
		{
			std::println("Member Accessibility Requirements: {}", accessibility);
		}

		for (const std::string& contact : member.familyContacts)
		{
			std::println("Member Family Contacts: {}", contact);
		}
	}
}

void MemberManagement::FindMember(const std::string MemberName)
{

}

void MemberManagement::AddMember()
{

}