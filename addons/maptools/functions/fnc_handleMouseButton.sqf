/*
 * Author: esteldunedain
 * Handle mouse buttons.
 *
 * Arguments:
 * 0: 1 if mouse down down, 0 if mouse button up (Number)
 * 1: Parameters of the mouse button event
 *
 * Return Value:
 * Boolean, true if event was handled
 */
#define DEBUG_MODE_FULL
#include "script_component.hpp"

params ["_dir", "_params"];
_params params ["_control", "_button", "_screenPosX", "_screenPosY", "_shiftKey", "_ctrlKey", "_altKey"];
TRACE_2("params",_dir,_params);


if (_ctrlKey && {_button == 0}) exitWith {
    if (GVAR(freedrawing) && {_dir == 0}) then {
        GVAR(freedrawing) = false;
        GVAR(drawPosEnd) = _control ctrlMapScreenToWorld [_screenPosX, _screenPosY];
        TRACE_2("ending",GVAR(freedrawing),GVAR(drawPosEnd));
        [{
            diag_log text format ["MarkerPos %1=%2", getMarkerPos (allMapMarkers select (count allMapMarkers - 1)), GVAR(drawPosStart) distance2d (getMarkerPos (allMapMarkers select (count allMapMarkers - 1)))];
            if ((count GVAR(freeDrawingData)) != 3) exitWith {};
            GVAR(freeDrawingData) params ["", "_startPos", "_endPos"];
            _name = (allMapMarkers select (count allMapMarkers - 1));
            _name setMarkerShape "RECTANGLE";

            _startPos set [2, 0];
            _endPos set [2, 0];
            _difPos = _endPos vectorDiff _startPos;
            _mag = vectorMagnitude _difPos;
            _name setMarkerPos (_startPos vectorAdd (_difPos vectorMultiply 0.5));
            _name setMarkerSize [5, _mag / 2];
            _name setMarkerDir (180 + (_difPos select 0) atan2 (_difPos select 1) mod 360);


            // _name setMarkerShape "POLYLINE";

        }, []] call CBA_fnc_execNextFrame;
    } else {
        if (_dir == 1) then {
            GVAR(freeDrawingData) = [];
            GVAR(freedrawing) = true;
            GVAR(drawPosStart) = _control ctrlMapScreenToWorld [_screenPosX, _screenPosY];
            TRACE_2("starting",GVAR(freedrawing),GVAR(drawPosStart));
        };
    };
};



private _handled = false;

// If it's not a left button event, exit
if (_button != 0) exitWith {_handled};

// If releasing
if (_dir != 1) then {
    if (GVAR(mapTool_isDragging) || GVAR(mapTool_isRotating)) then {
        GVAR(mapTool_isDragging) = false;
        GVAR(mapTool_isRotating) = false;
        _handled = true;
    };
} else {
    // If clicking
    if !(call FUNC(canUseMapTools)) exitWith {};

    // Transform mouse screen position to coordinates
    private _pos = _control ctrlMapScreenToWorld [_screenPosX, _screenPosY];
    _pos set [count _pos, 0];

    GVAR(mapTool_isDragging) = false;
    GVAR(mapTool_isRotating) = false;

    // If no map tool marker then exit
    if (GVAR(mapTool_Shown) == 0) exitWith {};

    // Check if clicking the maptool
    if (_pos call FUNC(isInsideMapTool)) exitWith {
        // Store data for dragging
        GVAR(mapTool_startPos) = + GVAR(mapTool_pos);
        GVAR(mapTool_startDragPos) = + _pos;

        private _rotateKeyPressed = switch (GVAR(rotateModifierKey)) do {
        case (1): {_altKey};
        case (2): {_ctrlKey};
        case (3): {_shiftKey};
            default {false};
        };

        if (_rotateKeyPressed) then {
            // Store data for rotating
            GVAR(mapTool_startAngle) = + GVAR(mapTool_angle);
            GVAR(mapTool_startDragAngle) = (180 + ((GVAR(mapTool_startDragPos) select 0) - (GVAR(mapTool_startPos) select 0)) atan2 ((GVAR(mapTool_startDragPos) select 1) - (GVAR(mapTool_startPos) select 1)) mod 360);
            // Start rotating
            GVAR(mapTool_isRotating) = true;
        } else {
            // Start dragging
            GVAR(mapTool_isDragging) = true;
        };
        _handled = true;
    };
};

_handled
