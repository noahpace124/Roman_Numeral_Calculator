//includes
#include <iostream>
#include <string>
using namespace std;

//function declarations
int RomanNumeralToValue(char input);

//main
int main() {
	//variable declarations
	bool quit = false;

	while (!quit) {
		//loop variable declarations
		bool display = true;
		int output = 0;
		string input;

		//getting roman numeral input
		cout << "Enter Roman Numerals (or \"quit\"): " << endl;
		cout << ">> ";
		getline(cin, input);

		if (input != "quit") { //if quit was not inputted
			//updating output
			for (int i = 0; i < input.size(); i++) {
				if (RomanNumeralToValue(input.at(i)) == -1) { //if the given input value is not a valid roman numeral, then output error and don't display results
					cout << "Invalid Input: " << input.at(i) << endl;
					display = false;
					break;
				}
				if ((i + 1) < input.size()) { //if the given input value has a following value, proceed through the following conditions
					if (RomanNumeralToValue(input.at(i)) < (RomanNumeralToValue(input.at(i + 1))/(10))) { //if the given input value is less than 1/10th of the following input value, then output error and don't display results
						cout << "Invalid Input: " << input.at(i) << " is less than 1/10th of " << input.at(i + 1) << endl;
						display = false;
						break;
					}
					if (RomanNumeralToValue(input.at(i)) < RomanNumeralToValue(input.at(i + 1))) { //if the given input value is less than the following input value, then subtract and add them to output
						output += (RomanNumeralToValue(input.at(i + 1)) - RomanNumeralToValue(input.at(i)));
						i++;
					}
					else { //if the given input value is not less than the following input value, then add it to output
						output += RomanNumeralToValue(input.at(i));
					}
				}
				else { //if the given input value has no following input value, then add it to output
					output += RomanNumeralToValue(input.at(i));
				}
			}
			if (display) { //read out output value
				cout << "Total Value: " << output << endl;
			}
			cout << endl;
		}
		else { //quit was inputted
			quit = true;
		}
	}

	return 0;
}

//function definitions
int RomanNumeralToValue(char input) { //returns the given roman numeral's value if its valid
	if (input == 'I') { return 1; }
	else if (input == 'V') { return 5; }
	else if (input == 'X') { return 10; }
	else if (input == 'L') { return 50; }
	else if (input == 'C') { return 100; }
	else if (input == 'D') { return 500; }
	else if (input == 'M') { return 1000; }
	else { return -1; } //not a valid input value
}