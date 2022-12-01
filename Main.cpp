#include <iostream>
#include "Application.h"

Restaurant** RestaurantList();

using namespace std;

int main() {
	Restaurant** Restaurant_List = RestaurantList();
	Application app(Restaurant_List);

	int choice = 99;

	while (choice != 0) {
		
		cout << "Hello " << app.getClient()->getName() << endl
			<< "-------------------------" << endl
			<< "       -Wolt Menu-" << endl
			<< "-------------------------" << endl
			<< "1- Place an order" << endl
			<< "2- View recent orders" << endl
			<< "3- View your details" << endl
			<< "Please choose an option: ";

		cin >> choice;
		
		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;

		default:
			cout << " ";
			break;
		}
	}

	return 0;
};


Restaurant** RestaurantList() {
	Dish** dishset1 = new Dish*[4];
	Dish** dishset2 = new Dish*[5];
	Dish** dishset3 = new Dish*[5];
	Dish** dishset4 = new Dish*[5];
	Dish** dishset5 = new Dish*[5];

	dishset1[0] = new Dish("Hot Wings", Appetizer, 15);
	dishset1[1] = new Dish("Half Chicken", MainCourse, 30);
	dishset1[2] = new Dish("Nuggets", MainCourse, 20);
	dishset1[3] = new Dish("American Ice-Cream", Dessert, 10);

	dishset2[0] = new Dish("Carrot Salad", Appetizer, 15);
	dishset2[1] = new Dish("Onion Soup", Appetizer, 15);
	dishset2[2] = new Dish("Vegan Burger", MainCourse, 30);
	dishset2[3] = new Dish("HotVegDog", MainCourse, 25);
	dishset2[4] = new Dish("NOT cheese cake", Dessert, 20);

	dishset3[0] = new Dish("Pottato Chips", Appetizer, 15);
	dishset3[1] = new Dish("Meat Balls", MainCourse, 20);
	dishset3[2] = new Dish("Schnizel", MainCourse, 30);
	dishset3[3] = new Dish("Coco Cake", Dessert, 15);
	dishset3[4] = new Dish("Lemon Pai", Dessert, 20);

	dishset4[0] = new Dish("Bamba candy", Appetizer, 15);
	dishset4[1] = new Dish("Cookies", Appetizer, 15);
	dishset4[2] = new Dish("Vanilla Cake", Dessert, 15);
	dishset4[3] = new Dish("Sufgania", Dessert, 20);
	dishset4[4] = new Dish("Marshmello Coffe", Dessert, 20);

	dishset5[0] = new Dish("Chicken Bun", Appetizer, 20);
	dishset5[1] = new Dish("Fad Thai", MainCourse, 35);
	dishset5[2] = new Dish("Fad Siu", MainCourse, 35);
	dishset5[3] = new Dish("Misu Soup", Dessert, 20);

	Adress* add1 = new Adress("Tel Aviv", 11);
	Adress* add2 = new Adress("Ramat Gan", 7);
	Adress* add3 = new Adress("Tel Aviv", 23);
	Adress* add4 = new Adress("Tel aviv", 29);
	Adress* add5 = new Adress("Yahud", 55);

	Restaurant** list = new Restaurant*[5];
	list[0] = new Restaurant("KFC", add1, dishset1);
	list[1] = new Restaurant("OnlyVegan", add2, dishset2);
	list[2] = new Restaurant("Asaf's Coffe", add3, dishset3);
	list[3] = new Restaurant("Show Room", add4, dishset4);
	list[4] = new Restaurant("The Thai House", add5, dishset5);

	return list;
}