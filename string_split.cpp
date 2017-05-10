#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> string_split(string s, char delim){
    vector<string> v;
    stringstream ss(s);
    string token;
    while(getline(ss, token, delim)){
        v.push_back(token);
    }

    return v;
}


int main(){
    string s = "I want to split this string by space";
    char delim = ' ';
    vector<string> v = string_split(s,delim);
    for(auto x:v){
        cout<<x<<endl;
    }
}
