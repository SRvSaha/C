//
//   @author      : SRvSaha
//   Filename     : string_to_int.cpp
//   Timestamp    : 13:30 10-May-2017 (Wednesday)
//   Description  : Conversion of String to Integer
//


#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

long string_to_int(string s){
    stringstream ss;
    long result;
    ss<<s;
    ss>>result;
    return result;
}

int main(){
    string s = "10000000024";
    long result = string_to_int(s);
    cout<<result<<endl;
    printf("%ld\n",result);
}
