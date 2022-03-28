#ifndef PROVIDER_H
#define PROVIDER_H

   //*****************************************************************
   // FILE:      Provider.h
   // AUTHOR:	 Harry Chieng
   // LOGON ID:  z1811457
   // DUE DATE:  9/26/2017
   // 
   // PURPOSE:   Declaration for the Provider class, which represents 
   //            information about a health care provider.
   //*****************************************************************

   class Provider
      {
      // Data members and method prototypes for the Provider class go here
	private:
	char Number[7]={}; //C strings
	char Specialty[41]={};
	char Name[41]={};
	char ProviderAddress1[41]={};
	char ProviderAddress2[31]={};
	char City[21]={};
	char State[3]={};
	char ZipCode[6]={};
	char PhoneNumber[15]={};
	public:
      Provider();
      Provider(const char*, const char*, const char*, const char*, const char*, const char*, const char*, const char*,
       const char*);

      const char* getProviderNumber() const;
      const char* getName() const;
      const char* getSpecialty() const;
      void print() const;
      };

   #endif
