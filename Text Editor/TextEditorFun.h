#ifndef TEXT_H
#define TEXT_H
#include<iostream>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<regex>
#include<vector>
#include <algorithm>
using namespace std;

// ______________________________________

// Functions
void add_txt(string filename);
void view_txt(string filename);
void clear(string filename);
void view_encryption(string filename);
void Decrypt(string filename);
void NumOfWordInTheFile(string filename);
void NumOfchars(string filename);
void NumOfLines(string filename);
void CheckIfWordExist(string filename);
void Merge(string filename);
void word_count(string filename);
void toupper_function(string filename);
void tolower_function(string filename);
void first_letter_upper(string filename);
void press(int x);
void savefun(string filename);
void SaveOutput(string filename);
// ______________________________________

string filename;
string targetfile;
string Textfile;
string save;
// ______________________________________

#endif