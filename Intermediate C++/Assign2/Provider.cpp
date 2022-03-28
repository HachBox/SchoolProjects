#include <cstring>
#include <iostream>
#include <vector>

#include "Provider.h"

using namespace std;

Provider::Provider(){}

Provider::Provider(const char* newNumber, const char* newSpecialty, const char* newName, const char* newProviderAddress1, const char* newProviderAddress2, const char* newCity, const char* newState, const char* newZipCode,
       const char* newPhoneNumber){

strcpy(Number, newNumber);

strcpy(Specialty, newSpecialty);

strcpy(Name, newName);

strcpy(ProviderAddress1, newProviderAddress1);

strcpy(ProviderAddress2, newProviderAddress2);

strcpy(City, newCity);

strcpy(State, newState);

strcpy(ZipCode, newZipCode);

strcpy(PhoneNumber, newPhoneNumber);
}

void Provider::print() const
	{
        cout << "#" << Number << endl
         << Name << endl
         << Specialty << endl
         << ProviderAddress1 << endl
         << ProviderAddress2 << endl
         << City << ", " << State << " " << ZipCode << endl
         << PhoneNumber << endl
         << endl;
	}

const char* Provider::getProviderNumber() const
   {
   return Number;
   }

const char* Provider::getSpecialty() const
   {
   return Specialty;
   }

const char* Provider::getName() const
   {
   return Name;
   }
