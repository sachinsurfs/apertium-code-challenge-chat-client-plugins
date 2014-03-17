/* This is a plugin made by Sachin Shastri <sachinsurfs@gmail.com> for gsoc/apertium in chat client coding challenge. It reverses a string with three asterisk*/

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

/* Include glib.h for various types */
#include <glib.h>

/* In can config.h predefines Plugin */
#ifndef PURPLE_PLUGINS
# define PURPLE_PLUGINS
#endif

/* Necessary libpurple headers for this plugin. */
#include "internal.h"
#include "plugin.h"
#include "notify.h"
#include "util.h"
#include "version.h"
#include <stdio.h>
#include <string.h>
#define PLUGIN_ID "core-sachinsurfs-String_Rev"
#define PLUGIN_AUTHOR "Sachin Shastri <sachinsurfs@gmail.com>"
int count_chars(char*,char);

PurplePlugin *plugin_handle = NULL;
/* Message formatting. If the message contains three asterisk, it is replaced with a reversed string*/
static gboolean outgoing_msg_cb(PurpleAccount *account, const char *who, char **message,
		PurpleConversation *conv, PurpleMessageFlags flags, gpointer null)
{
	int count=0;
	count=count_chars(*message,'*');
	if(count==3)
	{char *src = *message;
		char *end = src + strlen(src) - 1;

		while (end > src)
		{
			char t = *end;
			*end-- = *src;
			*src++ = t;
		}


//		g_free(*end);
	}
	return FALSE;
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

	static gboolean
plugin_load(PurplePlugin *plugin)
{
	void *handle = purple_conversations_get_handle();
	plugin_handle = plugin;
	purple_signal_connect(handle, "receiving-im-msg", plugin,
			PURPLE_CALLBACK(outgoing_msg_cb), NULL);
	purple_signal_connect(handle, "sending-im-msg", plugin,
			PURPLE_CALLBACK(outgoing_msg_cb), NULL);

	return TRUE;
}



/**
 * Plugin Description
 */
static PurplePluginInfo info = {
	PURPLE_PLUGIN_MAGIC,        /* magic number */
	PURPLE_MAJOR_VERSION,       /* purple major */
	PURPLE_MINOR_VERSION,       /* purple minor */
	PURPLE_PLUGIN_STANDARD,     /* plugin type */
	NULL,                       /* UI requirement */
	0,                          /* flags */
	NULL,                       /* dependencies */
	PURPLE_PRIORITY_DEFAULT,    /* priority */

	PLUGIN_ID,                  /* id */
	"Reversal plugin",      /* name */
	"1.0",                      /* version */
	"Reverses string",      /* summary */
	"On entering '*' three times , string is reversed ",      /* description */
	PLUGIN_AUTHOR,              /* author */
	"http://pidgin.im",         /* homepage */

	plugin_load,                /* load */
	NULL,                       /* unload */
	NULL,                       /* destroy */

	NULL,                       /* ui info */
	NULL,                       /* extra info */
	NULL,                       /* prefs info */
	NULL,                       /* actions */
	NULL,                       /* reserved */
	NULL,                       /* reserved */
	NULL,                       /* reserved */
	NULL                        /* reserved */
};

	static void
init_plugin(PurplePlugin *plugin)
{
}

PURPLE_INIT_PLUGIN(stringreversal, init_plugin, info)
