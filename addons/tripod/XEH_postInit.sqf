#include "script_component.hpp"

if (!hasInterface) exitWith {};

GVAR(adjustPFH) = -1;

GVAR(height) = 0;

// Cancel adjustment if interact menu opens
["ace_interactMenuOpened", {[ACE_player] call FUNC(handleInteractMenuOpened)}] call CBA_fnc_addEventHandler;

// Cancel adjusting on player change.
["ace_playerChanged", {_this call FUNC(handlePlayerChanged)}] call CBA_fnc_addEventHandler;
["ace_playerVehicleChanged", {[ACE_player, objNull] call FUNC(handlePlayerChanged)}] call CBA_fnc_addEventHandler;

// handle falling unconscious
["ace_unconscious", {_this call FUNC(handleUnconscious)}] call CBA_fnc_addEventHandler;

// @todo captivity?
