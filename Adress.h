#pragma once

class Adress {
private:
	int m_street;
	char* m_city;

public:

	Adress();
	Adress(const Adress& adress);
	~Adress();
	int getStreet() { return m_street; }
	void setStrret(int street) { m_street = street; }
};