#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// if the character is a DELIMITER,the function returns 'true' 
bool isDelimiter(char delimiter) {
   if (delimiter == ':' || delimiter == '+' || delimiter == '-' || delimiter == '*' ||  delimiter == '?' || delimiter == '>' || delimiter == '<' ||
   delimiter == '/' || delimiter == ',' || delimiter == ';' || delimiter == '(' || delimiter == ')' ||
   delimiter == '[' || delimiter == ']' || delimiter == '{' || delimiter == '}'|| delimiter == ' ' || delimiter == '"' ) 
   return (true);
   return (false); // if character isn't a recognized delimiter the function returns 'false'
}

// if the str is a identifier, the function returns 'true';
bool isIdentifier(char* str){
	int i;
		for(i = 0; str[i]; i++){ 
  		str[i] = toupper(str[i]); // replacing each of str's character to upper Case
  		}
   if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||    str[0] == '3' || str[0] == '4' || str[0] == '5' ||    str[0] == '6' || str[0] == '7' || str[0] == '8' || 
       str[0] == '9' || str[0] == '_' || isDelimiter(str[0]) == true ){  // controlling first index of str
   	return (false); 
   } 
   
   else if(strlen(str)>20){ // controlling str's lenght
   	printf("ERROR!! the '%s' identifier is too Large!!!\n",str); // if str is too large, printing an error message on console
   	return (false);    	
   }   
   return (true);
}

 // if the str is a integer, the function returns 'true'
bool isInteger(char* str) {
   int i, len = strlen(str);  // finding lenght of str
   
   for (i = 0; i < len; i++) {
      if (str[i] != '0' && str[i] != '1' && str[i] != '2'&& str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' )
      // controlling each of the str's character for finding invalid symbol
      	return (false);
      
     if (len == 0 ) {
   	return (false);
   	}else if(len > 10){ // controlling str's lenght
   	printf("ERROR!! the %s is too Large!!!\n",str); // if str is too large, printing an error message on console
   	return (false);
   }       
   } // end of for
   return (true);
}

// if the ch is a valid operator, the function returns 'true'
bool isOperator(char ch){
   if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == ':') 
   	return (true);
   return (false);
}
// if the parameter of the function is a bracket, the function returns 'true'
bool isBracket(char bracket){
   if ((bracket == '(' ) || (bracket == ')' ) || (bracket == '[' ) || (bracket == ']' ) || (bracket == '{' ) || (bracket == '}' ))
   	return (true);
   return (false);
}
// if the ch is a quote character , the function returns 'true'
bool isStringConst(char ch){
   if ((ch== '"' ) )  
   	return (true);
   return (false);
}
// if the str is a valid keyword, the function returns 'true'
bool isKeyword(char* str) {
		int i;
		for(i = 0; str[i]; i++){
  		str[i] = tolower(str[i]); // replacing each of str's character to lower Case
  		}
  		
   if (!strcmp(str, "break") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "const") || !strcmp(str, "continue") || !strcmp(str, "do") || !strcmp(str, "else") || 
    	!strcmp(str, "enum") || !strcmp(str, "float") || !strcmp(str, "for") || !strcmp(str, "goto")  || !strcmp(str, "if") || !strcmp(str, "int") || !strcmp(str, "long") ||
   		!strcmp(str, "record") || !strcmp(str, "return") || !strcmp(str, "static") || !strcmp(str, "while"))  	// valid keywords...
		   		
   return (true);
   return (false);
}

// if the ch is a semicolon(;), the function returns 'true'
bool isEndOfLine(char ch){  
   if ((ch == ';' ) )
   	return (true);
   return (false);
} 

// The function creates and returns a new string by dividing the given string value from the indexes sent as parameters.
char* subString(char* str, int left, int right) {
   int i;
   char* subStr = (char*)malloc( sizeof(char) * (right - left + 2)); // creating an empty character array with size of substring 
   for (i = left; i <= right; i++)
      subStr[i - left] = str[i]; // assigning str to substring
   subStr[right - left + 1] = '\0';  // assignin last index of substring to end of file string
   return (subStr);
}


// the function detects words from file and writes the words another file
void detectTokens(char* str,FILE* dosya) {
	
   int left = 0, right = 0;  //  variables(left,right)  are keeping first and last index of substring
   int length = strlen(str); 
   while (right <= length) {  // end of string check
      if (isDelimiter(str[right]) == false)  // Checking if the word in the index is a symbol or a space character
      right++;
      if (isDelimiter(str[right]) == true && left == right) { // checking the type of delimiter 
         if (isOperator(str[right]) == true){  // checking the type of operator
         	if(str[right+1]== '+' || str[right+1] ==  '-' || str[right+1] == '='){  // checking the operators of ++,--,:=
         		right += 1;
         		fprintf(dosya,"Operator(%c%c)\n", str[right-1],str[right]); // writing to file
			 }
			 else {
			 	
			 	fprintf(dosya,"Operator(%c)\n", str[right]);  // writing to file 
			 }
			 
			 
         	// checking the bracket symbol 
		 }else if (isBracket(str[right]) == true){
		 	
             	if (str[right] == '(' ){  
             		if(str[right+1]=='*'){  // checking the comment 
             			right+=2;
         			    while(str[right] != '\0') {  // checking the end of file string
             			    right++;
             			    if(str[right] == '*' && str[right+1] == ')'){ // checking the close comment
             			        right++;
             			        break;  
             			    }
 
         			        right++;
             			}
             			if(str[right] == '\0') {  // checking the end of file string
						 
             			printf("ERROR!! You didnt close comments\n");  // printing the error message about closing comment
						 }
					 }else{ // if it isn't a comment, writing type of bracket
					 	fprintf(dosya,"LeftPar\n");  
					 }
		   			// writing the type of bracket
		   		}else if(str[right] == ')' ){
		   			fprintf(dosya,"RightPar\n");
		   		}else if(str[right] == '[' ){
		   			fprintf(dosya,"LeftSquareBracket\n");
		   		}else if(str[right] == ']' ){
		   			fprintf(dosya,"RightSquareBracket\n");
		   		}else if(str[right] == '{' ){
		   			fprintf(dosya,"LeftCurlyBracket\n");
		   		}else if(str[right] == '}' ){
		   			fprintf(dosya,"RightCurlyBracket\n");
		   		}
		   	// checking the end of line character
		 }else if (isEndOfLine(str[right]) == true){
		 		fprintf(dosya,"EndOfLine\n");
		 	// checking the string constants
		 }else if(isStringConst(str[right]) == true){
		 		right +=1;
		 		while(str[right]!= '"' ){ // checking the quote symbol
		 				right +=1;
		 				if (str[right] == '\0'){ // checking end of file symbol
		 					break;
						 }
					 }
					 if(str[right] == '\0' ){  // checking the end of file 
						 	printf("ERROR!! You didnt close the quote\n");  // printing an error message about string const
					 }else if(str[right] == '"'){ // checking the close quote symbol
		 				int a;
		 				char* m;
		 				int c =0;
		 				
		 				for(a = left;a<=right;a++){  // assign the string constant to an array
		 					
		 					m[c] = str[a];
		 					c +=1;
		 				
						}						
						fprintf(dosya,"StringConst(%s) ",m); // writing the string constant to file
						fprintf(dosya,"\n"); 				
		 				
					 }
				 }			
		 
		 right++;  // incrementing the right index
		 left = right;	 // equating the right index with the left index
        
         
      } else if (isDelimiter(str[right]) == true && left != right || (right == length && left != right)) { // checking the keywords, integers, and identifiers
         char* subStr = subString(str, left, right - 1); // creating an array to throwing the words from file 
         if (isKeyword(subStr) == true) // checking the keyword
            fprintf(dosya,"Keyword(%s)\n", subStr); // writing to file
         else if (isInteger(subStr) == true) // checking the integers
            fprintf(dosya,"IntConst(%s)\n", subStr); // writing  to file
         else if (isIdentifier(subStr) == true)  // checking the identifiers
         	fprintf(dosya,"Identifier(%s)\n", subStr); // writing to file 
         
         left = right; // // equating the right index with the left index
      }
   }   
   return; 
}


int main(int argc, char *argv[]) {
	
	FILE *d; // the file pointer
	int index;  // index value
	
	char* name = (char*)malloc(200); // 100 memory allocations
	if((d=fopen("code.psi","r"))==NULL) {  // opening file 
		printf("dosya acilamadi.");
	}
	else {
	
		while(!feof(d)) {  // reading data from file
			char a = fgetc(d);
			
			if(a != '\n'){  // skipping the /n character and throwing the read data into array
				name[index] = a;
				index +=1;
				printf("%c",a);
			}
			
		}
		
		fclose(d); // closing the file
		
		printf("\n \n");
		char* name1 = subString(name,0,index-2);  // assigning the data from the file to a smaller array
	
		FILE *dosya = fopen("code.lex", "w"); // opening a file for writing datas
		
		detectTokens(name1,dosya);  // calling detectTokens functions
		free(name1); // return the array to memory
		free(name); // return the array to memory

	}	
	return 0;
}
