#pragma once

//---        Adress.h          ---//

class Adress {
private:
	int m_street;
	char* m_city;

public:
	Adress();
	Adress(const char* city, int street);
	Adress(const Adress& adress);
	Adress& operator=(const Adress& adress);
	~Adress();

	//--- Getters & setters ---//
	int getStreet() { return m_street; }
	void setStrret(int street) { m_street = street; }

	char* getCity() { return m_city; }
	void setCity(char* city) { m_city = city; }
};