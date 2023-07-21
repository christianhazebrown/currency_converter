#include <iostream>
#include <currency.h>
#include <unistd.h>
#include <curl/curl.h>
using namespace std;

//Main function only entry point for the program
int main(int argc, char** argv){
    Currency c;                 // init Currency header file
    cout.precision(4);          
    int choice;
    cout << "Enter what currency you would like to convert:\n 1) Dollars\n 2) Euros\n" << endl;
    try{
        cin >> choice;
        if(choice == 0){
            throw exception();
        }
    }catch(const exception& e) {cout << "Please enter a valid number." << endl;};
    return 0;
}