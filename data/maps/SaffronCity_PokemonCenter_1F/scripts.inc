SaffronCity_PokemonCenter_1F_MapScripts:: @ 816EFEC
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SaffronCity_PokemonCenter_1F_OnTransition:: @ 816EFF7
	setrespawn SPAWN_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_1F_EventScript_16EFFB:: @ 816EFFB
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end

SaffronCity_PokemonCenter_1F_EventScript_16F004:: @ 816F004
	msgbox gUnknown_819C058, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_16F00D:: @ 816F00D
	msgbox gUnknown_819C023, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_1F_EventScript_16F016:: @ 816F016
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_eq EventScript_16F02D
	msgbox gUnknown_819C0B4
	release
	end

EventScript_16F02D:: @ 816F02D
	msgbox gUnknown_819C102
	release
	end
