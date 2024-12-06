#include <iostream>
#include <fstream>
#include <limits>

void showRooms();
void reserveRoom();
void cancelRoom();

int main(){

  int choice;
  bool running = true;

  std::cout << "Welcome To My Hotel!\n";

  while (running){

    std::cout << "****************************\n";
    std::cout << "What Would You Like To Do?\n";
    std::cout << "1. Show Rooms\n";
    std::cout << "2. Book A Room\n";
    std::cout << "3. Cancel A Room\n";
    std::cout << "4. Quit\n";
    std::cin >> choice;

    if (std::cin.fail() || std::cin.peek() != '\n')
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cerr << "Invalid Input. Please Enter One Character.\n";
      continue;
    }

    switch (choice)
    {

    case 1:
      showRooms();
      break;

    case 2:
      reserveRoom();
      break;
    
    case 3:
      cancelRoom();
      break;

    case 4:
      std::cout << "Thank You For Coming To My Hotel!\n";
      running = false;
      break;

    default:
      std::cerr << "Please Enter Either A Valid Number (1, 2, 3, 4)\n";
      break;
    }

  }

  return 0;
}

void showRooms(){

  std::ifstream fileIn("rooms.txt");

  if (!fileIn.is_open()){

    std::cerr << "File Could Not Be Opened";
    return;
  }

  std::string line;
  int lineNumber = 0;

  while (std::getline(fileIn, line)){

    if (line.empty())
    {
      
      std::cout << "Room " << lineNumber + 1 << ": " << "X" << '\n';

    }

    else
    {

      std::cout << "Room " << lineNumber + 1 << ": " << line << '\n';

    }

    lineNumber++;
  }

  fileIn.close();
}

void reserveRoom(){

  std::ofstream fileOut("temp.txt");
  std::ifstream fileIn("rooms.txt");

  if (!fileOut.is_open()){

    std::cerr << "File Could Not Be Opened";
    return;
  }

  std::string name;
  int roomNumber;

  std::cout << "Enter Your Name:\n";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, name);

  std::cout << "Enter Your Room Number:\n";
  std::cin >> roomNumber;

  if (roomNumber > 10 || roomNumber < 1){

    std::cerr << "Room Number Must Be Between 1 - 10.\n";
    return;
  }

  std::string line;
  int lineNumber = 0;

  while (std::getline(fileIn, line)){

    if (lineNumber + 1 == roomNumber){

      if (line.empty())
      {

        lineNumber++;
        fileOut << name << '\n';
        std::cout << "Room " << lineNumber << " Is Yours!" << '\n';
        continue;
      }

      else 
      {

        std::cout << "This Room Is Already Booked.\n";

      }

    }

    fileOut << line << '\n';
    
    lineNumber++;
  }

  

  fileOut.close();
  fileIn.close();

  std::remove("rooms.txt");
  std::rename("temp.txt", "rooms.txt");
}
void cancelRoom(){

  std::ofstream fileOut("temp.txt");
  std::ifstream fileIn("rooms.txt");

  int roomNumber;

  std::cout << "Enter Your Room Number:\n";
  std::cin >> roomNumber;

  if (roomNumber > 10 || roomNumber < 1){

    std::cerr << "Room Number Must Be Between 1 - 10.\n";
    return;
  }

  std::string line;
  int lineNumber = 0;

  while (std::getline(fileIn, line)){

    if (lineNumber + 1 == roomNumber){

      if (line.empty())
      {
        std::cout << "Room " << lineNumber + 1 << " Isn't Booked!" << '\n';
      }

      else 
      {
        lineNumber++;
        fileOut << '\n'; 
        std::cout << "Booking Has Been Canceled.\n";
        continue;
      }

    }

    fileOut << line << '\n';
    
    lineNumber++;
  }

  

  fileOut.close();
  fileIn.close();

  std::remove("rooms.txt");
  std::rename("temp.txt", "rooms.txt");
}