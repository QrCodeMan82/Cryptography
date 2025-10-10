#include <iostream>
#include <string>
int main(){
    std::string input;
    std::cout << "Input the string you want to count the frequencies of:\n";
    std::getline(std::cin, input);
    int counts[26] = {};
    for (char c: input){
        if (c <= 'Z' && c >= 'A'){
            counts[c - 'A']++;
        } else if (c <= 'z' && c >= 'a'){
            counts[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; i++){
        std::cout << "#" << char('a'+i) << " = " << counts[i] << '\n';
    }
    return 0;
}