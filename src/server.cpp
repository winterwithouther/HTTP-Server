#include <sys/socket.h>
#include <iostream>
#include <unistd.h>

int main() {
    
    /**
     * socket(
     *  AF_INET // IPv4
     *  SOCK_STREAM // TCP
     *  0   // default protocol
     * )
     */

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        std::cerr << "Failed to create socket\n";
        return 1;
    }

    std::cout << "Socket created." << server_socket << "\n";

    // closing the socket
    close(server_socket);

    return 0;
}