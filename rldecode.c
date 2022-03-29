#include <stdio.h>
#include <stdbool.h>

/*
 * The isnumber() function examines the character given as its first
 * argument and returns true if and only if the character represents
 * an number.  This helper function should be relatively short.
 *
 * Returns true if the given character represents an number, false
 * otherwise.
 */
bool isnumber(char c){
	if(c >= 48 && c <= 57)
		return true; 
	else
		return false; 
}


/*
 * The decode() function takes a run-length encoded string as its
 * argument, parses every integer n preceding every character in
 * the string, and prints each character n times.  For example, if
 * the string passed to decode() is "1a3b", decode() will print
 * "abbb".  It returns an integer that represents the summed value
 * of the amount of characters printed; in this example, decode()
 * would return the integer 4.
 *
 * This function must also handle malformed run-length encoded strings.
 * A malformed string is any string which does not adhere to the RLE
 * implementation described in the handout. If a malformed string is
 * encountered, it should cease printing the decoded string, print an
 * error message, and return -1.
 *
 * Returns the integer value of the total amount of characters printed,
 * or -1 if the run-length encoded string is malformed.
 */

int convert(char c){
	return c % 48; 
}



int decode(char *str){
	int count = 0;
	int num = 0; 
	bool number = false; 
	bool character = false; 

	if(!isnumber(str[0]))
	{
		//printf("\n");
		printf("%s","error");
		return -1;
	}

	for(int i = 0; str[i] != '\0'; i++){
		if(isnumber(str[i])){
			num = num *10 + convert(str[i]);
			number = true; 
		}
		else
		{
			if(character || num <= 0){
				//printf("\n");
				printf("%s","error");
				return -1; 
			}
			character = true;
			num = 0;
		}
		if(number && character){
			number = false; 
			character = false; 
		}
	}
	num = 0;
	
	if(!number && !character){
		for(int i = 0; str[i] != '\0'; i++){

			if(isnumber(str[i])){
				//printf("%d ",convert(str[i]));
				number = true; 
				num = num *10 + convert(str[i]);
			}
			else
			{
				int x = 0;

				while(x<num){
					printf("%c",str[i]); 
					x = x + 1; 
				}
				count = count + num; 
				num = 0; 
				character = true;
			}
			if(number && character){
				number = false; 
				character = false; 
			}
		}
		printf("\n");

		return count; 
	}
	else 
	{
		//printf("\n");
		printf("%s","error");
		return -1; 

	}
}

/*
 * The main function is where C programs begin.
 *
 * This function parses its arguments and returns the value they
 * represent.  In this assignment, the only valid argument is a
 * run-length encoded string.  Any extra arguments in excess of
 * this single valid argument make the invocation of your program
 * invalid.
 *
 * Remember that the argument in argv[0] is the name of the program, so
 * a program passed exactly one argument on the command line will
 * receive _two_ arguments: its name in argv[0] and the provided
 * argument in argv[1].
 *
 * Arguments:
 * argc - The number of arguments received
 * argv - The arguments received as an array of C strings
 *
 * Returns 0 if the argument is well-formed and the string could
 * be decoded, non-zero otherwise.
 */
int main(int argc, char *argv[]) {
//      Your main program logic should go here, with helper logic in the
//      * functions isnumber() and decode(), which you can place below
//      * the closing brace of main() 
	if(decode(argv[1]) == -1)
		return -1; 
	else 
    	return 0;
}

/* You should implement isnumber() and decode() here */
