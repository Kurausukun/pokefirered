SevenIsland_TanobyRuins_MoneanChamber_MapScripts:: @ 8164CCF
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_MoneanChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_MoneanChamber_OnTransition:: @ 8164CD5
	setworldmapflag FLAG_WORLD_MAP_SEVEN_ISLAND_TANOBY_RUINS_MONEAN_CHAMBER
	call EventScript_1A925E
	end
