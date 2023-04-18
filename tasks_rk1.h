#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
#include <locale>
#include <Windows.h>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <vector>
#include <tuple>
#include <map>
#include <list>
#include <vector>
#include <stdio.h>
#include <string.h>
#ifndef UNTITLED_TASKS_RK1_H
#define UNTITLED_TASKS_RK1_H

char* NewChar(const char* s);

class WorkWithFile {
private:
    char* dataOfFile = new char[20];

    void readFromFile(const char* fileName);

    void prepareTestFile(const char* fileName);

public:
    WorkWithFile(const char* fileName);

    ~WorkWithFile();

    void writeStatInfoToFile(const char* outFile);
};

char* convertDecToBin(int number);

void writeToFile(const char* fileName, const char* strNum);

char* convertBinToHex(const char* binNum);

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum);

void buildTree(int height);

std::vector<std::pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount);

void randFill(float* ar, int N);

#endif
