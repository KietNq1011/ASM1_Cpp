#include <iostream>
#include <cctype>
#include <string>


using namespace std;

// MH_1 check key
void check_key()
{
    string password; // Personal identification number
    // Loop until the correct personal identification number is entered (default is 12345678)
    while (true) {
        cout << "Nhap ma so ca nhan: ";
        cin >> password;

        if (password == "123") {
            break;
        }
        else {
            cout << "Sai ma so ca nhan. Vui long nhap lai." << endl;
            system("pause");
            system("cls");
        }
    }
}

// MH_2 
int menu_MH2()
{
    system("cls");  // Clear the screen

    cout << "XIN MOI LUA CHON:" << endl;
    cout << "1. P" << endl;
    cout << "2. R" << endl;
    cout << "3. N" << endl;
    cout << "4. D" << endl;
    cout << "5. POWER OFF" << endl;

    int choice;
    cout << "Choice: ";
    cin >> choice;

    return choice;
}

// Gear P - using pointer
void gear_P(int* speed)
{
    if (*speed == 0) {
        system("cls");
        cout << "Da ve so P." << endl;
        cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl << endl;
    }
    else {
        system("cls");
        cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0KM/H" << endl;
    }
}

// Gear N
void gear_N(int* speed)
{
    if (*speed == 0) {
        system("cls");
        cout << "Da ve so N (Tam dung xe)." << endl;
    }
    else {
        system("cls");
        cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0KM/H" << endl;
    }
}

// Gear R
void gear_R(int* speed)
{
    system("cls");
    cout << "Da ve so R." << endl;
    *speed = 7;
}

// Gear D
void gear_D(int* speed)
{

    system("cls");
    cout << "Da ve so D." << endl;
    *speed = 7;
}

// Option MH_4
int menu_MH4(int* speed)
{
    int action;
    cout << "TOC DO HIEN TAI: " << *speed << "km/h" << endl;
    cout << "MOI LUA CHON" << endl;
    cout << "1. TANG TOC" << endl;
    cout << "2. GIAM TOC" << endl;
    cout << "3. PHANH" << endl;
    cout << "4. TRO VE MENU" << endl;

    cin >> action;

    return action;
}

// Check speed and display warnings
void check_speed(int* speed, int choice)
{
    if ((*speed > 0) && ((choice == 2) || (choice == 4))) {
        while (true) {
            int action = menu_MH4(speed);

            if (action == 1) {
                *speed += 5;
            }
            else if (action == 2) {
                *speed -= 5;
            }
            else if (action == 3) {
                system("cls");
                *speed = 0;
            }
            else
                break; // Exit the loop if the user chooses to return to the menu.

            // Check speed and display warnings
            // If speed is below 60 and below 20 (for R)
            if ((choice == 4 && *speed < 60 && *speed > 0) || (choice == 2 && *speed < 20 && *speed > 0)) {
               system("cls");
            }
            // If speed > 60 km/h (for D) or 20 km/h (for R), issue a high-speed warning to the driver
            else if ((choice == 4 && *speed >= 60) || (choice == 2 && *speed >= 20))
            {
                system("cls");
                cout << "CANH BAO: Toc do qua cao cho lai xe!" << endl;
            }
            // Check if the user decelerates to a speed below 0
            else if (*speed <= 0)
            {
                system("cls");
                *speed = 0;
            }
        }
    }
}

int main() {
    int speed = 0;  // Initial speed
    int* speed_ptr = &speed;

    check_key(); // call fn to check password

    while (true) {
        int choice = menu_MH2();
        if (choice == 1) {
            gear_P(speed_ptr);
        }
        else if (choice == 2) {
            gear_R(speed_ptr);
        }
        else if (choice == 3) {
            gear_N(speed_ptr);
        }
        else if (choice == 4) {
            gear_D(speed_ptr);
        }
        else if (choice == 5) {
            system("cls");
            cout << "XE DA DUOC TAT. TAM BIET" << endl;
            return 0;
        }
        else {
            system("cls");
            cin.clear(); // Xóa trạng thái lỗi của cin 
            cin.ignore(); // Loại bỏ dữ liệu không hợp lệ từ bộ đệm đầu vào
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            system("pause");
            continue;
        }


        check_speed(speed_ptr, choice);

        system("pause");  // Pause the screen for the user to read messages
    }

    return 0;
}

