/*
        Time Complexity: O(M * N)
        Space complexity:O(M + N)

        Where 'M' denotes the length of the string 'text' and 'N' denotes the length of string 'pattern'.
*/

// bad match table (method 1)

#include<string.h>

vector<int> patternSearch(string text, string pattern) {
    int sizeOfAlphabet = 256;
    int n = pattern.size();
    int m = text.size();

    vector<int>ans;
    int preComputed[sizeOfAlphabet];
    char textArray[m + 1];
    strcpy(textArray, text.c_str());
    char patternArray[n + 1];
    strcpy(patternArray, pattern.c_str());


    // Initialize all occurrences as -1  
    for (int i = 0; i < sizeOfAlphabet; i++){
        preComputed[i] = -1;  
    }

    // Precomputation for bad characters heuristic
    for(int i = 0; i < n; i++) {
        preComputed[(int)patternArray[i]] = i;
    }

    // 'skip' is skip of the pattern with respect to text
    int skip = 0;

    while(skip <= (m - n)){
        int j = n - 1;

        
        // Keep decreasing skip j of pattern while characters of pattern and text are
        // matching at the shift skip 
        
        while(j >= 0 and patternArray[j] == textArray[skip + j]) {
            j--;
        }

        // If the pattern is found then we will get a negative j
        if(j < 0) {
            ans.push_back(skip);

            // Shift the pattern as discussed so that last occurence in pattern matches with text
            if((skip + n) < m) {
                skip += n - preComputed[textArray[skip + n]];
            }

            else {
                skip += 1;
            }
        }

        else {
            
            // Shift to align bad character
            skip += max(1, j - preComputed[textArray[skip + j]]);
        }
    }

    // If the pattern is not found
    if(ans.size() == 0) {
        ans.push_back(-1);
    }

    return ans;
}

//Good Suffix heuristic(method 2)

/*
        Time Complexity: O(M * N)
        Space complexity:O(M + N)

        where M denotes the length of the string text and 
        N denotes the length of string pattern.
*/

#include<string.h>

// PreComputation for strong good suffix rule
void preComputeStrongSuffix(int skip[], int endBorders[], char patternArray[], int n) {
    int i = n, j = n + 1;
    endBorders[i] = j;

    while (i > 0) {

        while (j <= n && patternArray[i - 1] != patternArray[j - 1]) {

            if (skip[j] == 0) {
                skip[j] = j - i;
            }

            j = endBorders[j];
        }

        i--;
        j--;
        endBorders[i] = j;
    }
}

// PreComputation for case 2
void preComputeSecondCase(int skip[], int endBorders[], char patternArray[], int n) {
    int i, j;
    j = endBorders[0];
    for (i = 0; i <= n; i++) {

        if (skip[i] == 0) {
            skip[i] = j;
        }

        if (i == j) {
            j = endBorders[j];
        }
    }
}

vector<int> patternSearch(string text, string pattern) {
    int index = 0, j;
    int n = pattern.size();
    int m = text.size();

    char textArray[m + 1];
    strcpy(textArray, text.c_str());
    char patternArray[n + 1];
    strcpy(patternArray, pattern.c_str());
    int endBorders[n + 1];
    int skip[n + 1];

    vector <int> ans;

    for (int i = 0; i < n + 1; i++) {
        skip[i] = 0;
    }

    // PreCompute for both the cases
    preComputeStrongSuffix(skip, endBorders, patternArray, n);
    preComputeSecondCase(skip, endBorders, patternArray, n);

    while (index <= m - n) {
        j = n - 1;
        
        // Keep decreasing skip j of pattern while characters of pattern and text are
        // matching at this shift skip
        
        while (j >= 0 && patternArray[j] == textArray[index + j]) {
            j--;
        }

        // If the pattern is found then we will get a negative j
        if (j < 0) {
            ans.push_back(index);
            index += skip[0];
        }
        else {
        
            // Else skip the whole part and move forward
            index += skip[j + 1];
        }
    }

    if (ans.size() == 0) {
        ans.push_back(-1);
    }

    return ans;
}