SilphCo_3F_MapScripts:: @ 81616C5
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_3F_OnLoad
	.byte 0

SilphCo_3F_OnLoad:: @ 81616CB
	call_if_unset FLAG_SILPH_3F_DOOR_1, EventScript_Close3FDoor1
	call_if_unset FLAG_SILPH_3F_DOOR_2, EventScript_Close3FDoor2
	end

SilphCo_3F_EventScript_1616DE:: @ 81616DE
	lock
	faceplayer
	compare VAR_MAP_SCENE_SILPH_CO_11F, 1
	goto_if_ge EventScript_1616F5
	msgbox gUnknown_81758AD
	release
	end

EventScript_1616F5:: @ 81616F5
	msgbox gUnknown_81758D3
	release
	end

SilphCo_3F_EventScript_1616FF:: @ 81616FF
	msgbox gUnknown_81759DC, MSGBOX_SIGN
	end

SilphCo_3F_EventScript_161708:: @ 8161708
	trainerbattle_single TRAINER_SCIENTIST_JOSE, Text_175948, Text_17597D
	msgbox gUnknown_8175990, MSGBOX_AUTOCLOSE
	end

SilphCo_3F_EventScript_16171F:: @ 816171F
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_25, Text_1758F6, Text_175911
	msgbox gUnknown_817591C, MSGBOX_AUTOCLOSE
	end
