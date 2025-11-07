#include <iostream>
#include <string>
int main(){
    std::string outputs[26];
    std::cout << "Please input your string:\n";
    std::string input;
    std::getline(std::cin, input);
    for (auto it = input.begin(); it < input.end(); it++){
        *it = std::toupper(*it);
    }
    outputs[0] = input;
    for (int i = 1; i < 26; i++){
        for (int i = 0; i < input.size(); i++){
            if (input[i] > 'Z' || input[i] < 'A'){
                
            } else if (input[i] + 1 > 'Z'){
                input[i] =  char(input[i] + 1 -26);
            } else {
                input[i] =  char(input[i]+1);
            }
        }
        outputs[i] = input;
    }
    for (std::string i: outputs){
        std::cout << i << "\n\n";
    }
    return 0;
}