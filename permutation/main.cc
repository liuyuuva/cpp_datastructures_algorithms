#include <iostream>
#include <string>

void RecPermute(std::string sofar, std::string rest){
  if (rest == ""){
    std::cout << sofar << std::endl;
  }else{
    for (int i = 0; i < rest.length(); i++){
      std::string next = sofar + rest[i];
      std::string remaining = rest.substr(0, i) + rest.substr(i+1);
      RecPermute(next, remaining);
    }
  }
}

void ListPermutations(std::string s)
{
  RecPermute("", s);
}

int main(int argc, char *argv[])
{
  std::string source_string= "ABC";
  ListPermutations(source_string);
  
  return 0;
}

   
