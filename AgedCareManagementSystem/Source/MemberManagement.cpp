#include "MemberManagement.h"

//External Includes
#include <print>
#include <format>
#include <iostream>

MemberManagement::MemberManagement()
{
	Member testMember;
	testMember.givenName = "John";
	testMember.familyName = "Doe";
	testMember.age = 75;
	testMember.phoneNumber = 0423654115;
	testMember.carePlan = "Daily exercise and medication management.";
	testMember.accessibilityRequirements.push_back("Wheelchair access");
	testMember.familyContacts.push_back("Jane Doe - Daughter");
	memberList.push_front(testMember);
}

MemberManagement::~MemberManagement()
{
}

void MemberManagement::Run()
{
	while (true)
	{
		Menu();
		std::cin >> textInput;
		system("cls");

		if (textInput == "Back")
		{
			break;
		}

		HandleInput(textInput);
	}
}

void MemberManagement::HandleInput(const std::string Input)
{
	if (Input == "0")
	{
		ShowAllMembers();
	}

	if (Input == "1")
	{
		FindMember();
	}

	if (Input == "2")
	{
	}

	if (Input == "3")
	{
	}

	if (Input == "4")
	{
	}
}

void MemberManagement::Menu()
{
	std::println("Welcome to the Member Management!");
	std::println("Here are the options:");
	std::println("[0] - Show All Members");
	std::println("[1] - Search for Member");
	std::println("[2] - Add a Member");
	std::println("[3] - Remove a Member");
	std::println("Type in [Back] to navigate to the Aged CareMain Menu");
}

void MemberManagement::ShowAllMembers() const
{
	for (Member member : memberList)
	{
		std::println("Member Name: {}", member.givenName);
		std::println("Member Name: {}", member.familyName);
		std::println("Member Age: {}", std::to_string(member.age));
		std::println("Member Contact Number: {}", std::to_string(member.phoneNumber));

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

void MemberManagement::FindMember()
{
	std::println("Please enter in Member First Name!");
	std::cin >> textInput;

	const std::string name = textInput;

	for (Member member : memberList)
	{
		if (name == member.givenName)
		{
			std::string format = std::format("Found: {}", member.givenName);
			std::println("{}", format);
			return;
		}
	}

	std::println("Did not find any Member with the Name: {}", name);
}

void MemberManagement::AddMember()
{

}