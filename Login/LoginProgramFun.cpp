#include"LoginProgramFun.h"

string cypher (string w)
{

    for (int i =0; i < w.length(); i++)
    {
        w[i]++;
    }
    return w;

}

string HiddenPassword(string pass){
    char ch;
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
    return pass;
    
}
string StrengthOfPassword(){
    string pass;
    int strength=0,b=0;
    bool IsValid=true;
    while(IsValid){
        cout<<"Please Enter a strong password & more than 8 char : ";
        pass=HiddenPassword(pass);
        if(pass.length()>=8){
            if(regex_search(pass,regex("[A-Z]+")))
                strength+=10;

            if(regex_search(pass,regex("[a-z]+")))
                strength+=10;

            if(regex_search(pass,regex("[0-9]+")))
                strength+=10;

            if(regex_search(pass,regex("[~`""!@#$%^&*()-_+={}[]|;:<>,./?/*]+")))
                strength+=10;

            IsValid=false;
        }
        else{
            cout<<"\nplease enter a password more than 8 char \n";
        }
    }

    if(strength>=30){
        cout<<"\nYour password is very strong\n";
        return pass;
    }
    else{
        cout<<"\nYour password is weak\n";
        StrengthOfPassword();
    }

}

string RepeatThePassword(string pass1, string pass2){

    bool iscorrect=true;

    while(iscorrect){

        pass1 = StrengthOfPassword();
        cout<<"\nPlease repeat the password :\n";
        pass2=HiddenPassword(pass2);

        if(pass1==pass2){
            cout<<"\nThe password are identical\n";
            iscorrect=false;
            return pass1;

        }
        else{
            cout<<"The password are not identical\nplease enter the password again\n";
        }
    }

}
void registeration()
{



    string se, su, sp, sph;
    cout<<"Enter the following informations.\n";
    user:
    //checking availability:
    cout<<"Username: "; cin>>batman.username;
    ifstream searchu("Database.txt");
    while(searchu>>su)
    {
        if(su==batman.username)
        {
            cout<<"This username is already taken, try again.\n";
            goto user;
        }
    }
    searchu.close();
    //checking the username:
    regex correct_user("[-]*[a-zA-Z]+[-]*[a-zA-Z]+[-]*");
    regex_match(batman.username,correct_user);
    if (regex_match(batman.username,correct_user) != true)
    {
        cout<<"Error, the username is incorrect, try again.\n";
        cout<<"(NOTE: the username must be started by alphabet character and doesn't contain spaces.\n";
        goto user;
    }

    pass:
    //checking availability:
    cout << "Rules of strong password should user enter\n"
            "\n"
            "    At least 8 characters (required for your Muhlenberg password)—the more characters, the better\n"
            "    A mixture of both uppercase and lowercase letters\n"
            "    A mixture of letters and numbers \n"
            "    Inclusion of at least one special character, e.g., ! @ # ? ]\n";

    batman.password = RepeatThePassword(batman.password , batman.password2);

    ifstream searchp("Database.txt");
    while(searchp>>sp)
    {
        if(sp==batman.password)
        {
            cout<<"This password is already taken, try again.\n";
            goto pass;
        }
    }

    searchp.close();

    emailaddress:
    //checking availability:
    cout<<"Email: ";
    cin>>batman.email;
    ifstream searche("Database.txt");
    while(searche>>se)
    {
        if(se==batman.email)
        {
            cout<<"This email is already taken, try again."<<endl;
            goto emailaddress;
        }
    }
    searche.close();
    //checking the email:
    regex correct_email("[a-z|A-Z|0-9|.]+\\@[gmail|yahoo]+\\.com");
    regex_match(batman.email,correct_email);
    if (regex_match(batman.email,correct_email) != true)
    {
        cout<<"Error, the email is incorrect, try again.\n";
        cout<<"(NOTE: the formula of the email --> [a-zA-z0-9.]+[@gmail|@yahoo].com)\n";
        goto emailaddress;
    }

    phone:
    cout<<"Phone number: "; cin>>batman.phone;
    //checking availability:
    ifstream searchph("Database.txt");
    while(searchph>>sph)
    {
        if(sph==batman.phone)
        {
            cout<<"This phone number is already taken, try again.\n";
            goto phone;
        }
    }
    searchph.close();
    //checking the number:
    regex correct_num("01[0-2|5]\\d{8}");
    regex_match(batman.phone,correct_num);
    if (regex_match(batman.phone,correct_num) != true)
    {
        cout<<"\nError, the number is incorrect, try again.\n";
        cout<<"\n(NOTE: the number must start by '010' or '011' or '012' or '015' and the number must be 11 number.\n";
        goto phone;
    }
    string cyphered_password = cypher(batman.password);
    ofstream reg("Database.txt",ios::app);
    reg<<batman.username<< endl<<cyphered_password<< endl<<batman.email<< endl<<batman.phone<< endl<<"______________________"<<endl;

    cout<<"\nRegistration sucessful\n\n";


}
bool check_compatibility(string old_cyphered , string email)
{
    bool iscompatible;
    string search;
    ifstream text_file("Database.txt");
    string all_text;

    while(text_file >> search)
    {
        if (all_text == old_cyphered)
        {
            string savedpass = old_cyphered;
        }

        if(all_text == email)
        {
            string savedemail = email;
        }
        all_text +=search;
    }
    int begin = all_text.find(old_cyphered);
    int end = old_cyphered.length();
    int emailplace = all_text.find (email);
    if (begin+end == emailplace)
    {
        iscompatible = true;
        return iscompatible;
    }
    else{

        iscompatible = false;
        return iscompatible;}

}
void change_password()
{
    bool ispass , isemail;
    string old_password , email , new_password , new_password1 , sph ,se , search ,words, old_cyphered , new_cyphered;
    ifstream searche("Database.txt");
    ifstream searchph("Database.txt");
    ifstream searchcheck("Database.txt");
    fstream text_file("Database.txt");

    //infinite loop until the password change is valid
    while (true){

        cout << "To change your password please enter : \n \n";
        cout << "Your email : \n ";
        cin >> email;
        cout << "Old Password : \n ";
        cin >> old_password;
        cout << "Rules of strong password should user enter\n"
                "\n"
                "    At least 8 characters (required for your Muhlenberg password)—the more characters, the better\n"
                "    A mixture of both uppercase and lowercase letters\n"
                "    A mixture of letters and numbers \n"
                "    Inclusion of at least one special character, e.g., ! @ # ? ]\n";

        old_cyphered = cypher(old_password);
        new_cyphered = cypher (RepeatThePassword(batman.password , batman.password2));

        //compare new password with the re-written new password
        int temp3 = new_password.compare(new_password1);
        //check if the user is registered from before
        while (!searchph.eof()) {
            searchph >> sph;

            if (sph == old_cyphered) {
                ispass = true;
            }
        }

        while (!searche.eof())
        {
            searche >> se;

            if (se == email)
            {
                isemail = true;

            }

        }
        string temp;
        string all_text = "";
        int counter =0;
        while(text_file >> search)
        {
            all_text +=search + "\n";
        }

        if (check_compatibility( old_cyphered,email) == true)
        {
        int begin = all_text.find(old_cyphered);
        int end = old_cyphered.length();
        all_text.erase(begin,end);
        all_text.insert(begin , new_cyphered);
        std::fstream text_file;
        text_file.open("Database.txt", std::ofstream::out | std::ofstream::trunc);
        text_file << all_text;



        if ((temp3) == 0 && isemail == true && ispass == true && old_cyphered !=new_cyphered)
        {
            cout << "Password successfuly changed! \n";
            break;
        }
        else{
            cout << "Can't re-new the password! \n";
            cout << "Please make sure that the old password and email are correct, and that the re-newed password is typed the same twice!";
            break;
        }


    }
        else
        {
            cout << "Can't re-new the password! \n";
            cout << "Please make sure that the old password and email are correct, and that the re-newed password is typed the same twice!";
            break;

        }


    }}






void password_and_email()
{
    string password_match = batman.password;
    string email_match = batman.email;
    int counter=0;
    ifstream searche("Database.txt");
    ifstream searchph("Database.txt");

//infinite loop until login is in success
    while (true){
        string cyphered;
        string email;
        string password = "";
        cout << "Please enter your ID and password : ";
        cout << "\n \n Email : ";
        cin >> email;
        cout << "\n \n Password : ";
        password=HiddenPassword(password);
        cyphered = cypher(password);
        string sph , se ;
        bool ispass , isemail;
        //repeats the error of logging in maximum 3 times , then bans user
        if (counter < 3) {



            while (!searchph.eof()) {
                searchph >> sph;

                if (sph == cyphered) {
                    ispass = true;
                }
            }
            while (!searche.eof())
            {
                    searche >> se;
                    if (se == email) {
                        isemail = true;

                }
            }


        }
        if (isemail == true && ispass == true && check_compatibility(cyphered ,email) == true)
        {
            cout << "\nSuccessful login , welcome!";
            break;
        }
        else {

                cout << "\nFailed login. Try again.\n";
                counter += 1;


            }

        if (counter == 3) {
            cout << "\nYou've attempted logging in 3 times! , you are now banned from this program.";
            break;

        }}
    searche.close();
    searchph.close();
    }



void login ()
{
  password_and_email();
}
