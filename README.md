# Auto_Documentation
 This enum "language" will help with switch in main function of the program ^ 
```cpp
enum language {
```
 file_ending function is a function to recognize file type ^ 
```cpp
language file_ending(string file_path, int marker) {
```
 To parsering files will be used classes where will be methods 
 to directly parser each language 
cout << temp << '\n';
 when there is // it will output everything to the end of the line
 it will output everything to the end of the line
```cpp
          after_lines = true;
```
 close the file after working on it
 Getting user input file path from argv[] 
 It is the tool for programers so there dont have to be nice gui 
 So to run it you just have to ./auto_docs [file_path] 
string file_path;
  file_path = argv[1];
 opening file with open() from fstream library to the in object 
fstream in;
 If the file is open correct --> check the language 
 In file path we will collect the ending file type ^ 
```cpp
  language file_type;
```
 variable temp is to work with it in the future 
 {parser Python3.7}
