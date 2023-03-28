#include "tasks_rk1.h"

void task_4(){
    buildTree(8);
}

void task_2(){
    writeToFile("result_task2.txt", convertDecToBin(30));
}

int main() {
    task_4();
    task_2();

    return 0;
}

