SafariZone_Center_MapScripts:: @ 8162357
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZone_Center_OnTransition
	.byte 0

SafariZone_Center_OnTransition:: @ 816235D
	setworldmapflag FLAG_WORLD_MAP_SAFARI_ZONE_CENTER
	end

SafariZone_Center_EventScript_162361:: @ 8162361
	msgbox gUnknown_81777F2, MSGBOX_SIGN
	end

SafariZone_Center_EventScript_16236A:: @ 816236A
	msgbox gUnknown_81777FD, MSGBOX_SIGN
	end

SafariZone_Center_EventScript_162373:: @ 8162373
	msgbox gUnknown_817782F, MSGBOX_SIGN
	end
