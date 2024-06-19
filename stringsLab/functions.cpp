# include "functions.h"
# include <string>
// add any includes

using std::cout, std::cin, std::endl, std::string;

void deobfuscate() {
    // TODO
    // getting user input without the spaces
    string user;
    string final = "";
    char details[10];
    cout << "Please enter obfuscated sentence: ";
    getline(cin, user);
    cout << "Please enter deobfuscation details: ";
    cin >> details;

    int num;
    for (int i = 0; i < 10; i++) {
        num = details[i] - 48;
        final.append(user.substr(0, num));
        user.erase(0, num);
        final.append(" ");
    }

    cout << "Deobfuscated sentence: " << final;
    cout << endl;
}

void wordFilter() {
    // TODO
    string sentence;
    cout << "Please enter the sentence: ";
    getline(cin, sentence);

    string word;
    cout << "Please enter filter word: ";
    cin >> word;

    int len = word.length();

    string newSen = sentence;
    int index = 0;
    string replace;
    for (unsigned int j = 0; j < word.length(); j++) {
        replace += "#";
    }


    for (int i = 0; i < 4; i++) {
        index = sentence.find(word);
        newSen.replace(index, len, replace);
        sentence.erase(index, len);

    }
    

    cout << "Filtered Sentence: " << newSen;


}

void passwordConverter() {
    // TODO
    string pass;
    cout << "Please enter your text input: ";
    cin >> pass;
    cout << "input: " << pass << endl;
    for (unsigned int i = 0; i < pass.length(); i++) {
        if (pass[i] == 'a') {
            pass.replace(i, 1, "@");
        }
        else if (pass[i] == 'e') {
            pass.replace(i, 1, "3");
        }
        else if (pass[i] == 'i') {
            pass.replace(i, 1, "!");
        }
        else if (pass[i] == 'o') {
            pass.replace(i, 1, "0");
        }
        else if (pass[i] == 'u') {
            pass.replace(i, 1, "^");
        }

    }
    string c;
    for (int j = (pass.length() - 1); j >= 0; j--) {
        c += pass[j];
    }
    pass.append(c);
    cout << "output: " << pass << endl;
    //cout << pass;

}

void wordCalculator() {
    // TODO
}

void palindromeCounter() {
    // TODO
}