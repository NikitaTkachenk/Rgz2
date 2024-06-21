#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

string join(const vector<string>& tokens, char delimiter) {
    ostringstream result;
    for (size_t i = 0; i < tokens.size(); ++i) {
        result << tokens[i];
        if (i != tokens.size() - 1) {
            result << delimiter;
        }
    }
    return result.str();
}

void editTags(vector<string>& tags) {
    vector<string> tagNames = { "Title", "Artist", "Album", "Year", "Comment", "Track", "Genre" };
    for (size_t i = 0; i < tags.size(); ++i) {
        cout << "Current " << tagNames[i] << ": " << tags[i] << endl;
        cout << "Enter new " << tagNames[i] << " (or press Enter to leave unchanged): ";
        string input;
        getline(cin, input);
        if (!input.empty()) {
            tags[i] = input;
        }
    }
}

int main() {
    string filePath;
    cout << "Enter the path to the metadata file: ";
    getline(cin, filePath);

    ifstream fin(filePath);
    if (!fin.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string inputStr;
    getline(fin, inputStr);
    fin.close();

    vector<string> tags = split(inputStr, ',');

    cout << "Metadata tags read from file:" << endl;
    for (const auto& tag : tags) {
        cout << tag << ", ";
    }

    editTags(tags);

    string outputStr = join(tags, ',');
    ofstream fout(filePath);
    if (!fout.is_open()) {
        cerr << "Error writing to file!" << endl;
        return 1;
    }

    fout << outputStr;
    fout.close();

    cout << "Updated metadata string saved to file: " << filePath << endl;
    return 0;
}
