#include "SimpleSocket.hpp";

// Constructor

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interf)
{
	// Define addres structure
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = htonl(interf);
	// Establish socket
	sock = socket(domain, service, protocol);
	test_connection(sock);
	// establish network connetion
	connection = connect_to_network(sock, address);
	test_connection(connection);
}

// Test connection virtual function

void HDE::SimpleSocket::test_connection(int item_to_test)
{
	// Confirm connection or socket has ben established
	if(item_to_test < 0) {
		perror("Error: Fail on connect");
		exit(EXIT_FAILURE);
	}
}

// Get functions

struct sockaddr_in HDE::SimpleSocket::get_address()
{
	return address;
}

int HDE::SimpleSocket::get_sock()
{
	return sock;
}

int HDE::SimpleSocket::get_connection()
{
	return connection;
}