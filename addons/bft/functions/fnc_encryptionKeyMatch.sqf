/*
 * Author: Glowbal
 *
 *
 * Arguments:
 * 0: keySetOne <ARRAY>
 * 1: keySetTwo <ARRAY>
 *
 * Return Value:
 * has common keys? <BOOLEAN>
 *
 * Public: No
 */

#include "script_component.hpp"

params ["_keySetOne", "_keySetTwo"];

private ["_return"];
// ToDo: replace with arrayIntersect when available
// count (_keySetOne arrayIntersect _keySetTwo) > 0

_return = false;
{
    if (_x in _keySetTwo) exitWith { _return = true; };
} forEach _keySetOne;

_return
