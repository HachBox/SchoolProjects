   //*****************************************************************
   // FILE:      Provider.h
   // AUTHOR:    Harry Chieng
   // LOGON ID:  z1811457
   // DUE DATE:  9/26/2017
   //
   // PURPOSE:   Declaration for the Provider class, which represents
   //            information about a health care provider.
   //*****************************************************************

#include "Provider.h"

class ProviderDB
{
private:
	Provider providers[40];
	int numProviders = 0;

public:
	ProviderDB();
	ProviderDB(const char*);

	//void setNumber(const char*); //funct prototype
	//void setSpecialty(const char*);
	//void setName(const char*);
	//void setProviderAddress1(const char*);
	//void setProviderAddress2(const char*);
	//void setCity(const char*);
	//void setState(const char*);
	//void setZipCode(const char*);
	
      void print();

	void sortByProviderNumber();
	void sortBySpecialty();
	void sortByName();

};
