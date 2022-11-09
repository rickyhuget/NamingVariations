#include <cmath>
//#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string split(string input) {
    if ((input[4] >= 'A') && (input[4] <= 'Z')) { // if upper case
        input[4] = input[4] + 32; // to lower case
    }
    
    // iterate through input to add spaces and make lower cases
    for (int i = 5; i < input.length(); i++) {
        if ((input[i] >= 'A') && (input[i] <= 'Z')) {
            input[i] = input[i] + 32; // make lower case
            input.insert(i, " "); // add space
        }
    }
    if (input[2] == 'M') { // if method
        input = input.substr(0, input.length()-2); // take "()" off
    }
    
    return input.substr(4, input.length()-4);
}

string combine(string input) {
    if (input[2] == 'C') { // if class
        input[4] = input[4] - 32; // make upper case
    }
    
    // iterate thru input to delete spaces and make camel case
    for (int i = 5; i < input.length(); i++) {
        if (input[i] == ' ') { // if space
            input.erase(i, 1); // erase one element
            input[i] = input[i] - 32; // make upper case
        }
    }
    
    if (input[2] == 'M') { // if method
        input = input + "(" + ")"; // add parentheses
    }
    
    return input.substr(4, input.length()-4);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string input;
    //int iter = 0;
    while (getline(cin, input)) {
        if (input[0] == 'S') {
            input = split(input);
        }
        if (input[0] == 'C') {
            input = combine(input);
        }
        
        cout << input << endl;
        //iter++;
    };
    
    return 0;
}