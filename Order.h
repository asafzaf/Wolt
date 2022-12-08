#pragma once
#include "Dish.h"
#include "Adress.h"

//---        Order.h          ---//

class Order {
private:
	char* m_restaurantName;
	Adress m_clientAdress;
	Adress m_restaurantAdress;
	Dish** m_dishes;
	int m_totalSum;

public:
	Order();
	~Order();

	//---      Methods      ---//
	void calculateSum(Dish** dish);
	void printOrder();
	void deleteDish();

	//--- Getters & setters ---//

	char* getRestaurantName() { return m_restaurantName; }
	void setRestaurantName(char* restaurantName) { m_restaurantName = restaurantName; }

	Adress getClientAdress() { return m_clientAdress; }
	void setclientAdress(Adress clientAdress) { m_clientAdress = clientAdress; }

	Adress getRestaurantAdress() { return m_restaurantAdress; }
	void setRestaurantAdress(Adress RestaurantAdress) { m_restaurantAdress = RestaurantAdress; }

	Dish** getDishes() { return m_dishes; }
	void setDishes(Dish** dish) { m_dishes = dish; }

	int getTotalSum() { return m_totalSum; }
	void setTotalSum(int totalSum) { m_totalSum = totalSum; }
};