#include "../include/base64.h"

char BUKAFKI[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; // РўР°Р±Р»РёС†Р° СЃРёРјРІРѕР»РѕРІ РєРѕРґРёСЂРѕРІРєРё Base64
const int UNKNOWN_SYMBOL = 100; // РџСЂРё РѕР±РЅР°СЂСѓР¶РµРЅРёРё РЅРµРґРѕРїСѓСЃС‚РёРјРѕРіРѕ СЃРёРјРІРѕР»Р°

// Р¤СѓРЅРєС†РёСЏ РєРѕРґРёСЂСѓРµС‚ 3 РІС…РѕРґРЅС‹С… Р±Р°Р№С‚Р° РІ 4 РІС‹С…РѕРґРЅС‹С…
void B64Encode(unsigned char in[3], int len, unsigned char out[4])
{
	out[0] = BUKAFKI[in[0] >> 2];
	out[1] = BUKAFKI[((in[0] & 0x03) << 4) | (in[1] >> 4)];
	out[2] = BUKAFKI[((in[1] & 0x0F) << 2) | (in[2] >> 6)];
	out[3] = BUKAFKI[in[2] & 0x3F]; 

	// Р•СЃР»Рё РЅР° РІС…РѕРґ РїРѕСЃС‚СѓРїРёР»Рѕ РјРµРЅСЊС€Рµ 3С… "РґРѕСЃС‚РѕРІРµСЂРЅС‹С…" Р±Р°Р№С‚РѕРІ,
	// РґРѕРїРѕР»РЅСЏРµРј РІС‹С…РѕРґРЅСѓСЋ РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚СЊ СЃРїРµС†. СЃРёРјРІРѕР»Р°РјРё '='
	if (len <= 2)
		out[3] = '=';
	if (len == 1)
		out[2] = '=';
}


// РџРѕР»СѓС‡РёС‚СЊ РёРЅРґРµРєСЃ СЃРёРјРІРѕР»Р° РІ С‚Р°Р±Р»РёС†Рµ B64TABLE
unsigned int getB64Index(unsigned char c)
{
	int i;
	for (i=0; i<64; i++)
		if (c == BUKAFKI[i])
			return i;
	
	return UNKNOWN_SYMBOL;	// Р•СЃР»Рё СЃРёРјРІРѕР» РІ С‚Р°Р±Р»РёС†Рµ РЅРµ РЅР°Р№РґРµРЅ
}

// РћР±СЂР°С‚РЅРѕРµ РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРµ - 4 РІС…РѕРґРЅС‹С… Р±Р°Р№С‚Р°, Р·Р°РєРѕРґРёСЂРѕРІР°РЅРЅС‹С… 
// РІ Base64, СЂР°СЃРєРѕРґРёСЂСѓРµРј РІ 3 РёСЃС…РѕРґРЅС‹С… Р±Р°Р№С‚Р°, Рё РІРѕР·РІСЂР°С‰Р°РµРј
// РєРѕР»РёС‡РµСЃС‚РІРѕ "РґРѕСЃС‚РѕРІРµСЂРЅС‹С…" СЂР°СЃРєРѕРґРёСЂРѕРІР°РЅРЅС‹С… СЃРёРјРІРѕР»РѕРІ
int B64Decode(unsigned char in[4], unsigned char out[3])
{
	int i;
	for (i = 0; i < 4; i++ )
		in[i] = getB64Index( in[i] );

	out[0] = ( in[0] << 2 ) | ( ( in[1] & 0x30 ) >> 4 );
	out[1] = ( in[1] << 4 ) | ( ( in[2] & 0x3C ) >> 2 );
	out[2] = ( in[2] << 6 ) | in[3];

	int len = 3;
	if ( in[2] == UNKNOWN_SYMBOL ) //РЎРёРјРІРѕР» РЅРµ РЅР°Р№РґРµРЅ РІ С‚Р°Р±Р»РёС†Рµ ('=')
		len--;
	if ( in[3] == UNKNOWN_SYMBOL )
		len--;

	return len;
}

int BASE64()
{
	char *test = (char *)malloc(sizeof(test));
	int lenght = 0, vvod = 1;
	printf("enter coding word \n");
	 while (vvod == 1) {
    scanf("%c", &test[lenght]);

    if (test[lenght] == '\n'){
    	test[lenght] = '\0';
      break;
}
    test = (char *)realloc(test, ++lenght + 1);
  }
	
	
	char encoded[100];  // РЎСЋРґР° РїРѕРјРµСЃС‚РёРј Р·Р°РєРѕРґРёСЂРѕРІР°РЅРЅСѓСЋ РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚СЊ
	
	
	printf("Original string: %s\n", test);
   	// РљРѕРґРёСЂРѕРІР°РЅРёРµ
	int j = 0,i = 0, k = 0;
	for (i = 0; i < strlen( test ); )
	{
		int len = 1;
		unsigned char in[3]; // Р’СЂРµРјРµРЅРЅР°СЏ РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚СЊ РґР»СЏ РєРѕРґРёСЂРѕРІР°РЅРёСЏ (Р±СѓС„РµСЂ)
		
		// РљРѕРїРёСЂСѓРµРј 3 РѕС‡РµСЂРµРґРЅС‹С… СЃРёРјРІРѕР»Р° РёР· РёСЃС…РѕРґРЅРѕР№ СЃС‚СЂРѕРєРё РІ Р±СѓС„РµСЂ
		in[0] = test[i++];
		if (i<strlen(test))
		{
			in[1] = test[i++];
			len++;
		}
		if (i<strlen(test))
		{
			in[2] = test[i++];
			len++;
		}
	
		unsigned char out[4]; // Р‘СѓС„РµСЂ РґР»СЏ Р·Р°РєРѕРґРёСЂРѕРІР°РЅРЅС‹С… Р±Р°Р№С‚РѕРІ

		B64Encode(in, len, out);

		// РљРѕРїРёСЂСѓРµРј Р·Р°РєРѕРґРёСЂРѕРІР°РЅРЅС‹Рµ Р±Р°Р№С‚С‹ РІ СЂРµР·СѓР»СЊС‚РёСЂСѓСЋС‰СѓСЋ СЃС‚СЂРѕРєСѓ
		encoded[j++] = out[0];
		encoded[j++] = out[1];
		encoded[j++] = out[2];
		encoded[j++] = out[3];
	}
	encoded[j] = '\0'; // Р”РѕР±Р°РІР»СЏРµРј "РєРѕРЅРµС† СЃС‚СЂРѕРєРё" (РґР»СЏ РІС‹РІРѕРґР° РЅР° СЌРєСЂР°РЅ)


   	// Р”РµРєРѕРґРёСЂРѕРІР°РЅРёРµ
	char decoded[100]; // РЎСЋРґР° РїРѕРјРµСЃС‚РёРј СЂР°СЃРєРѕРґРёСЂРѕРІР°РЅРЅСѓСЋ РїРѕСЃР»РµРґРѕРІР°С‚РµР»СЊРЅРѕСЃС‚СЊ
	
	j=0; 
	for (i = 0; i < strlen( encoded ); )
	{
		unsigned char in[4];

		for (k = 0; k < 4; k++ )
			in[k] = encoded[ i++ ];
		
		unsigned char out[3];

		int len = B64Decode(in, out);

		for (k = 0; k < len; k++ )
			decoded[ j++ ] = out[k];
	}
	decoded[j] = '\0';
	
	printf("Encoded string : %s \n", encoded);
	printf("Decoded string : %s \n", decoded);
	
}

