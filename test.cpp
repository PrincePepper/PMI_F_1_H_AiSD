#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> bucket_sort(vector<string> mass_words) {

    for (int i = 2; i > -1; i--) {
        vector<vector<string>> support_mass;
        support_mass.resize(123);

        for (int j = 0; j < mass_words.size(); j++) {
            string letter = mass_words[j];
            support_mass[(int) letter[i]].push_back(letter);
        }

        mass_words.clear();

        for (int j = 0; j < support_mass.size(); j++) {
            if (support_mass[j].size() > 0) {
                for (int l = 0; l < support_mass[j].size(); l++) {
                    mass_words.push_back(support_mass[j][l]);
                }
            }
        }
    }
    return mass_words;
}


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    vector<string> mass_of_words;
    string word;

    for (int i = 0; i < n; i++) {
        fin >> word;
        mass_of_words.push_back(word);
    }

    vector<string> sorted_mass;

    sorted_mass = bucket_sort(mass_of_words);

    for (int i = 0; i < n; i++) {
        fout << sorted_mass[i] << endl;
    }
}
