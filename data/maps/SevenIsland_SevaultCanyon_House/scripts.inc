SevenIsland_SevaultCanyon_House_MapScripts:: @ 8172182
	.byte 0

SevenIsland_SevaultCanyon_House_EventScript_172183:: @ 8172183
	lock
	goto_if_set FLAG_TEMP_2, EventScript_172211
	playbgm MUS_P_SCHOOL, 0
	applymovement 1, Movement_172231
	waitmovement 0
	fadedefaultbgm
	delay 30
	applymovement 1, Movement_FacePlayer
	waitmovement 0
	msgbox gUnknown_81A4D72
	textcolor 3
	msgbox gUnknown_81A4DAF, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_172225
	msgbox gUnknown_81A4DD8
	closemessage
	call EventScript_1A6675
	compare VAR_FACING, DIR_SOUTH
	call_if_ne EventScript_172206
	delay 30
	playbgm MUS_P_SCHOOL, 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_172231
	waitmovement 0
	fadedefaultbgm
	delay 30
	call EventScript_OutOfCenterPartyHeal
	msgbox gUnknown_81A4DF5
	setflag FLAG_TEMP_2
	release
	end

EventScript_172206:: @ 8172206
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

EventScript_172211:: @ 8172211
	applymovement 1, Movement_FacePlayer
	waitmovement 0
	msgbox gUnknown_81A4D72
	release
	end

EventScript_172225:: @ 8172225
	textcolor 0
	msgbox gUnknown_81A4DC8
	release
	end

Movement_172231:: @ 8172231
	walk_in_place_down
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_fastest_right
	delay_4
	walk_in_place_fastest_up
	delay_4
	walk_in_place_fastest_left
	delay_4
	walk_in_place_fastest_down
	delay_4
	step_end

SevenIsland_SevaultCanyon_House_EventScript_172242:: @ 8172242
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHANSEY, 0
	msgbox gUnknown_81A4E26
	waitmoncry
	release
	end
