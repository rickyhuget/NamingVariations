# NamingVariations

This code is based off of a HackerRank challenge.
The initial commit was the previous code I wrote to complete the challenge.
The second commit is the code refactored using SOLID principles 
in an effert to better understand those principles in practice.

Input Format: 

Each line of the input file will begin with an operation (S or C) 
  followed by a semi-colon followed by M, C, or V followed by a semi-colon followed by the words you'll need to operate on.
The operation will either be S (split) or C (combine)
M indicates method, C indicates class, and V indicates variable
In the case of a split operation, the words will be a camel case method, class or variable name 
  that you need to split into a space-delimited list of words starting with a lowercase letter.
In the case of a combine operation, the words will be a space-delimited list of words starting with lowercase letters 
  that you need to combine into the appropriate camel case String. 
  Methods should end with an empty set of parentheses to differentiate them from variable names.
  
Output Format:

For each input line, your program should print either the space-delimited list of words (in the case of a split operation) 
  or the appropriate camel case string (in the case of a combine operation).
  
  
Sample Input:
  S;M;plasticCup()
  C;V;mobile phone
  C;C;coffee machine
  S;C;LargeSoftwareBook
  C;M;white sheet of paper
  S;V;pictureFrame

Sample Output:
  plastic cup
  mobilePhone
  CoffeeMachine
  large software book
  whiteSheetOfPaper()
  picture frame
  
