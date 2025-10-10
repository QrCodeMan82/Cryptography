#include <iostream>
#include <string>
int main(){
    std::string input;
    std::string key;
    std::cout << "Please input the text to be decrypted:\n";
    std::getline(std::cin, input);
    for (auto c = input.begin(); c < input.end(); c++){
        if (*c <= 'z' && *c >= 'a'){
            *c = std::toupper(*c);
        }
    }
    bool cont;
    bool flag = false;
    do {
        std::cout << "Please input the key that should be used or enter EXIT to exit:\n";
        std::getline(std::cin, key);
        if (key == "EXIT"){
            cont = false;
        } else {
            for (auto c = key.begin(); c < key.end(); c++){
                if (*c <= 'z' && *c >= 'a'){
                    *c = std::toupper(*c);
                } else if (*c <= 'Z' && *c >= 'A'){
                    continue;
                } else {
                    std::cout << "This is not a valid key! Keys can contain upper and lowercase letters, but no other characters\n";
                    flag = true;
                    break;
                }
            }
            if (flag){
                flag = false;
                continue;
            }
            cont = true;
            std::cout << "Decoded text:\n";
            for (int i = 0; i < input.size(); i++){
                if (input[i] >= 'A' && input[i] <= 'Z'){
                    if (input[i] - key[i%key.size()] + 'A' < 'A'){
                        std::cout << char(input[i] - key[i%key.size()] + 'A' + 26);
                    } else {
                        std::cout << char(input[i] - key[i%key.size()] + 'A');
                    }
                }
            }
            std::cout << '\n';
        }
    } while (cont);
    return 0;
}