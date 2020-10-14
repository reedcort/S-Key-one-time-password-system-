#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string expired= "expired.txt";
string storage = "storage.txt";
string initial_pass = "initial_pass.txt";

void appendFile(string text, string fileName){
    ofstream f;
    f.open (fileName,ios_base::app);
    f << text << endl;
    f.close();
}
void writeFile(string text, string fileName)
{
    ofstream f;
    f.open (fileName);
    f << text << endl;
    f.close();
}

bool is_file_exist(string fileName)
{
    ifstream infile(fileName);;
    return infile.good();
}
string readFile(string fileName)
{
    string orginal_passwd;
    fstream f;
    f.open(fileName,ios::in);
    string tp;
    while(getline(f, tp)){ 
        orginal_passwd = tp;   
      }
    f.close();  
    return orginal_passwd;

}
string generate_hash(const char *key){
    hash<const char*> ptr_hash;
    string new_passwd = to_string(ptr_hash(key));
    return new_passwd;
}