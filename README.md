# 🚀 Multithreaded Elevator System Design in C++

A multithreaded elevator system simulation implemented in **Modern C++** demonstrating:

- Low Level Design (LLD)
- Object-Oriented Design
- Concurrency & Synchronization
- Strategy Design Pattern
- Elevator Scheduling Algorithms
- Thread-safe Request Handling

This project was built as part of machine coding / LLD interview preparation for Software Development Engineer (SDE) roles.

---

# 📌 Features

✅ Multiple elevators support  
✅ Internal and external elevator requests  
✅ Dedicated worker thread per elevator  
✅ Thread-safe request queues  
✅ Direction-aware request scheduling  
✅ Pluggable elevator scheduling strategies  
✅ Strategy Design Pattern implementation  
✅ Graceful shutdown handling  
✅ Extensible architecture for future enhancements  

---

# 🧠 Design Patterns Used

## 1. Strategy Pattern

Used for elevator allocation algorithms.

Implemented strategies:
- Nearest Elevator Strategy
- Least Busy Elevator Strategy

This allows easy future extensions like:
- Smart batching
- AI-based dispatching
- Priority scheduling
- Time-optimized routing

---

# 🏗️ High Level Architecture

```text
+-------------------+
|     Building      |
+-------------------+
          |
          v
+-------------------+
| ElevatorScheduler |
+-------------------+
          |
          v
+-------------------+
| SelectionStrategy |
+-------------------+
      /       \
     /         \
Nearest      LeastBusy
Strategy      Strategy

          |
          v
+-------------------+
| ElevatorController|
+-------------------+
          |
          v
+-------------------+
|     Elevator      |
+-------------------+
```

---

# 📂 Project Structure

```text
.
├── main.cpp
│
├── models
│   ├── building.cpp
│   ├── elevator.cpp
│   ├── ElevatorController.cpp
│   ├── ElevatorScheduler.cpp
│   ├── floor.cpp
│   ├── InternalButton.cpp
│   └── ExternalButton.cpp
│
├── strategy
│   ├── SelectionStrategy.cpp
│   ├── NearestElevator.cpp
│   └── LeastBusy.cpp
│
└── enums
    ├── directions.cpp
    └── GateState.cpp
```

---

# ⚙️ Core Components

## 🚪 Elevator

Represents the physical elevator car.

Responsibilities:
- Move between floors
- Maintain elevator direction
- Open/close doors
- Track elevator state

---

## 🎮 ElevatorController

Controls one elevator asynchronously.

Responsibilities:
- Process floor requests
- Maintain UP/DOWN queues
- Run worker thread
- Synchronize access using mutex + condition variable

Each elevator has its own dedicated worker thread.

---

## 🧠 ElevatorScheduler

Responsible for assigning elevators.

Responsibilities:
- Receive external requests
- Choose optimal elevator
- Delegate request using scheduling strategy

---

## 📌 SelectionStrategy

Abstract interface for elevator selection policies.

Implemented strategies:
- `NearestElevator`
- `LeastBusy`

Makes the scheduler extensible.

---

## 🔘 InternalButton

Handles requests from inside the elevator.

Example:
- Passenger presses floor 5 inside elevator.

---

## 🔘 ExternalButton

Handles floor requests.

Example:
- Passenger presses UP/DOWN button from floor.

---

## 🏢 Building

Maintains:
- Floors
- Elevator scheduler
- Elevator system initialization

---

# 🔄 Concurrency Model

Each elevator runs independently using a worker thread.

```text
External/Internal Request
            |
            v
   ElevatorController
            |
            v
      Request Queue
            |
            v
      Worker Thread
            |
            v
     Elevator Movement
```

---

# 🔒 Synchronization Used

The system uses:

- `std::mutex`
- `std::condition_variable`
- `std::unique_lock`
- Dedicated worker threads

to ensure thread-safe request handling.

---

# 🧪 Sample Request Flow

```text
1. User presses UP button on floor 3
2. ElevatorScheduler selects best elevator
3. ElevatorController receives request
4. Worker thread wakes up
5. Elevator moves floor-by-floor
6. Door opens at target floor
```

---

# 🖥️ Technologies Used

- C++17
- STL
- Multithreading Library
- Object-Oriented Programming
- Concurrency & Synchronization

---

# 🚀 How To Run

## 1️⃣ Clone Repository

```bash
git clone <your-repository-url>
cd <repository-name>
```

---

## 2️⃣ Compile

### Linux / macOS

```bash
g++ -std=c++17 -pthread main.cpp -o elevator_system
```

### Windows (MinGW)

```bash
g++ -std=c++17 -pthread main.cpp -o elevator_system.exe
```

---

## 3️⃣ Run

### Linux / macOS

```bash
./elevator_system
```

### Windows

```bash
elevator_system.exe
```

---

# 📌 Example Output

```text
Creating a building ......

Moving Up the elevator:1 & currFloor is 1
Moving Up the elevator:1 & currFloor is 2
Moving Up the elevator:1 & currFloor is 3
Stopping the elevator:1 at 3

Opening the door of elevator1 stand back
```

---

# 🔮 Future Enhancements

- Dynamic pickup optimization
- Smart request batching
- Starvation prevention
- Elevator zoning
- Maintenance mode
- Emergency mode
- Weight/load balancing
- Real-time monitoring dashboard
- Async event-driven architecture

---

# 📚 Concepts Demonstrated

This project demonstrates understanding of:

- Low Level Design
- SOLID Principles
- Object-Oriented Programming
- Producer-Consumer Pattern
- Strategy Design Pattern
- Concurrency
- Thread Synchronization
- Scheduling Algorithms
- Extensible System Design

---

# 🎯 Suitable For

- SDE Interview Preparation
- LLD Practice
- Machine Coding Rounds
- Multithreading Practice
- Modern C++ Practice

---

# 📄 License

This project is intended for learning, interview preparation, and educational purposes.

---

# 👨‍💻 Author

Rumit Sharma

```
