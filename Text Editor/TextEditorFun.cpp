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
// << write
// >> read
void press(int x){
    cout<<"Enter any number to view the List again : ";
    cin>>x;
}

// __________________________________________________________
string &capitalize(string &w){
    for(int i=0;i<w.length();i++){
        if(w.at(i)>=97 && w.at(i)<=122){
            w[i]-=32;
        }
    }
    return w;
}
// __________________________________________________________

void NumOfWordInTheFile(string filename){
    int number=0;
    fstream file; 
    // string filename;
    string word;
    file.open(filename, ios::in);
    // if (file.fail())
    //     cout << "File open error!" << endl;
    // else {
    //     cout << "File opened successful.\n";
    //     cout << "Now reading information.\n";
    // }
    while (!file.eof()) {
        file >> word;
        if(regex_search(word,regex("[A-Za-z]+"))){
            number+=1;
        }
    }
    cout<<"\nThe number of words is : "<<number<<" word"<<endl;
    file.close();
    cout << "\nFile closed\n";

}
// ____________________________________________________________

void NumOfchars(){
    int number=0;
    fstream file; char ch;
    file.open("TextEditor.txt", ios::in);
    if (file.fail())
        cout << "File open error!" << endl;
    else {
        cout << "File opened successful.\n";
        cout << "Now reading information.\n";
    }
    while (!file.eof()) {
        file.get(ch);
        number+=1;
    }
    cout<<"The number of character is : "<<number-1<<" char"<<endl;
    file.close();
    cout << "\nFile closed\n";

}
// ______________________________________________________________

void NumOfLines(){

    int num=0;
    fstream file;  string line;
    file.open("TextEditor.txt", ios::in);
    if (file.fail())
        cout << "File open error!" << endl;
    else {
        cout << "File opened successful.\n";
        cout << "Now reading information.\n";
    }
    while (!file.eof()) {
        getline(file,line);
        num+=1;
    }
    cout<<"The number of lines in file is: "<<num<<" line\n";
    file.close();
    cout << "\nFile closed. \n";
}

// _______________________________________________________________

void CheckIfWordExist(){
    int num=0;
    string word;
    fstream file;  string words;
    file.open("TextEditor.txt", ios::in);
    if (file.fail())
        cout << "File open error!" << endl;
    else {
        cout << "File opened successful.\n";
        cout << "Now reading information.\n";
    }
    int c=0;
    cout<<"Enter the word you want to check it: ";
    cin>>word;
    capitalize(word);
    while (!file.eof()) {
        file >> words;
        capitalize(words);
        if(word==words){
            cout<<"Word was found in the file\n";
            c=1;
            break;
        }
        
    }
    if(c==0){
        cout<<"Word was not found in the file\n";
    }
    file.close();
    cout << "\nFile closed. \n";
}
// ____________________________________________________________
// void Merge(){
//     string line;
//     fstream ifs,ofs;
//     ifs.open("file1.txt",ios::in);
//     ofs.open("file2.txt",ios::app);
//     if(ifs && ofs){
//         while (!ifs.eof())
//         {
//             getline(ifs,line);
//             ofs<<line<<"\n";
//         }
//         cout<<"....Merged Done....";
//     }
//     else{
//         cout<<"Error cant open the File";
//     }
//     ifs.close();
//     ofs.close();
// }











// void Mergetest(){
//     string line;
//     fstream ifs,ofs;
//     ifs.open("file1.txt",ios::in);
//     ofs.open("file2.txt",ios::in);
//     if(ifs && ofs){
//         while (!ifs.eof())
//         {
//             getline(ifs,line);
//             save+=line;
//             // cout<<endl;
//         }
//         while (!ofs.eof())
//         {
//             getline(ofs,line);
//             save+=line;
//             // cout<<endl;
//         }
//         cout<<"....Merged Done....";
//     }
//     else{
//         cout<<"Error cant open the File";
//     }
//     cout<<endl<<save<<endl;
//     ifs.close();
//     ofs.close();
// }
// void savefun(){
//     fstream ofs;
//     string line;
//     ofs.open("file2.txt",ios::out);
//     // while (!ofs.eof()){
//         ofs<<save;
//         cout<<endl;
//     // }
//     ofs.close();
// }