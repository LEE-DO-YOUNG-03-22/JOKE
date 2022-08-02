#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void str_prn (char**); // 출력 함수
int main() {
int i, j, a;
int k = 0;
char temp[80];
int* arr_1[3]; int* arr_2[3]; int* arr_3[3];
for (i = 0; i < 3; i++) {
 arr_1[i] = (int*)malloc(4 * sizeof(int));
 arr_2[i] = (int*)malloc(4 * sizeof(int));
 arr_3[i] = (int*)malloc(4 * sizeof(int));
 }
for (i = 0; i < 3; i++) {
for (j = 0; j < 4; j++) {
 arr_2[i][j] = 12 - k;
 arr_1[i][j] = ++k;
 arr_3[i][j] = arr_1[i][j] + arr_2[i][j];
 }
 }
 printf("---<< 행렬의 합 출력 >>---\n");
for (i = 0; i < 3; i++) {
for (j = 0; j < 4; j++) {
 printf("%5d", arr_1[i][j]);
 }
if(i != 1)
 printf(" ");
else
 printf(" +");
for (j = 0; j < 4; j++) {
 printf("%5d", arr_2[i][j]);
 }
if(i != 1)
 printf(" ");
else
 printf(" =");
for (j = 0; j < 4; j++) {
 printf("%5d", arr_3[i][j]);
 }
 printf("\n");
 }
 printf("\n---<< 문자 배열의 동적 할당 >>---\n");
char** str = (char**)malloc(3 * sizeof(char*));
for (i = 0; i < 3; i++) {
 printf("문자열을 입력 >> ");
 gets(temp);
 str[i] = (char*)malloc(strlen(temp)+1);
strcpy(str[i], temp);
 }
 printf("\n---<< 입력 받은 문자열 >>---\n");
 str_prn (str);
for (i = 0; i < 3; i++) {
 free(arr_1[i]);
 free(arr_2[i]);
 free(arr_3[i]);
 free(str[i]);
 }
 free(str);
return 0;
}
void str_prn (char** str) {
int i;
for (i = 0; i < 3; i++) {
 printf("%s\n", str[i]);
 }
}
// Yonsei
// 2021-1 Computer Programming
// Homework
