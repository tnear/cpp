/*
std::filesystem (C++17) provides an interface for managing files independent of platform
https://en.cppreference.com/w/cpp/filesystem
*/

#include <algorithm>
#include <cassert>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void currentPath()
{
    // get current working directory (pwd/cwd)
    filesystem::path p = filesystem::current_path();
    assert(p.string().find("cpp") != -1);
    assert(p.string().find("filesystem") != -1);
}

void exists()
{
    filesystem::path realFile {"Filesystem.cpp"};
    filesystem::path fakeFile {"FakeFile.cpp"};

    assert(filesystem::exists(realFile));
    assert(!filesystem::exists(fakeFile));
}

void isdir()
{
    filesystem::path newDir{"NewDirectory"};

    assert(!filesystem::is_directory(newDir));
    assert(filesystem::create_directory(newDir));
    assert(filesystem::is_directory(newDir));
    assert(filesystem::remove(newDir));
}

void mkdir()
{
    filesystem::path newDir { "NewDirectory" };

    assert(filesystem::create_directory(newDir));
    assert(filesystem::remove(newDir));
    assert(!filesystem::is_directory(newDir));
}

void parentPath()
{
    filesystem::path p = filesystem::current_path();
    filesystem::path parent = p.parent_path();

    // pwd: project/cpp/filesystem
    // parent: project/cpp
    assert(parent.string().find("filesystem") == -1);
    assert(parent.string().find("cpp") != -1);
}

void createFile()
{
    // <filesystem> does not provide a way to create files (only directories)
    ofstream ofStream;
    const string fileName = "file.txt";

    // writing
    ofStream.open(fileName);
    ofStream << "Line 1\n";
    ofStream << "Line 2\n";
    ofStream.close();

    assert(filesystem::exists(filesystem::path{fileName}));

    // remove file
    filesystem::remove(fileName);

    assert(!filesystem::exists(filesystem::path{fileName}));
}

// std::filesystem::rename(path &old, path &new)
void rename()
{
    filesystem::path file = "a.txt";
    filesystem::path fileRenamed = "b.txt";

    assert(!filesystem::exists(file));
    assert(!filesystem::exists(fileRenamed));

    // create file
    ofstream ofStream;
    ofStream.open(file.string());
    ofStream << "Line 1";
    ofStream.close();

    // rename file
    filesystem::rename(file, fileRenamed);

    assert(!filesystem::exists(file));
    assert(filesystem::exists(fileRenamed));

    // remove file when done
    filesystem::remove(fileRenamed);
}

void remove()
{
    filesystem::path file = "a.txt";
    assert(!filesystem::exists(file));

    // create file
    ofstream ofStream;
    ofStream.open(file.string());
    ofStream << "Line 1";
    ofStream.close();
    assert(filesystem::exists(file));

    // remove file
    filesystem::remove(file);

    assert(!filesystem::exists(file));
}

void directoryIterator()
{
    // useful for listing files in a directory (ls/dir)
    filesystem::path dir {"."};

    bool found = false;
    for (const filesystem::directory_entry &entry : filesystem::directory_iterator(dir))
    {
        if (entry.path().filename().string() == "Filesystem.cpp")
            found = true;
    }

    // verify this file is in the directory
    assert(found);
}

void path()
{
    filesystem::path file {"C:/Temp/Nested/File.txt"};

    //     stem: "File"
    // filename: "File.txt"
    //   parent: "C:/Temp/Nested"
    assert(file.stem().string() == "File");
    assert(file.filename().string() == "File.txt");
    assert(file.parent_path().string() == "C:/Temp/Nested");
}

void test()
{
    currentPath();
    exists();
    isdir();
    mkdir();
    parentPath();
    createFile();
    rename();
    remove();
    directoryIterator();
    path();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
