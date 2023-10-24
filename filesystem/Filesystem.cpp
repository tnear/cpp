// std::filesystem (C++17) provides an interface for managing files independent of platform
// https://en.cppreference.com/w/cpp/filesystem

#include <algorithm>
#include <cassert>
#include <filesystem>
#include <iostream>
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

void test()
{
    currentPath();
    exists();
    isdir();
    mkdir();
    parentPath();
}

int main()
{
    test();

    std::cout << std::endl <<  __FILE__ " tests passed!" << std::endl;
    return 0;
}
