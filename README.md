# Socially Responsible Computing - Academic Roster Project

This program demonstrates reusable code for parsing student information in academic environments while adhering to principles of socially responsible computing (SRC) and implementing an object-oriented design.

## Key Features:
- Soft delete to flag invalid records instead of erasing them
- Validation of email formats
- Calculation of average days per course
- Filtering by degree program(Security, Networking, Software)
- Parsing Data behind the scenes

  ### How to Run This Program
  -Clone the Repository
  git clone https://github.com/rosaperea5030/SociallyResponsibleComputing.git
  cd SociallyResponsibleComputing

  -Open the Project in Your IDE
  Recommended: Visual Studio, Code::Blocks, or any C++-compatible IDE

  -Build the Project
  If using terminal with g++ run:
  g++ main.cpp roster.cpp student.cpp -o rosterApp
  ./rosterApp

  #### Program Input
  -The program comes with built-in student data as string literals
  -No external input file is required
  -The program will run automatically and display results using the functions       inside the driver

This solution helps preserve data integrity and makes it easier for future developers to review or fix issues.

**Author:** Rosa Perea
**Course:** C++2 - Final Project
