# C++ Priority Queue and Team Data Management System

This project includes a C++ implementation of a priority queue and utilities for creating and managing team data. The project includes scripts for building a heap, creating teams, and managing priority queue operations using JSON data.

## Project Files

1. **priority_queue.cpp**
   - Implementation of the priority queue.

2. **priority_queue.h**
   - Header file for the priority queue implementation.

3. **build_heap.cpp**
   - Script to build a heap from a JSON file containing operations.

4. **create_teams.cpp**
   - Script to create teams from a JSON file containing player statistics.

5. **create_heap_operation_data.cpp**
   - Script to generate test data for heap operations.

6. **create_team_data.cpp**
   - Script to generate test data for team creation.

7. **team_data.cpp**
   - Implementation for managing team data.

8. **team_data.h**
   - Header file for managing team data.

9. **json.hpp**
   - JSON for Modern C++ library header file.

10. **test.json**
    - Sample JSON file containing test data for heap operations.

11. **Makefile**
   - Makefile for compiling the C++ source code.

## How to Use

### Prerequisites

- C++ compiler (e.g., g++)
- JSON for Modern C++ library

### Steps

1. **Clone the Repository**

   ```sh
   git clone https://github.com/yourusername/Priority-Queue-Team-Data-Management.git
   cd Priority-Queue-Team-Data-Management
   ```

2. **Compile the Code**

   ```sh
   make
   ```

3. **Run the Applications**

   - **Build Heap**
     ```sh
     ./build_heap.exe test.json
     ```

   - **Create Teams**
     ```sh
     ./create_teams.exe test.json
     ```

   - **Generate Heap Operation Data**
     ```sh
     ./create_heap_operation_data.exe numOperations maxHeapSize
     ```

   - **Generate Team Data**
     ```sh
     ./create_team_data.exe numPlayers
     ```

## Example

### Building the Heap

To build the heap from a JSON file containing operations:

```sh
./build_heap.exe test.json
```

### Creating Teams

To create teams based on player statistics from a JSON file:

```sh
./create_teams.exe test.json
```

### Generating Heap Operation Data

To generate test data for heap operations:

```sh
./create_heap_operation_data.exe numOperations maxHeapSize
```

### Generating Team Data

To generate test data for team creation:

```sh
./create_team_data.exe numPlayers