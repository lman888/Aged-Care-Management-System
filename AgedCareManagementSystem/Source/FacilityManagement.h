//External Includes
#include <string_view>
#include <string>
#include <vector>
#include <list>


struct Facility
{
	int roomNumber;
	std::list<std::string> utilities;
	std::string reservationDetails;
	std::string reservationDate;
	std::string reservationEnd;
	std::string maintenanceStatus;
};


#pragma once
class FacilityManagement
{
public:
	FacilityManagement();
	~FacilityManagement();

	void Test();
	void Run();

private:

	void Menu();

	void ShowRooms();

	void HandleInput(const std::string Input);

	std::list<Facility> facilityList;

	std::string getDate(const std::string& label);




};

