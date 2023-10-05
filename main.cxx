#include <iostream>
#include <string>
int main(int numbers, char *content[]) {
  if (numbers == 3) {
    std::string parameter1{content[0]};
    auto pointertoparameter2{*(content[1])};
    auto lengthofparameter1{parameter1.size()};
    auto parameter3asint{std::atoi(content[2])};
    auto var6{0};
    auto var7{0};
    std::string parameter2{content[1]};
    while (true) {
      var6 += parameter2[var7++];
      if (var7 >= static_cast<int>(parameter2.size())) {
        break;
      }
    }
    
    if ((var6 ^ pointertoparameter2 * 3) << (lengthofparameter1 & 0x1f) == parameter3asint) {
      std::cout << "Correct!" << std::endl;
      std::cout << var6 << std::endl;
    } else {
      std::cout << "Wrong!" << std::endl;
    }
  }
}