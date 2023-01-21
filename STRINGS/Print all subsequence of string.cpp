// C++ program for the above approach
//method 1(pick and don't pick concept)

#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void printSubsequence(string input, string output)
{
	// Base Case
	// if the input is empty print the output string
	if (input.empty()) {
		cout << output << endl;
		return;
	}

	// output is passed with including
	// the Ist character of
	// Input string
	printSubsequence(input.substr(1), output + input[0]);

	// output is passed without
	// including the Ist character
	// of Input string
	printSubsequence(input.substr(1), output);
}

// Driver code
int main()
{
	// output is set to null before passing in as a
	// parameter
	string output = "";
	string input = "abcd";

	printSubsequence(input, output);

	return 0;
}

// method 2(using binary representation of numbers to create subsequence)

// Implementation :

// 1. We take the string as input.

// 2. We declare a vector of strings to store each sub-sequence as a string.

// 3. Each time call the function with 1,2,3 and so on and we only push those indexes in our string whose bit is set and we keep incrementing our index pointer.

// 4. Once we have generated the corresponding sub-sequence for a binary representation we can push this string into our vector of strings.

// 5. Finally we can print our vector of strings and get the desired output.

// C++


#include<bits/stdc++.h>
using namespace std;

string print(string s , int i){
	int j = 0;
	string sub;
	
	//finding where the bit is set
	while(i>0){
		if(i & 1){
			sub.push_back(s[j]); //pushing only when bit is set
		}
		j++; //always incrementing the index pointer
		i = i >> 1;
	}
	
	return sub;
}

vector<string> createsubsets(string& s){
	
	vector <string> res;
	for(int i = 1 ; i <= ((1 << s.size()) - 1) ; i++){
		//each time we create a subsequence for corresponding binary representation
		res.push_back(print(s,i));
	}
	return res;
}

int main(){
	string s = "abcd";
	//vector of strings to store all sub-sequences
	vector <string> print = createsubsets(s);
	
	//print function
	for(int i = 0 ; i < print.size() ; i++){
		for (int j = 0; j < print[i].size(); j++){
			cout << print[i][j]<<" ";
		}
		cout << endl;
	}
	return 0;
}

