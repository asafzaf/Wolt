#pragma once
#include <iostream>
#include "Application.h"

Application::Application(Restaurant** restaurant) {

	m_order = nullptr;

	char* buff = new char[20];

	std::cout << "Please enter your name: ";
	std::cin >> buff;

	char* name = new char[strlen(buff) + 1];
	strcpy(name, buff);

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

	Adress tempAdress = Adress(cityname, streetnumber);

	m_client = new Client(name, phone, tempAdress);
	if (m_client == NULL) {
		std::cout << "Memory Error!" << std::endl;
	}
	m_retaurant = new Restaurant*[5];
	if (m_retaurant == NULL) {
		std::cout << "Memory Error!" << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		Restaurant* ptr_src = restaurant[i];
		Restaurant* ptr_des = m_retaurant[i];
		char* buff = new char[20];
		buff = ptr_src->getName();
		
		ptr_des->setName(buff);
		ptr_des->setAdress(ptr_src->getAdress());
		ptr_des->setMenu(ptr_src->getMenu());
		std::cout << "hiii";
	}
	std::cout << "hiii";
	delete[] buff;
}

Application::~Application() {
	delete m_client;
	delete m_retaurant;
	delete m_order;
}


void Application::PlaceOrder() {

}