/*db에 넣기 위한 기본 형식 바꿈 프로그램 입니다 전화번호 5개 까지 가능 합니다*/


#include <stdio.h>
#include <string>
#include <fcntl.h>
#define max 200
#pragma warning(disable:4996)
int number_mix(const int big, const int small);



int main(){
	int chgnum2, chgnum3, chgnum4, chgnum5, chgnum6;
	FILE *fp, *fp2;
	char arrTest[max];
	char arr[max];
	char lastArr[max];
	int num1, num2, num3, num4, num5, num6;
	char str[max] = { 0, };
	int loop = 0, loop2;
	int count = 0;
	int i = 0;
	int flag = 0;
	//읽을 파일과 쓰기할 파일
	fp = fopen("beforetotal.txt", "rb+");
	fp2 = fopen("aftertotal.txt", "wb+");

	//if (fseek(fp, 0, SEEK_END) != '\n')
	while (!feof(fp))
	{
		fgets(arrTest, sizeof(arrTest), fp);
	}
	fseek(fp, -2, SEEK_END);
	char tmp[3];
	fgets(tmp, 2, fp);
	if (strcmp(tmp, "\r\n") != 0){
		fputs("\r\n", fp);
	}
	fseek(fp, 0, SEEK_SET);

	//printf("%d", sizeof(arr));
	while (!feof(fp))
	{
		//printf("loop = %d\n", loop);
		fgets(arr, sizeof(arr), fp);

		if ((strcmp(arr, lastArr) == 0))
			continue;
		else {
			strncpy(lastArr, arr, sizeof(arr));
		}
		//printf("arr = %s\t arr2 = %s\n", arr, arr2);

		for (loop2 = 0; loop2 < max; loop2++){
			if (arr[loop2] == ','){
				count++;
			}
		}


		if (count == 1){

			//정수 2개와 문장 하나를 배열로 부터 읽는다.
			sscanf(arr, " %d, %d %[^\n]s ", &num1, &num2, str);

			//첫번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//첫번째 정수와 두번째 정수 합성
			chgnum2 = number_mix(num1, num2);

			//두번째 정수와 문장 저장

			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

		}
		else if (count == 2){

			//정수 3개와 문장 하나를 배열로 부터 읽는다.
			sscanf(arr, " %d, %d, %d %[^\n]s ", &num1, &num2, &num3, str);

			//첫번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//첫번째 정수와 두번째 정수 합성
			chgnum2 = number_mix(num1, num2);

			//두번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//첫번째 정수와 세번째 정수 합성
			chgnum3 = number_mix(num1, num3);

			//세번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);
		}

		else if (count == 3){


			//정수 4개와 문장 하나를 배열로 부터 읽는다.
			sscanf(arr, " %d, %d, %d, %d %[^\n]s ", &num1, &num2, &num3, &num4, str);

			//첫번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//첫번째 정수와 두번째 정수 합성
			chgnum2 = number_mix(num1, num2);

			//두번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//첫번째 정수와 세번째 정수 합성
			chgnum3 = number_mix(num1, num3);

			//세번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);

			//첫번째 정수와 네번째 정수 합성
			chgnum4 = number_mix(num1, num4);

			//네번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum4, str);
		}


		else if (count == 4){


			//정수 5개와 문장 하나를 배열로 부터 읽는다.
			sscanf(arr, " %d, %d, %d, %d, %d %[^\n]s ", &num1, &num2, &num3, &num4, &num5, str);

			//첫번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//첫번째 정수와 두번째 정수 합성
			chgnum2 = number_mix(num1, num2);

			//두번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//첫번째 정수와 세번째 정수 합성
			chgnum3 = number_mix(num1, num3);

			//세번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);

			//첫번째 정수와 네번째 정수 합성
			chgnum4 = number_mix(num1, num4);

			//네번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum4, str);

			//첫번째 정수와 다섯번째 정수 합성
			chgnum5 = number_mix(num1, num5);

			//다섯번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum5, str);
		}

		else if (count == 5){


			//정수 5개와 문장 하나를 배열로 부터 읽는다.
			sscanf(arr, " %d, %d, %d, %d, %d, %d %[^\n]s ", &num1, &num2, &num3, &num4, &num5, &num6, str);

			//첫번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//첫번째 정수와 두번째 정수 합성
			chgnum2 = number_mix(num1, num2);

			//두번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//첫번째 정수와 세번째 정수 합성
			chgnum3 = number_mix(num1, num3);

			//세번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);

			//첫번째 정수와 네번째 정수 합성
			chgnum4 = number_mix(num1, num4);

			//네번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum4, str);

			//첫번째 정수와 다섯번째 정수 합성
			chgnum5 = number_mix(num1, num5);

			//다섯번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum5, str);

			//첫번째 정수와 여섯번째 정수 합성
			chgnum6 = number_mix(num1, num6);

			//여섯번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", chgnum6, str);
		}

		else{

			//정수 1개와 문장 하나를 배열로 부터 읽는다.
			sscanf(arr, " %d %[^\n]s ", &num1, str);

			//첫번째 정수와 문장 저장
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

		}

		count = 0;
	};


	fclose(fp);
	fclose(fp2);
	printf("번호 나누기 완료\n");
	printf("중복 지우기 시작\n");

}


int number_mix(const int big, const int small)
{
	int digit;
	for (digit = 1; digit < small; digit *= 10);
	return big / digit * digit + small;
}