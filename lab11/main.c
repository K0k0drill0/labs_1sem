/*
Астахова Анастасия Сергеевна
группа М8О-113Б-22

Вариант 5
Подсчитать количество слов с лексикографически возрастающими буквами
латинского алфавита.
*/

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_razd(char a) {
  if (a == ' ' || a == '\n' || a == '\t') {
    return true;
  }
  else {
    return false;
  }
}

int main() {

    char c1, c2, c3;
    c1 = 1;
    c2 = 2;
    c3 = 3;

    int counter = 0;
    c1 = getchar();
    while (isalpha(c1) == false && is_razd(c1) == false) {
        c1 = getchar();
    }
    c2 = getchar();
    if (c2 == EOF) {
      printf("\nКоличество слов с лексикографически возрастающими буквами : %d\n", 0);
      return 0;
    }
    while (isalpha(c2) == false && is_razd(c2) == false) {
        c2 = getchar();
    }

    c1 = tolower(c1);
    c2 = tolower(c2);

    bool flag;
    if (c2 <= c1){
      flag = false;
    }
    else {
      flag = true;
    }
    while (c3 != EOF) {

        c3 = getchar();
        while (isalpha(c3) == false && is_razd(c3) == false && c3 != EOF) {
            c3 = getchar();
        }
        c3 = tolower(c3);

        switch (c3) {
        case ' ':
            if (flag == true && is_razd(c1) == false && is_razd(c2) == false) {
                counter++;
            }
            flag = true;
            break;
        case '\n':
          if (flag == true && is_razd(c1) == false && is_razd(c2) == false) {
              counter++;
            }
            flag = true;
            break;
        case '\t':
          if (flag == true && is_razd(c1) == false && is_razd(c2) == false) {
            counter++;
          }
          flag = true;
          break;
        default:
            if (c3 <= c2 && isalpha(c2) && isalpha(c3)) {
                flag = false;
            }
            break;
        }
        c1 = c2;
        c2 = c3;

    }
    if (is_razd(c2) == false) {
      if (flag == true && is_razd(c1) == false) {
          counter++;
      }
      flag = true;
    }
    printf("\nКоличество слов с лексикографически возрастающими буквами : %d\n", counter);
    return 0;
}
