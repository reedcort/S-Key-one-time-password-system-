/* 
*Authenticates one-time password.
 *
 * Compile as follows: g++ -o server server.cpp -O3 -Wall -std=c++11 -lm -I
 *
 * Author: Cortney Reed
 * Date created: April 19, 2020
 *
 *
 */

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <iterator>
#include "header.h"
using namespace std;

int active (0);
string passwd;
set<string> setOfhashs;


int main(){
    cout <<"\n";
    cout << "Welcome to the server!"<<endl;
    cout << "Enter one-time password to login: ";
    getline(cin, passwd);
    cout <<"\n";

    ifstream file(storage);
    copy(istream_iterator<string>(file),istream_iterator<string>(),inserter(setOfhashs, setOfhashs.end()));

    set<string>::iterator it = setOfhashs.find(passwd);
    if(it != setOfhashs.end()){
        cout << "SUCCESSFULLY AUTHENTICATED"<< endl;
        cout <<"\n";
        writeFile("",storage);
        exit(1);
    }
    else{
         cout << "FAILED TO AUTHENTICATE"<< endl;
         cout <<"\n";
    }
    return 0;
}