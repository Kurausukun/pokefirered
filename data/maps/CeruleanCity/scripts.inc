CeruleanCity_MapScripts:: @ 8166471
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_OnTransition
	.byte 0

CeruleanCity_OnTransition:: @ 8166477
	setworldmapflag FLAG_WORLD_MAP_CERULEAN_CITY
	call_if_unset FLAG_GOT_SS_TICKET, EventScript_166484
	end

EventScript_166484:: @ 8166484
	setobjectxyperm 1, 30, 12
	setobjectxyperm 5, 26, 31
	setobjectxyperm 6, 27, 31
	return

CeruleanCity_EventScript_16649A:: @ 816649A
	lockall
	setvar VAR_TEMP_1, 0
	goto EventScript_1664CC
	end

CeruleanCity_EventScript_1664A6:: @ 81664A6
	lockall
	setvar VAR_TEMP_1, 1
	setobjectxyperm 8, 23, 0
	goto EventScript_1664CC
	end

CeruleanCity_EventScript_1664B9:: @ 81664B9
	lockall
	setvar VAR_TEMP_1, 2
	setobjectxyperm 8, 24, 0
	goto EventScript_1664CC
	end

EventScript_1664CC:: @ 81664CC
	textcolor 0
	setvar VAR_MAP_SCENE_ROUTE22, 2
	playbgm MUS_RIVAL1, 0
	addobject 8
	applymovement 8, Movement_1665D3
	waitmovement 0
	msgbox gUnknown_817EAD7
	setvar VAR_LAST_TALKED, 8
	compare VAR_STARTER_MON, 2
	call_if_eq EventScript_166582
	compare VAR_STARTER_MON, 1
	call_if_eq EventScript_16658D
	compare VAR_STARTER_MON, 0
	call_if_eq EventScript_166598
	famechecker FAMECHECKER_BILL, 0
	msgbox gUnknown_817EB95
	closemessage
	playbgm MUS_RIVAL2, 0
	compare VAR_TEMP_1, 0
	call_if_eq EventScript_1665A3
	compare VAR_TEMP_1, 1
	call_if_eq EventScript_1665A3
	compare VAR_TEMP_1, 2
	call_if_eq EventScript_1665B5
	msgbox gUnknown_817ECD4
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setflag FLAG_GOT_FAME_CHECKER
	giveitem ITEM_FAME_CHECKER
	msgbox gUnknown_817ED5D
	closemessage
	applymovement 8, Movement_1665FB
	waitmovement 0
	fadedefaultbgm
	removeobject 8
	releaseall
	end

EventScript_166582:: @ 8166582
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_SQUIRTLE, Text_17EB71
	return

EventScript_16658D:: @ 816658D
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_BULBASAUR, Text_17EB71
	return

EventScript_166598:: @ 8166598
	trainerbattle_no_intro TRAINER_RIVAL_CERULEAN_CHARMANDER, Text_17EB71
	return

EventScript_1665A3:: @ 81665A3
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1665C7
	applymovement 8, Movement_1665D9
	waitmovement 0
	return

EventScript_1665B5:: @ 81665B5
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1665CD
	applymovement 8, Movement_1665EA
	waitmovement 0
	return

Movement_1665C7:: @ 81665C7
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_down
	step_end

Movement_1665CD:: @ 81665CD
	delay_16
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

Movement_1665D3:: @ 81665D3
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Movement_1665D9:: @ 81665D9
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_1665EA:: @ 81665EA
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_1665FB:: @ 81665FB
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_EventScript_166603:: @ 8166603
	lock
	faceplayer
	goto_if_defeated TRAINER_TEAM_ROCKET_GRUNT_5, EventScript_16662E
	message Text_17EE0E
	waitmessage
	playbgm MUS_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, Text_17EE70
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto EventScript_16662E
	end

EventScript_16662E:: @ 816662E
	msgbox gUnknown_817EE9C
	checkitemspace ITEM_TM28, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_166677
	giveitem_msg gUnknown_817EEBF, ITEM_TM28
	msgbox gUnknown_817EEED
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	setflag FLAG_GOT_TM28_FROM_ROCKET
	release
	end

EventScript_166677:: @ 8166677
	textcolor 0
	msgbox gUnknown_817EF07
	release
	end

CeruleanCity_EventScript_166683:: @ 8166683
	lockall
	setvar VAR_TEMP_1, 0
	applymovement 2, Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	goto EventScript_1666C3
	end

CeruleanCity_EventScript_1666A3:: @ 81666A3
	lockall
	setvar VAR_TEMP_1, 1
	applymovement 2, Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	goto EventScript_1666C3
	end

EventScript_1666C3:: @ 81666C3
	textcolor 0
	msgbox Text_17EE0E
	setvar VAR_LAST_TALKED, 2
	trainerbattle_no_intro TRAINER_TEAM_ROCKET_GRUNT_5, Text_17EE70
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	goto EventScript_16662E
	end

CeruleanCity_EventScript_1666E7:: @ 81666E7
	lock
	faceplayer
	msgbox gUnknown_817F0F1
	closemessage
	applymovement 1, Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_1666FE:: @ 81666FE
	lock
	faceplayer
	goto_if_set FLAG_GOT_SS_TICKET, EventScript_166713
	msgbox gUnknown_817F01D
	release
	end

EventScript_166713:: @ 8166713
	msgbox gUnknown_817EF89
	release
	end

CeruleanCity_EventScript_16671D:: @ 816671D
	msgbox gUnknown_817F0B2, MSGBOX_NPC
	end

CeruleanCity_EventScript_166726:: @ 8166726
	msgbox gUnknown_817EF3F, MSGBOX_NPC
	end

CeruleanCity_EventScript_16672F:: @ 816672F
	msgbox gUnknown_817F319, MSGBOX_NPC
	end

CeruleanCity_EventScript_166738:: @ 8166738
	lock
	faceplayer
	msgbox gUnknown_817F2CF
	closemessage
	applymovement 11, Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

CeruleanCity_EventScript_16674F:: @ 816674F
	lock
	random 3
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 0
	call_if_eq EventScript_1667B0
	compare VAR_0x8008, 1
	call_if_eq EventScript_1667B6
	compare VAR_0x8008, 2
	call_if_eq EventScript_1667BC
	waitmessage
	delay 40
	playse SE_PIN
	applymovement 5, Movement_QuestionMark
	waitmovement 0
	delay 30
	compare VAR_0x8008, 0
	call_if_eq EventScript_1667C2
	compare VAR_0x8008, 1
	call_if_eq EventScript_1667CB
	compare VAR_0x8008, 2
	call_if_eq EventScript_1667D4
	release
	end

EventScript_1667B0:: @ 81667B0
	message Text_17F183
	return

EventScript_1667B6:: @ 81667B6
	message Text_17F1C2
	return

EventScript_1667BC:: @ 81667BC
	message Text_17F1E9
	return

EventScript_1667C2:: @ 81667C2
	msgbox gUnknown_817F1A1
	return

EventScript_1667CB:: @ 81667CB
	msgbox gUnknown_817F1D2
	return

EventScript_1667D4:: @ 81667D4
	msgbox gUnknown_817F1FC
	return

CeruleanCity_EventScript_1667DD:: @ 81667DD
	lock
	random 4
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 0
	call_if_eq EventScript_166814
	compare VAR_0x8008, 1
	call_if_eq EventScript_16681D
	compare VAR_0x8008, 2
	call_if_eq EventScript_166826
	compare VAR_0x8008, 3
	call_if_eq EventScript_16682F
	release
	end

EventScript_166814:: @ 8166814
	msgbox gUnknown_817F270
	return

EventScript_16681D:: @ 816681D
	msgbox gUnknown_817F287
	return

EventScript_166826:: @ 8166826
	msgbox gUnknown_817F2A2
	return

EventScript_16682F:: @ 816682F
	msgbox gUnknown_817F2B7
	return

CeruleanCity_EventScript_166838:: @ 8166838
	msgbox gUnknown_817F420, MSGBOX_SIGN
	end

CeruleanCity_EventScript_166841:: @ 8166841
	msgbox gUnknown_817F453, MSGBOX_SIGN
	end

CeruleanCity_EventScript_16684A:: @ 816684A
	msgbox gUnknown_817F4C5, MSGBOX_SIGN
	end

CeruleanCity_EventScript_166853:: @ 8166853
	lockall
	famechecker FAMECHECKER_MISTY, 0
	msgbox gUnknown_817F4EF
	releaseall
	end
