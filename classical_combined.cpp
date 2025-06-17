#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DoubleStorage {
private:
    double* values;
    int size;

public:
    DoubleStorage() : values(nullptr), size(0) {}

    ~DoubleStorage() {
        delete[] values;
    }

    void readFromKeyboard() {
        cout << "Enter the number of values: ";
        cin >> size;
        values = new double[size];
        cout << "Enter " << size << " double values:\n";
        for (int i = 0; i < size; ++i) {
            cin >> values[i];
        }
    }

    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Cannot open file '" << filename << "'\n";
            return;
        }
        file >> size;
        values = new double[size];
        for (int i = 0; i < size; ++i) {
            file >> values[i];
        }
        file.close();
    }

    void printToScreen() const {
        cout << "Values:\n";
        for (int i = 0; i < size; ++i) {
            cout << values[i] << " ";
        }
        cout << endl;
    }

    void writeToFile(const string& filename) const {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Cannot write to file '" << filename << "'\n";
            return;
        }
        for (int i = 0; i < size; ++i) {
            file << values[i] << "\n";
        }
        file.close();
    }

    void sortValues() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                if (values[i] > values[j]) {
                    double temp = values[i];
                    values[i] = values[j];
                    values[j] = temp;
                }
            }
        }
    }
};

int main() {
    DoubleStorage ds;
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
