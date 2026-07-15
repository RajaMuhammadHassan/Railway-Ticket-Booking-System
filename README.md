# 🚆 Railway Ticket Booking System

A console-based **Railway Ticket Booking System** built in **C++**, simulating a simplified version of a real-world train ticketing platform (inspired by Pakistan Railways). It supports user registration, login, ticket booking/cancellation, and an admin dashboard for managing the system.

## ✨ Features

### 👤 User
- Register a new account
- Login with username & password
- View live train schedule with fare and seat availability
- Book a ticket (auto-generates Ticket ID and Seat number)
- View personal booked tickets
- Cancel a ticket (with 85% refund policy)

### 🛠️ Admin
- View total bookings, confirmed/cancelled counts, and total revenue
- View all tickets booked across the system
- View all registered users

## 🧰 Tech Stack

- **Language:** C++
- **Concepts used:** Structs, Arrays, Functions, Pass-by-reference, Control flow, Basic I/O formatting

## 🚀 How to Run

1. Make sure you have a C++ compiler installed (e.g. **g++**).
2. Clone this repository:
   ```bash
   git clone https://github.com/RajaMuhammadHassan/Railway-Ticket-Booking-System.git
   cd Railway-Ticket-Booking-System
   ```
3. Compile the program:
   ```bash
   g++ railway_Project.cpp -o railway
   ```
4. Run it:
   ```bash
   ./railway
   ```

## 🔑 Demo Accounts

| Role  | Username | Password  |
|-------|----------|-----------|
| Admin | admin    | admin123  |
| User  | shah     | shah123   |

## 📌 Sample Trains

| ID  | Train Name         | From    | To         | Time  | Fare (Rs.) |
|-----|---------------------|---------|------------|-------|------------|
| T01 | Khyber Mail         | Karachi | Peshawar   | 08:00 | 800        |
| T02 | Awam Express        | Karachi | Lahore     | 14:00 | 600        |
| T03 | Tezgam              | Karachi | Lahore     | 21:00 | 750        |
| T04 | Green Line          | Karachi | Islamabad  | 16:00 | 1000       |
| T05 | Islamabad Express   | Lahore  | Islamabad  | 07:00 | 350        |

## 👨‍💻 Author

**Raja Muhammad Hassan**
Software Engineering Student @ NUML
[LinkedIn](https://www.linkedin.com/in/raja-muhammad-hassan)
