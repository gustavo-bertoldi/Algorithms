#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]) {
    //Palindrome conditions
    //If nb letters is even: All letters must be in pairs
    //If nb letters is odd: All letters must be in pairs except for one

    char *input = argv[1];
    unordered_map<char, int> letters;

    int nb_letters = 0;
    while (*input != '\0') {
        if (*input != ' ') {
            if (letters.count(*input) == 0) letters.insert({*input, 0});
            letters[*input] += 1;
            nb_letters++;
        }
        input++;
    }

    auto nb_odd = [](pair<char, int> x){ return (x.second - 1) % 2 == 0; };
    auto single = find_if(letters.begin(), letters.end(), nb_odd);
    if (single != letters.end()) letters.erase(single -> first);
    
    auto nb_even = [](pair<char, int> x){ return x.second % 2 == 0; };
    bool is_palindrome = all_of(letters.begin(), letters.end(), nb_even);

    if (is_palindrome) cout << "Is a palindrome permutation" << endl;
    else cout << "Is not a palindrome permutation" << endl;
}