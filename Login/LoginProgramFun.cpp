// shap of password should be entered

    /*a minimum of 1 lower case letter [a-z] and
    a minimum of 1 upper case letter [A-Z] and
    a minimum of 1 numeric character [0-9] and
    a minimum of 1 special character: ~`!@#$%^&*()-_+={}[]|\;:"<>,./?*/

// _______________________________________________________________________________________________

// Rules of strong password should user enter

    /*At least 8 characters (required for your Muhlenberg password)—the more characters, the better
    A mixture of both uppercase and lowercase letters
    A mixture of letters and numbers 
    Inclusion of at least one special character, e.g., ! @ # ? ]*/ 
//__________________________________________________________________________________________________

#include<iostream>
#include<conio.h>
#include<regex>
using namespace std;
void HiddenPassword(){
    char ch;
    string pass ;
    cout<<"Alhlan ya habibi\n";
    cout<<"please enter the password : ";
    ch=getch();
    bool Valid=true;
    while(Valid){
        if(ch==8 && pass.length()!=0){
                cout<<"\b \b";
                pass.pop_back();
                ch=getch();
        }
        else if(ch==13){
            Valid=false;
            break;
        }
        else{
            if(ch!=13){
                cout<<"*";
                pass+=ch;
                ch=getch();
            }
        }
    }
    cout<<endl<<pass<<endl;
    cout<<endl;
    if(pass=="tawfik"){
        cout<<"correct password\n";
        cout<<"Khod sambosa";
    }
    else{
        cout<<"wrong password please try again";
    }
    
}
// ___________________________________________________________________________

void StrengthOfPassword(){
    string pass;
    int strength=0,b=0;
    bool IsValid=true;
    while(IsValid){
        cout<<"Please Enter a strong password & more than 8 char : ";
        cin>>pass;
        if(pass.length()>=8){
            if(regex_search(pass,regex("[A-Z]+")))
                strength+=10;

            if(regex_search(pass,regex("[a-z]+")))
                strength+=10;

            if(regex_search(pass,regex("[0-9]+")))
                strength+=10;

            if(regex_search(pass,regex("[~`""!@#$%^&*()-_+={}[]|;:<>,./?*/]+")))
                strength+=10;

            IsValid=false;   
        }
        else{
            cout<<"please enter a password more than 8 char \n"; 
        }    
    }
    
    if(strength>=30){
        cout<<"Your password is very strong";
    }
    else{
        cout<<"Your password is weak";
    }    
        
}

// ______________________________________________________________________

void RepeatThePassword(){
    string pass1,pass2;
    bool iscorrect=true;

    while(iscorrect){

        cout<<"please enter the password you want to set : ";
        cin>>pass1;

        cout<<"Please repeat the password :";
        cin>>pass2;
        
        if(pass1==pass2){
            cout<<"The password are identical";
            iscorrect=false;
        }
        else{
            cout<<"The password are not identical\nplease enter the password again\n";
        }
    }

}
