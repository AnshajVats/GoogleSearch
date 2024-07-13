#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;


bool isvalidcc(const string&);
bool checkCreditCardNumber(const string& cc);
bool ValidatingCreditCardNumber(const string& cc);
void twoMultiplication(vector<int>& digit);
int sumOfEven(vector<int>& digit);
int sumOfOdd(vector<int>& digit);

int main()
{
	//
	// PLEASE DO NOT CHANGE function main
	//
	vector<string> cardnumbers = {
		 "371449635398431", "4444444444444448", "4444424444444440", "4110144110144115",
		"4114360123456785", "4061724061724061", "5500005555555559", "5115915115915118",
		"5555555555555557", "6011016011016011", "372449635398431", "4444544444444448",
		"4444434444444440", "4110145110144115", "4124360123456785", "4062724061724061",
		"5501005555555559", "5125915115915118", "5556555555555557", "6011116011016011",
		 "372449635397431", "4444544444444448", "4444434444544440", "4110145110184115",
		"4124360123457785", "4062724061724061", "5541005555555559", "5125115115915118",
		"5556551555555557", "6011316011016011"
	};

	int i;
	vector<string>::iterator itr;

	for (i = 1, itr = cardnumbers.begin(); itr != cardnumbers.end(); ++itr, i++) {
		cout << setw(2)  << i << " " 
			 << setw(17) << *itr 
			 << ((isvalidcc(*itr)) ? " is valid" : " is not valid") << endl;
	}

	return 0;
}

bool isvalidcc(const string& cc) {
    return checkCreditCardNumber(cc);
}

bool checkCreditCardNumber(const string& cc) {
    int sum = 0;
    int length = static_cast<int>(cc.length());
    bool validNumber;
    if (length >= 13 && length <= 16 && cc[0] == '4' || cc[0] == '5' || cc[0] == '6' || (cc[0] == '3' && cc[1] == '7')) {
        validNumber = true;
    }

    validNumber = ValidatingCreditCardNumber(cc);

    return validNumber;
}

bool ValidatingCreditCardNumber(const string& cc) {

    int length = static_cast<int>(cc.length());
    int evenSum = 0;
    int oddSum = 0;
    vector<int> numbers;
    for (int i = length - 1; i >= 0; i--) {
        int digit = cc[i] - '0';
        numbers.insert(numbers.begin(), digit);
    }
    twoMultiplication(numbers);
    evenSum = sumOfEven(numbers);
    oddSum = sumOfOdd(numbers);
    return (evenSum + oddSum) % 10 == 0;
}

void twoMultiplication(vector<int>& digit) {
    int sum = 0;
    int length = static_cast<int>(digit.size());
    int doubleDigit = 1;

    for(int i = length - 2; i >= 0; i -= 2) {
        digit[i] *= 2;
        if (digit[i] > 9) {
            digit[i]  = digit[i]/10 + digit[i] % 10;
        }
    }
}

int sumOfEven(vector<int>& digit) {
    int sum = 0;
    for (int i = 0; i < digit.size(); i ++) {
        if((i & 1) == 0)sum += digit[i];
    }
    return sum;
}

int sumOfOdd(vector<int>& digit) {
    int sum = 0;
    int length = static_cast<int>(digit.size());
    for(int i = length; i >= 0; i--) {
        if((i & 1) != 0)sum += digit[i];
    }
    return sum;
}
