#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    ifstream fin("file1.txt");
    ofstream fout("file2.txt");
    string word;
    if (!fin.is_open() || !fout.is_open()) {
        cout << "Файл не может быть открыт!\n";
        return 1;
    }
    while (!fin.eof()) {
        fin >> word;
        for (int i = 0; i < word.size(); i++)
            if (word[i] > 'A' && word[i] < 'Z')
                word[i] += 'z' - 'Z';
        words.push_back(word);
    }
    sort(words.begin(), words.end());

    for (int i = 0; i < (int)words.size(); i++) {
        fout << words.at(i) << endl;
    }
    fin.close();
    fout.close();
}
