#include <iostream>
#include <string>
int main(){
    std::cout << "Please input your string:\n";
    std::string input;
    std::getline(std::cin, input);
    for (auto it = input.begin(); it < input.end(); it++){
        *it = std::toupper(*it);
    }
    for (int i = 1; i < 26; i++){
        std::cout << "Shifting by " << i << ":\n";
        for (char ch: input){
            if (ch > 'Z' || ch < 'A'){
                std::cout << ch;
            } else if (ch + i > 'Z'){
                std::cout  << char(ch + i -26);
            } else {
                std::cout << char(ch+i);
            }
        }
        std::cout << '\n';
    }
    return 0;
}