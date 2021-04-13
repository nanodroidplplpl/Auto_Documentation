#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

/* This enum "language" will help with switch in main function of the program ^ */
enum language {
  C,
  PYTHON,
  CPP,
  FAIL
};

/* file_ending function is a function to recognize file type ^ */
language file_ending(string file_path, int marker) {
  string file_type;
  for (int i = marker; i < file_path.length(); i++) {
    file_type = file_type + file_path[i];
  }
  cout << file_type << endl;
  if ( file_type == ".c" ) {
    return C;
  } else if ( file_type == ".py" ) {
    printf("python\n");
    return PYTHON;
  } else if ( file_type == ".cpp" ) {
    return CPP;
  }
  return FAIL;
}

/* To parsering files will be used classes where will be methods */
/* to directly parser each language */

void c_like (string file_path, string type) {
  fstream in;

  in.open(file_path, ios::in);
  if (in.good() == false) {
    printf("The file path is incorrect or something goes wrong\n");
    exit(0);
  }

  string temp; bool next_line = false, on_line_no_common = false, on = true, after_lines = false;
  while (getline(in,temp)) {
    if (after_lines) {
      cout << "```"<< type << '\n';
      cout << temp << '\n';
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
      cout << temp << '\n';
    }
    if (on) {
      for (int i = 0; i < temp.length(); i++) {
        // when there is // it will output everything to the end of the line
        if (temp[i] == '/' && temp[i+1] == '/') {
          temp = temp.substr(i+2, temp.length()-i-1);
          cout << temp << '\n';
        }
        if (temp[i] == '/' && temp[i+1] == '*') {
          temp = temp.substr(i+2, temp.length()-i-1);
          next_line = true;
          on_line_no_common = true;
        }
        if (next_line) {
          if (temp[i] == '*' && temp[i+1] == '/') {
            temp = temp.substr(0, i);
            next_line = false;
            on_line_no_common = false;
            cout << temp << '\n';
          }
        }
        if (temp[i] == '^') {
          after_lines = true;
        }
      }
    }
    if(next_line && on_line_no_common){
      cout << temp <<'\n';
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
  /* variable temp is to work with it in the future */
  switch (file_type) {
    case C:
      c_like(file_path, "c");
      printf("c ok\n");
      break;
    case CPP:
      c_like(file_path, "cpp");
      printf("cpp\n");
      break;
    case PYTHON:
      // {parser Python3.7}
      printf("python\n");
      break;
    default:
      printf("wrond again\n");
  }
  printf("Work done\n");
}
