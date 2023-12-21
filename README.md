THE APPLYCATION DISPLAYS DRIVER ASSISTANCE INFOMATION

##About the Application
The application is written using C++ programming language written with VISUAL STUDIO 2022.
It simulates a simple vehicle control system. The user can control the vehicle by selecting different gears and performing actions such as accelerating, decelerating, and turning off the vehicle.

##File Structure
The code is organized into a single file, and all functions are declared and defined within that file.

##Key Code Features

1. Global Variables
   speed and previous_choice are global variables used to maintain the current speed of the vehicle and the previously selected gear.
2. Function Declarations
   Functions are declared at the beginning of the file, providing a clear overview of the available functionalities.
3. Input Validation
   The program includes input validation mechanisms to handle incorrect user inputs gracefully. It uses cin.fail() to detect input failure and clears and ignores the input buffer accordingly.
4. Password Validation
   The program checks for a correct personal identification number (PIN) using the check_key() function before granting access to the main functionalities.
5. Menu Display and Gear Selection
   The menu_MH2() function displays a menu for selecting gears (P, R, N, D, POWER OFF).
   It also checks for specific conditions, such as attempting to shift from R to D or vice versa while the vehicle is in motion.
6. Gear Functions
   Individual functions (gear_P(), gear_R(), gear_N(), gear_D()) simulate actions and warnings associated with each gear selection based on the vehicle's speed.
7. Speed Control Menu
   The menu_MH4() function manages a menu for controlling the vehicle's speed, allowing acceleration, deceleration, braking, and returning to the main menu.
8. Continuous Operation
   The main() function runs in a continuous loop, allowing users to interact with the program until they choose to power off the vehicle.

##How to Use

1. Launching the Program
   Compile and execute the program using a C++ compiler.
2. Personal Identification Number (PIN)
   Enter the correct PIN (default is "12345678") to access the main functionalities.
3. Interacting with the Program
   Choose gears (P, R, N, D) or select POWER OFF to exit the program.
   Adjust the vehicle's speed using the speed control options.
4. Handling Messages and Warnings
   Follow on-screen instructions and warnings.
   Ensure the vehicle is stationary before shifting gears from R to D or vice versa.
