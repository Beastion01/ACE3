#include "script_component.hpp"

// bail if running on HC
if (!hasInterface) exitWith {};

// setup draw size variables
[1] call FUNC(updateDrawSize);
[true] call FUNC(setDrawText);

// setup of mapOpened and mapClosed events, temporary as they are in the process of being implemented in common
GVAR(mapVisibleLastFrame) = false;
[{
    // "mapOpened" event
    if ((!GVAR(mapVisibleLastFrame)) && (visibleMap)) then {
        GVAR(mapVisibleLastFrame) = true;
        ["mapOpened", []] call EFUNC(common,localEvent);
    };

    // "mapClosed" event
    if (GVAR(mapVisibleLastFrame) && (!visibleMap)) then {
        GVAR(mapVisibleLastFrame) = false;
        ["mapClosed", []] call EFUNC(common,localEvent);
    };
}, 0, []] call cba_fnc_addPerFrameHandler;

/*
// register with reporting channels when map is opened
["mapOpened",{
    // set icon size back to default
    [1] call FUNC(updateDrawSize);
    [true] call FUNC(setDrawText);
    // register reporting modes
    [EGVAR(bft,allReportingModes)] call EFUNC(bft,updateRegisteredModes);
    // set encryption key
    [[ACE_player] call EFUNC(bft,getEncryptionKey)] call EFUNC(bft,updateRegisteredEncryptionKeys);
    // start update loop
    [true,5] call EFUNC(bft,updateAvailableDevicesPosition);
}] call EFUNC(common,addEventHandler);

["mapClosed",{
    [false] call EFUNC(bft,updateAvailableDevicesPosition);
}] call EFUNC(common,addEventHandler);*/
