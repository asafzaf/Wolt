// This project made by:
// Asaf Zafrir (205929029)
// Moran Benjamin (212139869)

#pragma once
#include "Adress.h"

//---        Client.h          ---//

class Client {
private:
	char* m_name;
	char* m_phone_num;
	int m_credits;
	Adress m_address;

public:
	Client(char* name, char* phone_num, Adress adress);
	~Client();
	
	//--- Getters & setters ---//
	char* getName() { return m_name; }
	void setName(char* name) { m_name = name; }

	char* getPhoneNum() { return m_phone_num; }
	void setPhoneNum(char* phone_num) { m_phone_num = phone_num; }

	int getCredits() { return m_credits; }
	void setCredits(int credits) { m_credits = credits; }

	Adress getAdress() { return m_address; }
	void setAdress(Adress adress) { m_address = adress; }
};