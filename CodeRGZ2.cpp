#include <iostream>
#include <string>
#include <vector>
#include <sstream>
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
    for (size_t i = 4; i < tags.size()-1; ++i) {
        cout << "Current tag " << i - 3 << ": " << tags[i] << endl;
        cout << "Enter new tag(or space to leave current tag): ";
        string input;
        getline(cin, input);
        if (!input.empty()) {
            tags[i] = input;
        }
    }
}
int main() {
    string inputStr;
    cout << "Enter metadata string: ";
    getline(cin, inputStr);
    vector<string> tags = split(inputStr, '/');
    editTags(tags);
    string outputStr = join(tags, '/');
    cout << "Updated metadata string: " << outputStr << endl;
    return 0;
}