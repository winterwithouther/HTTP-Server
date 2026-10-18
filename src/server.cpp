#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <cstring>

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

    std::cout << "Socket created: " << server_socket << "\n";

    sockaddr_in server_address{};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // calling bind
    if (bind(server_socket,
            reinterpret_cast<sockaddr*>(&server_address), sizeof(server_address)) == -1) {
        std::cerr << "Failed to bind socket\n";
        close(server_socket);
        return 1;
    }

    std::cout << "Socket bound to 127.0.0.1:8080\n";

    // calling listen
    if (listen(server_socket, 10) == -1) {
        std::cerr << "Failed to listen on socket\n";
        close(server_socket);
        return 1;
    }

    std::cout << "Server is listening on 127.0.0.1:8080\n";

    int client_socket = accept(server_socket, nullptr, nullptr);

    if (client_socket == -1) {
        std::cerr << "Failed to accept connection\n";
        close(server_socket);
        return 1;
    }

    std::cout << "Client connected\n";

    char buffer[1024];

    ssize_t bytes_received = recv(
        client_socket,
        buffer,
        sizeof(buffer),
        0
    );

    if (bytes_received == -1) {
        std::cerr << "Failed to receive data\n";
        close(client_socket);
        close(server_socket);
        return 1;
    }

    std::cout << "Received " << bytes_received << " bytes\n";
    std::cout.write(buffer, bytes_received);
    std::cout << "\n";

    const char* response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: 13\r\n"
        "\r\n"
        "Hello, World!";

    size_t total_sent = 0;
    size_t response_length = strlen(response);

    while (total_sent < response_length) {
        // call send() with the remaining bytes
        ssize_t bytes_sent = send(client_socket,
            response + total_sent,
            response_length - total_sent,
            0);

        // Check if send() returned <= 0
        if (bytes_sent <= 0) {
            std::cerr << "Failed to send response\n";
            close(client_socket);
            close(server_socket);
            return 1;
        }

        // update total_sent
        total_sent += bytes_sent;
    }

    // Close client connection
    close(client_socket);

    // Close listening socket
    close(server_socket);

    return 0;
}