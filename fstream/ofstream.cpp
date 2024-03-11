// ofstream.cpp -- Output file stream
// https://cplusplus.com/reference/fstream/ofstream/

#include <algorithm>
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void write()
{
    // create new file using ofstream
    ofstream ofStream;
    const string fileName = "file.txt";

    // writing
    {
        ofStream.open(fileName);

        ofStream << "Line 1\n";
        ofStream << "Line 2\n";

        // close stream when done
        ofStream.close();
    }

    // reading
    {
        // read file into vector<string>
        ifstream ifStream(fileName);
        vector<string> lines;

        string line;
        while (getline(ifStream, line))
        {
            lines.push_back(line);
        }

        assert(lines.size() == 2);
        assert(lines[0] == "Line 1");
        assert(lines[1] == "Line 2");

        // close stream when done
        ifStream.close();
    }

    // delete file when done
    filesystem::remove(fileName);
}

bool writeStringsToFile(const vector<string> &lines, const string &fileName)
{
    // open a file in write mode
    ofstream outFile(fileName);

    if (!outFile.is_open())
        return false; // cannot be opened

    // write lines
    for (const string &line : lines)
        outFile << line << endl;

    // close file when done
    outFile.close();
    return true;
}

vector<string> readLinesFromFile(const string &fileName)
{
    // open file
    ifstream inFile(fileName);

    if (!inFile.is_open())
        return {}; // could not open file

    vector<string> lines;
    string line;
    // read each line
    while (getline(inFile, line))
    {
        lines.push_back(line);
    }

    // close file when done
    inFile.close();
    return lines;
}

void test()
{
    write();
}

int main()
{
    test();

    cout << endl <<  __FILE__ " tests passed!" << endl;
    return 0;
}
