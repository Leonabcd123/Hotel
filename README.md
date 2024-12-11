# Hotel Room Management System

This is a simple hotel room management system built in C++ that allows users to manage hotel rooms by adding, removing, booking, and canceling room reservations. The system interacts with a file (`rooms.txt`) to store and update room information.

## Features

- **Add Rooms:** Users can add a specified number of rooms to the system.
- **Remove Rooms:** Users can remove a specified number of rooms from the system.
- **Show Rooms:** Displays the current status of all rooms, showing if they are booked or available.
- **Book a Room:** Users can reserve a room by entering their name and selecting a room number.
- **Cancel a Reservation:** Users can cancel an existing reservation for a specified room.
- **Input Validation:** Ensures user input is valid and prevents incorrect values from being entered.

## File Structure

- **rooms.txt**: Stores room statuses (empty for available rooms, and the guest name for booked rooms).
- **temp.txt**: A temporary file used during the booking and cancellation process to avoid modifying the original `rooms.txt` directly.

## How to Compile and Run

1. Clone this repository or download the project files.
2. Open a terminal and navigate to the project directory.
3. Compile the program using a C++ compiler (e.g., g++):

   ```bash
   g++ hotel_management.cpp -o hotel_management
   ```

    4. Run the compiled program:
    ```bash
    .\hotel_management
    ```
    
## Usage
Once the program is running, it will display a menu with options:

1. **Add Rooms**: Add a specified number of rooms (between 1 and 100).
2. **Remove Rooms**: Remove a specified number of rooms (up to the total number of rooms).
3. **Show Rooms**: Display all rooms and their current status (booked or available).
4. **Book a Room**: Enter your name and choose a room to book (the room must be available).
5. **Cancel a Room**: Enter the room number to cancel your reservation (the room must be booked).
6. **Quit**: Exit the program.
## Example Workflow

```bash
Welcome To My Hotel!
****************************
What Would You Like To Do?
1. Add Rooms
2. Remove Rooms
3. Show Rooms
4. Book A Room
5. Cancel A Room
6. Quit
The program will prompt you to make a selection and guide you through the necessary steps based on your choice.
```

## Input Validation
- If invalid input is entered (e.g., non-numeric values for room numbers), the program will prompt the user to enter a valid number.
- When booking or canceling rooms, the program ensures that the room exists and is available or booked, respectively.
  
## License
This project is open source and available under the MIT License.
