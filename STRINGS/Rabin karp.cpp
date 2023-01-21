// This is simple mathematics, we compute the decimal value of the current window from the previous window. 
// Example: pattern length is 3 and string is “23456” 
// You compute the value of the first window (which is “234”) as 234. 
// How will you compute the value of the next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.

// Follow the steps mentioned here to implement the idea:


// Initially calculate the hash value of the pattern.
// Start iterating from the starting of the string:
// Calculate the hash value of the current substring having length m.
// If the hash value of the current substring and the pattern are same check if the substring is same as the pattern.
// If they are same, store the starting index as a valid answer. Otherwise, continue for the next substrings.
// Return the starting indices as the required answer.
// Below is the implementation of the above approach:

// The average and best-case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm) and S.C O(1)

/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}

			// if p == t and pat[0...M-1] = txt[i, i+1,
			// ...i+M-1]

			if (j == M)
				cout << "Pattern found at index " << i
					<< endl;
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			// We might get negative value of t, converting
			// it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

/* Driver code */
int main()
{
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";

	// we mod to avoid overflowing of value but we should
	// take as big q as possible to avoid the collison
	int q = INT_MAX;

	// Function Call
	search(pat, txt, q);
	return 0;
}

// This is code is contributed by rathbhupendra



