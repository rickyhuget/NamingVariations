using System;

class Program {

  static string split(string input)
  {
    string tempStr = input[0].ToString();
    int start = 1;
    int count = 0;
    for (int i = 1; i < input.Length; i++)
    {
      count++;
      if (Char.IsUpper(input[i]) || i == input.Length-1)
      {
        if (i == input.Length-1)
        {
          count++;
        }
        tempStr += input.Substring(start, count-1) + " ";
        count = 1;
        start = i;
      }
      if (input[i] == '(' || input[i] == ')')
      {
        tempStr += input.Substring(start, count-1) + " ";
        break;
      }
    }
    tempStr = tempStr.ToLower();
    return tempStr;
  }
  
  static string combine(string input, char c) 
  {
    string newString = "";
    int start = 0;
    int count = 0;

    for (int i = 0; i < input.Length; i++)
    {
      if (input[i] == ' ' || i == input.Length-1)
      {
        if (c != 'C' && start == 0)
        {
          newString += input[start]; // stay lower
        }
        else
        {
          newString += char.ToUpper(input[start]); // to upper
        }
        newString += input.Substring(start+1, count-1);
        start = i+1;
        count = 0;
      }
      count++;
    }

    if (c == 'M')
    {
      newString += "()";
    }

    return newString;
  }
  
  public static void Main (string[] args) 
  {
    string input;
    string newString = null;
    while (true) 
    {
      input = Console.ReadLine();
      if (input[0] == 'S') 
      {
        newString = split(input.Substring(4,input.Length-4));
      }
      if (input[0] == 'C') 
      {
        newString = combine(input.Substring(4,input.Length-4), input[2]);
      }
      Console.WriteLine(newString);
    };
    
  }
}