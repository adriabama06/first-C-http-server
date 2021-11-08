
#ifndef SimpleSocket_hpp
#include <winsock2.h>
//#include <sys/socket.h> // change to this if you not are on windows
//#include <windows.h>
//#include <netinet/in.h> // change to this if you not are on windows
#include <iostream>

namespace HDE
{
	class SimpleSocket
	{
		private:
			struct sockaddr_in address;
			int sock;
			int connection;
		public:
			SimpleSocket(int domain, int service, int protocol, int port, u_long interf);
			// Virtual function to connect to the network
			virtual int connect_to_network(int sock, struct sockaddr_in adress) = 0;
			// Function to check if the socket or connection
			void test_connection(int);
			// Get functions
			struct sockaddr_in get_address();
			int get_sock();
			int get_connection();
		};
}


#endif //!SimpleSocket_hpp