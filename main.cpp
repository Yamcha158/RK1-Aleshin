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
#include <bitset>
#include <tuple>
#include <map>
#include <list>
#include <iterator>
#include "tasks_rk1.h"

void task1() {
    WorkWithFile a("sourceFile_task1.txt");
    a.writeStatInfoToFile("result_sourceFile_task1.txt");
}

void task2() {
    writeToFile("result_task2.txt", convertDecToBin(6));
}

void task3() {
    writeToFile("result_task3.txt", 0, convertBinToHex("101101101"), "101101101");
}

void task4() {
    buildTree(8);
}

void task5() {
    float TwoDArray[4][4];
    for (int i = 0; i < 4; ++i) {
        randFill(TwoDArray[i], 4);
    }
    std::vector<std::pair<int, float>> vec = averStr2DArray(*TwoDArray, 4, 4);
    FILE* pFile = fopen("result_task5.txt", "w");
    for (auto i : vec)
        fprintf(pFile, "%d\t%c\t%f\n", i.first, ':', i.second);
    fclose(pFile);
}

int Node::countNodes = 0;
LinkedList lst;

void task6() {
    for (int i = 0; i < 4; ++i) {
        lst.push_back(3 * i);
    }
    lst.writeToFileFromHead();
    lst.writeToFileFromTail();
}

void task7() {
    lst.insert(9, 4);
}

void task8() {
    StudentInfo test;
    test.addSubj("OP");
    test.addMark("OP", 5);
    test.writeAllInfoToFile();
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
    task6();
    task7();
    task8();
    return 0;
}
