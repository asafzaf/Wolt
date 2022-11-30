#pragma once

class Adress {
private:
	int m_street;
	const char* m_city;

public:

	Adress(const char* city, int street);
	Adress(const Adress& adress);
	Adress& operator=(const Adress& adress);
	~Adress();
	int getStreet() { return m_street; }
	void setStrret(int street) { m_street = street; }
};