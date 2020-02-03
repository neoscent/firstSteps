// Made by Neoscent
// 3.2.20 (dd.mm.yyyy)
// IDE: Codeblocks & XCode
// GNU GCC Compiler

/*
 
 /////// Morse Translator /////////
 
 I did this mainly out of boredom, but turned out a pretty cool project to do as a starter.
 So in this version i'm gonna call 1.0, all you can do is:
        1.- Translate a text from a file (named "textIn.txt") to morse code.
        2.- Translate morse code from a file (named "morseIn.txt") to normal text.
 
 Only the basics are translated: English alphabet from A to Z, and punctuation ',' & '.'
 Blank space is translated as '/' into morse, and backwards is translated as a tab.
 
 I didn't expect anyone to see this .cpp, but if, for any reason, you found it, I hope you can give
 me some feedback on it, I would really appreciate it!
 
 I'm looking forward to improve this, adding characters like cyrillic alphabet for example, more
 punctuation. And along with this, adding other stuff, such as translating this program.
 
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void toMorse();
void fromMorse();
void menu();
void pause();
char whichLetter(char* dotBar, int i);

int main(){
    menu();
    return 0;
}

void menu(){
    int option;
    while(option!=3){
        cout << "WELCOME TO MORSE TRANSLATOR!" << endl;
        cout << "\t(1) Text to Morse" << endl;
        cout << "\t(2) Morse to Text" << endl;
        cout << "\t(3) Exit " << endl;
        cout << "Enter an option: ";
        cin >> option;
        system("clear");
        if(option==3)
            exit(1);
        if(option==1){
            toMorse();
        }
        else if(option==2){
            fromMorse();
        }
        else{
            cout << "Invalid option, try again." << endl;
            pause();
            system("clear");
        }
    }
}
void toMorse(){
    char letter;
    ifstream inFile;
    ofstream outFile;
    inFile.open("textIn.txt");
    outFile.open("textOut.txt");
    if(!inFile.fail()){
        cout << "Hold on, I'm reading and writing..." << endl;
        inFile.get(letter);
        while(!inFile.eof()){
            letter = tolower(letter);
            switch (letter){
            case 'a':
                outFile<<"._ ";
                break;
            case 'b':
                outFile<<"_... ";
                break;
            case 'c':
                outFile<<"_._. ";
                break;
            case 'd':
                outFile<<"_.. ";
                break;
            case 'e':
                outFile<<". ";
                break;
            case 'f':
                outFile<<".._. ";
                break;
            case 'g':
                outFile<<"__. ";
                break;
            case 'h':
                outFile<<".... ";
                break;
            case 'i':
                outFile<<".. ";
                break;
            case 'j':
                outFile<<".___ ";
                break;
            case 'k':
                outFile<<"_._ ";
                break;
            case 'l':
                outFile<<"._.. ";
                break;
            case 'm':
                outFile<<"__ ";
                break;
            case 'n':
                outFile<<"_. ";
                break;
            case 'o':
                outFile<<"___ ";
                break;
            case 'p':
                outFile<<".__. ";
                break;
            case 'q':
                outFile<<"__._ ";
                break;
            case 'r':
                outFile<<"._. ";
                break;
            case 's':
                outFile<<"... ";
                break;
            case 't':
                outFile<<"_ ";
                break;
            case 'u':
                outFile<<".._ ";
                break;
            case 'v':
                outFile<<"..._ ";
                break;
            case 'w':
                outFile<<".__ ";
                break;
            case 'x':
                outFile<<"_.._ ";
                break;
            case 'y':
                outFile<<"_.__ ";
                break;
            case 'z':
                outFile<<"__.. ";
                break;
            case ' ':
                outFile<<"/ ";
                break;
            case '\n':
                outFile<<"\n";
                break;
            case ',':
                outFile<<"__..__ ";
                break;
            case '.':
                outFile<<"._._._ ";
                break;
            }
            inFile.get(letter);
        }
    cout << "File ready! Enjoy." << endl;
    pause();
    system("clear");
    }
    else{
        cout << "File not found. Make sure: \n1.- it's in the right directory." << endl;
        cout << "2.- It is named as 'morseIn.txt'" << endl;
        pause();
        system("clear");
    }
}

void fromMorse(){
    char donut, dotBar[6];
    int i;
    ifstream inFile;
    ofstream outFile;
    inFile.open("morseIn.txt");
    outFile.open("morseOut.txt");
    if(!inFile.fail()){
        cout << "Hold on, I'm decoding..." << endl;
        while(!inFile.eof()){
            i=-1;
            do{
                if(!inFile.eof())
                    inFile.get(donut);
                if(donut!=' '){
                    i++;
                    dotBar[i]=donut;
                }
            }while(!inFile.eof()&&donut!=' ');
            if(!inFile.eof()){
                donut=whichLetter(dotBar, i);
                outFile << donut;
            }
        }
        cout << "File ready! Enjoy." << endl;
        pause();
        system("clear");
    }
    else
        cout << "File not found: Make sure it exist!" << endl;
}

char whichLetter(char* dotBar, int i){
    if(dotBar[i]=='/')
        return '\t';
    if(dotBar[i]=='.'){
        if(!i)// .
            return 'e';
        else{ //x.
            i--;
            if (dotBar[i]=='.'){ // x..
                if (!i) //..
                    return 'i';
                else{ // x..
                    i--;
                    if (dotBar[i]=='.'){ //...
                        if (!i)
                            return 's';
                        i--;
                        if (dotBar[i]=='.') //....
                            return 'h';
                        else //_...
                            return 'b';
                    }
                    else if (dotBar[i]=='_'){//x_..
                        if (!i) // _..
                            return 'd';
                        else{
                            i--;
                            if (dotBar[i]=='.')// ._..
                                return 'l';
                            else //__..
                                return 'z';
                        }
                    }
                }
            }
            else if (dotBar[i]=='_'){ // x_.
                if (!i) // _.
                    return 'n';
                else{
                    i--;
                    if(dotBar[i]=='.'){// x._. //midnight driving 50:50
                        if (!i) //._.
                            return 'r';
                        else{ //x._.
                            i--;
                            if (dotBar[i]=='.') //.._.
                                return 'f';
                            else //_._.
                                return 'c';
                        }
                    }
                    else{ // x__.
                        if (!i)
                            return 'g';
                        else
                            return 'p';
                    }
                }
            }
        }
    }
    else if (dotBar[i]=='_'){//x_
        if(!i) // _
            return 't';
        else{ // x_
            i--;
            if (dotBar[i]=='.'){ //x._
                if (!i) //._
                    return 'a';
                else{ //x._
                    i--;
                    if (dotBar[i]=='.'){//x.._
                        if (!i) //.._
                            return 'u';
                        else{ //x.._
                            i--;
                            if (dotBar[i]=='.')
                                return 'v';
                            else
                                return 'x';
                        }
                    }
                    else {//x_._
                        if (!i)
                            return 'k';
                        else{
                            i--;
                            if (dotBar[i]=='_')
                                return 'q';
                            else
                                return '.';
                        }
                    }
                }
            }
            else{//x__
                if (!i) //__
                    return 'm';
                else{ //x__
                    i--;
                    if (dotBar[i]=='.'){//x.__
                        if (!i) //.__
                            return 'w';
                        else{ //x.__
                            i--;
                            if (dotBar[i]=='.')
                                return ',';
                            else
                                return 'y';
                        }
                    }
                    else{ // x___
                        if (!i)
                            return 'o';
                        else
                            return 'j';
                    }
                }
            }
        }
    }
    return '#';
}

void pause(){
    cout << "Press enter to continue..." << endl;
    cin.get();
    cin.get();
}
