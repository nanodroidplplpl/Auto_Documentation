/*Atention,
Program made by Maciej Kawka.
It generate auto documentation which will help you makeing it fast.
There is one rule: mark '^' will take code bellow and put it in docsumentation.*/

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/* This enum "language" will help with switch in main function of the program ^^^^^^ */
enum language {
  C,
  PYTHON,
  CPP,
  FAIL
};

/* file_ending function is a function to recognize file type ^ */
language file_ending(string file_path, int marker) {
  string file_type;
  /* There is marker in the function construction so it iteration from marker point. ^*/
  for (int i = marker; i < file_path.length(); i++) {
    file_type = file_type + file_path[i];
  }
  /* It just work on if statements to chose write enum from [.ending].*/
  if ( file_type == ".c" ) {
    return C;
  } else if ( file_type == ".py" ) {
    return PYTHON;
  } else if ( file_type == ".cpp" ) {
    return CPP;
  }
  return FAIL;
}

/* Some languages are similar so this function will be for: c,c++,java etc.*/
/* file_path is to open file and type is to use it to give right type for github ^*/
void c_like (string file_path, string type) {
  fstream in;

  /* Open a file and then check if the file is correct. ^*/
  in.open(file_path, ios::in);
  if (in.good() == false) {
    printf("The file path is incorrect or something goes wrong\n");
    exit(0);
  }

  /* There is while() function with some variables that help it to correct parser all the file. ^^*/
  string temp; bool next_line = false, on_line_no_common = false, on = true, after_lines = false;
  size_t after_lines_iter = 0; bool after_lines_git = false;
  /* Every line doing operation so it will also iter every sign because There
  is no faster method to check the computational complexity is the lowest:
  n = O(n) where n is how many numbers it have. ^*/
  while (getline(in,temp)) {
    /* This how it work this loop is it takeing every sign and chec if There
    is some configurations int particular language and if it finde some of if
    its makeing some specjal steps*/
    if (after_lines_git) {
      cout << "```" << type << '\n';
      after_lines_git = false;
    }
    if (after_lines) {
      cout << temp << '\n';
      after_lines_iter--;
    }
    if (after_lines && after_lines_iter == 0) {
      cout << "```" << '\n';
      after_lines = false;
    }
    if (next_line) {
      on_line_no_common = false;
      for (int i = 0; i < temp.length(); i++) {
        on = false;
        if (temp[i] == '*' && temp[i+1] == '/') {
          temp = temp.substr(0, i);
          //cout << temp << '\n';
          next_line = false;
          on = true;
          break;
        }
      }
      cout << temp << "<br/>" <<'\n';
    }
    /* This is it, on is variable to switch between this loop and instructions higher ^^*/
    if (on) {
      for (int i = 0; i < temp.length(); i++) {
        // when there is // it will output everything to the end of the line ^
        if (temp[i] == '/' && temp[i+1] == '/') {
          temp = temp.substr(i+2, temp.length()-i-1);
          cout << temp << "<br/>" <<'\n';
        }
        // ^
        if (temp[i] == '/' && temp[i+1] == '*') {
          temp = temp.substr(i+2, temp.length()-i-1);
          next_line = true;
          on_line_no_common = true;
        }
        //^^
        if (next_line) {
          if (temp[i] == '*' && temp[i+1] == '/') {
            temp = temp.substr(0, i);
            next_line = false;
            on_line_no_common = false;
            cout << temp << "<br/>" << '\n';
          }
        }
        /* Also if ^ is there it increse after_lines_iter and switch after_lines for true ^^^^*/
        if (temp[i] == '^') {
          after_lines = true;
          after_lines_git = true;
          after_lines_iter++;
        }
      }
    }
    if(next_line && on_line_no_common){
      cout << temp << "<br/>" <<'\n';
    }
  }

  // close the file after working on it
  in.close();
}

int main(int argc, char *argv[]) {
  /* Getting user input file path from argv[] */
  /* It is the tool for programers so there dont have to be nice gui */
  /* So to run it you just have to ./auto_docs [file_path] */
  /*string file_path;
  file_path = argv[1];*/

  string file_path;
  file_path = argv[1];

  /* opening file with open() from fstream library to the in object */
  //fstream in;

  /* If the file is open correct --> check the language */
  /* In file path we will collect the ending file type ^ */
  language file_type;
  for (int i = 0; i < file_path.length(); i++) {
    if (file_path[i] == '.') {
      file_type = file_ending(file_path, i);
      break;
    }
  }
  printf("This is auto generated documentation.\nBelow it is code explonation, part by part:");
  /* Switch is for choose correct language ^^^^^^^^^^^^^ */
  switch (file_type) {
    case C:
      c_like(file_path, "c");
      break;
    case CPP:
      c_like(file_path, "cpp");
      break;
    case PYTHON:
      printf("python\n");
      break;
    default:
      printf("wrond again\n");
  }
}
