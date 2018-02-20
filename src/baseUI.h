/*
Viru
baseUI.h
This class, baseUI, includes most GUI related content for the program, besides information dumped
	into text files and compile / build run time execution data. 

All buttons, textboxes, etc will be stored here. 
*/

#define NOMINMAX // this is later used for iterating through data and preventing stream corruption.
#pragma once
#include <string> 
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream> 
#include <limits>
#include <iterator>
#include <boost/algorithm/string.hpp> // if this is not included, select the solution and go to project -> properties and then... 
// Go to C/C++ --> General -> Additional include directories and select the boost_1_63_0 folder. 
#include <msclr\marshal_cppstd.h> // used to exchange std::string data and system String ^ data.

std::string pythonKeywords[35] = {
	"False", "class ", "finally ", " is ", "return ", "None ", "continue ", "for ", 
	"lambda ", "try:", "True",	"def ", "from ", "nonlocal ", "while ",
	"else ", "import ", "pass ", "break ", "except ", "in ", "raise ", "and ",
	"del ", "global ", "not ", "with ", "as ", "elif ", "if ", " or ", "yield ", "assert ", "print(", "input("
};

std::string pythonDataTypes[16] = { 
	"int ", "str ", "float", "complex", "list(", 
	"tuple(", "dict(", "set(", "frozenset", "chr", "unichr", "ord", 
	"hex", "oct", "int(", "str("
};

std::string cppKeywords[75] = {
	"alignas ", "alignof ", "and ", " and_eq ", "asm ", "atomic_cancel ",
	"atomic_commit ", "atomic_noexcept ", "bitand ", " bitor ", "break", "case:", "catch",
	"compl ", "concept ", "constexpr ", "const_cast ", "continue ", "decltype ",
	"default ", "delete ", "do ", "dynamic_cast ", "else ", "explicit ", "export ", "extern ", 
	"false", "for(", "friend", "goto ", "if(", "import", "inline", "module", "mutable",
	"namespace ", "new ", "noexcept ", "not", " not_eq", "nullptr", "operator",
	" or", " or_eq", "private:", "protected:", "public:", "register ", "reinterpret_cast",
	"requires", "return ", "signed", "sizeof", "static ", "static_assert", "static_cast",
	"switch (", "synchronized", "template", "this-", "thread_local", "throw ", "true", "try",
	"typedef ", "typeid", "typename", "union", "using ", "virtual ", "volatile",
	"while", "xor", " xor_eq"
};

std::string cppDataTypes[20] = {
	"struct ", "int", "bool", "double", "float", "long", 
	"void", "unsigned", "string", "char", "char16_t", "char32_t", 
	"class ", " const", "short", "enum", "auto", "wchar_t", "std", "size_t"
};

std::string numberList[10] = {
	"1", "2", "3", "4", "5", "6", "7", "8", "9", "0"
};

std::string operatorList[20] = {
	"+", "-", "/", "*", ".", "&", "^", "%", "$", "=", "!", ">", "<", "|", "~", "?", ":",  "__init__", "\"", "\'"
};

std::string containerList[6] = {
	"(", ")", "[", "]", "{", "}"
};

std::string commentList[4] = {
	"//", "/*", "*/", "#"
};

namespace mainUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// baseGUI provides all interactable services (buttons, inputs, textboxes) for the user, and establishes a design.
	/// </summary>
	public ref class baseGUI : public System::Windows::Forms::Form
	{
	public:
		baseGUI(void)
		{
			InitializeComponent(); // basic constructor component 
		}
	protected:
		~baseGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  programText;
	public: System::Windows::Forms::TextBox^  nameBox;
	private: System::Windows::Forms::Label^  nameLabel;
	private: System::Windows::Forms::Label^  languageLabel;
	private: System::Windows::Forms::ComboBox^  languageBox;
	private: System::Windows::Forms::PictureBox^  divider;

	public: System::Windows::Forms::ListBox^  functionSelector;
	private: System::Windows::Forms::Label^  funtionCollectionLabel;
	private: System::Windows::Forms::Button^  saveButton;


	Color monokaiPink = Color::FromArgb(253, 151, 31);
	Color monokaiYellow = Color::FromArgb(249, 38, 114);
	Color monokaiOrange = Color::FromArgb(230, 218, 115);
	Color monokaiComment = Color::FromArgb(83, 78, 63);
	Color monokaiPurple = Color::FromArgb(102, 217, 239);
	Color monokaiGreen = Color::FromArgb(162, 217, 43);
	msclr::interop::marshal_context access; // create an alias for marshal_context access 

	private: System::Windows::Forms::Button^  copyButton;
	private: System::Windows::Forms::Button^  deleteButton;

	private:
		/// <summary>
		/// Required designer variable for execution. 
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(baseGUI::typeid));
			this->programText = (gcnew System::Windows::Forms::RichTextBox());
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->nameLabel = (gcnew System::Windows::Forms::Label());
			this->languageLabel = (gcnew System::Windows::Forms::Label());
			this->languageBox = (gcnew System::Windows::Forms::ComboBox());
			this->divider = (gcnew System::Windows::Forms::PictureBox());
			this->functionSelector = (gcnew System::Windows::Forms::ListBox());
			this->funtionCollectionLabel = (gcnew System::Windows::Forms::Label());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->copyButton = (gcnew System::Windows::Forms::Button());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->divider))->BeginInit();
			this->SuspendLayout();
			// 
			// programText
			// 
			this->programText->AcceptsTab = true;
			this->programText->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->programText->ForeColor = System::Drawing::SystemColors::Window;
			resources->ApplyResources(this->programText, L"programText");
			this->programText->Name = L"programText";
			this->programText->TextChanged += gcnew System::EventHandler(this, &baseGUI::codeTextUpdate);
			// 
			// nameBox
			// 
			this->nameBox->ForeColor = System::Drawing::SystemColors::WindowFrame;
			resources->ApplyResources(this->nameBox, L"nameBox");
			this->nameBox->Name = L"nameBox";
			// 
			// nameLabel
			// 
			resources->ApplyResources(this->nameLabel, L"nameLabel");
			this->nameLabel->Name = L"nameLabel";
			// 
			// languageLabel
			// 
			resources->ApplyResources(this->languageLabel, L"languageLabel");
			this->languageLabel->Name = L"languageLabel";
			this->languageLabel->Click += gcnew System::EventHandler(this, &baseGUI::sendCode);
			// 
			// languageBox
			// 
			this->languageBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->languageBox->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->languageBox->FormattingEnabled = true;
			this->languageBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { resources->GetString(L"languageBox.Items"), resources->GetString(L"languageBox.Items1") });
			resources->ApplyResources(this->languageBox, L"languageBox");
			this->languageBox->Name = L"languageBox";
			// 
			// divider
			// 
			resources->ApplyResources(this->divider, L"divider");
			this->divider->Name = L"divider";
			this->divider->TabStop = false;
			// 
			// functionSelector
			// 
			this->functionSelector->FormattingEnabled = true;
			resources->ApplyResources(this->functionSelector, L"functionSelector");
			this->functionSelector->Name = L"functionSelector";
			this->functionSelector->SelectedIndexChanged += gcnew System::EventHandler(this, &baseGUI::sendCode);
			// 
			// funtionCollectionLabel
			// 
			resources->ApplyResources(this->funtionCollectionLabel, L"funtionCollectionLabel");
			this->funtionCollectionLabel->Name = L"funtionCollectionLabel";
			// 
			// saveButton
			// 
			resources->ApplyResources(this->saveButton, L"saveButton");
			this->saveButton->Name = L"saveButton";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &baseGUI::writeToFile);
			// 
			// copyButton
			// 
			resources->ApplyResources(this->copyButton, L"copyButton");
			this->copyButton->Name = L"copyButton";
			this->copyButton->UseVisualStyleBackColor = true;
			this->copyButton->Click += gcnew System::EventHandler(this, &baseGUI::copyToClipboard);
			// 
			// deleteButton
			// 
			resources->ApplyResources(this->deleteButton, L"deleteButton");
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &baseGUI::deleteData);
			// 
			// baseGUI
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->copyButton);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->funtionCollectionLabel);
			this->Controls->Add(this->functionSelector);
			this->Controls->Add(this->divider);
			this->Controls->Add(this->languageBox);
			this->Controls->Add(this->languageLabel);
			this->Controls->Add(this->nameLabel);
			this->Controls->Add(this->nameBox);
			this->Controls->Add(this->programText);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"baseGUI";
			this->Opacity = 0.99;
			this->Load += gcnew System::EventHandler(this, &baseGUI::accessFunctionNames);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->divider))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void codeTextUpdate(System::Object^  sender, System::EventArgs^  e) {

		/// ------------------------------------------------------------------------------------ ///
		/*
		This function is merely here to catch updates to code text in the RichTextBox^ programText.
		*/
		/// ------------------------------------------------------------------------------------ ///
		
	}

		private: System::Void deleteData(System::Object^  sender, System::EventArgs^  e) {

			/// ------------------------------------------------------------------------------------ ///
			/*
			This function is activated when the delete button is pressed. It calls a function, deleteFunction
				which deletes the function in the file. (It deletes the file and rewrites it completely.) 
			*/
			/// ------------------------------------------------------------------------------------ ///

			deleteFunction(functionSelector->GetItemText(functionSelector->SelectedItem));
			programText->Text = " "; // we do not want to reset this in the function, as it is used for other manipulations.
		}

	private: System::Void sendCode(System::Object^  sender, System::EventArgs^  e) {

		/// ------------------------------------------------------------------------------------ ///
		/*
		This function, which is passed down the location of the GUI object / class, and event arguments,
			retrieves code text from the file database.txt and sends it to a RichTextbox^ called programText.

		The function is heavily reliant on msclr marshal and the string library.
		*/
		/// ------------------------------------------------------------------------------------ ///

		std::ifstream fin("database.txt");
		int selectedIndex = functionSelector->SelectedIndex; auto i = 0, j = 0, line = 1; std::string fileString;
		// In the line above, the function selected by the user is created as an int, and multiple counters are made to iterate through a file. Line is used to represent which line in the file the pointer is. 
		
		
		std::string codeArray[1450] = { "" };
		if (fin.is_open()) {
			do { // find the function in the filename, and iterate until the function selected in the ListBox^ matches the index of the function name in database.txt 
				std::getline(fin, fileString);
				++line;
				if (fileString[0] == '*' && fileString[1] == '^') {
					++i;
				}
			} while (i <= selectedIndex);

			std::string container;
			gotoLine(fin, line); // move the pointer viewing the file to the line where the code is. 
			std::getline(fin, container);
			while (container != "*%." || container == "*%.\n" || container == "*%. ") {
				std::getline(fin, container);
				if (!(container == "*%" || container == "*%.") && j < 1450) {
					codeArray[j] = std::string(container);
					++j;
				}
			}

			fin.close();
			std::string compositeString("");
			for (auto u = 0; u < 1450; ++u) {
				compositeString.append(codeArray[u] + "\n");
			}

			std::ifstream finPatcher("patchErrors.txt");
			std::string baseString; std::getline(finPatcher, baseString); // fix color highlighitng with patch .txt file data. 
			finPatcher.close();
			//boost::trim_right(compositeString);
			String ^ fileStringSystem = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(char *)compositeString.c_str());
			String ^ deconstructor = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(char *)baseString.c_str());
			programText->Text = deconstructor; // deconstruct text inside box
			programText->Text = fileStringSystem;
			std::string language(grabLanguage());
			operateHighlights(language);
			nameBox->Text = functionSelector->GetItemText(functionSelector->SelectedItem); // update if a user tries to edit
			String ^ sysLang = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(char *)language.c_str());
			languageBox->Text = sysLang; // ... so that metadata is preserved.

	}
		else {
			;//throw std::invalid_argument("database.txt File not found. Create a new file, database.txt in the same directory as the .cpp files.");
		}
}

	private: System::Void accessFunctionNames(System::Object^ sender, System::EventArgs^ e) {

		/// ------------------------------------------------------------------------------------ ///
		/*
		This function retrieves functionNames from database.txt using the function getFunctions.
		It is merely an event attatcher.
		*/
		/// ------------------------------------------------------------------------------------ ///

		getFunctions();
		checkUserAuthToken();

	}

	private: System::Void copyToClipboard(System::Object^ sender, System::EventArgs^ e) {

		/// ------------------------------------------------------------------------------------ ///
		/*
		This function retrieves data from a RichTextBox^, and copies it to a windows clipboard.
		*/
		/// ------------------------------------------------------------------------------------ ///

		System::String^ theCode = programText->Text;
		Clipboard::SetText(theCode);
	}

	public: System::Void writeToFile(System::Object^  sender, System::EventArgs^  e) {

		/// ------------------------------------------------------------------------------------ ///
		/*
		This function, which takes in the eventArgs / event data, and a reference to the object / class of the GUI,
			updates the database.txt file that is found in the same directory as this .h file.

		This function is heavily reliant on the marshal msclr library, as it needs to convert strings and
			system String ^.*/
		/// ------------------------------------------------------------------------------------ ///

		// Create a System String to Hold Function Name, A String of Code, and the Language of said code
		System::String^ functionName; System::String^ codeString; System::String^ languageString;
		functionName = nameBox->Text; codeString = programText->Text; languageString = languageBox->Text;

		// Convert System::String^ arg to cppstd lib string.  
		std::string functionNameStandard(access.marshal_as<std::string>(functionName));
		std::string codeStringStandard(access.marshal_as<std::string>(codeString));
		std::string languageStringStandard(access.marshal_as<std::string>(languageString));

		removeAsterisks(functionNameStandard);

		std::string functionCollection[250]; auto m = 0;
		std::string contentText;
		std::fstream getData("database.txt");
		if (getData.is_open()) {
			while (!(getData.eof())) {
				std::getline(getData, contentText);
				if (contentText[0] == '*' && contentText[1] == '^') {
					functionCollection[m] = contentText;
					++m;
				}
			}
			getData.close();
		}

		std::string checkFunction = ("*^" + functionNameStandard);
		for (auto t = 0; t < 250; ++t) {
			if (functionCollection[t] == (checkFunction)){
				deleteFunction(functionName);
				break;
			}
		}

		std::fstream fout;
		fout.open("database.txt", std::fstream::app); // prevent overriding on foutstream. source: http://stackoverflow.com/questions/4155537/writing-into-a-text-file-without-overwriting-it
		if (fout.is_open()) {
			fout << "*^" << functionNameStandard << "\n";
			fout << "*&" << languageStringStandard << "\n";
			fout << "*%\n" << codeStringStandard << "\n*%." << "\n";
		}
		else {
			;// throw std::invalid_argument("database.txt File not found. Create a new file, database.txt in the same directory as the .cpp files.");
		}
		fout.close();
		getFunctions();
	}
			 void removeAsterisks(std::string& inputString) {

				 /// ------------------------------------------------------------------------------------ ///
				 /*
				 Takes in a parameter, std::string (from <#include string> by reference.
				 This function will remove all asterisks from a string passed by reference.
				 We want to remove asterisks from function names in the program often because asterisks are used
					 in the back end system to categorize data.
				 */
				 /// ------------------------------------------------------------------------------------ ///

				 for (int i = 0; i < int(inputString.length() - 1); ++i) {
					 if (char(inputString[i]) == '*') { // Assume that users do not NEED * in function names...
						 inputString.erase(i, i); // we want to remove all traces of * in the function name...
					 } // since * is used to index where new functions are in the text file. 
				 }
			 }
			 std::string grabLanguage() {

				 /// ------------------------------------------------------------------------------------ ///
				 /*
				 This function, grabLanguage, obtains the language of a given function
				 through the "database.txt" file and returns it as a string.
				 */
				 /// ------------------------------------------------------------------------------------ ///
				 std::string language; int selectedIndex = functionSelector->SelectedIndex; auto i = 0, line = 1; std::string fileString;
				 std::ifstream finFind("database.txt");
				 if (finFind.is_open()) {
					 do { // find the function in the filename, and iterate until the function selected in the ListBox^ matches the index of the function name in database.txt 
						 std::getline(finFind, fileString);
						 ++line;
						 if (fileString[0] == '*' && fileString[1] == '^') {
							 ++i;
						 }
					 } while (i <= selectedIndex);
					 finFind.close();

					 finFind.open("database.txt");
					 std::string container;
					 gotoLine(finFind, (line + 0)); // move the pointer viewing the file to the line where the code is. 
					 std::getline(finFind, container);
					 language = std::string(container);
					 language.erase(0, 2);
				 }
				 finFind.close();
				 return language;
}

		void checkUserAuthToken() {

			/// ------------------------------------------------------------------------------------ ///
			/*
			See if the user has ever used the program before. If not, give a popup that shows them instructions. 
			FOR THIS FUNCTION TO WORK ON A USED VERSION OF THE PROGRAM, THIS APPLICATION MUST HAVE ADMIN 
			AND UAC / REGISTRY EDIT PERMISSIONS. 
			*/
			/// ------------------------------------------------------------------------------------ ///
			String^ registryLocation = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Cryptography";
			String^ userIdentifier = (String^)Microsoft::Win32::Registry::GetValue(registryLocation, "MachineGuid", "0");
			std::string userID(access.marshal_as<std::string>(userIdentifier));

			std::ifstream finID("userAuthToken.txt"); std::string token;;
			if (finID.is_open()) {
				std::getline(finID, token);
				if (token != userID) {
					finID.close();
					std::fstream fout("userAuthToken.txt");
					fout << userID;
					System::Windows::Forms::MessageBox::Show("How to use the function manager:\n\n\
To write code that you want to save into your function, type in the black IDE like box. \
For your code to be saved, you will have to name the function and hit save.\n\
Type in the function name in the name textbox. \
Choose a language from the drop - down box if you would like syntax highlighting when you *next* view the code.\n\n\
If you leave the program, your function code will not be saved unless you hit save.\n\
Functions will appear on the left-hand side of the menu. Click or use the arrow keys to view the code of the function.\n\n ", "Instructions");
					fout.close();
				}
				else {
					finID.close();
				}
			}
			else {
				;// throw std::invalid_argument("userAuthToken.txt not found. User authentication cannot proceed until this file exists in the same directory as this .h file.");
			}
			}

		void operateHighlights(std::string language) {

			/// ------------------------------------------------------------------------------------ ///
			/*
			This function updates a RichTextBox^ programText to add syntax highlighting for a given function.
			*/
			/// ------------------------------------------------------------------------------------ ///

			if(programText->TextLength > 30000) {
				; // pass if there is way too much data. 
			}
			else {
				if (language == "Python" || language == "C++") {
					if (language == "Python") {
						for (auto k = 0; k <= 15; ++k) { // data types
							syntaxHighlight(programText, pythonDataTypes[k], monokaiPink);
						}
						for (auto i = 0; i <= 34; ++i) { // keywords 
							syntaxHighlight(programText, pythonKeywords[i], monokaiYellow);
						}
						syntaxHighlight(programText, "#", monokaiComment);
						commentHighlight(programText, monokaiComment);
					}
					else if (language == "C++") {
						for (auto k = 0; k <= 19; ++k) { // data types
							syntaxHighlight(programText, cppDataTypes[k], monokaiPink);
						}
						for (auto i = 0; i <= 74; ++i) { // keywords 
							syntaxHighlight(programText, cppKeywords[i], monokaiYellow);
						}
						for (auto p = 0; p <= 3; ++p) {
							syntaxHighlight(programText, commentList[p], monokaiComment);
						}
						cCommentHighlight(programText, monokaiComment);
					}
					for (auto l = 0; l <= 9; ++l) {
						syntaxHighlight(programText, numberList[l], monokaiPurple);
					}
					for (auto z = 0; z <= 19; ++z) {
						syntaxHighlight(programText, operatorList[z], monokaiGreen);
					}
					for (auto z = 0; z <= 5; ++z) {
						syntaxHighlight(programText, containerList[z], monokaiOrange);
					}
				}
			}

	}
		void deleteFunction(String^ functionToDestroySystemVers) {

			std::ifstream fin("database.txt");
			std::string code(""); std::string container("");
			if (fin.is_open()) {
				while (!(fin.eof())) {
					std::getline(fin, container);
					code.append(container + "\n");
				}
			}
			// default parameter: String^ functionToDestroySystemVers = functionSelector->GetItemText(functionSelector->SelectedItem);
			std::string functionToDestroy(access.marshal_as<std::string>(functionToDestroySystemVers));
			functionToDestroy.insert(0, "*^");
			//int found = int(code.find_first_of(functionToDestroy))
			int found = code.find(functionToDestroy);
			int endCut = found;
			while (!(char(code[endCut]) == '*' && char(code[endCut + 1]) == '%' && char(code[endCut + 2]) == '.')) { // while not at end of the function 
				++endCut;
			}
			endCut += 3;
			code.erase(found, (endCut-found));
			fin.close();
			std::ofstream outputFile;
			
			if (remove("database.txt") != 0){
				;// throw std::invalid_argument("database.txt not found.");
			}
			else {
				outputFile.open("database.txt");
				outputFile << code;
				outputFile.close();
			}
			getFunctions();
			std::string placeholder = " ";
			String^ sysPlace = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(char *)placeholder.c_str());
			nameBox->Text = sysPlace; // update if a user tries to edit
		}

		void getFunctions() {

			/// ------------------------------------------------------------------------------------ ///
			/*
			This function takes in no inputs, and updates the listBox called functionSelector.
			Data is taken from "database.txt" which is in the same directory as the .h file. 
			Function names start with *^ in .txt database.
			Items are also refreshed in this function to prevent duplication. 
			*/
			/// ------------------------------------------------------------------------------------ ///

			functionSelector->Items->Clear(); // remove duplicates 
			std::string fileLine; std::string functionNames[250] = { "" };
			std::ifstream fin("database.txt"); int i = 0;
			if (fin.is_open()) {
				while (!fin.eof()) {
					std::getline(fin, fileLine);
					if (fileLine[0] == '*' && fileLine[1] == '^') { // if the string has a function name encoding
						fileLine.erase(0, 2); // remove the encoding from the string to just have function name
						functionNames[i] = fileLine;
						++i;
					}
				}
			}
			else {
				;// throw std::invalid_argument("database.txt File not found. Create a new file, database.txt in the same directory as the .cpp files.");
			}
			for (auto i = 0; i < 250; ++i) { // for all possible elements in the array of function names 
				if (!(functionNames[i] == "")) { 
					String ^ ansiStringStandard = System::Runtime::InteropServices::Marshal::PtrToStringAnsi((IntPtr)(char *)functionNames[i].c_str());
					functionSelector->Items->Add(ansiStringStandard); // above, we have converted an array of std::string to system String ^.
				}
			}
			fin.close();


	}
		std::ifstream& gotoLine(std::ifstream& file, int num) {

			/// ------------------------------------------------------------------------------------ ///
			/* 
			This function has been inspired by this source, Xeo: http://stackoverflow.com/questions/5207550/in-c-is-there-a-way-to-go-to-a-specific-line-in-a-text-file 
			The function takes in a file through the passed ifstream, and an integer num, 
				which is used to iterate though the file.
			Essentially, the function moves the pointer in the system viewing file to the line given by num. 
			*/
			/// ------------------------------------------------------------------------------------ ///

			file.seekg(std::ios::beg);
			for (auto i = 0; i < num - 1; ++i) {
				file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			return file;
		}

		void syntaxHighlight(RichTextBox^ box, std::string highlight, Color color) {

			/// ------------------------------------------------------------------------------------ ///
			/*
			Function Inspired by this source, Hans Passant : http://stackoverflow.com/questions/455713/selectively-coloring-text-in-richtextbox
			This function takes in a system RichTextBox, string from the #include <string module> and a System::Drawing::Color type
			The function searches the text in a text box, box, for the phrase to change the color of, highlight.
			The color of the phrase is set to color.
			*/
			/// ------------------------------------------------------------------------------------ ///

			int position = box->SelectionStart; int length = highlight.length();
			String ^ boxContent = box->Text; // get the content of textbox parameter. 
			std::string content(access.marshal_as<std::string>(boxContent)); // convert system String ^ to std::string
			for (int i = 0; ;) {
				int j = content.find(highlight, i);
				if (j < 0) { // if no more found strings with content of parameter highlight, then stop. 
					break;
				}
				box->SelectionStart = j; //start recolor at the index of highlight. 
				box->SelectionLength = length;
				box->SelectionColor = color;
				i = j + 1; // iterate through content faster by using j+1 instead of i++
			}
			}

		void commentHighlight(RichTextBox^ searchBox, Color commentColor) {

			/// ------------------------------------------------------------------------------------ ///
			/*
			This protoype testing function takes in a RichTextBox^ to grab text from, and a System::Drawing::Color type which is used a comment color. 
			The function searches the text in a text box, sarchBox, and the color of all text after a # in a line is set to commentColor.
			*/
			/// ------------------------------------------------------------------------------------ ///

			String ^ boxContent = searchBox->Text; // get the content of textbox parameter. 
			std::string content(access.marshal_as<std::string>(boxContent)); // convert system String ^ to std::string
			int position = 0;

			std::istringstream stringStrm(content); 
			std::string lineContent;

			auto a = 0;
			auto t = 0; // total of how many chars have been counted. 
			auto totalLength = content.size();

			while (!(stringStrm.eof())) {
				std::getline(stringStrm, lineContent);
				int lineLength = lineContent.length();
				while(a < lineLength){
					++t;// weve seen a character 
					if (lineContent[a] == '#' || (lineContent[a] == '\"' && lineContent[a + 1] == '\"' && lineContent[a + 2] == '\"')) {
						searchBox->SelectionStart = t;
						searchBox->SelectionLength = lineLength - a;
						searchBox->SelectionColor = commentColor;
					}
					++a;
				}
				++t;
				a = 0; // reset a because we are on the next line. 
			}
		}

		void cCommentHighlight(RichTextBox^ searchBox, Color commentColor) {

			/// ------------------------------------------------------------------------------------ ///
			/*
			This protoype testing function takes in a RichTextBox^ to grab text from, and a System::Drawing::Color type which is used a comment color.
			The function searches the text in a text box, sarchBox, and the color of all text after a # in a line is set to commentColor.
			*/
			/// ------------------------------------------------------------------------------------ ///

			String ^ boxContent = searchBox->Text; // get the content of textbox parameter. 
			std::string content(access.marshal_as<std::string>(boxContent)); // convert system String ^ to std::string
			int position = 0;

			std::istringstream stringStrm(content);
			std::string lineContent;

			auto a = 0;
			auto t = 0; // total of how many chars have been counted. 
			auto totalLength = content.size();

			while (!(stringStrm.eof())) {
				std::getline(stringStrm, lineContent);
				int lineLength = lineContent.length();
				while (a < lineLength) {
					++t;// weve seen a character 
					if (lineContent[a] == '/' && lineContent[a+1] == '/' || lineContent[a] == '/' && lineContent[a + 1] == '*') {
						searchBox->SelectionStart = t;
						searchBox->SelectionLength = lineLength - a;
						searchBox->SelectionColor = commentColor;
					}
					++a;
				}
				++t;
				a = 0; // reset a because we are on the next line. 
			}
		}
		};
}
