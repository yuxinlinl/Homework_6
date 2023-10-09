#include <iostream>
#include <string>

//Function to calculate the checksum of a string
int CalculateChecksum(const std::string& str){
  int checksum = 0;
  for (int i = 0 ; i <= str.size() ; i++){
    checksum += str[i];
  }
  return checksum;
}

//Function to calculate the key based on inputs
int Calculatekey(const std::string& programName, char* parameter1, int parameter2){
  std::string programNameStr{ programName };
  char firstChar = *parameter1;
  int programNameLength = programNameStr.size();
  
  int checksum = CalculateChecksum(programNameStr);
  int key = (checksum ^ (firstChar*3)) << (programNameLength & 0x1f);

  return key;
}

int main(int numbers, char *content[]) {
  if (numbers == 3){
    std::string programName{content[0]};
    char firstChar = {*(content[1])};
    int programNameLength = programName.size();
    int parameter2 = std::atoi(content[2]);
    
    int key = Calculatekey(programName,content[1],parameter2);

    std::cout << "Checksum:" << CalculateChecksum(programName) << std::endl;
    std::cout << "Key:" << key << std::endl;
    std::cout << "Expected Key: " << parameter2 << std::endl;
    
    
    if (key == parameter2){
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}
