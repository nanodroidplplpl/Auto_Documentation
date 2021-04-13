# Auto_Documentation
 This enum "language" will help with switch in main function of the program ^ <br/>
```cpp
enum language {
```
 file_ending function is a function to recognize file type ^ <br/>
```cpp
language file_ending(string file_path, int marker) {
```
 To parsering files will be used classes where will be methods <br/>
 to directly parser each language <br/>
cout << temp << '\n';<br/>
 when there is // it will output everything to the end of the line<br/>
 it will output everything to the end of the line<br/>
```cpp
          after_lines = true;
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
 variable temp is to work with it in the future <br/>
 {parser Python3.7}<br/>

