/*db�� �ֱ� ���� �⺻ ���� �ٲ� ���α׷� �Դϴ� ��ȭ��ȣ 5�� ���� ���� �մϴ�*/


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
	//���� ���ϰ� ������ ����
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

			//���� 2���� ���� �ϳ��� �迭�� ���� �д´�.
			sscanf(arr, " %d, %d %[^\n]s ", &num1, &num2, str);

			//ù��° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//ù��° ������ �ι�° ���� �ռ�
			chgnum2 = number_mix(num1, num2);

			//�ι�° ������ ���� ����

			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

		}
		else if (count == 2){

			//���� 3���� ���� �ϳ��� �迭�� ���� �д´�.
			sscanf(arr, " %d, %d, %d %[^\n]s ", &num1, &num2, &num3, str);

			//ù��° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//ù��° ������ �ι�° ���� �ռ�
			chgnum2 = number_mix(num1, num2);

			//�ι�° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//ù��° ������ ����° ���� �ռ�
			chgnum3 = number_mix(num1, num3);

			//����° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);
		}

		else if (count == 3){


			//���� 4���� ���� �ϳ��� �迭�� ���� �д´�.
			sscanf(arr, " %d, %d, %d, %d %[^\n]s ", &num1, &num2, &num3, &num4, str);

			//ù��° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//ù��° ������ �ι�° ���� �ռ�
			chgnum2 = number_mix(num1, num2);

			//�ι�° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//ù��° ������ ����° ���� �ռ�
			chgnum3 = number_mix(num1, num3);

			//����° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);

			//ù��° ������ �׹�° ���� �ռ�
			chgnum4 = number_mix(num1, num4);

			//�׹�° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum4, str);
		}


		else if (count == 4){


			//���� 5���� ���� �ϳ��� �迭�� ���� �д´�.
			sscanf(arr, " %d, %d, %d, %d, %d %[^\n]s ", &num1, &num2, &num3, &num4, &num5, str);

			//ù��° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//ù��° ������ �ι�° ���� �ռ�
			chgnum2 = number_mix(num1, num2);

			//�ι�° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//ù��° ������ ����° ���� �ռ�
			chgnum3 = number_mix(num1, num3);

			//����° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);

			//ù��° ������ �׹�° ���� �ռ�
			chgnum4 = number_mix(num1, num4);

			//�׹�° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum4, str);

			//ù��° ������ �ټ���° ���� �ռ�
			chgnum5 = number_mix(num1, num5);

			//�ټ���° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum5, str);
		}

		else if (count == 5){


			//���� 5���� ���� �ϳ��� �迭�� ���� �д´�.
			sscanf(arr, " %d, %d, %d, %d, %d, %d %[^\n]s ", &num1, &num2, &num3, &num4, &num5, &num6, str);

			//ù��° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

			//ù��° ������ �ι�° ���� �ռ�
			chgnum2 = number_mix(num1, num2);

			//�ι�° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum2, str);

			//ù��° ������ ����° ���� �ռ�
			chgnum3 = number_mix(num1, num3);

			//����° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum3, str);

			//ù��° ������ �׹�° ���� �ռ�
			chgnum4 = number_mix(num1, num4);

			//�׹�° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum4, str);

			//ù��° ������ �ټ���° ���� �ռ�
			chgnum5 = number_mix(num1, num5);

			//�ټ���° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum5, str);

			//ù��° ������ ������° ���� �ռ�
			chgnum6 = number_mix(num1, num6);

			//������° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", chgnum6, str);
		}

		else{

			//���� 1���� ���� �ϳ��� �迭�� ���� �д´�.
			sscanf(arr, " %d %[^\n]s ", &num1, str);

			//ù��° ������ ���� ����
			fprintf(fp2, "0%d\t%s\r\n", num1, str);

		}

		count = 0;
	};


	fclose(fp);
	fclose(fp2);
	printf("��ȣ ������ �Ϸ�\n");
	printf("�ߺ� ����� ����\n");

}


int number_mix(const int big, const int small)
{
	int digit;
	for (digit = 1; digit < small; digit *= 10);
	return big / digit * digit + small;
}