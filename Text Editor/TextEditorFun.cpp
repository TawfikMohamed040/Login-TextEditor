// Program:     TextEditorApp.cpp
// Purpose:     Text Editor App
//              to do many function on files

/* Authors:     Tawfik Mohamed Khalil        id->20211024
                Badr Nasr Al-Din Al-Badri    id->20210086
                Youssef Abdullah Ahmed       id->20211117

*/
// Date:     27 April 2022
// Version: 1.0

#include"TextEditorFun.h"

void press(int x){
    cout<<"\nEnter any number to view the List again : ";
    cin>>x;
}
//________________________________________________________________________________________________________________________________________

void add_txt(string filename) {
    fstream fout;
    string added_txt;
    cout << "please enter the text you want to add and (write EOF in a new line to stop) : \n";
    // open file in append mode
    fout.open(filename, ios::app);
    while (getline(cin, added_txt))
    {
        // if user write EOF stop writing in the file
        if (added_txt == "EOF") // to end the function
        {
            break;
        }
        // save in a var called save to send to savefun() 
        save+=added_txt;
        save+="\n";
    }

    fout.close();
}
//________________________________________________________________________________________________________________________________________

void view_encryption(string filename) {
    string words;
    fstream myfile;
    // open file in read mode
    myfile.open(filename, ios::in);
    vector<char> sentence;
    while (getline(myfile, words)) {
        for (int i = 0; i < words.length(); i++) {
            words[i] = (char)(words[i] + 1);
            // save the encrypted char in vector
            sentence.push_back(words[i]);
        }
        sentence.push_back('\n');
    }
    myfile.close();
    for (int i=0; i < sentence.size(); i++)
    // save in a var called save to send to savefun() 
        save+=sentence[i];
}
//_______________________________________________________________________________________________________________________________________

void Decrypt(string filename) {
    string words;
    fstream myfile;
    // open file in read mode
    myfile.open(filename, ios::in);
    vector<char> sentence;
    while (getline(myfile, words)) {
        for (int i = 0; i < words.length(); i++) {
            words[i] = (char)(words[i] - 1);
            // save the decrypted char in vector
            sentence.push_back(words[i]);
        }
        sentence.push_back('\n');
    }
    myfile.close();
    for (int i = 0; i < sentence.size(); i++)
    // save in a var called save to send to savefun() 
        save+=sentence[i];

}
//_______________________________________________________________________________________________________________________________________

void view_txt(string filename) {
    string line;
    fstream file;
    // open file in read mode
    file.open(filename, ios::in);
    cout<<endl;
    // loop on every line in the file to the end of it
    while (!file.eof()){
        getline(file, line);
        cout << line << endl;
    }
    cout<<endl;
    file.close();
}
//_______________________________________________________________________________________________________________________________________

void clear(string filename) {
    ofstream clear(filename);
    clear << "";
    clear.close();
}
//_______________________________________________________________________________________________________________________________________

string &capitalize(string &w){
    for(int i=0;i<w.length();i++){
        // capitalize words
        if(w.at(i)>=97 && w.at(i)<=122){
            w[i]-=32;
        }
    }
    return w;
}
//_______________________________________________________________________________________________________________________________________

void NumOfWordInTheFile(string filename){
    int number=0;
    fstream file; 
    string word;
    // open file in read mode
    file.open(filename, ios::in);
    // loop on every word in the file to the end of it
    while (!file.eof()) {
        file >> word;
        // calc num of words
        if(regex_search(word,regex("[A-Za-z]+"))){
            number+=1;
        }
    }
    cout<<"\nThe number of words is : "<<number<<" word"<<endl;
    file.close();
    cout << "\nFile closed\n";

}
//_______________________________________________________________________________________________________________________________________

void NumOfchars(string filename){
    int number=0;
    fstream file; char ch;
    // open file in read mode
    file.open(filename, ios::in);
    // loop on every char in the file to the end of it
    while (!file.eof()) {
        // calc num of words
        file.get(ch);
        number+=1;
    }
    cout<<"The number of character is : "<<number-1<<" char"<<endl;
    file.close();
    cout << "\nFile closed\n";

}
///_______________________________________________________________________________________________________________________________________

void NumOfLines(string filename){

    int num=0;
    fstream file;  string line;
    // open file in read mode
    file.open(filename, ios::in);
    // loop on every line in the file to the end of it
    while (!file.eof()) {
        // calc num of lines
        getline(file,line);
        num+=1;
    }
    cout<<"The number of lines in file is: "<<num<<" line\n";
    file.close();
    cout << "\nFile closed. \n";
}

//_______________________________________________________________________________________________________________________________________

void CheckIfWordExist(string filename){
    int num=0;
    string word;
    fstream file;  string words;
    // open file in read mode
    file.open(filename, ios::in);
    int c=0;
    cout<<"Enter the word you want to check it: ";
    cin>>word;
    capitalize(word);
    // loop on every word in the file to the end of it
    while (!file.eof()) {
        file >> words;
        capitalize(words);
        // check if the word is exist or not
        if(word==words){
            cout<<"\nWord was found in the file\n";
            c=1;
            break;
        }
        
    }
    if(c==0){
        cout<<"\nWord was not found in the file\n";
    }
    file.close();
    cout << "\nFile closed. \n";
}
//_______________________________________________________________________________________________________________________________________

void Merge(string filename){
    fstream ifs,ofs;
    string line,filemerge;
    cout<<"enter the name of the file to merge : ";
    cin>>filemerge;
    // open file in read mode
    ifs.open(filename,ios::in);
    ofs.open(filemerge,ios::in);
    if(ifs && ofs){
        // loop on every line in the file to the end of it
        while (!ofs.eof())
        {
            getline(ofs,line);
            save+=line;
            // save in a var called save to send to savefun() 
            save+="\n";
        }
        // loop on every line in the file to the end of it
        while (!ifs.eof())
        {
            getline(ifs,line);
            save+=line;
           // save in a var called save to send to savefun() 
            save+="\n";
        }
        cout<<"\n....Merged Done....";
    }
    else{
        cout<<"Error cant open the File";
    }
    ifs.close();
    ofs.close();
}
//_______________________________________________________________________________________________________________________________________

void word_count(string filename)
{

    int num=0;
    string word;
    fstream file;  string words;
    // open file in read mode
    file.open(filename, ios::in);
    int c=0;
    cout<<"Enter the word you want to scerch: ";
    cin>>word;
    capitalize(word);
    // loop on every word in the file to the end of it
    while (!file.eof()) {
        file >> words;
        capitalize(words);
        // calc how many times the word in the file
        if(word==words){
            num+=1;
        }
        
    }
    cout<<"\nThe word you enterd found "<<num<<" times\n";
    file.close();
} 

//_______________________________________________________________________________________________________________________________________

void toupper_function(string filename)
{
    // open file in read mode
    ifstream text_file;
    text_file.open(filename);
    // check if the file opend
    if (text_file.is_open())
    {
        char temp;
        char text;
        while (text_file)
        {
            temp = text_file.get();
            text = toupper(temp);
            // save in a var called save to send to savefun() 
            save+=text;
        }
    }
}
//_______________________________________________________________________________________________________________________________________

void tolower_function(string filename)
{
    // open file in read mode
    ifstream text_file;
    text_file.open(filename);
      // check if the file opend
    if (text_file.is_open())
    {
        char temp;
        char text;
        while (text_file)
        {
            temp = text_file.get();
            text = tolower(temp);
            // save in a var called save to send to savefun() 
            save+=temp;

        }
    }
}
//_______________________________________________________________________________________________________________________________________
void first_letter_upper(string filename) {
    fstream text_file;
    text_file.open(filename);
    string words;
    string temp;
    // loop on every word in the file
    while (!text_file.eof()) {
        text_file >> words;
        // first lower all word's char
        for (int j =0; j<=words.length(); j++)
        {

            words[j] = tolower(words[j]);

        }
        // second upper the first char of every word
        for (int j =0; j<=words.length(); j++)
        {
            words[0]= toupper(words[0]);

        }
        temp = words;
        // save in a var called save to send to savefun() 
        save+=temp;
        save+=' ';
    }
    cout << "\nDone!";
}


// void first_letter_upper(string filename) {
//     fstream text_file;
//     text_file.open(filename);
//     string words;
//     string temp;
//     while (!text_file.eof() ) {
//         text_file >> words;
//         for (int j =0; j<=words.length(); j++)
//         {
//             words[0]= toupper(words[0]);
//         }
//             temp = words;
//             // save in a var called save to send to savefun() 
//             save+=temp;
            
//     }
//     cout << "\nDone! .. You can now see the final output at 'target.txt'!";
// }
//_______________________________________________________________________________________________________________________________________

void savefun(){
    cout<<"enter the name of the file you want to save in(file end wih .txt) : ";
    cin>>targetfile;
    fstream ofs;
    // open file in write mode
    ofs.open(targetfile,ios::out);
    for(int i=0;i<save.length();i++){
            ofs<<save[i];   
    }
    cout<<"\nsaved Done";
    ofs.close();
}