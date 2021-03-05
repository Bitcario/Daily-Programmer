/*
  Athr: Bitcario
  Prog: Necklace Matching
  Desc: See wiki entry
  Date: 03.04.2021
  Note: Bonus Part 2.  Explicitly outputs where 4 words have same "necklace".
        Solution based on: https://tinyurl.com/37rpemrc
*/

// Header Files
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <map>
#include <string>
#include <iterator>
#include <algorithm>

// Function Prototypes
std::string 
SmallestRotatedStr(std::string);

// main()
int
main ()
{
  // Delcarations
  std::map<std::string, std::list<std::string>> rotatedStrs;
  std::fstream inputFile;
  std::string inStr;
  std::string rotatedStr;
  std::map<std::string, std::list<std::string>>::iterator rotatedStrsIter;
 
  // Set up 
  inputFile.open("enable1.txt", std::ios::in);

  if (!inputFile)
  {
    std::cout << "No such file" << std::endl;
  }

  // Input and processing
  while (getline(inputFile, inStr))
  {
    rotatedStr = SmallestRotatedStr(inStr); 
    rotatedStrsIter = rotatedStrs.find(rotatedStr);

    if (rotatedStrsIter == rotatedStrs.end())
    {
      rotatedStrs.insert(
        std::pair<std::string, std::list<std::string>>(
          rotatedStr, 
          std::list<std::string>{rotatedStr}));
    }
    else
    {
      rotatedStrsIter->second.push_back(inStr);
    }
  } 

  // Print where exactly 4 words can be rotated to the same "necklace"
  for (rotatedStrsIter = rotatedStrs.begin(); rotatedStrsIter != rotatedStrs.end(); 
       rotatedStrsIter++)
  {
    if (rotatedStrsIter->second.size() == 4)
    {
      std::list<std::string> words = rotatedStrsIter->second;
      std::list<std::string>::iterator iterA;
      for (iterA = words.begin(); iterA != words.end(); iterA++)
      {
        std::cout << *iterA << std::endl;
      }
    }
  }

  // Clean up
  inputFile.close();

  return EXIT_SUCCESS;
}  

std::string 
SmallestRotatedStr(std::string str)
{
  if (str == "")
  {
    return "";
  }

  std::string least;
  size_t strLen;

  least = str;
  strLen = str.size();

  for (size_t i = 0; i < strLen; i++)
  {
    std::rotate(str.begin(), str.begin() + 1, str.end());
    least = str < least ? str : least;
  }

  return least;
}
