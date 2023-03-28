#include <cstring>
#include <map>
#include "tasks_rk1.h"

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

char* convertDecToBin(int number) {
        int b = number, a, i = 0, d, ss;
        const int N = 33;
        int arr[N]{};
        for (; b != 0;) {
                a = b % 2;
                arr[i] = a;
                b = b / 2;
                if (b != 0)
                        i++;
        }
        for (; i >= 0; i--) {
                ss = arr[i];
                std::cout << ss;
        }
        return 0;
}

void writeToFile(const char* fileName, const char* strNum){
    FILE* pFile = fopen(fileName, "w");
    fprintf(pFile, "%s", strNum);
    fclose(pFile);
}

