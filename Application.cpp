#pragma once
#include <iostream>
#include "Application.h"

//---            Application.cpp            ---//
//---     Con's, Dis's & lot of methods     ---//

Application::Application(Restaurant** restaurant) { // The Constractor.

	m_order = nullptr;

	char* name = new char[20];

	std::cout << "Please enter your name: ";
	std::cin >> name;

	char* phone = new char[sizeof(char)*10 +1];
	while (phone[0] != '0' || phone[1] != '5' || strlen(phone) != 10) {
		std::cout << "Please enter your phone number (without '-'): ";
		std::cin >> phone;
	}

	char* buff = new char[20];

	std::cout << "Please enter your adress:" << std::endl
		<< "City name: ";
	std::cin >> buff;
	char* cityname = new char[strlen(buff) +1];
	strncpy(cityname, buff, strlen(buff));
	
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

	m_order = new Order();

	while (strcmp(temp_restaurant->getAdress()->getCity(), m_client->getAdress().getCity()) != 0)
	{
		std::cout << "The restaurant city doesn't match with your city... Please choose other restaurant" << std::endl;
		std::cin >> numRestaurant;
		while (numRestaurant < 1 || numRestaurant > 5)
		{
			std::cout << "Please choose restaurant: ";
		}
	}

	Menu temp_menu = temp_restaurant->getMenu();
		
	m_order->setRestaurantName(temp_restaurant->getName());
	m_order->setclientAdress(m_client->getAdress());
	m_order->setRestaurantAdress(m_client->getAdress());

	Dish** temp_dish = new Dish * [10];
	for (int i = 0; i < 10; i++) {
		temp_dish[i] = nullptr;
	}

	int numOfDish = 0;
	int DishSelection = 99;
	temp_menu.printDishes();
	std::cout << "(Type '0' to end choosing)" << std::endl
		<< "Choose dish: ";

	while (DishSelection != 0) {
		std::cin >> DishSelection;

		if (DishSelection < 1 || (DishSelection > temp_menu.getNumOfDishes())) {
			std::cout << "Please choose a real number!" << std::endl;
		}
		else {
			//Dish* chosen_dish = temp_menu.SelectDishByIndex(DishSelection - 1);
			temp_dish[numOfDish] = temp_menu.SelectDishByIndex(DishSelection - 1);
			std::cout << "Your dish has been added! Please choose another dish: ";
			numOfDish++;
		}
	}

	m_order->setDishes(temp_dish);
	std::cout << "Do you want to see order details?" << std::endl
		<< "1- Yes." << std::endl
		<< "2- Return to main." << std::endl
		<< "> ";
	m_order->calculateSum(temp_dish);
	int choice = 0;
	std::cin >> choice;

	while (choice < 1 || choice > 2) {
		std::cout << "Please choose real choice";
		std::cin >> choice;
	}
	if (choice == 1) {
		m_order->printOrder();
		confirm();
	}

	if (choice == 2) {
		return;
	}
}

void Application::confirm() {
	if (m_order == nullptr) {
		std::cout << "There is no order..." << std::endl;
		return;
	}
	m_order->printOrder();
	std::cout << "Confirm order?" << std::endl
		<< "1- Yes." << std::endl
		<< "2- No." << std::endl;
	int confirm = 0;
	std::cin >> confirm;
	while (confirm < 1 || confirm > 2) {
		std::cout << "Please try again... " << std::endl
			<< "> ";
		std::cin >> confirm;
	}
	if (m_client->getCredits() < m_order->getTotalSum()) {
		std::cout << "You don't have enouth credits to complete the order!" << std::endl
			<< "Choose one of these options:" << std::endl
			<< "1- Add credits." << std::endl
			<< "2- Delete dishes." << std::endl
			<< "> ";
		int creditschoice;
		std::cin >> creditschoice;
		while (creditschoice != 2244) {
			switch (creditschoice)
			{
			case 1:
				m_client->setCredits(500);
				creditschoice = 2244;
				break;
			case 2:
				m_order->deleteDish();
				break;
			default:
				std::cout << "Please try again: ";
				std::cin >> creditschoice;
				break;
			}
		}
	}
	return;
}

int Application::chooseRestaurant() { // Printing Restaurant list for choosing.
	std::cout << "Restaurant Menu:" << std::endl
		<< "No.	|Name	|" << std::endl;
	int num;
	Restaurant** list = getRestaurant();

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1
			<< "	|" << list[i]->getName()
			<< "	|" << list[i]->getAdress()->getCity()
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