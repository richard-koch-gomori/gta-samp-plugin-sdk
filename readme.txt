SA:MP 0.2 Pawn Plugin SDK
June 2007
Readme

================================

San Andreas Multiplayer 0.2 introduces a new powerful tool
to enhance the gamemodes you create even more: plugins. With
the full power of C(++) available to you, the possibilities
are ranging from database-interfaces to webservers and full
gamemodes. 

The SA-MP plugin SDK contains an easy hello-world example
to demonstrate the basic usage of plugins. All plugins have
access to a set of functions provided by the pawn-toolkit,
so you technically can create any command you like. A sidenote
on this is that you cannot access SA-MP's internal systems,
including the netcode-part, so adding new features which
require client-side modifications is not possible.

In order to create your own plugin, use your favorite C (or
C++) editor and create a new project. Every project needs
to contain the following files:

- amxplugin.cpp
- plugin.h
- plugincommon.h
- amx.h

Incase you want to compile your plugin on Linux operating
systems, you will need to include the files getch.c, getch.h
and sclinux.h as well. Linux also needs the compile flags
"-DLINUX -Iamx/" with your favorite compiler, GCC for example.

Next to that, you will need to create a file that contains the 
code for your plugin (which is helloworld.cpp in this SDK 
package),which needs to contain a number of functions which 
can be accessed by the SA-MP Server. These functions, 
which need to be visible to other programs (they need to be 
exported, see helloworld.def), are the following:

- Load           Called when the plugin itself gets initialized.
- AmxLoad        Called when a new gamemode/filterscript is loaded.
- Unload         When the server shuts down, this will be called.
- AmxUnload      Called on the moment that a gamemode/filterscript stops.
- Supports       Called right before Load(), exports the version.

Again, see the helloworld.cpp file for an example how
exactly these functions should work. The logprintf() function
is available to print a line of text to the server's console,
but also to the server_log.txt file. Other data exported
to your plugin are the addresses for the AMX-toolkit functions,
so you don't have to implent those yourself. Please do remember
that Pawn is singlethreaded, incase you are thinking of using
multiple threads in your plugin!

In order to load up your plugins, modify your server.cfg file
and add a line saying "plugins Name1 Name2", where Name# gets
replaced by the filename of your plugin (without .dll!). After
this your plugin is completely usable and will be loaded
by the server.

For more plugin examples and ready-to-go plugins, please check
the Trac-website at http://dev.sa-mp.com or the plugin forum
on the SA-MP Forums, which can be found on http://forum.sa-mp.com

(c)2005-2007 SA-MP Team

