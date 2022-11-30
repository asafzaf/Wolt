#include "Adress.h"
#include<iostream>

using namespace std;

Adress::Adress(){

Adress *st;

    while (int i=1){

        cout << " write your city name --->   " ;
        cin >> st->m_city ;
        // compare between st.city and our cities


        //if user's city isn't ok-
        cout << "We only deliver to Tel Aviv, Ramat Gan and Yehud" << endl
            << "please select a city from those" ;
        // back to while loop

        //while user's city is ok-

        cout << "Now, please write your street number --->   " ;
        cin >> st->m_street ;
        if (st->m_street < 0)
        {
            cout << endl << "There is a problem with your street number. please write a positive number." ;
            // go back to while
        }
        
        else{
            cout << "We got your details successfully!" ;
            i= 2; //end of loop
        }

        Adress(const st);

    }
}


// copy c'tor
Adress::Adress(const Adress& adress); {

    m_city = new char [adress->m_city];
    if (m_city == NULL)
    {
        delete[] m_city;
    }

    m_city = adress->m_city;
    m_street = adress->m_street;

}

Adress::~Adress(){
    delete[] m_city;
}
