#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int speed = 0;
int previous_choice = 0;

// Function declarations
void check_key();
int menu_MH2();
void gear_P();
void gear_N();
void gear_R();
void gear_D();
int menu_MH4();
void check_speed(int choice);

int main() {
    check_key(); // call fn to check password

    while (true) {
        int choice = menu_MH2();
        if (choice == 1) {
            gear_P();
        }
        else if (choice == 2) {
            gear_R();
        }
        else if (choice == 3) {
            gear_N();
        }
        else if (choice == 4) {
            gear_D();
        }
        else if (choice == 5) {
            system("cls");
            cout << "XE DA DUOC TAT. TAM BIET" << endl;
            return 0;
        }
        else {
            system("cls");
            cin.clear(); // delete error cin status
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            system("pause");
            continue;
        }

        check_speed(choice);

        system("pause");  // Pause the screen for the user to read messages
    }

    return 0;
}

void check_key()
{
    string password;
    while (true) {
        cout << "Nhap ma so ca nhan: ";
        cin >> password;

        if (password == "12345678") {
            break;
        }
        else {
            cout << "Sai ma so ca nhan. Vui long nhap lai." << endl;
            system("pause");
            system("cls");
        }
    }
}

int menu_MH2()
{
    system("cls");
    cout << "XIN MOI LUA CHON:" << endl;
    cout << "1. P" << endl;
    cout << "2. R" << endl;
    cout << "3. N" << endl;
    cout << "4. D" << endl;
    cout << "5. POWER OFF" << endl;

    int choice;
    cout << "Choice: ";
    cin >> choice;

    // If switching from R to D and speed is not 0, display a warning
    if (previous_choice == 2 && choice == 4 && speed != 0) {
        cout << "VUI LONG CHUYEN TOC DO VE 0 TRUOC KHI CHUYEN SO" << endl;
        choice = previous_choice;
        system("pause");
    }
    else if (previous_choice == 4 && choice == 2 && speed != 0) {
        cout << "VUI LONG CHUYEN TOC DO VE 0 TRUOC KHI CHUYEN SO" << endl;
        choice = previous_choice;
        system("pause");
    }

    previous_choice = choice;
    return choice;
}

void gear_P()
{
    if (speed == 0) {
        system("cls");
        cout << "Da ve so P." << endl;
        cout << "CHU Y SU DUNG PHANH TAY DE DAM BAO AN TOAN" << endl << endl;
    }
    else {
        system("cls");
        cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0KM/H" << endl;
    }
}

void gear_N()
{
    if (speed == 0) {
        system("cls");
        cout << "Da ve so N (Tam dung xe)." << endl;
    }
    else {
        system("cls");
        cout << "HAY CHAC CHAN XE DA DUNG VA VAN TOC LA 0KM/H" << endl;
    }
}

void gear_R()
{
    if (speed == 0) {
        system("cls");
        cout << "Da ve so R." << endl;
        speed = 7;
    }
    else {
        system("cls");
        cout << "Da ve so R." << endl;
        if (speed > 20)
            cout << "CANH BAO: Toc do qua cao cho lai xe!" << endl;
    }
}

void gear_D()
{
    if (speed == 0) {
        system("cls");
        cout << "Da ve so D." << endl;
        speed = 7;
    }
    else {
        system("cls");
        cout << "Da ve so D." << endl;
        if (speed > 60)
            cout << "CANH BAO: Toc do qua cao cho lai xe!" << endl;
    }
}

int menu_MH4()
{
    int action;
    while (true)
    {
        cout << "TOC DO HIEN TAI: " << speed << "km/h" << endl;
        cout << "MOI LUA CHON" << endl;
        cout << "1. TANG TOC" << endl;
        cout << "2. GIAM TOC" << endl;
        cout << "3. PHANH" << endl;
        cout << "4. TRO VE MENU" << endl;
        cout << "Choice: ";
        cin >> action;
        if (action <= 4 && action >= 1)
        {
            break;
        }
        else {
            cin.clear(); // Xóa trạng thái lỗi của cin 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');// Loại bỏ dữ liệu không hợp lệ từ bộ đệm đầu vào
            cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
            system("pause");
            system("cls");
            continue;
        }
    }

    return action;
}

void check_speed(int choice)
{
    if ((speed > 0) && ((choice == 2) || (choice == 4))) {
        while (true) {
            int action = menu_MH4();

            if (action == 1) {
                speed += 5;
            }
            else if (action == 2) {
                speed -= 5;
            }
            else if (action == 3) {
                system("cls");
                speed = 0;
            }
            else
                break;

            if ((choice == 4 && speed < 60 && speed > 0) || (choice == 2 && speed < 20 && speed > 0)) {
                system("cls");
            }
            else if ((choice == 4 && speed >= 60) || (choice == 2 && speed >= 20)) {
                system("cls");
                cout << "CANH BAO: Toc do qua cao cho lai xe!" << endl;
            }
            else if (speed <= 0) {
                system("cls");
                speed = 0;
            }
        }
    }
}
