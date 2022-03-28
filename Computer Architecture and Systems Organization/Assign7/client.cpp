/*
 * CSCI 463 Assignment 7 - IPC
 *
 * Author: Harry Chieng
 *
 * client.cpp
 *
 * **********************************************************************************/

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <arpa/inet.h>
#include <iostream>
using std::cerr;
using std::endl;
using std::cout;

#define DATA "Half a league, half a league . . ."

void usage() {
	cerr << "Usage: client [-s server-ip] server-port" << endl;
	cerr << "    -s server-ip Specify the server's IPv4 number in dotted-quad format." << endl;
	cerr << "    server-port The server port number to which the client must connect." << endl;
	exit (1);
}

/*
 * This program creates a socket and initiates a connection with the socket
 * given in the command line.  One message is sent over the connection and
 * then the socket is closed, ending the connection. The form of the command
 * line is streamwrite hostname portnumber
 *
 * @param argc An integer that contains the count of arguments that follow in argv. Always >= 1.
 *
 * @param argv An array of null-terminated strings representing command-line arguments entered by 
 * the user of the program.
 *
 * @notes Not the most complete program, but here it is!
 *
 */

int main(int argc, char *argv[])
{
	int opt;
	int sock;	//FD for the socket connecting the server
	struct sockaddr_in server;	//socket address for the server connection
	struct in_addr int_addr;
	inet_pton(AF_INET,"127.0.0.1",(void*)&int_addr);
	while((opt = getopt(argc, argv, "s:")) != -1) {
		switch(opt) {
			case 's':
				{
					if(inet_pton(AF_INET, optarg,(void*)&int_addr)<0){
						perror("inet_pton");
						exit(EXIT_FAILURE);
					}
				}
				break;
			default:
				{
					usage();
				}
		}
	}
	server.sin_addr = int_addr;
	/* Create socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("opening stream socket");
		exit(1);
	}
	if(optind != argc-1) {
		usage();
	}

	/* Connect socket using name specified by command line. */
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[optind]));

	//cout << "problem here" << endl;
	if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0) {
		perror("connecting stream socket");
		exit(1);
	}
	if (write(sock, DATA, sizeof(DATA)) < 0) {
		perror("writing on stream socket");
	}
	close(sock);
}

