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
    std::filesystem::remove(fileName);
}

void test()
{
    write();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
