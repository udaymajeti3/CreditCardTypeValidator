#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

bool isValidAmex(const string& ccNumber) {
    return (ccNumber.length() == 15 && (ccNumber.substr(0, 2) == "34" || ccNumber.substr(0, 2) == "37"));
}

bool isValidDiners(const string& ccNumber) {
    string prefix = ccNumber.substr(0, 2);
    return (ccNumber.length() == 15 && (prefix == "30" || prefix == "36" || prefix == "38") || (prefix >= "300" && prefix <= "303"));
}

bool isValidDiscover(const string& ccNumber) {
    return (ccNumber.length() == 16 && ccNumber.substr(0, 4) == "6011");
}

bool isValidEnroute(const string& ccNumber) {
    string prefix = ccNumber.substr(0, 4);
    return (ccNumber.length() == 16 && (prefix == "2014" || prefix == "2149"));
}

bool isValidJcb15(const string& ccNumber) {
    return (ccNumber.length() == 16 && (ccNumber.substr(0, 4) == "2100" || ccNumber.substr(0, 4) == "1800"));
}

bool isValidJcb16(const string& ccNumber) {
    string prefix = ccNumber.substr(0, 4);
    return (ccNumber.length() == 16 && (prefix == "3088" || prefix == "3096" || prefix == "3112" || prefix == "3158" || prefix == "3337" || prefix == "3528"));
}

bool isValidMastercard(const string& ccNumber) {
    string prefix = ccNumber.substr(0, 2);
    return (ccNumber.length() == 16 && (prefix >= "51" && prefix <= "55"));
}

bool isValidVisa(const string& ccNumber) {
    string prefix = ccNumber.substr(0, 1);
    return (ccNumber.length() == 13 || ccNumber.length() == 16) && (prefix == "4" || ccNumber.substr(0, 4) == "4024" || ccNumber.substr(0, 4) == "4916" || ccNumber.substr(0, 4) == "4539" || ccNumber.substr(0, 4) == "4556" || ccNumber.substr(0, 4) == "4532" || ccNumber.substr(0, 4) == "4929" || ccNumber.substr(0, 4) == "4485" || ccNumber.substr(0, 4) == "4716");
}

bool isValidVoyager(const string& ccNumber) {
    return (ccNumber.length() == 13 || ccNumber.length() == 16) && ccNumber.substr(0, 4) == "8699";
}

bool isValidRupay(const string& ccNumber) {
    return (ccNumber.length() == 16 && ((ccNumber.substr(0, 2) == "65") ||(ccNumber.substr(0, 2) == "35") ||(ccNumber.substr(0, 2) == "60") || (ccNumber.substr(0, 4) == "6521") || (ccNumber.substr(0, 4) == "6522")));
}

string getCardType(const string& ccNumber) {
    if (isValidAmex(ccNumber)) return "American Express";
    if (isValidDiners(ccNumber)) return "Diners";
    if (isValidDiscover(ccNumber)) return "Discover";
    if (isValidEnroute(ccNumber)) return "Enroute";
    if (isValidJcb15(ccNumber)) return "JCB 15";
    if (isValidJcb16(ccNumber)) return "JCB 16";
    if (isValidMastercard(ccNumber)) return "MasterCard";
    if (isValidVisa(ccNumber)) return "Visa";
    if (isValidVoyager(ccNumber)) return "Voyager";
    if (isValidRupay(ccNumber)) return "RuPay";
    return "Unknown";
}

bool isNumberString(const string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] < '0' || s[i] > '9')
            return false;
    }
    return true;
}

int main() {
    string ccNumber;
    
    cout << "You can enter 'exit' anytime to quit." << endl;
    
    while (true) {
        
        cout << "Please enter a CC number to validate: ";
        cin >> ccNumber;
        
        if (ccNumber == "exit")
            break;
        
        else if (!isNumberString(ccNumber)) {
            cout << "Invalid input! "<<endl;
            continue;
        }
            
        int len = ccNumber.length();
        int doubleEvenSum = 0;

        for (int i = len - 2; i >= 0; i = i - 2) {
            int dbl = (stoi(string(1,ccNumber[i])) * 2); // Currently each number is in Char so we use stoi of string to change string to int
            if (dbl > 9) {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }
        for (int i = len - 1; i >= 0; i = i - 2) {
            doubleEvenSum += (ccNumber[i] - 48);
        }

        string cardType = getCardType(ccNumber);
        if(doubleEvenSum % 10 == 0){
            if (cardType=="MasterCard"){
                cout<<"Valid "<<cardType<<endl;
            }
            else{
                cout<<"Valid "<<cardType<<" Card"<<endl;
            }
        }
        else{
            cout<<"Invalid Card"<<endl;
        }
       
        continue;        
    }

    return 0;
}
