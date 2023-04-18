#include <cstring>
#include <map>
#include <fstream>
#include "tasks_rk1.h"

char* NewChar(const char* s) {
    char* NString = new char[20];
    int chek = 0;
    for (int i = 0; i < strlen(s); ++i) {
        int chek1 = 0;
        for (int j = i; j > 0; j--) {
            if (s[i] == s[j - 1]) {
                chek++;
                chek1++;
                break;
            }
        }
        if (chek1 == 0) {
            NString[i - chek] = s[i];
            NString[i - chek + 1] = '\0';
        }
    }
    return NString;
}

void WorkWithFile::readFromFile(const char* fileName) {
    FILE* pFile;
    pFile = fopen(fileName, "r");
    fscanf(pFile, "%s", dataOfFile);
    fclose(pFile);
}

void WorkWithFile::prepareTestFile(const char* fileName) {
    FILE* pFile;
    pFile = fopen(fileName, "w");
    int val = 20;
    int i;
    srand(time(nullptr));
    char viewtxt;
    for (i = 0; i < val; ++i)
    {
        viewtxt = (rand() % ('z' - 'a' + 1)) + 'a';
        if (viewtxt < 'a') viewtxt = ' ';
        fwrite(&viewtxt, 1, sizeof(viewtxt), pFile);
    }
    fclose(pFile);
}

WorkWithFile::WorkWithFile(const char* fileName) {
    prepareTestFile(fileName);
    readFromFile(fileName);
}

WorkWithFile::~WorkWithFile() {
    delete[] dataOfFile;
}

void WorkWithFile::writeStatInfoToFile(const char* outFile) {
    char* Symbols = NewChar(dataOfFile);
    int* CounterArray = new int[strlen(Symbols)];
    for (int i = 0; i < strlen(Symbols); ++i) {
        CounterArray[i] = 0;
    }
    for (int i = 0; Symbols[i] != '\0'; ++i) {
        for (int j = 0; j < strlen(dataOfFile); ++j) {
            if (Symbols[i] == dataOfFile[j])
                CounterArray[i]++;
        }
    }
    FILE* pFile = fopen(outFile, "w");
    for (int i = 0; i < strlen(Symbols); ++i) {
        fprintf(pFile, "%c\t%d\n", Symbols[i], CounterArray[i]);
    }
    fclose(pFile);
    delete[] Symbols;
    delete[] CounterArray;
}

char* convertDecToBin(int number) {
	char* system = new char[33];
	int count = 0;
	for (int i = 32; number > 0; i--) {
		system[i] = number % 2 + '0';
		number /= 2;
		count++;
	}
	char* Systema = new char[count];
	int Index = 33 - count;
	for (int i = 0; i < count; ++i) {
		Systema[i] = system[Index++];
		Systema[i + 1] = '\0';
	}
	delete[]system;
	return Systema;
}
void writeToFile(const char* fileName, const char* strNum) {
    FILE* pFile = fopen(fileName, "w");
    fprintf(pFile, "%s", strNum);
    fclose(pFile);
}

char* convertBinToHex(const char* binNum) {
    int number = 0;
    if ((int)(strlen(binNum)) % 4 != 0)
        number = 4 - (int)(strlen(binNum)) % 4;
    char* BinNum = new char[number + strlen(binNum) + 1];
    std::map<std::string, char> gg{ {"0000", '0'}, {"0001", '1'}, {"0010", '2'}, {"0011", '3'}, {"0100", '4'}, {"0101", '5'},
                              {"0110", '6'}, {"0111", '7'}, {"1000", '8'}, {"1001", '9'}, {"1010", 'A'}, {"1011", 'B'},
                              {"1100", 'C'}, {"1101", 'D'}, {"1110", 'E'}, {"1111", 'F'} };
    for (int i = 0; i < number; ++i) {
        BinNum[i] = '0';
    }
    for (int i = number; i < number + strlen(binNum) + 1; ++i) {
        BinNum[i] = binNum[i - number];
        BinNum[i + 1] = '\0';
    }
    char* HexNum = new char[8];
    int index = 0;
    int i = 0;
    while (i < strlen(BinNum)) {
        char* temp = new char[5];
        for (int j = 0; j < 4; ++j) {
            temp[j] = BinNum[i++];
            temp[j + 1] = '\0';
        }
        HexNum[index++] = gg.find(temp)->second;
        delete[] temp;
    }
    HexNum[index] = '\0';
    delete[] BinNum;
    return HexNum;
}

void writeToFile(const char* fileName, int writeAppend, const char* hexNum, const char* binNum) {
    FILE* pFile = fopen(fileName, "w");
    fprintf(pFile, "%s\t%s", binNum, hexNum);
    fclose(pFile);
}

void buildTree(int height) {
	int b = 1, d = height * 2;
	for (int i = 0; i < height; i++) {
		if (i > 0)
			b = b + 2;
		std::cout.width(d);
		for (int j = 0; j < b; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
		--d;
	}
}

std::vector<std::pair<int, float>> averStr2DArray(const float* ar, int colCount, int rowCount) {
    std::vector<std::pair<int, float>> vector;
    for (int i = 0; i < rowCount; ++i) {
        float sum = 0;
        for (int j = 0; j < colCount; ++j) {
            sum += (*(ar + (i * colCount) + j));
        }
        float avr = sum / colCount;
        vector.emplace_back(i, avr);
    }
    return vector;
}

void randFill(float* ar, int N) {
    for (int i = 0; i < N; i++) {
        ar[i] = rand() / float(RAND_MAX) * 24.f + 1.f;
    }
}
