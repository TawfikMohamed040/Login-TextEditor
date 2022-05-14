// Program:     TextEditorApp.cpp
// Purpose:     Text Editor App
//              to do many function on files

/* Authors:     Tawfik Mohamed Khalil        id->20211024
                Badr Nasr Al-Din Al-Badri    id->20210086
                Youssef Abdullah Ahmed       id->20211117

*/
// Date:     27 April 2022
// Version: 1.0

// TextEditor.txt

#include"TextEditorFun.cpp"
#include"TextEditorFun.h"

int main(){
    int choice;
    // // string FILE;
    // fstream file;
    // cout<<"Ahlan ya user ya habibi\n";
    // cout<<"Please,enter the file name with the extension :";
    // cin>>Textfile;    
    // file.open(Textfile, ios::in);
    // if (file.fail()){
    //     cout << "This is a new file. I created it for you" << endl;
    //     file.open(Textfile, ios::out);
    // }
    // else {
    //     cout << "This File Already Exists";
    // }
    // bool IsTrue=true;
    // while(IsTrue){
    //     cout<<endl;
    //     cout<<"\n1.Add new text to the end of the file\n2.Display the content of the file\n3.Empty the file";
    //     cout<<"\n4.Encrypt the file content\n5.Decrypt the file content\n6.Merge another file";
    //     cout<<"\n7.Count the number of words in the file.\n8.Count the number of characters in the file";
    //     cout<<"\n9.Count the number of lines in the file\n10.Search for a word in the file";
    //     cout<<"\n11.Count the number of times a word exists in the file\n12.Turn the file content to upper case.";
    //     cout<<"\n13.Turn the file content to lower case.\n14.Turn file content to 1st caps (1st char of each word is capital)";
    //     cout<<"\n15.Save\n16.Exit";
    //     cout<<endl;
    //     cout<<"\nEnter your choice :";
    //     cin>>choice;
    //     if(choice==1){
    //         cout<<"badr";
    //     }
    //     else if(choice==2){
    //         view_txt(Textfile);
    //         press(choice);
            
    //     }
    //     // else if(choice==3){
            
    //     // }
    //     // else if(choice==4){
            
    //     // }
    //     // else if(choice==5){
            
    //     // }
    //     else if(choice==6){
    //         Merge(Textfile);
    //         press(choice);
    //     }
    //     else if(choice==7){
    //         NumOfWordInTheFile(Textfile);
    //         press(choice);
    //     }
    //     else if(choice==8){
    //         NumOfchars(Textfile);
    //         press(choice);
    //     }
    //     else if(choice==9){
    //         NumOfLines(Textfile);
    //         press(choice);
    //     }
    //     else if(choice==10){
    //         CheckIfWordExist(Textfile);
    //         press(choice);
    //     }
    //     // else if(choice==11){
            
    //     // }
    //     // else if(choice==12){
            
    //     // }
    //     // else if(choice==13){
            
    //     // }
    //     // else if(choice==14){
            
    //     // }
    //     // else if(choice==15){
            
    //     // }
    //     else if(choice==16){
    //         cout<<"\nThanks for using Test editor";
    //         break;
    //     }
    // }
    // Mergetest();
    // cout<<"1 for merge 2 for exit :";
    // cin>>choice;
    while(true){
        cout<<"1 for merge 2 for exit :";
        cin>>choice;
        if(choice==1){
            Mergetest();
            // break;
        }
        else if(choice==2){
            savefun();
            break;
        }    

    }
}