/*
 * Author: bux, commy2
 * Replace the disposable launcher with the used dummy.
 *
 * Arguments:
 * 0: unit - Object the event handler is assigned to <OBJECT>
 * 1: weapon - Fired weapon <STRING>
 * 2: muzzle - Muzzle that was used <STRING>
 * 3: mode - Current mode of the fired weapon <STRING>
 * 4: ammo - Ammo used <STRING>
 * 5: magazine - magazine name which was used <STRING>
 * 6: projectile - Object of the projectile that was shot <OBJECT>
 *
 * Return Value:
 * Nothing
 *
 * Example:
 * [fromBisFiredEH] call ace_disposable_fnc_replaceATWeapon;
 *
 * Public: No
 */
#include "script_component.hpp"

private ["_unit", "_weapon", "_projectile", "_replacementTube", "_items"];

_unit = _this select 0;
_weapon = _this select 1;
_projectile = _this select 6;

if (!local _unit) exitWith {};

_replacementTube = getText (configFile >> "CfgWeapons" >> _weapon >> "ACE_UsedTube");
if (_replacementTube == "") exitWith {}; //If no replacement defined just exit
if (_weapon != (secondaryWeapon _unit)) exitWith {}; //just to be sure


//Save array of items attached to launcher
_items = secondaryWeaponItems _unit;
//Replace the orginal weapon with the 'usedTube' weapon
_unit addWeapon _replacementTube;
//Makes sure the used tube is still equiped
_unit selectWeapon _replacementTube;
//Re-add all attachments to the used tube
{
    if (_x != "") then {_unit addSecondaryWeaponItem _x};
} forEach _items;


// AI - Remove the ai's missle launcher tube after the missle has exploded
if !([_unit] call EFUNC(common,isPlayer)) then {
    [{
        EXPLODE_2_PVT(_this,_params,_pfhId);
        EXPLODE_3_PVT(_params,_unit,_tube,_projectile);

        //don't do anything until projectile is null (exploded/max range)
        if (isNull _projectile) then {
            //Remove PFEH:
            [_pfhId] call cba_fnc_removePerFrameHandler;

            //If (tube is dropped) OR (is dead) OR (is player) just exit
            if (((secondaryWeapon _unit) != _tube) || {!alive _unit} || {([_unit] call EFUNC(common,isPlayer))}) exitWith {};

            private ["_items", "_container"];

            _items = secondaryWeaponItems _unit;
            _container = createVehicle ["GroundWeaponHolder", position _unit, [], 0, "CAN_COLLIDE"];
            _container setPosAsl (getPosAsl _unit);
            _container addWeaponCargoGlobal [_tube, 1];
            {
                if (_x != "") then {_container addItemCargoGlobal [_x, 1];};
            } forEach _items;
            _unit removeWeaponGlobal _tube;
        };
    }, 1, [_unit, _replacementTube, _projectile]] call CBA_fnc_addPerFrameHandler;
};
