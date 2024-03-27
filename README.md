#Student Advisor Management System

**Overview**
This project is a simple student advisor management system implemented in C. It allows users to manage a list of advisees for different advisors, perform operations such as adding new advisees, changing majors, deleting students, merging advisor lists, printing advisees for a specific advisor, and quitting the program while saving advisee information to files.

**Features**
Add New Advisee: Users can input information for a new student and add them to the appropriate advisor's list.
Advisee Changes Major: If a student changes their major, their record can be moved from one advisor's list to another.
Advisee Changes School: If a student changes schools, they can be removed from the advisor's list.
Merge Lists: Lists of advisees for different advisors can be merged if one advisor is not available.
Print Advisees for an Advisor: Users can view the list of advisees for a specific advisor.
Quit and Save: The program allows users to quit and saves the advisee information to separate files for each advisor.

**How to Use**
Run the program.
Choose an operation from the menu by entering the corresponding number.
Follow the prompts to input necessary information or IDs.
Repeat steps 2-3 as needed.
When done, choose option 6 to quit and save advisee information to files.
Optionally, view or modify the saved files containing advisee information.

**File Structure**
main.c: Contains the main program logic.
advisee_node struct: Defines the structure of a node representing a student.
Functions: Includes functions for adding, searching, changing majors, deleting students, merging lists, printing advisees, and quitting.
Files: Talei_advisees.txt and VanLierde_advisees.txt are used to store advisee information for each advisor.

**Dependencies**
This project is written in C and requires a C compiler to build and run.
Standard C libraries such as stdio.h, stdlib.h, and string.h are used.

**Usage Notes**
Ensure proper input when prompted to prevent errors.
Advisors' names are case-sensitive.
Verify file permissions when saving advisee information.

**Future Improvements**
Implement error handling for invalid inputs.
Enhance user interface for better interaction.
Add more features such as sorting and updating student information.
Improve file handling for robustness and flexibility.
