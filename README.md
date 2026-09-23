# C++ Networking & HTTP Server

A systems programming project built in modern C++ to explore networking, resource management, concurrency, and low-level software design.

The project begins as a basic TCP client/server implementation and will progressively evolve into a multithreaded HTTP server.

## Project Goals

The primary goal is to develop a deeper understanding of how networked software works at the systems level while applying modern C++ concepts in a practical project.

The project will focus on:

* Modern C++
* RAII and resource management
* Smart pointers and ownership
* Move semantics
* STL containers and algorithms
* TCP/IP networking
* Linux sockets and file descriptors
* Multithreading and synchronization
* Thread pools
* HTTP
* Error handling
* Testing and debugging
* CMake and project organization

## Project Roadmap

### Phase 1 — Basic TCP Server

Build a simple TCP echo server and client.

Topics:

* IPv4
* TCP
* Sockets
* IP addresses and ports
* `socket()`
* `bind()`
* `listen()`
* `accept()`
* `connect()`
* `send()`
* `recv()`
* Resource cleanup
* Basic error handling

### Phase 2 — Concurrent Server

Extend the server to support multiple clients.

Topics:

* `std::thread`
* Thread lifetime
* Shared state
* Mutexes
* Race conditions
* Thread safety
* Producer/consumer patterns

### Phase 3 — Networking Architecture

Refactor the project into reusable C++ components.

Topics:

* RAII
* Move semantics
* Smart pointers
* STL
* Interfaces and abstractions
* Resource ownership
* Error handling
* Thread pools
* CMake project organization

### Phase 4 — HTTP Server

Build an HTTP server on top of the TCP networking layer.

Planned functionality:

* HTTP request parsing
* HTTP response generation
* HTTP methods
* Status codes
* Headers
* Routing
* Static file serving
* Basic API endpoints
* Concurrent client handling

## Architecture

The final system is planned to follow this general architecture:

```text
Client
   |
   v
TCP Socket
   |
   v
HTTP Parser
   |
   v
Router
   |
   +---- Static Files
   |
   +---- API Handlers
   |
   v
HTTP Response
   |
   v
TCP Socket
   |
   v
Client
```

## Development Environment

* C++
* CMake
* Linux / WSL
* Git
* GitHub

## Status

Currently in development.

The project is beginning with Phase 1: a basic TCP client and echo server.

## Learning Approach

The project is being developed incrementally. Each phase introduces new systems and C++ concepts before they are used in later phases.

The goal is not only to produce a working server, but to understand the underlying design decisions, operating-system interfaces, resource management, networking protocols, and concurrency mechanisms involved.
