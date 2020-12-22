# CRYMIUM

CRYMIUM is a plugin for CRYENGINE that allows you to use UIs made with web technologies (HTML, CSS, JavaScript) in your games. It runs on the Chromium Embedded Framework.

It is still a work in progress and contributions are very welcome!

## Build

### Requirements

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

CRYMIUM consists of two parts: The renderer sub process and the plugin. We need to build each and put them where they are needed.

### Build the CRYMIUM plugin and sub process

- With the solution open in Visual Studio, select Build > Build Solution. Wait for the build to finish

## Installation

### Create a CRYENGINE project
- Open CRYENGINE Launcher and create a new project using the C++ Thrid Person Shooter template (you can use any C++ template you like but it might be easier to follow the guide using the same template)
- Close the CRYENGINE Editor window that opens

### Generate the project's CMakeLists file and modify it to include CRYMIUM in the build

- In the newly created project's root directory right click the "Game.cryproject" file and select "Generate Solution"
- Close the console window that opens. This will generate a CMakeLists.txt file in the project's Code directory
- Open the newly created Code/CMakeLists.txt file and look for the section where the include directories are added. It should look something like this:
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
- In the custom section Link Crymium.lib to the project:
```
#BEGIN-CUSTOM
# Make any custom changes here, modifications outside of the block will be discarded on regeneration.
target_link_libraries(Game PUBLIC "C:/git/CRYMIUM/build/Crymium/Debug/Crymium.lib")
#END-CUSTOM
```

CRYMIUM requires C++17 or higher. Let's modify our project to use C++17

- Add a setting in the custom section to use C++17:
```
#BEGIN-CUSTOM
# Make any custom changes here, modifications outside of the block will be discarded on regeneration.
target_link_libraries(Game PUBLIC "C:/git/CRYMIUM/build/Crymium/Debug/Crymium.lib")
set_target_properties(Game PROPERTIES CXX_STANDARD 17)
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
- In the Solution Explorer right click "GameLauncher" and select Debug > Start New Instance to make sure the game starts and works. Close the game window afterwards.

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
- Add the CRYMIUM plugin just before the Game plugin:
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

- Make sure the game still runs (open the Visual Studio solution, right click "GameLauncher" in the solution explorer and select Debug > Start New Instance)

CRYMIUM is now installed and ready to use in your project!

## Usage - display a UI

Let's create a simple HTML UI and use it in our game with CRYMIUM.

### Create a simple UI
- In the root directory of your project find the "Assets" folder and create a new folder called "UIs"
- In the new UIs folder create another new folder called "SimpleUI"
- In the "SimpleUI" folder create a HTML file called "index.html"
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
To do this, first we need to construct an instance of an implementation of `ICrymiumContainer`, which provides instances of all the classes used with CRYMIUM.

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
We now have a container with all of the CRYMIUM features.
Next, we need to initialise CRYMIUM. We can do this by using CRYMIUM's `ICrymiumInitialiser` interface.
An implementation of this can be retrieved form the container via its `GetCrymiumInitialiser()` method.
- After composing the container, call `GetCrymiumInitialiser()` on it to get the initialiser and call `Initialise()` on it:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
_crymiumContainer = CrymiumContainerComposer::Compose();
_crymiumContainer->GetCrymiumInitialiser()->Initialise();
```
With CRYMIUM initialised we can now activate the UI we made earlier by using the `IUiActivator` interface.
- After initialising CRYMIUM get the UI Activator from the container and activate the "SimpleUI" UI:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
_crymiumContainer = CrymiumContainerComposer::Compose();
_crymiumContainer->GetCrymiumInitialiser()->Initialise();
_crymiumContainer->GetUiActivator()->Activate("SimpleUI");
```

- Rebuild the solution

Now when you run the game you should see the HTML UI that says "CRYMIUM works!"

## Usage - making a main menu

Let's create a main menu for our game and use CRYMIUM to render and control it.

### Create the main menu
- In the root directory of your project find the "Assets" folder and find the "UIs" folder you created earlier
- In the new UIs folder create another new folder called "MainMenu"
- In the "MainMenu" folder create a HTML file called index.html
- Open index.html in a text editor and paste the following HTML into it:
```
<!DOCTYPE html>
<html style="height:100%;background:white">
<head>
<style>
.menu-item {
	background-color: #eee;
	flex:1;
	margin:50px;
	display: flex;
	justify-content: center;
	align-items: center;
	font-size: large;
}

.menu-item:focus {
  background-color: #ccc;
}
</style>
</head>
    <body style="height:100%;margin:0">
        <div style="height:100%;max-width:100%;display:flex;flex-direction:column">
			<div id="new-game" class="menu-item" tabindex=0 onclick="onNewGameSelected()">New Game</div>
			<div id="options" class="menu-item" tabindex=0>Options</div>
			<div id="quit" class="menu-item" tabindex=0>Quit</div>
		</div>
		
		<script>
			var selectedIndex = 0;
			
			var menuItems = document.getElementsByClassName("menu-item");
			
			var menuItemCount = menuItems.length;

			var focused = menuItems[0];

			document.getElementById(menuItems[selectedIndex].id).focus();
		
			function onKeyPress(e) {
			  
				if(event.key === 'ArrowDown') {

					if(selectedIndex >= menuItemCount - 1) {
						selectedIndex = 0;
					}
					else {
						selectedIndex++;
					}

					focused = document.getElementById(menuItems[selectedIndex].id);
					focused.focus();
						
				}
				
				if(event.key === 'ArrowUp') {

					if(selectedIndex <= 0) {
						selectedIndex = menuItemCount - 1;
					}
					else {
						selectedIndex--;
					}

					focused = document.getElementById(menuItems[selectedIndex].id);
					focused.focus();

				}

				if(event.key === 'Enter' && focused != null)
				{
					focused.click();
				}

			}

			function onNewGameSelected() {

				window.cefQuery({
					request: 'new-game',
					onSuccess: function(response) {},
					onFailure: function(error_code, error_message) {}
				});
			}
			
			document.addEventListener('keydown', onKeyPress);
		</script>
    </body>
</html>
```

The main menu has three menu items: New Game, Options and Quit.
It also has some javascript that allows us to cycle between the menu items by pressing up or down on the keyboard.

### Use the main menu in the CRYENGINE project

Let's update the game's code so that it opens our main menu when it starts.

- With the project solution still open in Visual Studio, in the Solution Explorer find Project/Game/GamePlugin.cpp
- Open GamePlugin.cpp and find the code we added earlier to use the simple UI:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
_crymiumContainer = CrymiumContainerComposer::Compose();
_crymiumContainer->GetCrymiumInitialiser()->Initialise();
_crymiumContainer->GetUiActivator()->Activate("SimpleUI");
```
- Update the code so that we open the main menu instead of the simple UI:
```
//gEnv->pConsole->ExecuteString("map example s", false, true);
_crymiumContainer = CrymiumContainerComposer::Compose();
_crymiumContainer->GetCrymiumInitialiser()->Initialise();
_crymiumContainer->GetUiActivator()->Activate("MainMenu");
```
- Rebuild the solution

Now when you run the game you should see the main menu we just added. When you press up and down on your keyboard CRYMIUM will send the inputs to the menu and cycle between the options.

### Implement the New Game menu item

So far we can cycle through the menu items, but we can't actually select any of them.
Let's wire up the New Game menu item so that we can press enter on the keyboard to select it and load the game map.

The main menu sends a request to CEF when selected, using `window.cefQuery`:
```
function onNewGameSelected() {

	window.cefQuery({
		request: 'new-game',
		onSuccess: function(response) {},
		onFailure: function(error_code, error_message) {}
	});
}
```

We need to update our game code so that CRYMIUM will open the map when it receives this request. We can do this by creating an implementation of CRYMIUM's `ICefMessageHandler` and registering it for use.

- With the project solution still open in Visual Studio, in the Solution Explorer find Project/Game/GamePlugin.h
- Open GamePlugin.h and add the following class at the bottom of the file, after the closing bracket of the `CGamePlugin` class:
```
class NewGameMessageHandler : public ICefMessageHandler
{
public:
	NewGameMessageHandler(IUiCloser* uiCloser): _uiCloser(uiCloser) {}

	void Handle(std::string request)
	{
		if(request == "new-game")
		{
			gEnv->pConsole->ExecuteString("map example s", false, true);
			_uiCloser->Close();
		}
	}

private:
	IUiCloser* _uiCloser;
};
```

We now have a new `NewGameMessageHandler` class in our code that implements CRYMIUM's `ICefMessageHandler` interface.
`NewGameMessageHandler`'s `Handle` method is implemented to open the game map when the "new-game" request is received. It does this by using the line of code we commented out earlier.
It also uses CRYMIUM's `IUiCloser` to close the main menu. `IUiCloser` must be injected into the class via its constructor.

Now let's create an instance of `NewGameMessageHandler` and register it for use.

- In GamePlugin.h add an `ICefMessageHandler` field to the private section of `CGamePlugin`:
```
private:
	std::unique_ptr<ICrymiumContainer> _crymiumContainer;
	std::unique_ptr<ICefMessageHandler> _newGameMessageHandler;
};
```
- In GamePlugin.cpp, after we compose the CRYMIUM container but before we initialise CRYMIUM, assign an instance of `NewGameMessageHandler` to the new field, providing it in the `IUiCloser` instance from the CRYMIUM container, and then pass it to the container:
```
_crymiumContainer = CrymiumContainerComposer::Compose();

_newGameMessageHandler = std::make_unique<NewGameMessageHandler>(_crymiumContainer->GetUiCloser());
_crymiumContainer->Set(_newGameMessageHandler.get());

_crymiumContainer->GetCrymiumInitialiser()->Initialise();
_crymiumContainer->GetUiActivator()->Activate("MainMenu");
```
- Rebuild the solution

Now when you run the game you can select the "New Game" menu item on the main menu to open the game map!