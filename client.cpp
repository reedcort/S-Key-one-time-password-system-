/* 
*Initializes plain text password and prints one-time password.
 *
 * Compile as follows: g++ -o client client.cpp -O3 -Wall -std=c++11 -lm -I
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
#include <sstream>
#include <set>
#include <iterator>
#include "header.h"
using namespace std;

char passwd [256];
char word;
const char *orginal_passwd;
int active (0);
string option;
string new_passwd;
set<string> setOfhashs;

int main(){
    cout <<"\n";
    cout << "Welcome to  S/KEY:"<<endl;
    while(active == 0){
        
        cout <<"\t1.) To initialize your plaintext password enter 1: "<<endl
        <<"\t2.) To get new onetime password enter 2: "<<endl
        <<"\n" 
        <<"Please enter 1 or 2: ";
        getline(cin, option);
        int num=0;
        
        stringstream(option) >> num;
        ifstream file("expired.txt");
        copy(istream_iterator<string>(file),istream_iterator<string>(),inserter(setOfhashs, setOfhashs.end()));
        
        switch (num){
            case 1:{
                cout << "Type your plaintext password: ";
                cin.getline(passwd,256);
                cout <<"\n";

                if (strlen(passwd) == 0 ){
                    cout << "Password cannot be empty"<< endl<<endl;
                    continue;
                }
                else
                {
                    int loop= 0;
                    while (loop == 0)
                    {
                        new_passwd = generate_hash(passwd);

                        set<string>::iterator it = setOfhashs.find(new_passwd);
                        if(it != setOfhashs.end()){
                            continue;
                        }
                        else{
                            setOfhashs.insert(new_passwd);
                            cout << "Your one-time password is: " << new_passwd << endl;
                            cout <<"\n";
                            loop = 1;
                        }      
                    }
                    writeFile(new_passwd,storage);
                    writeFile(new_passwd,expired);
                    writeFile(passwd,initial_pass);
                    exit(1);
                }    
            }
            case 2:{
                int loop= 0;
                 if (is_file_exist(storage) ==0 || is_file_exist(expired) ==0 || is_file_exist(initial_pass) == 0)
                {
                    cout <<"\n";
                    cout << "Missing one or more files, please initialize a new plain text password"<<endl;
                    cout <<"\n";
                    continue;
                }

                while (loop == 0)
                {
                    orginal_passwd = readFile(initial_pass).c_str();
                    new_passwd = generate_hash(orginal_passwd);
                    set<string>::iterator it = setOfhashs.find(new_passwd);
                    if(it != setOfhashs.end()){
                        continue;
                    }
                    else{
                        setOfhashs.insert(new_passwd);
                        cout <<"\n";
                        cout << "Your one-time password is: " << new_passwd << endl;
                        cout <<"\n";
                        loop = 1;
                    }      
                writeFile(new_passwd,storage );
                appendFile(new_passwd,expired);
                exit(1);
                }
            }
            default:
                cout <<"\n";
                cout << "Error: Please enter either 1 or 2"<<endl;
                cout <<"\n";
                continue;
            }
    }
    return 0;
}


