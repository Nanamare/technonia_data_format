#include <stdio.h>
#include <iostream>
#include <string>
#include <map>

#pragma warning(disable: 4996)

using   namespace   std;

//숫자 인지 아닌지 체크
#define is_numeric( c ) ( (c) <= '9' && (c) >= '0' ) 

//tap이거나 숫자면 str++
inline  void    skip_non_numeric(char*& str)
{
	while (*str && *str != '\t' && !is_numeric(*str)) str++;
}

//tab이후 문자열에 저장
inline  char*   get_after_tab(char* str)
{
	while (*str && *str++ != '\t');
	return str;
}

//숫자문자열 얻기
size_t          get_number_string(char*& str, char* number_string)
{
	size_t  length = 0;
	char*   ptr = number_string;
	skip_non_numeric(str);
	while (is_numeric(*str)) *ptr++ = *str++, length++;
	*ptr = 0;
	return length;
}

//양식에 맞게 숫자 복사
void            mix_number_string(char* dst, const char* src)
{
	size_t  len_tgt = strlen(dst);
	size_t  len_src = strlen(src);
	if (len_tgt <= len_src) strcpy(dst, src);
	else strcpy(dst + len_tgt - len_src, src);
}

//추출 조합
size_t          extract_phone_number()
{
	FILE*   ifp = fopen("beforetotal.txt", "rb");
	if (!ifp)  return 0;
	FILE*   ofp = fopen("aftertotal.txt", "wb+");
	if (!ofp)  return 0;

	char    line[256];

	map< string, string > phone_data;
	map< string, string, less<string> >::iterator iter;
	typedef pair< string, string > phone_data_pair;

	int     counter = 0;
	while (fgets(line, sizeof line, ifp))
	{
		char*   ptr = line;
		char    number_string[16], mixed_number_string[16] = { 0 };
		char*   description = get_after_tab(line);
		while (get_number_string(ptr, number_string))
		{
			mix_number_string(mixed_number_string, number_string);
			phone_data.insert(phone_data_pair(mixed_number_string, description));
			counter++;
		}
	}

	for (iter = phone_data.begin(); iter != phone_data.end(); ++iter)
		fprintf(ofp, "%s\t%s", iter->first.c_str(), iter->second.c_str());

	printf("%d duplicated records skipped\n", counter - phone_data.size());

	fclose(ifp);
	fclose(ofp);
	return  phone_data.size();
}

int main()
{
	printf("total %d records extracted\n", extract_phone_number());
	getchar();
	return 0;
}