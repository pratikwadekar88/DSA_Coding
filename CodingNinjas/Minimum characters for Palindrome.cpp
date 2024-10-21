int minCharsforPalindrome(string str) {
	// Function to find the minimum number of characters that need to be added
    // at the beginning of the string to make it a palindrome.
    
	if(str.length() == 1) 
		// If the string has only one character, it is already a palindrome.
		// No characters need to be added, so return 0.
		return 0;
	
	// Initialize two pointers, one at the beginning and one at the end of the string.
	int i = 0, j = str.length() - 1;

	// 'res' will keep track of how many characters we need to add.
	int res = 0;

	// 'trim' is used to gradually reduce the size of the substring
	// we are checking for palindrome properties, starting from the end.
	int trim = j;

	// Loop to check the string and count how many characters are needed
	// to make it a palindrome.
	while(i < j) {
		// If the characters at the current pointers match, move inward.
		if(str[i] == str[j]) {
			i++;
			j--;
		} else {
			// If characters don't match, increment 'res' to indicate that
			// one more character needs to be added at the beginning to make
			// the rest of the string a palindrome.
			res++;
			
			// Reset 'i' to 0 to check from the beginning again.
			i = 0;
			
			// Decrease 'j' to check the next substring by decrementing 'trim'.
			j = --trim;
		}
	}

	// Return the number of characters needed to make the string a palindrome.
	return res;
}
