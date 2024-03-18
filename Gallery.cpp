#include <iostream>
#include <string>
#include "MemoryAccess.h"
#include "DatabaseAccess.h"
#include "AlbumManager.h"
#include <chrono>

#define WELCOME "Welcome to Gallery\nversion 1.0.3 by "
#define YOUR_NAME "Orel Tzur!"

void printSystemInfo()
{
	auto end = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);


	std::cout << WELCOME << YOUR_NAME << std::endl << "Date: " << std::ctime(&end_time);

}

int getCommandNumberFromUser()
{
	
	std::string message("\nPlease enter any command(use number): ");
	std::string numericStr("0123456789");
	

	std::cout << message << std::endl;
	std::string input;
	std::getline(std::cin, input);
	
	while (std::cin.fail() || std::cin.eof() || input.find_first_not_of(numericStr) != std::string::npos) {

		std::cout << "Please enter a number only!" << std::endl;

		if (input.find_first_not_of(numericStr) == std::string::npos) {
			std::cin.clear();
		}

		std::cout << std::endl << message << std::endl;
		std::getline(std::cin, input);
	}
	
	return std::atoi(input.c_str());
}

int main(void)
{
	// initialization data access
	DatabaseAccess dataAccess;
	//MemoryAccess dataAccess;

	// initialize album manager
	AlbumManager albumManager(dataAccess);


	std::string albumName;

	printSystemInfo();
	//std::cout << "Welcome to Gallery!" << std::endl;
	std::cout << "===================" << std::endl;
	std::cout << "Type " << HELP << " to a list of all supported commands" << std::endl;
	
	do {
		int commandNumber = getCommandNumberFromUser();
		
		try	{
			albumManager.executeCommand(static_cast<CommandType>(commandNumber));
		} catch (std::exception& e) {	
			std::cout << e.what() << std::endl;
		}
	} 
	while (true);
}


