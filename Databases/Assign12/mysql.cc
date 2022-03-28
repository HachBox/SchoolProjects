/*
Programmer: Harry Chieng
Section: CSCI 466-003
Assignment 12
Due: 05/04/2018
Function: C++ with MySql
*/

#include <iostream>
#include <string>
#include <my_global.h>
#include <mysql.h>

using namespace std;

//function that helps shorten the error checking between commands
void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);        
}

int main(int argc, char **argv)
{      
	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "mysql_init() is treason\n");
		exit(1);
	}  

	if (mysql_real_connect(con, "courses", "z1811457", "1994Dec20","z1811457", 0, NULL, 0) == NULL) {
		finish_with_error(con);
	}    

	if (mysql_query(con, "SELECT * FROM Marina")) {
		finish_with_error(con);
	}

	mysql_close(con);

	exit(0);
}
