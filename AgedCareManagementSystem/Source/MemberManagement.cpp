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

	Member testMember2;
	testMember2.givenName = "Tim";
	testMember2.familyName = "Doe";
	testMember2.age = 75;
	testMember2.phoneNumber = 0423654115;
	testMember2.carePlan = "Daily exercise and medication management.";
	testMember2.accessibilityRequirements.push_back("Wheelchair access");
	testMember2.familyContacts.push_back("Jane Doe - Daughter");
	memberList.push_front(testMember2);
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
		AddMember();
	}

	if (Input == "3")
	{
		RemoveMember();
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
		std::println("---------------------------------------------------------------");
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
		std::println("---------------------------------------------------------------");
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
	Member newMember;
	
	std::println("Enter Member Given Name: ");
	std::cin >> textInput;
	const std::string givenName = textInput;
	newMember.givenName = givenName;

	std::println("Enter Member Family Name: ");
	std::cin >> textInput;
	const std::string familyName = textInput;
	newMember.familyName = familyName;

	std::println("Enter Member Age: ");
	std::cin >> textInput;
	const int age = std::stoi(textInput);
	newMember.age = age;

	std::println("Enter Member Number: ");
	std::cin >> textInput;
	const int phoneNumber = std::stoi(textInput);
	newMember.phoneNumber = phoneNumber;

	std::println("Enter Member Care Plan: ");
	std::cin >> textInput;
	std::getline(std::cin, textInput);
	const std::string carePlan = textInput;
	newMember.carePlan = carePlan;

	std::println("Member Accessibility Requirements");
	std::println("Enter Number of Member Accessibility:");
	std::cin >> textInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	const int requirementAmount = std::stoi(textInput);
	for (int i = 0; i < requirementAmount; i++)
	{
		std::string format = std::format("Enter Accessibility {}:", i);
		std::println("{}", format);
		std::getline(std::cin, textInput);
		
		const std::string accessibility = textInput;
		newMember.accessibilityRequirements.push_back(accessibility);
	}
	
	std::println("Member Family Details");
	std::println("Enter Number of Member Family Members:");
	std::cin >> textInput;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	const int familyMemberAmount = std::stoi(textInput);
	for (int i = 0; i < familyMemberAmount; i++)
	{
		std::string format = std::format("Enter Family Member {}:", i);
		std::println("{}", format);
		std::getline(std::cin, textInput);
		
		const std::string familyContacts = textInput;
		newMember.familyContacts.push_back(familyContacts);
	}
	
	memberList.push_front(newMember);
}

void MemberManagement::RemoveMember()
{
	std::println("Please Enter the First Name of the Member you wish to Remove from the database.");
	std::cin >> textInput;

	for (auto it = memberList.begin(); it != memberList.end(); )
	{
		if (it->givenName == textInput)
		{
			it = memberList.erase(it);
			return;
		}
		else
		{
			++it;
		}
	}
	std::string format = std::format("{} was not a valid name in the database!", textInput);
	std::println("{}", format);
}