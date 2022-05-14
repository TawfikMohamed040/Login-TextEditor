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
    cout<<"\nEnter any number to view the List again : ";
    cin>>x;
}
//____________________________________________________
void view_txt(string filename) {
    string words;
    fstream file;
    file.open(filename, ios::in);
    cout<<endl;
    while (!file.eof()){
        getline(file, words);
        cout << words << endl;
    }
    cout<<endl;
    file.close();
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
    string word;
    file.open(filename, ios::in);
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

void NumOfchars(string filename){
    int number=0;
    fstream file; char ch;
    file.open(filename, ios::in);
    while (!file.eof()) {
        file.get(ch);
        number+=1;
    }
    cout<<"The number of character is : "<<number-1<<" char"<<endl;
    file.close();
    cout << "\nFile closed\n";

}
// ______________________________________________________________

void NumOfLines(string filename){

    int num=0;
    fstream file;  string line;
    file.open(filename, ios::in);
    while (!file.eof()) {
        getline(file,line);
        num+=1;
    }
    cout<<"The number of lines in file is: "<<num<<" line\n";
    file.close();
    cout << "\nFile closed. \n";
}

// _______________________________________________________________

void CheckIfWordExist(string filename){
    int num=0;
    string word;
    fstream file;  string words;
    file.open(filename, ios::in);
    int c=0;
    cout<<"Enter the word you want to check it: ";
    cin>>word;
    capitalize(word);
    while (!file.eof()) {
        file >> words;
        capitalize(words);
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
// ____________________________________________________________
void Merge(string filename){
    fstream ifs,ofs;
    string line,filemerge;
    cout<<"enter the name of the file to merge : ";
    cin>>filemerge;
    ifs.open(filename,ios::in);
    ofs.open(filemerge,ios::app);
    if(ifs && ofs){
        while (!ifs.eof())
        {
            getline(ifs,line);
            ofs<<line<<"\n";
        }
        cout<<"\n....Merged Done....";
    }
    else{
        cout<<"Error cant open the File";
    }
    ifs.close();
    ofs.close();
}











void Mergetest(){
    string line;
    fstream ifs,ofs;
    ifs.open("file1.txt",ios::in);
    ofs.open("file2.txt",ios::in);
    if(ifs && ofs){
        while (!ifs.eof())
        {
            getline(ifs,line);
            save+=line;
            // cout<<endl;
        }
        while (!ofs.eof())
        {
            getline(ofs,line);
            save+=line;
            // cout<<endl;
        }
        cout<<"....Merged Done....";
    }
    else{
        cout<<"Error cant open the File";
    }
    cout<<endl<<save<<endl;
    ifs.close();
    ofs.close();
}
void savefun(){
    fstream ofs;
    // char line[150];
    ofs.open("file2.txt",ios::out);
    // while (!ofs.eof()){
        for(int i=0;i<save.length();i++){
            ofs<<save[i];
        }
    // }
    ofs.close();
}