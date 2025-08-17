# 🗽 Philo

The **Philosophers** project is a classic exercise in concurrent programming.
It is based on the famous *Dining Philosophers Problem*, designed by Edsger Dijkstra, which illustrates the challenges of **synchronization, deadlocks, and resource sharing** in multithreaded environments.

In this project, I learned how to manipulate **threads** and discovered how they can be more lightweight and powerful than processes for solving concurrency problems.

---

## ✨ Features

* Simulation of philosophers sitting at a table, eating, thinking, and sleeping.
* Use of **POSIX threads (pthreads)** for concurrency.
* Synchronization with **mutexes** to avoid race conditions.
* Handling of **deadlocks** and starvation prevention.
* Fine-grained time management for accurate simulation.

---

## 📂 Project Structure

```
philo/
├── includes/                 
│   └── philo.h               # Header file with structs and function prototypes
├── src/                      
│   ├── main.c                # Entry point: initializes simulation and handles arguments
│   ├── le_philo/             # Core philosopher routines
│   └── tools/                # Utility functions
├── Makefile                  # Build rules for compilation
├── LICENSE                   # MIT license
├── README.md                 # Project documentation
└── compile_commands.json     # Compilation metadata for IDEs and analysis
```

---

## 🛠️ Installation & Usage

### 1. Clone the repository

```bash
git clone https://github.com/elhiba/philo.git
cd philo
```

### 2. Build the program

```bash
make
```

### 3. Run the simulation

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]
```

---

## 📖 Example

```bash
./philo 5 800 200 200
```

* **5** → philosophers
* **800** → time (ms) before a philosopher dies without eating
* **200** → eating duration (ms)
* **200** → sleeping duration (ms)

**Sample Output:**

```
0 1 is thinking
0 2 is thinking
1 1 has taken a fork
1 1 has taken a fork
1 1 is eating
...
```

---

## 🎯 Learning Objectives

By working on **Philo**, I practiced:

* Understanding and implementing **multithreading** with `pthread`.
* Using **mutexes** to protect shared resources.
* Designing algorithms to **avoid deadlocks and race conditions**.
* Gaining a deeper knowledge of **time management** in concurrent systems.
* Comparing **threads vs processes** and why threads are often more efficient.
