// *** Aufgabe ***

// Unten ist ein Text in einem C++-String abgelegt. Es handelt sich um die
// ersten beiden Absätze von "Alice in Wonderland" ohne jede Punktuation, also
// nur die reinen Wörter, jeweils durch ein Leerzeichen getrennt.

// Schreiben Sie ein Programm, das folgende Fragen beantwortet:
//   - Wie viele Wörter enthält der Text? (X)
//   - Welches ist das längste Wort? (X)
//   - Wie viele Buchstaben enthält der Text (ohne Lehrzeichen)? (X)
//   - Was ist die durchschnittliche Wortlänge? (X)
//   - Welcher Buchstabe kommt am häufigsten vor? (X)

#include <iostream>
#include <string>
#include <vector>

const std::string gAlice =
    "Alice was beginning to get very tired of sitting by her sister "
    "on the bank and of having nothing to do once or twice she had "
    "peeped into the book her sister was reading but it had no "
    "pictures or conversations in it and what is the use of a book "
    "thought Alice without pictures or conversation "
    "So she was considering in her own mind as well as she could "
    "for the hot day made her feel very sleepy and stupid whether "
    "the pleasure of making a daisy chain would be worth the trouble "
    "of getting up and picking the daisies when suddenly a White "
    "Rabbit with pink eyes ran close by her";

// Hinweis: Zugriff auf die einzelnen Characters eines Strings geht mit:
// gAlice[i], wobei i ein Integer ist. Das erste Zeichen hat Index 0.


std::tuple<std::vector<std::string>, int> getWords() {
    std::string buf;
    std::vector<std::string> words;

    int charcount = 0;

    for (int i = 0; i < gAlice.length(); i++) {
        // get the character at current index
        char c = gAlice[i];

        // if it is a space, append buffer contents to word array and clear buffer
        if (c == ' ') {
            words.push_back(buf);
            buf.clear();
            continue;
        }

        // in all other cases, append character to buffer
        buf.append(1, c);
        charcount++;
    }

    if (!buf.empty()) {
        words.push_back(buf);
    } // also push last word

    return {words, charcount};
}

std::tuple<std::string, int> getLargestWord(std::vector<std::string> words) {
    std::string largest = words[0];
    int length = words[0].size();
    for (int i = 1; i < words.size(); i++) {
        int l = words[i].size();
        std::string w = words[i];

        if (l > length) {
            length = l;
            largest = w;
        }
    }

    return {largest, length};
}

std::vector<int> countLetterAmount() {
    std::vector<int> letterCounts(26, 0); // initialize with zeroes
    for (int i = 0; i < gAlice.length(); i++) {
        // get the character at current index
        char c = (char)tolower(gAlice[i]);

        // if it is a space, ignore
        if (c == ' ') {
            continue;
        }

        letterCounts[c-'a']++;
    }

    return letterCounts;
}

void printLetterCounts(std::vector<int> letterCounts) {
    const std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};

    std::cout << "Anzahl aller Buchstaben: " << std::endl;
    for (int i = 0; i < letterCounts.size(); i++) {
        std::cout << alphabet[i] << ": " << letterCounts[i] << "  ";
    }
    std::cout << std::endl;
}

std::tuple<char, int> getHighestCountedLetter(std::vector<int> letterCounts) {
    const std::string alphabet{"abcdefghijklmnopqrstuvwxyz"};

    int maxIndex = 0, maxAmount = letterCounts[0];

    for (int i = 1; i < letterCounts.size(); i++) {
        int currentAmount = letterCounts[i];
        if (currentAmount > maxAmount) {
            maxIndex = i;
            maxAmount = currentAmount;
        }
    }

    return {(char)maxIndex+'a', maxAmount};
}

int main() {
    auto [words, charcount] = getWords();
    auto [largestWord, largestWordLength] = getLargestWord(words);
    auto letterCounts = countLetterAmount();
    auto [mostUsedCharName, mostUsedCharAmount] = getHighestCountedLetter(letterCounts);


    // results
    std::cout << "Wortanzahl: " << words.size() << std::endl;
    std::cout << "Längstes Wort: " << largestWord << " (" << largestWordLength << ")" << std::endl;
    std::cout << "Zeichenanzahl: " << charcount << std::endl;
    std::cout << "Durchschnittliche Wortlänge: " << charcount / words.size() << std::endl;
    printLetterCounts(letterCounts);
    std::cout << "Am meisten genutzer Buchstabe: " << mostUsedCharName << " (" << mostUsedCharAmount << ")" << std::endl;


    return 0;
}
