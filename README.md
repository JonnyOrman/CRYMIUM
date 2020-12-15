# CRYMIUM

CRYMIUM is a plugin for CRYENGINE that allows you to use UIs made with web technologies in your games. It runs on the Chromium Embedded Framework.

It is still a work in progress and contributions are very welcome!

## Building CRYMIUM

Requirements

Make sure you have the following installed:
- Visual Studio
- CMake
- CryEngine 5.6

### Clone CRYMIUM and create the solution
- Clone the repo
- Open a command prompt in the cloned repo directory and create a new directory called 'build'
```mkdir build```
- cd into the new Build directory
```cd build```
- Use CMake to build the CRYMIUM code and produce a Visual Studio solution
```cmake -G "Visual Studio 16" -A x64 ../code```
- Open build/CRYMIUM.sln in Visual Studio

CRYMIUM consists of two parts: The the renderer sub process and the CRYENGINE plugin. We need to build each and put them where they are needed.

### Build the sub process

- With the solution open in Visual Studio, find the 'libcef_dll_wrapper' project in the solution explorer, right click it and select 'Build'
- When the build is finished, find the 'Crymium.SubProcess' project in the solution explorer, right click it and select 'Build'

### Build the CRYMIUM plugin

- Find the 'libcef_dll_wrapper' project in the solution explorer, right click it and select 'Properties'
- In the left hand menu go to Configuration Properties > C/C++ > Code Generation and set the 'Runtime Library' value to 'Multi-threaded Debug DLL (/MDd)', then click 'Apply' and close the properties window
- In the solution explorer right click the 'libcef_dll_wrapper' project and select 'Build'
- When the build is finished, find the 'Crymium' project in the solution explorer, right click it and select 'Build'

## Installing CRYMIUM

### Create a CRYENGINE project
- Open CRYENGINE Launcher and create a new project using the C++ Thrid Person Shooter template (you can use any C++ template you like but it might be easier to follow the guide using the same template)
- Close the CRYENGINE Editor window that opens

### Generate the project's CMakeLists file and modify it to include CRYMIUM in the build

- In the newly created project's root directory right click the 'Game.cryproject' file and select 'Generate Solution'
- Close the console window that opens. This will generate a CMakeLists.txt file in the project's 'Code' directory
- Open the newly created CMakeLists.txt file and look for the section where the include directories are added. It should look something like this:
```
target_include_directories(${THIS_PROJECT}
PRIVATE
    "${CRYENGINE_DIR}/Code/CryEngine/CryCommon"
    "${CRYENGINE_DIR}/Code/CryEngine/CryAction"
    "${CRYENGINE_DIR}/Code/CryEngine/CrySchematyc/Core/Interface"
    "${CRYENGINE_DIR}/Code/CryPlugins/CryDefaultEntities/Module"
)
```
- Add the path to the CRYMIUM code and the path to the CEF directory in your cloned CRYMIUM directory. For example, if you cloned CRYMIUM into the directory C:/git your include directories list should now look like this:
```
target_include_directories(${THIS_PROJECT}
PRIVATE
    "${CRYENGINE_DIR}/Code/CryEngine/CryCommon"
    "${CRYENGINE_DIR}/Code/CryEngine/CryAction"
    "${CRYENGINE_DIR}/Code/CryEngine/CrySchematyc/Core/Interface"
    "${CRYENGINE_DIR}/Code/CryPlugins/CryDefaultEntities/Module"
    "C:/git/CRYMIUM/Code"
    "C:/git/CRYMIUM/build/third_party/cef/cef_binary_79.1.27+gd2449e5+chromium-79.0.3945.117_windows64"
)
```
- Now find the custom section at the bottom of the file:
```
#BEGIN-CUSTOM
# Make any custom changes here, modifications outside of the block will be discarded on regeneration.
#END-CUSTOM
```
- In the custom section Link Crymium.lib to the project
```
#BEGIN-CUSTOM
# Make any custom changes here, modifications outside of the block will be discarded on regeneration.
target_link_libraries(Game PUBLIC "C:/git/CRYMIUM/build/Crymium/Debug/Crymium.lib")
#END-CUSTOM
```

Crymium requires C++17 or higher. Let's modify our project to use C++17

- Add a setting in the custom section to use C++17:
```
#BEGIN-CUSTOM
# Make any custom changes here, modifications outside of the block will be discarded on regeneration.
target_link_libraries(Game PUBLIC "C:/git/CRYMIUM/build/Crymium/Debug/Crymium.lib")

set_target_properties(Game PROPERTIES
            CXX_STANDARD 17
            )
#END-CUSTOM
```

Our CMake file should be ready now, so let's create the game solution.

- Open the directory of your CRYENGINE project, open a command prompt and create a build directory
```mkdir build```
- cd into the new Build directory
```cd build```
- Use CMake to create a solution for the project
```cmake -G "Visual Studio 16" -A x64 ../code```
- In the build directory find the Game.sln solution and open it in Visual Studio
- Select Build > Build Solution
- In the Solution Explorer right click 'GameLauncher' and select Debug > Start New Instance to make sure the game starts and works. Close the game window afterwards.

### Add the CRYMIUM renderer sub process to CRYENGINE

- Find the directory containing the CRYMIUM sub process files you built earlier (e.g. C:/git/CRYMIUM/build/Crymium.SubProcess/Debug)
- Copy the following contents of the directory into the CRYENGINE bin directory (e.g. C:/Program Files (x86)/Crytek/CRYENGINE Launcher/Crytek/CRYENGINE_5.6/bin/win_x64):
	- locales
	- swiftshader
	- cef.pak
	- cef_100_percent.pak
	- cef_200_percent.pak
	- cef_extensions.pak
	- chrome_elf.dll
	- Crymium.SubProcess
	- d3dcompiler_47.dll
	- devtools_resources.pak
	- icudtl.dat
	- libcef.dll
	- libEGL.dll
	- libGLESv2.dll
	- snapshot_blob.bin
	- v8_context_snapshot.bin


### Add the CRYMIUM plugin to the project

- Find the Crymium.dll plugin you built earlier (e.g. C:/git/CRYMIUM/bin/win_x64/Crymium.dll)
- Copy Crymium.dll into your project's bin directory (e.g. C:/git/MyCrymiumProject/bin/win_x64)
- Open your project's Game.cryproject file in a text editor and find the plugins section, which should look something like this:
```
"plugins": [
			{ "guid": "", "type": "EType::Native", "path": "CryDefaultEntities" },
			{ "guid": "", "type": "EType::Native", "path": "CrySensorSystem" },
			{ "guid": "", "type": "EType::Native", "path": "CryPerceptionSystem" },
			{ "guid": "", "type": "EType::Native", "path": "bin/win_x64/Game.dll" },
			{
				"guid": "",
				"type": "EType::Native",
				"path": "CryGamePlatform",
				"platforms": [ "PS4" ]
			}
		]
```
- Add the Crymium plugin just before the Game plugin:
```
"plugins": [
			{ "guid": "", "type": "EType::Native", "path": "CryDefaultEntities" },
			{ "guid": "", "type": "EType::Native", "path": "CrySensorSystem" },
			{ "guid": "", "type": "EType::Native", "path": "CryPerceptionSystem" },
            { "guid": "", "type": "EType::Native", "path": "bin/win_x64/Crymium.dll" },
			{ "guid": "", "type": "EType::Native", "path": "bin/win_x64/Game.dll" },
			{
				"guid": "",
				"type": "EType::Native",
				"path": "CryGamePlatform",
				"platforms": [ "PS4" ]
			}
		]
```

- Make sure the game still runs (open the Visual Studio solution, right click 'GameLauncher' and select Debug > Start New Instance)

CRYMIUM is now installed and ready to use in your project!

## Using CRYMIUM

Let's create a simple HTML UI and use it in our game with CRYMIUM.

### Create a simple UI
- In the root directory of your project find the 'Assets' folder and create a new folder called 'UIs'
- In the new UIs folder create another new folder called 'MyCrymiumUI'
- In the 'MyCrymiumUI' folder create a HTML file called index.html
- Open index.html in a text editor and paste the following HTML into it:
```
<!DOCTYPE html>
<html style="height:100%;background:white">
    <body style="height:100%;margin:0">
        <div style="height:100%;display:flex;align-items:center;justify-content:center">
			<h1>CRYMIUM works!</h1>
		</div>
    </body>
</html>
```

### Use the simple UI in the CRYENGINE project

Let's update the game's code so that it opens our UI instead of loading the map when it starts.

- With the project solution still open in Visual Studio, in the Solution Explorer find Project/Game/GamePlugin.cpp
- Open GamePlugin.cpp and find the following line of code:
```
    gEnv->pConsole->ExecuteString("map example s", false, true);
```
- This line of code opens the game map. Let's comment this line out so that the map does not load when the game starts:
```
    //gEnv->pConsole->ExecuteString("map example s", false, true);
```
Instead of loading the map we want our game to open our UI when it starts.
To do this, first we need to construct an instance of an implementation of `ICrymiumContainer`, which provides instances of all the classes used with Crymium.

- In the Solution Explorer find and open Project/Game/GamePlugin.h
- Find the included headers at the top of the file:
```
#include <CrySystem/ICryPlugin.h>
#include <CryGame/IGameFramework.h>
#include <CryEntitySystem/IEntityClass.h>
#include <CryNetwork/INetwork.h>
```
- Add `#include "Crymium/Core/ICrymiumContainer.h"` to allow us to use `ICrymiumContainer`:
```
#include <CrySystem/ICryPlugin.h>
#include <CryGame/IGameFramework.h>
#include <CryEntitySystem/IEntityClass.h>
#include <CryNetwork/INetwork.h>
#include "Crymium/Core/ICrymiumContainer.h"
```
- Go to the bottom of the file and find the protected section of the CGamePlugin class:
```
protected:
	// Map containing player components, key is the channel id received in OnClientConnectionReceived
	std::unordered_map<int, EntityId> m_players;
};
```
- Add a private section at the bottom of the class under the protected section and add an `ICrymiumContainer` field:
```
protected:
	// Map containing player components, key is the channel id received in OnClientConnectionReceived
	std::unordered_map<int, EntityId> m_players;

private:
	std::unique_ptr<ICrymiumContainer> _crymiumContainer;
};
```
- Back in GamePlugin.cpp, find the header includes at the top of the file:
```
#include "StdAfx.h"
#include "GamePlugin.h"

#include "Components/Player.h"

#include <CrySchematyc/Env/IEnvRegistry.h>
#include <CrySchematyc/Env/EnvPackage.h>
#include <CrySchematyc/Utils/SharedString.h>

#include <IGameObjectSystem.h>
#include <IGameObject.h>

// Included only once per DLL module.
#include <CryCore/Platform/platform_impl.inl>
```
- Add `#include "Crymium/CrymiumContainerComposer.h"` to allow us to use `CrymiumContainerComposer`:
```
#include "StdAfx.h"
#include "GamePlugin.h"

#include "Components/Player.h"

#include <CrySchematyc/Env/IEnvRegistry.h>
#include <CrySchematyc/Env/EnvPackage.h>
#include <CrySchematyc/Utils/SharedString.h>

#include <IGameObjectSystem.h>
#include <IGameObject.h>

// Included only once per DLL module.
#include <CryCore/Platform/platform_impl.inl>
#include "Crymium/CrymiumContainerComposer.h"
```
- Find the line of code that loads the game map that we commented out earlier:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
```
- Underneath this line compose an instance of `CrymiumContainer` using `CrymiumContainerComposer::Compose()` and assign it to the `_crymiumContainer` field:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
_crymiumContainer = CrymiumContainerComposer::Compose();
```
We now have a container with all of the Crymium features.
Next, we need to initialise Crymium. We can do this by using Crymium's `ICrymiumInitialiser` interface.
An implementation of this can be retrieved form the container via its `GetCrymiumInitialiser()` method.
- After composing the container, call `GetCrymiumInitialiser()` on it to get the initialiser and call `Initialise()` on it:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
_crymiumContainer = CrymiumContainerComposer::Compose();
_crymiumContainer->GetCrymiumInitialiser()->Initialise();
```
With Crymium initialised we can now activate the UI we made earlier by using the `IUiActivator` interface.
- After initialising Crymium get the UI Activator from the container and activate the "MyCrymiumUI" UI:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
_crymiumContainer = CrymiumContainerComposer::Compose();
_crymiumContainer->GetCrymiumInitialiser()->Initialise();
_crymiumContainer->GetUiActivator()->Activate("MyCrymiumUI");
```

- Rebuild the solution

Now when you run the game you should see the HTML UI you added earlier open in the game!