#pragma once
#include <iostream>
#include "Application.h"

//---            Application.cpp            ---//
//---     Con's, Dis's & lot of methods     ---//

Application::Application(Restaurant** restaurant) { // The Constractor.

	m_order = nullptr;

	char* buff = new char[20];

	std::cout << "Please enter your name: ";
	std::cin >> buff;

	char* name = new char[strlen(buff) + 1];
	strncpy(name, buff, strlen(buff));

	char* phone = new char[sizeof(char)*10 +1];
	while (buff[0] != '0' || buff[1] != '5' || strlen(buff) != 10) {
		std::cout << "Please enter your phone number (without '-'): ";
		std::cin >> buff;
	}
	strcpy(phone, buff);

	std::cout << "Please enter your adress:" << std::endl
		<< "City name: ";
	std::cin >> buff;
	char* cityname = new char[strlen(buff) +1];
	strcpy(cityname, buff);
	
	std::cout << "Please enter street number: ";
	int streetnumber;
	std::cin >> streetnumber;

	m_retaurant = new Restaurant * [5];

	Adress tempAdress = Adress(cityname, streetnumber);

	m_client = new Client(name, phone, tempAdress);
	if (m_client == NULL) {
		std::cout << "Memory Error!" << std::endl;
	}
	if (m_retaurant == NULL) {
		std::cout << "Memory Error!" << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		m_retaurant[i] = restaurant[i];
	}
	std::cout << "hiii";
	delete[] buff;
}

Application::~Application() { // Distractor (end of main).
	delete m_client;
	delete m_retaurant;
	delete m_order;
}

void Application::PlaceOrder() { // Starting order process.
	std::cout << "---------------------" << std::endl
		<< "Place An Order:" << std::endl
		<< "---------------------" << std::endl;
	int numRestaurant = 99;
	while (numRestaurant < 1 || numRestaurant > 5)
	{
		std::cout << "Please choose restaurant:" << std::endl
			<< "---------------------" << std::endl;
		numRestaurant = chooseRestaurant();
	}

	Restaurant* temp_restaurant = SelectRestaurantByIndex(numRestaurant-1);
	Menu temp_menu = temp_restaurant->getMenu();
		
	int numDish = 99;
	temp_menu.printDishes();
	std::cout << "(Type '0' to end choosing)" << std::endl
		<< "Choose dish: ";

	while (numDish != 0) {
		std::cin >> numDish;

		if (numDish < 1 || (numDish > temp_menu.getNumOfDishes())) {
			std::cout << "Please choose a real number!" << std::endl;
		}
		else {
			Dish* chosen_dish = temp_menu.SelectDishByIndex(numDish - 1);
			// add to order function!
			std::cout << "Your dish has been added! Please choose another dish: ";
		}
	}
}

int Application::chooseRestaurant() { // Printing Restaurant list for choosing.
	std::cout << "Restaurant Menu:" << std::endl
		<< "No.	|Name	|" << std::endl;
	int num;
	Restaurant** list = getRestaurant();

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1
			<< "	|" << list[i]->getName()
			<< "	|" << list[i]->getName()
			<< std::endl;
	}
	std::cout << "Select Restaurant: ";
	std::cin >> num;

	return num;
}

Restaurant* Application::SelectRestaurantByIndex(int Index) { // Return pointer of index.

	Restaurant* ptr = m_retaurant[Index];
	return ptr;
}