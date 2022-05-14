#ifndef TEXT_H
#define TEXT_H
#include<iostream>
#include<fstream>
#include<cctype>
#include<regex>
using namespace std;
void view_txt(string filename);
void NumOfWordInTheFile(string filename);
void NumOfchars(string filename);
void NumOfLines(string filename);
void CheckIfWordExist(string filename);
void Merge();
void press(int x);



void Mergetest();
void savefun();
string filename;
string Textfile;
string save;
#endif