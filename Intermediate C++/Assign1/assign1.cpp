/*
Programmer: Harry Chieng
you need to read a file of records into an array of objects, 
then loop through the array and print the objects.
*/

#include <iostream>
#include <iomanip>	
#include <fstream>
#include <cstring>	
#include <string> 

using namespace std;

class Provider
{	
	private: 
		char Number[7]{}; //C strings
		char Specialty[41]{};
		char Name[41]{};
		char ProviderAddress1[41]{};
		char ProviderAddress2[41]{};
		char City[21]{};
		char State[3]{};
		char ZipCode[6]{};
		char PhoneNumber[15]{};
		
	public:
		Provider(){}
		void setNumber(const char*); //funct prototype
		void setSpecialty(const char*);
		void setName(const char*);
		void setProviderAddress1(const char*);
		void setProviderAddress2(const char*);
		void setCity(const char*);
		void setState(const char*);
		void setZipCode(const char*);
		void setPhoneNumber(const char*);
		
		void print();
};

int getData(Provider providers[40]);
void printErrThang(Provider providers[40],int numProviders);

int main()
{
	Provider providers[40]; //create and object for the data (type (object)) <-- makes it plural
	int numProviders=getData(providers);
	//print data
	printErrThang(providers, numProviders);
	
	return 0;
}

int getData(Provider providers[40]) //receives parameter
{
	ifstream inFile; 	//C++ strings
	string number;
	string specialty;
	string firstName, lastName, middleName, title;
	string providerAddress1;
	string providerAddress2;
	string city;
	string state;
	string zipCode;
	string phoneNumber;
	
	inFile.open("providers.csv"); 
	if (!inFile)
    {
     	cerr << "Error - unable to open input file\n";	//checks error
      	exit(1);
    }
	int i;
	i = 0;
	while(inFile)
	{
		//get data
		getline(inFile, number, ',');
	    getline(inFile, specialty, ',');
	    getline(inFile, lastName, ',');
	    getline(inFile, firstName, ',');
	    getline(inFile, middleName, ',');
	    getline(inFile, title, ',');
	    getline(inFile, providerAddress1, ',');
	    getline(inFile, providerAddress2, ',');
	    getline(inFile, city, ',');
	    getline(inFile, state, ',');
	    getline(inFile, zipCode, ',');
	    getline(inFile,phoneNumber,'\n');
		
		//put data in the object
		providers[i].setNumber(number.c_str()); //providerss obj, element number i, 
		providers[i].setSpecialty(specialty.c_str());
		if(middleName!="") //does not equal nothing
			//SCIANNA, JOSEPH M., MD
			providers[i].setName((lastName+", "+firstName+" "+middleName+", "+title).c_str());
		else
			providers[i].setName((lastName+", "+firstName+", "+title).c_str());		
		providers[i].setProviderAddress1(providerAddress1.c_str());
		providers[i].setProviderAddress2(providerAddress2.c_str());
		providers[i].setCity(city.c_str());
		providers[i].setState(state.c_str());
		providers[i].setZipCode(zipCode.c_str());
		providers[i].setPhoneNumber(phoneNumber.c_str());
		
		i++; //increments i
	}
	
	return i; //value of variable is returned, name is not.
}

void printErrThang(Provider providers[40],int numProviders) //put parameter in
{
	//"for" each provider print it
	for(int i=0;i< numProviders;i++)
		providers[i].print();
}

void Provider::setNumber(const char* newNumber)
   {
   strcpy(Number, newNumber);
   }  
   
void Provider::setSpecialty(const char* newSpecialty)
   {
   strcpy(Specialty, newSpecialty);
   } 
   
void Provider::setName(const char* newName) //passing array of characters constant character array(*) 
   {
   strcpy(Name, newName);
   }  
   
void Provider::setProviderAddress1(const char* newProviderAddress1)
   {
   strcpy(ProviderAddress1, newProviderAddress1);
   } 
   
void Provider::setProviderAddress2(const char* newProviderAddress2)
   {
   strcpy(ProviderAddress2, newProviderAddress2);
   } 
   
void Provider::setCity(const char* newCity)
   {
   strcpy(City, newCity);
   } 
   
void Provider::setState(const char* newState)
   {
   strcpy(State, newState);
   } 
   
void Provider::setZipCode(const char* newZipCode)
   {
   strcpy(ZipCode, newZipCode);
   } 
   
void Provider::setPhoneNumber(const char* newPhoneNumber)
   {
   strcpy(PhoneNumber, newPhoneNumber);
   } 
   
void Provider::print()
{
	cout << "#" << Number << endl
    	 << Name << endl
    	 << Specialty
    	 << ProviderAddress1 << endl
    	 << ProviderAddress2 << endl
    	 << City << ", " << State << " " << ZipCode << endl
    	 << PhoneNumber << endl
	 << endl;
}
