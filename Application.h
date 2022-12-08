#pragma once
#include "Restaurant.h"
#include "Client.h"
#include "Order.h"

//---        Application.h          ---//

class Application {
private:
	Client* m_client;
	Restaurant** m_retaurant;
	Order* m_order;

public:
	Application(Restaurant** restaurant);
	~Application();

	//---      Methods      ---//
	void PlaceOrder();
	void confirm();
	int chooseRestaurant();
	Restaurant* SelectRestaurantByIndex(int Index);

	//--- Getters & setters ---//
	Client* getClient() { return m_client; }
	void setClient(Client* client) { m_client = client; }

	Restaurant** getRestaurant() { return m_retaurant; }
	void setRestaurant(Restaurant** restaurant) { m_retaurant = restaurant; }

	Order* getOrder() { return m_order; }
	void setOrder(Order* order) { m_order = order; }

};