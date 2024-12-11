#include <iostream>
#include <fstream>
#include <limits>

void setupRooms();
void addRooms();
void removeRooms();
void showRooms();
void reserveRoom();
void cancelRoom();

int main(){

  setupRooms();

  int choice;
  bool running = true;

  std::cout << "Welcome To My Hotel!\n";

  while (running){

    std::cout << "****************************\n";
    std::cout << "What Would You Like To Do?\n";
    std::cout << "1. Add Rooms\n";
    std::cout << "2. Remove Rooms\n";
    std::cout << "3. Show Rooms\n";
    std::cout << "4. Book A Room\n";
    std::cout << "5. Cancel A Room\n";
    std::cout << "6. Quit\n";
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
      addRooms();
      break;

    case 2:
      removeRooms();
      break;

    case 3:
      showRooms();
      break;

    case 4:
      reserveRoom();
      break;
    
    case 5:
      cancelRoom();
      break;

    case 6:
      std::cout << "Thank You For Coming To My Hotel!\n";
      running = false;
      break;

    default:
      std::cerr << "Please Enter Either A Valid Number (1, 2, 3, 4, 5, 6)\n";
      break;
    }

  }

  return 0;
}

void setupRooms(){

  std::ifstream fileIn("rooms.txt");

  if (!fileIn.is_open()){

  std::ofstream fileOut("rooms.txt");


  for (int i = 0; i < 10; i++){

    fileOut << '\n';

  }

  fileIn.close();
  fileOut.close();
  }

}

int getRooms(){

  std::ifstream fileIn("rooms.txt");

  if (!fileIn.is_open()){

    std::cerr << "File Could Not Be Opened";
    return 1;
  }

  std::string line;
  int lineNumber = 0;

  while (std::getline(fileIn, line)){

    lineNumber++;

  }

  fileIn.close();

  return lineNumber;
}

void addRooms(){

  std::ofstream fileOut("rooms.txt", std::ios::app);

  int numOfRooms;

  while (true){

    std::cout << "Enter How Many Rooms You Want To Add:\n";
    std::cin >> numOfRooms;

    if (numOfRooms < 1 || numOfRooms > 100){

      std::cout << "Please Enter A Number Between 1 - 100.\n";
      continue;
    }

    if (std::cin.fail() || std::cin.peek() != '\n')
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid Input. Please Enter One Character.\n";
        continue;
    }

    break;
  }

  for (int i = 0; i < numOfRooms; i++){

    fileOut << '\n';
  }

  fileOut.close();

  std::cout << "Successfully Added " << numOfRooms << " Rooms. Total Rooms: " << getRooms() << '\n';

}

void removeRooms() {
  int totalRooms = getRooms();

  if (totalRooms == 0) {
    std::cout << "No Rooms To Remove.\n";
    return;
  }

  int numOfRooms;
  while (true) {
      std::cout << "Enter How Many Rooms You Want To Remove (1 - " << totalRooms << "):\n";
      std::cin >> numOfRooms;

      if (std::cin.fail() || std::cin.peek() != '\n') {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cerr << "Invalid Input. Please Enter a Number.\n";
          continue;
      }

      if (numOfRooms < 1 || numOfRooms > totalRooms) {
          std::cout << "Please Enter a Number Between 1 - " << totalRooms << '\n';
          continue;
      }

      break;
  }

  std::ofstream fileOut("rooms.txt", std::ios::trunc);
  for (int i = 0; i < totalRooms - numOfRooms; i++) {
      fileOut << '\n';
  }

  fileOut.close();

  std::cout << "Successfully Removed " << numOfRooms << " Rooms. Total Rooms: " << totalRooms - numOfRooms << '\n';
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

  int totalRooms = getRooms();
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

  if (roomNumber > totalRooms || roomNumber < 1){

    std::cerr << "Room Number Must Be Between 1 - " << getRooms() << '\n';
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

  int totalRooms = getRooms();
  std::ofstream fileOut("temp.txt");
  std::ifstream fileIn("rooms.txt");

  int roomNumber;

  std::cout << "Enter Your Room Number:\n";
  std::cin >> roomNumber;

  if (roomNumber > totalRooms || roomNumber < 1)
  {

    std::cerr << "Room Number Must Be Between 1 - " << getRooms() << '\n';
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
