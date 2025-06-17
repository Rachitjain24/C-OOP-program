#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class DoubleVectorStorage {
private:
    vector<double> values;

public:
    void readFromKeyboard() {
        int size;
        cout << "Enter the number of values: ";
        cin >> size;

        values.clear();
        cout << "Enter " << size << " double values:\n";
        for (int i = 0; i < size; ++i) {
            double val;
            cin >> val;
            values.push_back(val);
        }
    }

    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Cannot open file '" << filename << "'\n";
            return;
        }

        values.clear();
        double val;
        while (file >> val) {
            values.push_back(val);
        }
        file.close();
    }

    void printToScreen() const {
        cout << "Values:\n";
        for (double val : values) {
            cout << val << " ";
        }
        cout << endl;
    }

    void writeToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Cannot write to file '" << filename << "'\n";
            return;
        }

        for (double val : values) {
            file << val << "\n";
        }
        file.close();
    }

    void sortValues() {
        sort(values.begin(), values.end());
    }
};

int main() {
    DoubleVectorStorage ds;
    int inputChoice, outputChoice;
    string inputFile, outputFile;

    cout << "Input options:\n1. Keyboard\n2. File\nEnter choice: ";
    cin >> inputChoice;

    if (inputChoice == 1) {
        ds.readFromKeyboard();
    } else if (inputChoice == 2) {
        cout << "Enter input filename: ";
        cin >> inputFile;
        ds.readFromFile(inputFile);
    } else {
        cout << "Invalid input choice.\n";
        return 1;
    }

    ds.sortValues();

    cout << "Output options:\n1. Screen\n2. File\nEnter choice: ";
    cin >> outputChoice;

    if (outputChoice == 1) {
        ds.printToScreen();
    } else if (outputChoice == 2) {
        cout << "Enter output filename: ";
        cin >> outputFile;
        ds.writeToFile(outputFile);
    } else {
        cout << "Invalid output choice.\n";
        return 1;
    }

    return 0;
}
