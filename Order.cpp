#include <iostream>
#include "Order.h"

Order::Order() { // The constractor
	m_dishes = new Dish * [10];
	for (int i = 0; i < 10; i++) {
		m_dishes[i] = nullptr;
	}
	m_totalSum = 0;

}

Order::~Order() { // Distractor
	int num = 0;
	while (m_dishes[num] != nullptr) {
		delete m_dishes[num];
		num++;
	}

	delete[] m_dishes;
}

void Order::calculateSum(Dish** dish) { // Updating the sum of the order
	m_totalSum = 0;
	Dish** tempPTR = m_dishes;
	int num = 0;
	while (tempPTR != nullptr) {
		m_totalSum += tempPTR[0]->getValue();
	}
}

void Order::printOrder() {

	std::cout << "-----------------" << std::endl
		<< "Order Details:" << std::endl
		<< "-----------------" << std::endl << std::endl
		<< "Your adress: " << m_clientAdress.getCity() << " " << m_clientAdress.getStreet() << std::endl
		<< "Restaurant adress: " << m_restaurantAdress.getCity() << " " << m_restaurantAdress.getStreet() << std::endl
		<< std::endl
		<< "Dishes:" << std::endl;
	
	int num = 0;
	Dish** tempPTR = m_dishes;
	while (tempPTR != nullptr) {
		std::cout << num + 1 << " - "
			<< tempPTR[num]->getName() << " - "
			<< tempPTR[num]->getDishType() << " - "
			<< tempPTR[num]->getValue() << " Nis"
			<< std::endl;
		num++;
	}
	std::cout << std::endl << "Order sum: " << getTotalSum();

	return;
}

void Order::deleteDish() { // Deleting dish from order
	printOrder();
	std::cout << "Choose the number of the dish to delete (0- to finish delete): ";
	int index;
	std::cin >> index;
	if (m_dishes[index] == nullptr) {
		std::cout << "Please choose real dish..." << std::endl;
		return;
	}
	delete m_dishes[index];
	for (int i = 10; i > index; i--) {
		m_dishes[i] = m_dishes[i + 1];
	}
	std::cout << "Deleted!" << std::endl;
}
