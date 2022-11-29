#include "Application.h"

int main() {
	Restaurant** Restaurant_List = RestaurantList();
	Application app(Restaurant_List);



	return 0;
}


Restaurant** RestaurantList() {
	Dish** dishset1 = new Dish*[5];
	Dish** dishset2 = new Dish*[5];
	Dish** dishset3 = new Dish*[5];
	Dish** dishset4 = new Dish*[5];
	Dish** dishset5 = new Dish*[5];

	dishset1[0] = ("Hot Wings", Appetizer, 15);



	Adress add1("Tel Aviv", 11);
	//Adress add2("Ramat Gan", 7);
	//Adress add3("Beer Sheva", 23);
	//Adress add4("Tel aviv", 29);
	//Adress add5("lisbon", 55);

	Restaurant* list = new Restaurant[5];
	list[1] = Restaurant("KFC", add1, )

	return list;
}