#ifndef PHP_TP_STRING_H
#define PHP_TP_STRING_H 1

char* strrstr(const char *haystack, const char *needle)
{
	char *r = NULL;

	if (!needle[0])
		return (char*)haystack + strlen(haystack);
	while (1) {
		char *p = strstr(haystack, needle);
		if (!p)
			return r;
		r = p;
		haystack = p + 1;
	}
}

int strpos(char *haystack, char *needle)
{
	char *p = strstr(haystack, needle);
	if (p)
		return p - haystack;
	return -1;
}

int strrpos(char *haystack, char *needle)
{
	char *p = strrstr(haystack, needle);
	if (p)
		return p - haystack;
	return -1;
}

char *substr(const char *text, int position, int length)
{
   char *temp = emalloc(length + 1);
   int i, j;

   for (i = position, j = 0; i < position + length; i++, j++)
   {
       temp[j] = text[i];
   }
   temp[j] = '\0';

   return temp;
}

#endif
