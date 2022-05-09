# Login-TextEditor
#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include <regex>
using namespace std;

void registeration()
{

    string se, su, sp, sph;
    string username, password, email, phone;
    cout<<"Enter the following informations.\n";
    user:
    //checking availability:
    cout<<"Username: "; cin>>username;
        ifstream searchu("Database.txt");
                        while(searchu>>su)
                        {
                                if(su==username)
                                {
                                    cout<<"This username is already taken, try again.\n";
                                    goto user;
                                }
                        }
                        searchu.close();
    //checking the username:
        regex correct_user("[-]*[a-zA-Z]+[-]*[a-zA-Z]+[-]*");
        regex_match(username,correct_user);
        if (regex_match(username,correct_user) != true)
        {
            cout<<"Error, the username is incorrect, try again.\n";
            cout<<"(NOTE: the username must be started by alphabet character and doesn't contain spaces.\n";
            goto user;
        }
    
    pass:
    //checking availability:
        cout<<"Password: "; cin>>password;
        ifstream searchp("Database.txt");
                        while(searchp>>sp)
                        {
                                if(sp==password)
                                {
                                    cout<<"This password is already taken, try again.\n";
                                    goto pass;
                                }
                        }
                        searchp.close();

    emailaddress:
    //checking availability:
        cout<<"Email: "; cin>>email;
        ifstream searche("Database.txt");
                        while(searche>>se)
                        {
                            if(se==email)
                            {
                                cout<<"This email is already taken, try again."<<endl;
                                goto emailaddress;
                            }
                        }
                        searche.close();
    //checking the email:
        regex correct_email("[a-z|A-Z|0-9|.]+\\@[gmail|yahoo]+\\.com");
        regex_match(email,correct_email);
        if (regex_match(email,correct_email) != true)
        {
            cout<<"Error, the email is incorrect, try again.\n";
            cout<<"(NOTE: the formula of the email --> [a-zA-z0-9.]+[@gmail|@yahoo].com)\n";
            goto emailaddress;
        }
        
    phone:
        cout<<"Phone number: "; cin>>phone;
    //checking availability:
        ifstream searchph("Database.txt");
                        while(searchph>>sph)
                        {
                                if(sph==phone)
                                {
                                    cout<<"This phone number is already taken, try again.\n";
                                    goto phone;
                                }
                        }
                        searchph.close();
    //checking the number:
        regex correct_num("01[0-2|5]\\d{8}");
        regex_match(phone,correct_num);
        if (regex_match(phone,correct_num) != true)
        {
            cout<<"Error, the number is incorrect, try again.\n";
            cout<<"(NOTE: the number must start by '010' or '011' or '012' or '015' and the number must be 11 number.\n";
            goto phone;
        }
        
    ofstream reg("Database.txt",ios::app);
    reg<<username<<endl<<password<<endl<<email<<endl<<phone<<endl<<"______________________"<<endl;

    cout<<"Registration sucessful\n\n";    

}

int main(){
    registeration();
  
  
  
    return 0;

}
