#include <iostream>

int divMod26(int x, int y){
    while (x%y != 0){
        x += 26;
    }
    x /= y;
    return x%26;
}

int subMod26(int x, int y){
    x -= y;
    return x%26;
}

int main(){
    std::string input;
    std::cout << "Please input the text:\n";
    getline(std::cin,input);
    std::string pairs;
    std::cout << "Please input two known pairs of letters in the form (a,b),(c,d):\n";
    std::cin >> pairs;
    int a = toupper(pairs[1])-'A';
    int b = toupper(pairs[3])-'A';
    int c = toupper(pairs[7])-'A';
    int d = toupper(pairs[9])-'A';
    int gradient = divMod26(subMod26(d,b),subMod26(c,a));
    int intercept = subMod26(b,a*gradient);
    auto mapping = [intercept,gradient](char c)->char{
        c = toupper(c);
        if (c < 'A' || c > 'Z'){
            return c;
        }
        int value = c-'A';
        value = value*gradient + intercept + 52;
        value %= 26;
        return char(value+'A');
    };
    std::string output;
    for (char c: input){
        output += mapping(c);
    }
    std::cout << "The decrypted text is:\n" << output;
}