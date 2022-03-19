//***********************************************************************************************
// Anagram Solver Challenge
//Author: Fatih Kayali
//This program including all the code is my own work and has been tested fully
// **********************************************************************************************

#include <iostream> //declares the standard devices cin, cout, clog, cerr; 
#include <string> //declares string types and conventions including begin & end iterator; 
#include <algorithm> //declares a collection of ranged functions; 
#include <random> //declares random number generation facilities; 
#include <fstream>//declares a set of standard file stream devices that can be used to to create, read and use files
#include <ctime>//declares a set of functions, macros and types to work with date and time information, e.g. the time() function is used to get the current time
//create a fixed identifier (a bit like an unchangeable global variable) with a string value; the compiler will automatically use the string for each instance of the identifier 
#define cDATAFILE "Words_75K_PreSubmissionTesting.csv" 

using namespace std; //tell the compiler that by default to use the “std” – this means that we don’t need to keep saying “std::cout” we can just use: “cout”

string GetWord(void) 
{ //this function should allow the user to enter a new word that can then be later manipulated
  string localString = ""; //declare and initialise a local string, used to store the new string
  cout << "\nPleae enter a new word or phrase: "; //by not including an end of line the input will be on the same line as the output message
  cin.ignore() ; //this is fors for avoiding over looping and for entering more than one word in to the input 
	getline(cin,localString); //get the input value from the user and store it in the local variable 'localstring'
  
  return localString; //pass the value stored in 'localstring' back to the calling instruction
}

void QuitNow(void) //This function allows user to quit from the program
{
	cout <<"\n\tThank you for using Anagram Solver - please come back soon"; //display a bye message in the end
	exit(EXIT_SUCCESS); //execute the c++ exit function and pass it c++ contant value called EXIT_SUCCESS; EXIT_SUCCESS is actually 0 -
}

string ToLower(string originalString)  //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to convert all of the letters to lowercase
{ 
  string localString = originalString; // declare a local variable called localstring and equalize to originalString
  for(int i=0;i<originalString.length();i++) //should be as same length as the originalString's 
  {
      if(localString[i]>=int('A') && localString[i] <=int('Z'))
      //if the letter is between capital "A" and capital "Z"
      {
        localString[i]=originalString[i]+32; //add 32 ASCII value to that letter's ASCII value, it will convert that letter into lowercase
      }
  }
  return localString; //return the value contained in the localstring local variable
} // as same as Task 1


string OrderWord(string originalString) 
{ //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to order letters in ascending order
  string localString = originalString; // declare a local variable called localstring and equalize to originalString
  int len=originalString.length(); //add an integer for declaring the original string length
  for (int i=0 ; i<len ; i++) 
  {
    for (int j=0 ; j<len;j++)
    {
      if(localString[i]<localString[j]) //compare the value of i and j and sort them
      {
        char tmp = localString[i];
        localString[i]=localString[j];
        localString[j]=tmp;
        
      }
    }
  }
  return localString; //return the value contained in the localstring local variable
 // as same as Task 1
}


void FindAnagrams(string originalString) //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to find and display the anagram words of the entered word
{
  string localString; // declare a variable of type string that can be used to hold each line as the file is

  ifstream dbFile; //create a special variable (actually a class (e.g. object with its own functions) that is defined in the <fstream> header that can be used to "stream" (read) info from files
    
  dbFile.open(cDATAFILE); //use the 'special' variable (object's) method (a.k.a. function) called 'open' with the name of the file to access; in this case use the value defined as cDATAFILE 
    //once opened the computer will put a lock of the file meaning that if someone tries to open 'this' specific file they will be told it is already in use
  
  int matchCount = 0; // declare an integer for counting matchs
  string pOriginalString = originalString;
  pOriginalString = ToLower(pOriginalString); // this is for avoiding capital letters 

  pOriginalString = OrderWord(pOriginalString); // order the letters

  while(!dbFile.eof()) 
  { //this sets up a loop that repeats until we have read every line in the opened file; line by line.
    //lets take a closer look:
    //in essence, "while (TRUE) { do this stuff }"
    //repeats (loops) everything inside the '{' and '}' while this this condition in the "while(TRUE)" is true
    //"dbFile.eof()" is a special method/function similar to "dbFile.open(cDATAFILE)" that returns true or false depending on whether we are at the End of the File (eof)
    //the '!' character is used to logically say "NOT" - in this case the instruction "while(!dbFile.eof()) { ... }" means "repeat this '...' while we are NOT at the end of the file"
          getline(dbFile, localString); //use getline function to access/put the current line of dbFile into the variable 'currentword', 
    
         string pLocalString = localString;
         pLocalString = ToLower(pLocalString);
         pLocalString = OrderWord(pLocalString);
         if (pLocalString==pOriginalString && ToLower
         (originalString)!=ToLower(localString)) //if the letters of the words from source and the entered word is same 
         {
           cout<<"\n "<<localString;
           matchCount++;
         } 
    }
   cout<<"\n\tThey match for "<<matchCount<<" times\n";
   dbFile.close();
}

string FindAnagramsNew(string originalString) //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to find and display the anagram words of the entered word 
//THIS IS FOR FindAll3LetterAnagrams and FindAll5LetterAnagrams
{
  string localString; // declare a variable of type string that can be used to hold each line as the file is

  ifstream dbFile; //create a special variable (actually a class (e.g. object with its own functions) that is defined in the <fstream> header that can be used to "stream" (read) info from files
    
  dbFile.open(cDATAFILE); //use the 'special' variable (object's) method (a.k.a. function) called 'open' with the name of the file to access; in this case use the value defined as cDATAFILE 
    //once opened the computer will put a lock of the file meaning that if someone tries to open 'this' specific file they will be told it is already in use
  string pOriginalString = originalString;
  pOriginalString = ToLower(pOriginalString); // this is for avoiding capital letters 

  pOriginalString = OrderWord(pOriginalString);
  
  string allAnagram=""; // declare a string for searching all anagrams
  
  while(!dbFile.eof()) 
  { //this sets up a loop that repeats until we have read every line in the opened file; line by line.
    //lets take a closer look:
    //in essence, "while (TRUE) { do this stuff }"
    //repeats (loops) everything inside the '{' and '}' while this this condition in the "while(TRUE)" is true
    //"dbFile.eof()" is a special method/function similar to "dbFile.open(cDATAFILE)" that returns true or false depending on whether we are at the End of the File (eof)
    //the '!' character is used to logically say "NOT" - in this case the instruction "while(!dbFile.eof()) { ... }" means "repeat this '...' while we are NOT at the end of the file"
          getline(dbFile, localString); //use getline function to access/put the current line of dbFile into the variable 'currentword', 
    
         string pLocalString = localString;
         pLocalString = ToLower(pLocalString);
         pLocalString = OrderWord(pLocalString);
         if (pLocalString==pOriginalString && ToLower
         (originalString)!=ToLower(localString))
         {
           if(allAnagram=="")
           {
              allAnagram=localString;
           }
           else
           {
             allAnagram=allAnagram+","+localString;
           }
         } 
    }
  dbFile.close(); //close the file
  return allAnagram; // return the value
}

void LargestWordAvailable(string originalString)  //this function is designed to expect one aurgument (called originalString) and returns a string. This function allows user to find and display the largest world possible containig the entered words letter's
{
  string localString; // declare a variable of type string that can be used to hold each line as the file is
  string largestString; //declare a variable for storing the largest word

  ifstream dbFile; //create a special variable (actually a class (e.g. object with its own functions) that is defined in the <fstream> header that can be used to "stream" (read) info from files
    
  dbFile.open(cDATAFILE); //use the 'special' variable (object's) method (a.k.a. function) called 'open' with the name of the file to access; in this case use the value defined as cDATAFILE 
    //once opened the computer will put a lock of the file meaning that if someone tries to open 'this' specific file they will be told it is already in use

    int matchCount= 0; // declare an integer for counting matchs
    int maximumLength= 0; // declare an integer for finding the maximum length word 

    originalString = ToLower(originalString); //to avoid capital letters 

     while(!dbFile.eof()) 
     { //this sets up a loop that repeats until we have read every line in the opened file; line by line.
    //lets take a closer look:
    //in essence, "while (TRUE) { do this stuff }"
    //repeats (loops) everything inside the '{' and '}' while this this condition in the "while(TRUE)" is true
    //"dbFile.eof()" is a special method/function similar to "dbFile.open(cDATAFILE)" that returns true or false depending on whether we are at the End of the File (eof)
    //the '!' character is used to logically say "NOT" - in this case the instruction "while(!dbFile.eof()) { ... }" means "repeat this '...' while we are NOT at the end of the file"
          getline(dbFile, localString); //use getline function to access/put the current line of dbFile into the variable 'currentword', 
   

          int currentMatch=0; // declare an integer for counting matchs
          for(int i=0;i<originalString.length();i++)
           {
             for(int j=0; j<localString.length();j++)
             {
               if(originalString[i]==localString[j]) // if the letters of the word from source and the entered words letters are same 
                {
                  currentMatch = currentMatch+1;
                  break;
                }
             }
           }

           if(currentMatch == maximumLength)
           {
             matchCount++;
           }

           if (currentMatch>maximumLength)
           {
             maximumLength=currentMatch;
             matchCount=1;
             largestString=localString;
           }
    }
    dbFile.close(); // close the file 
    cout<<"\nLargest word available is: "<<largestString;
    cout<<"\t\nMaximum character match: "<<maximumLength;
    cout<<"\t\nTotal word match is: "<<matchCount;
}

void FindAll3LetterAnagrams(void) //this function should allow the user to show every 3 lettered words which has anagrams
{
  string localString; // declare a variable of type string that can be used to hold each line as the file is
  string allAnagrams=""; //declare a variable for searching the all anagrams of word

  ifstream dbFile;
  dbFile.open(cDATAFILE);
 
    while(!dbFile.eof()) 
    {

    getline(dbFile, localString);
      if(localString.length()==3 && allAnagrams.find (localString) == std::string::npos) // if localString's length is equal to 3, find all of the anagrams
      {
       
       string allTmpAnagrams = FindAnagramsNew(localString); 
        if(allTmpAnagrams!="")
        {
          cout<<"\nAnagrams for "<<localString<<": " <<allTmpAnagrams;
          allAnagrams=allAnagrams+","+localString+","+allTmpAnagrams;
        }
      }
  }
}

void FindAll5LetterAnagrams(void) //this function should allow the user to show every 5 lettered words which has anagrams
{
  string localString; // declare a variable of type string that can be used to hold each line as the file is
  string allAnagrams=""; //declare a variable for searching the all anagrams of word

  ifstream dbFile;
  dbFile.open(cDATAFILE);
  
    while(!dbFile.eof()) 
    {

    getline(dbFile, localString);
      if(localString.length()==5 && allAnagrams.find(localString) == std::string::npos)  // if localString's length is equal to 5, find all of the anagrams
      {
       
       string allTmpAnagrams = FindAnagramsNew(localString); 
        if(allTmpAnagrams!="")
        {
          cout<<"\nAnagrams for "<<localString<<": " <<allTmpAnagrams;
          allAnagrams=allAnagrams+","+localString+","+allTmpAnagrams;
        }
      }
  }
}


void ReadFile(void) { //this function reads a specific text filed line by line and displays the result
    string currentWord; //declare a variable of type string that can be used to hold each line as the file is read
    ifstream dbFile; //create a special variable (actually a class (e.g. object with its own functions) that is defined in the <fstream> header that can be used to "stream" (read) info from files
    dbFile.open(cDATAFILE); //use the 'special' variable (object's) method (a.k.a. function) called 'open' with the name of the file to access; in this case use the value defined as cDATAFILE 
    //once opened the computer will put a lock of the file meaning that if someone tries to open 'this' specific file they will be told it is already in use

    while(!dbFile.eof()) { //this sets up a loop that repeats until we have read every line in the opened file; line by line.
    //lets take a closer look:
    //in essence, "while (TRUE) { do this stuff }"
    //repeats (loops) everything inside the '{' and '}' while this this condition in the "while(TRUE)" is true
    //"dbFile.eof()" is a special method/function similar to "dbFile.open(cDATAFILE)" that returns true or false depending on whether we are at the End of the File (eof)
    //the '!' character is used to logically say "NOT" - in this case the instruction "while(!dbFile.eof()) { ... }" means "repeat this '...' while we are NOT at the end of the file"
          getline(dbFile, currentWord); //use getline function to access/put the current line of dbFile into the variable 'currentword', 
   
          cout << endl << currentWord; //sent the output device and newline (start on a new line) and then display the string found in the current position of the file
     }
    //if we are here there the program has read each line until it got to the end of the file
     dbFile.close();//close the connection to the file (otherwise the file will remain locked to other users and this program)
  }

void Menu() 
{ //this function displays the menu to the user
  string currentString="alert"; //declare and initialise the variable to hold the current word ready to be manipulated
  string modifiedString; //declare and initialise the variable to hold the last modified word
  char menuOption; //declare a variable to hold the user's menu choice
  int startTicks, stopTicks; //declare the variables that will be used to hold integer values for the current clock time
  int totalTicks; //declare a variable to hold the total value
  float timeSeconds=0; //declare a floating point variable to hold the converted tick time to seconds
  
  do { //start an endless loop - this is so the associated code block repeats forever
    cout << "\n\nC++ Anagram Solver Challenge " << endl << endl; //display a title for the menu
    cout << "\t1. Enter a word or phrase (current word/phrase is: " << currentString << ")." << endl; //display the current string 
		cout << "\t2. Find an anagram of the word." << endl;
    cout << "\t3. Find the largest word containing (most of) these letters." << endl;
    cout << "\t4. Find all possible 3 letter words that are also anagrams." << endl;
    cout << "\t5. Find all possible 5 letter words that are also anagrams." << endl;
    
		cout << "\n\t0. Quit the program." << endl;
    //cout<<"\n\tUnfortunately ‘ "<<menuOption<<" ’  is not a valid option, please try again.";
    cout << "\n\tTime taken to complete the last function was: " << timeSeconds  <<" ms " << endl;
    
    cout << "\nPlease enter a valid option (1 – 5 or 0 to quit):  ";
    cin >> menuOption; //store the choice made by the user in the variable menuOption
    startTicks=clock(); //get the number of clock ticks consumed by the processor since the program started
    switch(menuOption) 
    { //a 'switch' statement is similar to multiple if's.

      case '1': //this basically "if the menuOption = 1", option 1 should call the function GetWord() 
        cout<<"\033c"; //Clear Linux console, it is a displaying option.I just wanted to show the user a clear page when the user wants to enter a word
        
        currentString = GetWord(); //call the function and store any returned value in the local variable currentString
        
        break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
        
      case '2': //this basically "if the menuOption = 2", option 2 should call the function FindAnagrams() 
       
       FindAnagrams(currentString); //call the function and store any returned value in the local variable currentString
       
       break;  //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
     
      case '3': //this basically "if the menuOption = 3", option 3 should call the function LargestWordAvailable()

      LargestWordAvailable(currentString); //call the function and store any returned value in the local variable currentString

      break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
       
      case '4': //this basically "if the menuOption = 4", option 4 should call the function FindAll3LetterAnagrams()

      FindAll3LetterAnagrams(); // activate the function FindAll3LetterAnagrams

      break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
      

      case '5': //this basically "if the menuOption = 5", option 5 should call the function FindAll5LetterAnagrams()

       FindAll5LetterAnagrams(); // activate the function FindAll5LetterAnagrams

      break; //this keyword is optional, however, if not used all the following "cases" are automatically true and the instructions will all be executed
      
      case '0': //this basically "if the menuOption = 0", option 0 should call the function QuitNow
      {  
        string decision; //declare a variable for creating decision
        cout<<"\n\tAre you sure (Y/N)?\n";
        cin>>decision;
          if (decision == "Y") {
            
            QuitNow();
          }
          if (decision == "y") {
            
            QuitNow();
          }
          if (decision == "Yes") {
            
            QuitNow();
          }
          // if decisionis "Y,y ore Yes" it calls the function QuitNow() and the program ends
          else
          {
            Menu();
          }
          // if decisionis not "Y,y ore Yes" programmoves on
        break;
      }
      default: //if the user enters a non-valid option this default message will display
        cin.ignore() ;
        cout<<"\n\tUnfortunately ‘ "<<menuOption<<" ’  is not a valid option, please try again.";
    }
    
    stopTicks=clock(); //get the number of clock ticks consumed by the processor since the program started; more times will have happened since we last took the time
    totalTicks = stopTicks - startTicks; //work out the difference in ticks
    timeSeconds = totalTicks/double(CLOCKS_PER_SEC) * 1000;//convert the ticks into mili seconds
    cout << endl << endl << "The System Took: " << timeSeconds << " miliseconds to complete the operation!" << endl;

  } while(true); //this tells the computer the conditions to break the "do" loop - while true is always true and therefore will continue forever; in essence and endless loop
}

int main() 
{ //this is the required function that will automatically execute when the program is run
  Menu(); //start the program menu function
}

int startTicks, stopTicks; //declare the variables that will be used to hold integer values for the current clock time
int totalTicks; //declare a variable to hold the total value
float timeSeconds; //declare a floating point variable to hold the converted tick time to seconds


//TEST LOG
//
//GetWord has added, works fine because it is same as Task 1
//
//QuitNow has added, works fine because it is same as Task 1
//Decisions for QuitNow has added,works fine
//
//FindAnagram has added,works fine but it doesn`t work when entering capital letters
//Problem has solved by adding ToLower function from the first task, now compiler always gets the lowercase words
//
//After the anagram displayed, compiler also displays and asks user to "Are you sure" from the QuitNow function, which is unnecessary
//Problem solved by adding the "break" in the case part
//
//My find all 3 possible words that are also anagrams function //does not work properly,I need to change my code for 
//FindAnagrams but if I change it everything is effected in bad //way.
//Problem has solved by addin a FindAnagramsNew function it is //exactly the same as FindAnagrams only difference is string allAnagram
//
//It also shows the same words anagram's again and again for //example it shows the anagram of the care than it shows the //anagrams of the race, with 75k words it is reduncancy
//Problem has solved by adding allAnagrams.find(localString) == std::string::npos added for avoiding showing the same words
//
//FindAll5LetterAnagrams works just fine beacuse it is exactly the same as FindAll3LetterAnagrams, just localString.length()//==5 part is different
//
//All necessary comments has added
//
//Unnecessary functions, variables and comments has deleted.