* If the program cannot compile due to the compiler not finding the Boost library, select the project and go to project -> properties and then... 
go to C/C++ --> General -> Additional include directories and select the boost_1_63_0 folder.

* The program can hold a maximum of 250 functions due to listbox restrictions. After 30,000 lines of code syntax highlighting is cancelled to save time.

* Syntax highlighting is only meant to properly update after a function has been saved and reclicked to save on performance, and because
multi-threading without the GNU compiler wasn't successful. 

* Syntax-highlighting conventions are slightly different than that of other programs. The encases of strings and comments are highlighted in color, however the string would not be.
Consider this string "t", " and " would be colored, however not t. To make up for this factor, datatypes such as int have their own color, instead of the std keyword colour. 

* Two functions found on stackoverflow have helped the development of this project by inspiration (not necessarily verbatim copy) and have been referenced at the proper function header.

* If you edit the database.txt file yourself, be weary of the conventions of how data is stored using *`s in combo with other names. 

* Instructions are only provided once on a new copy if the program does not have the ability to edit the System Regristry to check a system GUID and registry #.

* This program is for WINDOWS only. 
