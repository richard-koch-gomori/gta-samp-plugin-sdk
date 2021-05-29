//----------------------------------------------------------
//
//   SA:MP Multiplayer Modification For GTA:SA
//   Copyright 2004-2007 SA:MP Team
//
//----------------------------------------------------------

#include "../SDK/amx/amx.h"
#include "../SDK/plugincommon.h"

//----------------------------------------------------------

typedef void (*logprintf_t)(char* format, ...);

logprintf_t logprintf;
void **ppPluginData;
extern void *pAMXFunctions;

//----------------------------------------------------------
// The Support() function indicates what possibilities this
// plugin has. The SUPPORTS_VERSION flag is required to check
// for compatibility with the server. 

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

//----------------------------------------------------------
// The Load() function gets passed on exported functions from
// the SA-MP Server, like the AMX Functions and logprintf().
// Should return true if loading the plugin has succeeded.

PLUGIN_EXPORT bool PLUGIN_CALL Load( void **ppData ) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

	logprintf( "Plugin helloworld.dll got loaded." );
	return true;
}

//----------------------------------------------------------
// The Unload() function is called when the server shuts down,
// meaning this plugin gets shut down with it.

PLUGIN_EXPORT void PLUGIN_CALL Unload( )
{
	logprintf( "Plugin helloworld.dll got unloaded." );
}

//----------------------------------------------------------
// This is the sourcecode of the HelloWorld pawn native that we
// will be adding. "amx" is a pointer to the AMX-instance that's
// calling the function (e.g. a filterscript) and "params" is
// an array to the passed parameters. The first entry (params[0])
// is equal to  4 * PassedParameters, e.g. 16 for 4 parameters.

// native HelloWorld();
static cell AMX_NATIVE_CALL n_HelloWorld( AMX* amx, cell* params )
{
	logprintf( "Hello World, from the HelloWorld plugin!" );
	return 1;
}

// And an array containing the native function-names and the functions
// specified with them, e.g. HelloWorld -> n_HelloWorld in this example.
AMX_NATIVE_INFO HelloWorldNatives[ ] =
{
	{ "HelloWorld",			n_HelloWorld },
	{ 0,					0 }
};

//----------------------------------------------------------
// The AmxLoad() function gets called when a new gamemode or
// filterscript gets loaded with the server. In here we register
// the native functions we like to add to the scripts.

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad( AMX *amx ) 
{
	return amx_Register( amx, HelloWorldNatives, -1 );
}

//----------------------------------------------------------
// When a gamemode is over or a filterscript gets unloaded, this
// function gets called. No special actions needed in here.

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx ) 
{
	return AMX_ERR_NONE;
}
