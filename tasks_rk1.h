#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
#include <locale>
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

struct Node {
    Node* next;
    Node* prev;
    int nameNode;
    static int countNodes;
};

class LinkedList {
private:
    Node* Head;
    Node* Tail;
public:
    LinkedList();

    ~LinkedList();

    void push_back(int value);

    void writeToFileFromTail();

    void writeToFileFromHead();

    void insert(int nameNode, int position);
};

class StudentInfo {
private:
    std::tuple<std::string /*фамилия*/, std::string /*имя*/, char* /*№ студ билета*/> info;
    std::map<std::string/*название предмета*/, std::pair<std::list<int> /*список оценок*/, float /*средняя оценка*/>> subjMark;
public:
    /*	desription	:	добавления отметки по выбранному предмету
        input		:	subjName - название предмета, mark -- оценка
        output		:	0 - оценка добавлена, 1 - нет такого предмета
        author		:
        date		:
    */
    int addMark(const std::string& subjName, int mark);
    /*	desription	:	добавления отметки по выбранному предмету
        input		:	subjName - название предмета
        output		:	0 - предмет добавлен, 1 - такой предмет уже есть
        author		:
        date		:
    */
    int addSubj(const std::string& subjName);
    /*	desription	:	добавления нового предмета
        input		:	subjName - название предмета
        output		:	среднее значение оценки
        author		:
        date		:
    */
    float getAverMark(const std::string& subjName);
    /*	desription	:	вычисления средней оценки по предметам
        input		:	subjName - название предмета
        output		:	среднее значение оценки
        author		:
        date		:
    */
    void printInfoStudent(bool writeFile = false);
    /*	desription	:	запись данных в файл формат файла
                            [Фамилия] [имя] : [номер билета]
                                [предмет 1]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
                                [предмет 2]	:	[оценка 1], [оценка 2],... [оценка N] -- [среднее значение]
        input		:	subjName - название предмета
        output		:	среднее значение оценки
        author		:
        date		:
    */
    void writeAllInfoToFile();
};

#endif
