#include "SimpleSocket.hpp";

HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interf)
{
	// Define addres structure
	address.sin_family = domain;
	address.sin_port = htons(port);
	address.sin_addr.S_un = htonl(interf);
	// Establish connetion
	sock = socket(domain, service, protocol);
	// Bind
}