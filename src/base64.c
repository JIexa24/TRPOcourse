#include "../include/base64.h"

char BUKAFKI[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; // Таблица символов кодировки Base64
const int UNKNOWN_SYMBOL = 100; // При обнаружении недопустимого символа

// Функция кодирует 3 входных байта в 4 выходных
void B64Encode(unsigned char in[3], int len, unsigned char out[4])
{
	out[0] = BUKAFKI[in[0] >> 2];
	out[1] = BUKAFKI[((in[0] & 0x03) << 4) | (in[1] >> 4)];
	out[2] = BUKAFKI[((in[1] & 0x0F) << 2) | (in[2] >> 6)];
	out[3] = BUKAFKI[in[2] & 0x3F]; 

	// Если на вход поступило меньше 3х "достоверных" байтов,
	// дополняем выходную последовательность спец. символами '='
	if (len <= 2)
		out[3] = '=';
	if (len == 1)
		out[2] = '=';
}


// Получить индекс символа в таблице B64TABLE
unsigned int getB64Index(unsigned char c)
{
	int i;
	for (i=0; i<64; i++)
		if (c == BUKAFKI[i])
			return i;
	
	return UNKNOWN_SYMBOL;	// Если символ в таблице не найден
}

// Обратное преобразование - 4 входных байта, закодированных 
// в Base64, раскодируем в 3 исходных байта, и возвращаем
// количество "достоверных" раскодированных символов
int B64Decode(unsigned char in[4], unsigned char out[3])
{
	int i;
	for (i = 0; i < 4; i++ )
		in[i] = getB64Index( in[i] );

	out[0] = ( in[0] << 2 ) | ( ( in[1] & 0x30 ) >> 4 );
	out[1] = ( in[1] << 4 ) | ( ( in[2] & 0x3C ) >> 2 );
	out[2] = ( in[2] << 6 ) | in[3];

	int len = 3;
	if ( in[2] == UNKNOWN_SYMBOL ) //Символ не найден в таблице ('=')
		len--;
	if ( in[3] == UNKNOWN_SYMBOL )
		len--;

	return len;
}

char *BASE64(int desh, FILE * fout, char ** test)
{
	//char *test = (char *)malloc(sizeof(test));
	int lenght = 0, vvod = 1;
	int t;

	for (t = 0; t < 60; t++)
		{ 
		printf ("-");
		}
		printf ("\n");
if (*test == NULL) {
   *test = (char *)malloc(sizeof(char *));
   printf("Enter coding word \n");
   while (vvod == 1) {
    scanf("%c", &(*test)[lenght]);

    if ((*test)[lenght] == '\n'){
    	(*test)[lenght] = '\0';
      break;
    }
    *test = (char *)realloc(*test, ++lenght + 1);
  }
}
	
char *encoded = (char *)malloc(100 * sizeof(char *));  // Сюда поместим закодированную последовательность
	int j = 0,i = 0, k = 0;
if (desh == 0) {
   	// Кодирование
	
	for (i = 0; i < strlen( *test ); )
	{
		int len = 1;
		unsigned char in[3]; // Временная последовательность для кодирования (буфер)
		
		// Копируем 3 очередных символа из исходной строки в буфер
		in[0] = (*test)[i++];
		if (i<strlen((*test)))
		{
			in[1] = (*test)[i++];
			len++;
		}
		if (i<strlen((*test)))
		{
			in[2] = (*test)[i++];
			len++;
		}
	
		unsigned char out[4]; // Буфер для закодированных байтов

		B64Encode(in, len, out);

		// Копируем закодированные байты в результирующую строку
		encoded[j++] = out[0];
		encoded[j++] = out[1];
		encoded[j++] = out[2];
		encoded[j++] = out[3];
	}
	encoded[j] = '\0'; // Добавляем "конец строки" (для вывода на экран)
}
else if (desh == 1) {
   	// Декодирование
		j=0; 
	for (i = 0; i < strlen( (*test) ); )
	{
		unsigned char in[4];

		for (k = 0; k < 4; k++ )
			in[k] = (*test)[ i++ ];
		
		unsigned char out[3];

		int len = B64Decode(in, out);

		for (k = 0; k < len; k++ )
			encoded[ j++ ] = out[k];
	}
	encoded[j] = '\0';
}
  if (fout == NULL) {
    printf("\nBase64\n\n");
    printf("word: %s\n\n", *test);
    printf("rezult: %s\n", encoded);
    printf("\n\n");
  }
  else {
    fprintf(fout, "\nBase64\n\n");
    fprintf(fout, "word: %s\n\n", *test);
    fprintf(fout, "rezult: %s\n", encoded);
    fprintf(fout,"\n\n");
  }	

  return encoded;
}

