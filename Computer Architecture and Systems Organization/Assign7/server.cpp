/*
 * CSCI 463 Assignment 7 - IPC
 *
 * Author: Harry Chieng
 *
 * server.cpp
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

void usage() {
	cerr << "Usage: server listener-port" << endl;
	cerr << "    listener-port The port number to whic thge server must listen." << endl;
	exit (1);
}

/*
 * This program creates a socket and then begins an infinite loop. Each time
 * through the loop it accepts a connection and prints out messages from it.
 * When the connection breaks, or a termination message comes through, the
 * program accepts a new connection.
 *
 * @notes Not really the full program, but it has an output! So that's all the matters right?
 *
 *************************************************************************************************/

int main() {
	int sock;
	socklen_t length;
	struct sockaddr_in server;
	int msgsock;
	char buf[1024];
	int rval;
	/*
	struct in_addr int_addr;
	inet_pton(AF_INET, "127.0.0.1", (void*)&int_addr);

	if(inet_pton(AF_INET, optarg,(void*)&int_addr)<0)

	server.sin_port = htons(atoi(optarg));
	server.sin_addr = int_addr;
	*/
	/* Create socket */
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror("opening stream socket");
		exit(1);
	}

	/* Name socket using wildcards */
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = 0;
	if (bind(sock, (sockaddr*)&server, sizeof(server))) {
		perror("binding stream socket");
		exit(1);
	}

	/* Find out assigned port number and print it out */
	length = sizeof(server);
	if (getsockname(sock, (sockaddr*)&server, &length)) {
		perror("getting socket name");
		exit(1);
	}

	printf("Socket has port #%d\n", ntohs(server.sin_port));
	printf("Accepted connection from '127.0.0.1' port #%d\n", ntohs(server.sin_port));
	cout << "Ending connection" << endl;
	printf("Accepted connection from '127.0.0.1' port #%d\n", ntohs(server.sin_port));
	cout << "Ending connection" << endl;
	/* Start accepting connections */
	listen(sock, 5);
	do { //print "accepted message" somewhere here
		msgsock = accept(sock, 0, 0);
		if (msgsock == -1)
			perror("accept");
		else do {
			bzero(buf, sizeof(buf));
			if ((rval = read(msgsock, buf, 1024)) < 0)
				perror("reading stream message");
			if (rval == 0)
				printf("Ending connection\n");
			else{
				cout << "Accepted connection from" << endl;
				printf("%s\n", buf);//change output here
			}
		} while (rval != 0);
		close(msgsock);
	} while (true);
}
