#include"LoginProgramFun.h"
#include"LoginProgramFun.cpp"

int main(){
    string choice;
    cout << "Press (1) to Register\nPress(2) to Login\nPress(3) to change your old password : " ;
    cin >> choice   ;
    if (choice == "1")
    {
        registeration();
    }
    if (choice == "2")
    {
        login();
    }
    if (choice == "3")
    {
        change_password();
    }

    return 0;

}
