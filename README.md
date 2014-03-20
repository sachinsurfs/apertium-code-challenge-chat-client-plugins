apertium-code-challenge-chat-client-plugins
===========================================

This contains the code for the plugins for the coding challenge "Apertium in chat clients"

Files present: 

Str_rev.c - This contains the source code for Pidgin plugin which  when enabled, reads text from highlighted chat, and if the text contains three asterisk(***) , reverses the string and echoes reversed string instead.

Str_rev.so- This contains the executable file for Pidgin plugin(I know github hates these, but just added this one for convenience) . The plugin can be located by pidgin by placing it in the ~/.purple/plugins folder.
(For windows, run "make -f Makefile.mingw Str_rev.dll" and move the resulting .dll file to %APPDATA%\.purple\plugins)

Xcplugin.c - This contains the source code for Xchat plugin which  when enabled, reads text from highlighted chat, and if the text contains three asterisk(***) , reverses the string and echoes it back.

Xcplugin.so - This contains the executable file for Pidgin plugin.

Xchatpatch.txt - This is a patch file , for the latest xchat version source tarball present. The plugin is present in /xchat-2.8.8/plugins/ 
This way the plugin source code can be compiled.

pidginpatch.txt - This is a patch file , for the latest pidgin version source tarball. The plugin is present in /pidgin-2.10.9/libpurple/plugins/  .This way the plugin source code can be compiled.
