// 2022245033_이도영
#include <stdio.h>
#include <string.h>

char place[10]; //위치 변수
int seat;       //좌석 변수

void kios_();           //키오스크 함수 원형선언
int seat_status();      //좌석 현황 함수 원형선언
int seat_reservation(); //좌석 예약 함수 원형선언
int change_of_seat();   //좌석 변경 함수 원형선언
int cancel_of_seat();   //좌석 취소 함수 원형선언

char SEOUL[50][50]; //서울 좌석배열 선언
char BUSAN[50][50]; //부산 좌석 배열 선언

int main()
{
    kios_();                       //키오스크 함수 불러오기
    FILE *fp;                      //파일 포인터
    fp = fopen("server.txt", "w"); // 파일 쓰기 모드
    for (int i = 0; i < 20; i++)
    {                                   // 서울 부산 배열 확인 코드
        if (strcmp(SEOUL[i], "■") == 0) // 서울배열에 좌석이 있다면
        {
            fprintf(fp, "SEOUL %d\n", i + 1); // server.txt에 서울과 그 자리 입력
            // printf("SEOUL %d\n", i+1); //서울 저장된 좌석 불러오기
        }
        if (strcmp(BUSAN[i], "■") == 0)
        {                                     // 부산배열에 좌석이 있다면
            fprintf(fp, "BUSAN %d\n", i + 1); // server.txt에 부산과 그 자리 입력
            // printf("BUSAN %d\n", i+1); //부산 저장된 좌석 불러오기
        }
    }
    fclose(fp); //파일 닫기
    printf("서버연동 성공\n"); //서버연동성공 printf
    return 0;   //반환값
}

void seat_(int num) //좌석배열 함수
{
    FILE *fp; //파일 포인터

    for (int i = 0; i < 20; i++) //서울 좌석 20칸 불러오기
    {
        strcpy(SEOUL[i], "□"); //서울 모든좌석들 □으로 채우기
    }
    for (int i = 0; i < 20; i++) //서울 좌석 20칸 불러오기
    {
        strcpy(BUSAN[i], "□"); //부산 모든좌석들 □으로 채우기
    }
    fp = fopen("server.txt", "r"); // server.txt 파일 불러오기

    while (fscanf(fp, "%s %d", &place, &seat) != EOF) //파일에서 내용 읽기 & EOF까지 읽기
    {
        if (strcmp(place, "SEOUL") == 0) //서울과 장소 문자열 비교했을때 참일시
        {
            strcpy(SEOUL[seat - 1], "■"); //서울 좌석 중 해당하는 좌석만 ■으로 채우기
        }
        else //서울과 장소 문자열 비교했을때 거짓일시
        {
            strcpy(BUSAN[seat - 1], "■"); //부산 좌석 중 해당하는 좌석만 ■으로 채우기
        }
    }
    switch (num) // num 정수에 관해 선택문
    {
    case 1:                          // num이 1일때
        for (int i = 0; i < 20; i++) // 20번 반복
        {
            if (i % 2 == 0) // i가 2의 배수일때
            {
                if (i % 4 == 0) // i가 4의 배수일때
                {
                    printf("\n"); //줄바꿈 print
                }
                else // i가 4의 배수가 아닐때
                {
                    printf(" "); //스페이스 print
                }
            }
            printf("%s", SEOUL[i]); //서울좌석 배열 print
        }
        printf("\n");                //줄바꿈 print
        break;                       // switch case문 멈추기
    case 2:                          // num이 2일때
        for (int i = 0; i < 20; i++) // 20번 반복
        {
            if (i % 2 == 0) // i가 2의 배수일때
            {
                if (i % 4 == 0) // i가 4의 배수일때
                {
                    printf("\n"); //줄바꿈 print
                }
                else // i가 4의 배수가 아닐때
                {
                    printf(" "); //스페이스 print
                }
            }
            printf("%s", BUSAN[i]); //부산좌석 배열 print
        }
        printf("\n"); //줄바꿈 print
        break;        // switch case문 멈추기
    }
    fclose(fp); // server.txt 파일 닫기
}

void kios_() //키오스크 함수
{
    int ch;                                                                                              // ch 변수 선언
    printf("키오스크==버스==\n");                                                                        //키오스크 제목 print
    printf("1. 버스표 상태 | 2. 버스표 예매 | 3. 버스표 변경 |\n4. 버스표 취소 | 5. 프로그램 종료\n>>"); //키오스크 기능 print
    scanf("%d", &ch);                                                                                    //키오스크 기능선택 scanf
    printf("\n");                                                                                        //줄바꿈 print
    switch (ch)                                                                                          // ch 정수에 관해 선택문
    {
    case 1:                                                      // ch가 1일때
        printf("어떤 버스를 보시겠습니까? 1: 서울 2: 부산\n>>"); //버스 선택창 print
        int buss;                                                // buss 변수 선언
        scanf("%d", &buss);                                      //버스 선택창 scanf
        seat_status(buss);                                       //버스표 상태 함수 불러오기(즉, 좌석 현황 함수 불러오기)
        kios_();                                                 //키오스크 함수 다시 불러오기
        break;                                                   // switch case문 멈추기

    case 2:                 // ch가 2일때
        seat_reservation(); //버스표 예매 함수 불러오기(즉, 좌석 예약 함수 불러오기)
        break;              // switch case문 멈추기

    case 3:               // ch가 3일때
        change_of_seat(); //버스표 변경 함수 불러오기(즉, 좌석 변경 함수 불러오기)
        break;            // switch case문 멈추기

    case 4:               // ch가 4일때
        cancel_of_seat(); //버스표 취소 함수 불러오기(즉, 좌석 취소 함수 불러오기)
        break;            // switch case문 멈추기

    case 5:                                 // ch가 5일때
        printf("이용해주셔서 감사합니다. 변경된 내용을 서버에 전송합니다.\n"); //프로그램 종료 print
        break;                              // switch case문 멈추기
    }
}

int seat_status(int buss)
{                  //좌석 현황 함수
    printf("\n");  //줄바꿈 print
    if (buss == 1) // buss 선택 헀을때 1이면
    {
        printf("도착지 : SEOUL\n"); //서울 도착지 print
        printf("요금 : 20000\n");   //서울 요금 print
        printf("좌석 : ");          //서울 좌석 print
        seat_(buss);                //좌석 입출력 함수 불러오기
    }
    else if (buss == 2) // buss 선택 했을때 2이면
    {
        printf("도착지 : BUSAN\n"); //부산 도착지 print
        printf("요금 : 20000\n");   //부산 요금 print
        printf("좌석 : ");          //부산 좌석 print
        seat_(buss);                //좌석 입출력 함수 불러오기
    }
    printf("\n"); //줄바꿈 print

    return 0; //반환값 0;
}

int seat_reservation() //좌석 예약 함수
{
    int num;                                                      // num 변수 선언
    int buss;                                                     // buss 변수 선언
    printf("어떤 버스를 보시겠습니까? 1: 서울 2: 부산\n>>");      //버스 선택창 print
    scanf("%d", &buss);                                           //버스 선택창 scanf
    seat_status(buss);                                            //좌석 현황 함수 불러오기
    printf("예매할 좌석 번호를 알려주세요.\n[돌아가기 : 0]\n>>"); //좌석 번호창 print
    scanf("%d", &num);                                            //좌석 번호 창 scanf
    printf("\n");                                                 //줄바꿈 print
    if (buss == 1)                                                //서울을 선택했을 경우
    {
        if (num == 0) // num 선택했을 때 0이면
        {
            kios_(); //키오스크 함수로 되돌아가기
        }
        else if (strcmp(SEOUL[num - 1], "■") == 0) // num 선택했을 때 이미 예약된 좌석 번호와 똑같다면
        {
            printf("이미 예약된 좌석입니다. 다른 번호를 입력하세요.\n"); //이미 예약된 좌석 printf
            seat_reservation();                                          //좌석 예약 함수로 다시 돌아가기
        }
        else // num 선택 했을 때
        {
            strcpy(SEOUL[num - 1], "■");                                 //서울 좌석을 예약좌석으로 바꾸기
            printf("예매를 완료하였습니다. 이용해주셔서 감사합니다.\n"); //예매 완료 문구 print
        }
    }
    if (buss == 2) //부산을 선택했을 경우
    {
        {
            if (num == 0) // num 선택했을 때 0이면
            {
                kios_(); //키오스크 함수로 되돌아가기
            }
            else if (strcmp(BUSAN[num - 1], "■") == 0) // num 선택했을 때 이미 예약된 좌석 번호와 똑같다면
            {
                printf("이미 예약된 좌석입니다. 다른 번호를 입력하세요.\n"); //이미 예약된 좌석 printf
                seat_reservation();                                          //좌석 예약 함수로 다시 돌아가기
            }
            else // num 선택 했을 때
            {
                strcpy(BUSAN[num - 1], "■");                                 //부산 좌석을 예약좌석으로 바꾸기
                printf("예매를 완료하였습니다. 이용해주셔서 감사합니다.\n"); //예매 완료 문구 print
            }
        }
    }
    return 0; //반환값 0;
}

int change_of_seat() //좌석 변경 함수
{
    int num_1, num_2;                                                                                              //사용할 변수 선언
    int buss;                                                                                                      // buss 변수 선언
    printf("어떤 버스를 보시겠습니까? 1: 서울 2: 부산\n>>");                                                       //버스 선택창 print
    scanf("%d", &buss);                                                                                            //버스 선택창 scanf
    seat_status(buss);                                                                                             //좌석 현황 함수 불러오기
    printf("변경할 좌석 번호를 알려주세요(변경 전 변경 후).\nex. (12 13) 12 -> 13 자리 이동\n[돌아가기 : 0]\n>>"); //좌석 변경 창 print
    scanf("%d %d", &num_1, &num_2);                                                                                //좌석 변경 창 scanf
    printf("\n");                                                                                                  //줄바꿈 print
    if (num_1 == 0 || num_2 == 0)                                                                                  // num_1과 num_2를 선택했을 때 0이면
    {
        kios_(); //키오스크 함수로 되돌아가기
    }
    if (buss == 1) //서울을 선택했을 경우
    {
        if (strcmp(SEOUL[num_1 - 1], "□") == 0) // num 선택했을 때 예약에 되어있지 않은 좌석이면
        {
            printf("예약이 되어있지 않은 좌석입니다. 확인 후 다른 번호를 입력하세요.\n"); //예약이 되어있지 않은 좌석 printf
            change_of_seat();                                                             //좌석 예약 함수로 다시 돌아가기
        }
        else if (strcpy(SEOUL[num_2 - 1], "■") == 0)                     //옮기려는 좌석이 이미 예약되어있는 경우
        {                                                                // num 선택 했을 때
            printf("이미 예약된 좌석입니다. 다른 번호를 입력하세요.\n"); //이미 예약된 좌석 print
            change_of_seat();                                            //좌석 변경 함수로 돌아가기
        }
        else
        {
            printf("변경을 완료하였습니다. 이용해주셔서 감사합니다.\n"); //변경이 완료되었다는 창 print
            strcpy(SEOUL[num_1 - 1], "□");                               //옮기는 좌석을 빈 좌석으로 바꾸기
            strcpy(SEOUL[num_2 - 1], "■");                               //옮기고자 하는 좌석을 예약좌석으로 바꾸기
        }
    }
    if (buss == 2) //부산을 선택했을 경우
    {
        if (strcmp(BUSAN[num_1 - 1], "□") == 0) // num 선택했을 때 예약에 되어있지 않은 좌석이면
        {
            printf("예약이 되어있지 않은 좌석입니다. 확인 후 다른 번호를 입력하세요.\n"); //예약이 되어있지 않은 좌석 printf
            change_of_seat();                                                             //좌석 예약 함수로 다시 돌아가기
        }
        else if (strcpy(BUSAN[num_2 - 1], "■") == 0)                     //옮기려는 좌석이 이미 예약되어있는 경우
        {                                                                // num 선택 했을 때
            printf("이미 예약된 좌석입니다. 다른 번호를 입력하세요.\n"); //이미 예약된 좌석 print
            change_of_seat();                                            //좌석 변경 함수로 돌아가기
        }
        else
        {
            printf("변경을 완료하였습니다. 이용해주셔서 감사합니다.\n"); //변경이 완료되었다는 창 print
            strcpy(BUSAN[num_1 - 1], "□");                               //옮기는 좌석을 빈 좌석으로 바꾸기
            strcpy(BUSAN[num_2 - 1], "■");                               //옮기고자 하는 좌석을 예약좌석으로 바꾸기
        }
    }
    return 0; //반환값 0;
}

int cancel_of_seat() //좌석 취소 함수
{
    int num;                                                      //사용할 변수 선언
    int buss;                                                     // buss 변수 선언
    printf("어떤 버스를 보시겠습니까? 1: 서울 2: 부산\n>>");      //버스 선택창 print
    scanf("%d", &buss);                                           //버스 선택창 scanf
    seat_status(buss);                                            //좌석 현황 함수 불러오기
    printf("취소할 좌석 번호를 알려주세요.\n[돌아가기 : 0]\n>>"); //좌석 취소 창 print
    scanf("%d", &num);                                            //좌석 취소 창 scanf
    printf("\n");                                                 //줄바꿈 print
    if (num == 0)                                                 // num 선택했을 때 0이면
    {
        kios_(); //키오스크 함수로 되돌아가기
    }
    if (buss == 1) //서울을 선택했을 경우
    {
        if (strcmp(SEOUL[num - 1], "□") == 0) // num 선택했을 때 예약에 되어있지 않은 좌석이면
        {
            printf("예약이 되어있지 않은 좌석입니다. 확인 후 다른 번호를 입력하세요.\n"); //예약이 되어있지 않은 좌석 printf
            cancel_of_seat();                                                             //좌석 취소 함수로 돌아가기
        }
        else // num 선택했을 때 예약에 되어있는 좌석이면
        {
            printf("취소를 완료하였습니다. 이용해주셔서 감사합니다.\n"); //취소가 완료되었다는 창 print
            strcpy(SEOUL[num - 1], "□");                                 //선택된 예약좌석을 빈좌석으로 바꾸기
        }
    }
    if (buss == 2) //부산을 선택했을 경우
    {
        if (strcmp(BUSAN[num - 1], "□") == 0) // num 선택했을 때 예약에 되어있지 않은 좌석이면
        {
            printf("예약이 되어있지 않은 좌석입니다. 확인 후 다른 번호를 입력하세요.\n"); //예약이 되어있지 않은 좌석 printf
            cancel_of_seat();                                                             //좌석 취소 함수로 돌아가기
        }
        else // num 선택했을 때 예약에 되어있는 좌석이면
        {
            printf("취소를 완료하였습니다. 이용해주셔서 감사합니다.\n"); //취소가 완료되었다는 창 print
            strcpy(BUSAN[num - 1], "□");                                 //선택된 예약좌석을 빈좌석으로 바꾸기
        }
    }
    return 0; //반환값 0;
}
