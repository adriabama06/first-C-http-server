
#ifndef SimpleSocket_hpp
#include <winsock2.h>
//#include <sys/socket.h> // change to this if you not are on windows
//#include <windows.h>
//#include <netinet/in.h> // change to this if you not are on windows

namespace HDE
{
	class SimpleSocket
	{
		private:
			struct sockaddr_in address;
			int sock;
		public:
			SimpleSocket(int domain, int service, int protocol, int port, u_long interf);
		};
}


#endif //!SimpleSocket_hpp