/*This is a plugin made by Sachin Shastri <sachinsurfs@gmail.com> as a part of the coding challenge for apertium*/
#include "xchat-plugin.h"
#include <stdio.h>
#include <string.h>

#define PNAME "String_Rev"
#define PDESC "Reverses the message if string has ***"
#define PVERSION "1.0"
int count_chars(char*,char);
void stcpy(char* , char* );
static xchat_plugin *ph;   /* plugin handle */
static int enable = 1;

static int strrev(char *word[],void *userdata)
{

	int count=0;
	//stcpy(word[2],m);   
	char *p = NULL;
	char *n= word[2];
	p = malloc(strlen(n) + 1);
	char *m=p;
	for (; *n != '\0'; n++, p++) {
		*p = *n;
	}

	*p = '\0';	

	count=count_chars(m,'*');
	if(count==3)
	{char *src = m;
		char *end = src + strlen(src) - 1;

		while (end > src)
		{
			char t = *end;
			*end-- = *src;
			*src++ = t;
		}

	}
	xchat_print(ph, m);
	return XCHAT_EAT_NONE; 
}
int count_chars( char* string, char ch)
{int count = 0,i;
	int length = strlen(string);

	for (i = 0; i < length; i++)
	{
		if (string[i] == ch)
		{
			count++;
		}
	}

	return count;
}

void xchat_plugin_get_info(char **name, char **desc, char **version, void **reserved)
{
	*name = PNAME;
	*desc = PDESC;
	*version = PVERSION;
}

int xchat_plugin_init(xchat_plugin *plugin_handle,
		char **plugin_name,
		char **plugin_desc,
		char **plugin_version,
		char *arg)
{
	/* we need to save this for use with any xchat_* functions */
	ph = plugin_handle;

	/* tell xchat our info */
	*plugin_name = PNAME;
	*plugin_desc = PDESC;
	*plugin_version = PVERSION;
	xchat_hook_print(ph, "Channel Message", XCHAT_PRI_NORM, strrev, 0);
	return 1;       /* return 1 for success */
}
