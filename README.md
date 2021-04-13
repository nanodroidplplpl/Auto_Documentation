# Auto_Documentation
This is auto generated documentation.
Below it is code explonation, part by part:Atention,<br/>
Program made by Maciej Kawka.<br/>
It generate auto documentation which will help you makeing it fast.<br/>
There is one rule: mark '^' will take code bellow and put it in docsumentation.<br/>
```cpp

```
 This enum "language" will help with switch in main function of the program ^^^^^^ <br/>
```cpp
enum language {
  C,
  PYTHON,
  CPP,
  FAIL
};
```
 file_ending function is a function to recognize file type ^ <br/>
```cpp
language file_ending(string file_path, int marker) {
```
 There is marker in the function construction so it iteration from marker point. ^<br/>
```cpp
  for (int i = marker; i < file_path.length(); i++) {
```
 It just work on if statements to chose write enum from [.ending].<br/>
 Some languages are similar so this function will be for: c,c++,java etc.<br/>
 file_path is to open file and type is to use it to give right type for github ^<br/>
```cpp
void c_like (string file_path, string type) {
```
 Open a file and then check if the file is correct. ^<br/>
```cpp
  in.open(file_path, ios::in);
```
 There is while() function with some variables that help it to correct parser all the file. ^^<br/>
```cpp
  string temp; bool next_line = false, on_line_no_common = false, on = true, after_lines = false;
  size_t after_lines_iter = 0; bool after_lines_git = false;
```
 Every line doing operation so it will also iter every sign because There<br/>
  is no faster method to check the computational complexity is the lowest:<br/>
  n = O(n) where n is how many numbers it have. ^<br/>
```cpp
  while (getline(in,temp)) {
```
 This how it work this loop is it takeing every sign and chec if There<br/>
    is some configurations int particular language and if it finde some of if<br/>
    its makeing some specjal steps<br/>
cout << temp << '\n';<br/>
 This is it, on is variable to switch between this loop and instructions higher ^^<br/>
```cpp
    if (on) {
      for (int i = 0; i < temp.length(); i++) {
```
 when there is // it will output everything to the end of the line ^<br/>
 it will output everything to the end of the line ^<br/>
```cpp
        if (temp[i] == '/' && temp[i+1] == '/') {
```
 ^<br/>
^^<br/>
 Also if ^ is there it increse after_lines_iter and switch after_lines for true ^^^^<br/>
```cpp
        if (temp[i] == '^') {
```cpp
          after_lines = true;
          after_lines_git = true;
          after_lines_iter++;
        }
      }
```
 close the file after working on it<br/>
 Getting user input file path from argv[] <br/>
 It is the tool for programers so there dont have to be nice gui <br/>
 So to run it you just have to ./auto_docs [file_path] <br/>
string file_path;<br/>
  file_path = argv[1];<br/>
 opening file with open() from fstream library to the in object <br/>
fstream in;<br/>
 If the file is open correct --> check the language <br/>
 In file path we will collect the ending file type ^ <br/>
```cpp
  language file_type;
```
 Switch is for choose correct language ^^^^^^^^^^^^^ <br/>
```cpp
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
```
