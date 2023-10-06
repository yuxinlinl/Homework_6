#include <iostream>
#include <string>
int main(int numbers, char *content[]) {
  if (numbers == 3) {
    std::string parameter1{content[0]};
    auto pointertoparameter2{*(content[1])};
    auto lengthofparameter1{parameter1.size()};
    auto parameter3asint{std::atoi(content[2])};
    auto checksum{0};
    std::string parameter2{content[1]};
    for (int i = 0 ; i <= parameter2.size() ; i++) {
      checksum += parameter2[i];
    
      }
    
    int calculatekey(checksum, pointertoparameter2, parameter3asint);
	    return (checksum ^ pointertoparameter2 * 3) << (lengthofparameter1 & 0x1f);
    int key = calculatekey(checksum, pointertoparameter2, parameter3asint);

    if (key == parameter3asint) {
      std::cout << "Correct!" << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}