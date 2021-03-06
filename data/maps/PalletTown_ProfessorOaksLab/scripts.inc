PalletTown_ProfessorOaksLab_MapScripts:: @ 8168F7E
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_ProfessorOaksLab_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
	.byte 0

PalletTown_ProfessorOaksLab_OnTransition:: @ 8168F8E
	setflag FLAG_VISITED_OAKS_LAB
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
	call_if_eq EventScript_168FC6
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
	call_if_eq EventScript_168FD5
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8
	call_if_eq EventScript_168FC0
	call_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, EventScript_168FBC
	end

EventScript_168FBC:: @ 8168FBC
	setflag FLAG_OAK_SKIP_22_RIVAL_CHECK
	return

EventScript_168FC0:: @ 8168FC0
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9
	return

EventScript_168FC6:: @ 8168FC6
	setobjectxyperm 4, 6, 11
	setobjectmovementtype 4, 7
	savebgm MUS_OHKIDO
	return

EventScript_168FD5:: @ 8168FD5
	setobjectxyperm 4, 6, 11
	setobjectmovementtype 4, 7
	return

PalletTown_ProfessorOaksLab_OnWarp:: @ 8168FE1
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, EventScript_168FEB
	.2byte 0

EventScript_168FEB:: @ 8168FEB
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

PalletTown_ProfessorOaksLab_OnFrame:: @ 8168FF0
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, EventScript_16923E
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, EventScript_169002
	.2byte 0

EventScript_169002:: @ 8169002 
	lockall
	setvar VAR_FACING, DIR_NORTH
	textcolor 0
	applymovement 4, Movement_1692B0
	waitmovement 0
	removeobject 4
	setobjectxyperm 4, 6, 3
	setobjectmovementtype 4, 8
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1692B7
	waitmovement 0
	goto EventScript_169035
	end

EventScript_169035:: @ 8169035
	msgbox gUnknown_818EE60
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169174
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_1691BB
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_169194
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169194
	msgbox gUnknown_818EF59
	fadedefaultbgm
	msgbox gUnknown_818F004
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_1691DB
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_1691E6
	textcolor 3
	msgbox gUnknown_818F062
	closemessage
	call EventScript_1A6675
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_1691F1
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_1691FC
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_169215
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169227
	addobject 9
	addobject 10
	delay 30
	msgbox gUnknown_818F085
	closemessage
	removeobject 9
	removeobject 10
	delay 30
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169845
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_169850
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_16985B
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_16986D
	textcolor 3
	playfanfare MUS_FAN5
	message Text_18F0E8
	waitmessage
	waitfanfare
	call EventScript_1A6675
	special EnableNationalPokedex
	msgbox gUnknown_818F103
	msgbox gUnknown_818F1DB
	closemessage
	playbgm MUS_RIVAL2, 0
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169B69
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_169B7B
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_169B7B
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169B7B
	removeobject 8
	fadedefaultbgm
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8
	releaseall
	end

EventScript_169174:: @ 8169174
	setobjectxyperm 8, 5, 10
	addobject 8
	playbgm MUS_RIVAL1, 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169B94
	applymovement 8, Movement_169B9D
	waitmovement 0
	return

EventScript_169194:: @ 8169194
	setobjectxyperm 8, 6, 10
	addobject 8
	playbgm MUS_RIVAL1, 0
	applymovement 4, Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169B91
	applymovement 8, Movement_169B9D
	waitmovement 0
	return

EventScript_1691BB:: @ 81691BB
	setobjectxyperm 8, 6, 10
	addobject 8
	playbgm MUS_RIVAL1, 0
	applymovement 4, Movement_WalkInPlaceFastestDown
	applymovement 8, Movement_169B9D
	waitmovement 0
	return

EventScript_1691DB:: @ 81691DB
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

EventScript_1691E6:: @ 81691E6
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

EventScript_1691F1:: @ 81691F1
	applymovement 4, Movement_169232
	waitmovement 0
	return

EventScript_1691FC:: @ 81691FC
	applymovement 4, Movement_169238
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1698C7
	applymovement 8, Movement_1698C7
	waitmovement 4
	return

EventScript_169215:: @ 8169215
	applymovement 4, Movement_169232
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1698C3
	waitmovement 4
	return

EventScript_169227:: @ 8169227
	applymovement 4, Movement_169232
	waitmovement 0
	return

Movement_169232:: @ 8169232
	walk_up
	walk_left
	walk_in_place_fastest_up
	delay_16
	delay_4
	step_end

Movement_169238:: @ 8169238
	walk_left
	walk_left
	walk_up
	delay_16
	delay_4
	step_end

EventScript_16923E:: @ 816923E
	lockall
	textcolor 0
	applymovement 4, Movement_1692B0
	waitmovement 0
	removeobject 4
	setobjectxyperm 4, 6, 3
	setobjectmovementtype 4, 8
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1692B7
	waitmovement 0
	applymovement 8, Movement_WalkInPlaceFastestUp
	waitmovement 0
	clearflag FLAG_SPECIAL_FLAG_0x4001
	savebgm SE_STOP
	fadedefaultbgm
	msgbox gUnknown_818DC94
	closemessage
	delay 60
	msgbox gUnknown_818DFBC
	closemessage
	delay 30
	applymovement 8, Movement_1692C0
	waitmovement 0
	msgbox gUnknown_818DCB9
	msgbox gUnknown_818E0EA
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
	releaseall
	end

Movement_1692B0:: @ 81692B0
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_1692B7:: @ 81692B7
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_1692C0:: @ 81692C0
	walk_in_place_up
	walk_in_place_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_1692C3:: @ 81692C3
	lockall
	textcolor 0
	applymovement 4, Movement_FaceDown
	waitmovement 0
	msgbox gUnknown_818E177
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1692E5
	waitmovement 0
	releaseall
	end

Movement_1692E5:: @ 81692E5
	walk_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_1692E7:: @ 81692E7
	lockall
	setvar VAR_TEMP_2, 1
	goto EventScript_16930B
	end

PalletTown_ProfessorOaksLab_EventScript_1692F3:: @ 81692F3
	lockall
	setvar VAR_TEMP_2, 2
	goto EventScript_16930B
	end

PalletTown_ProfessorOaksLab_EventScript_1692FF:: @ 81692FF
	lockall
	setvar VAR_TEMP_2, 3
	goto EventScript_16930B
	end

EventScript_16930B:: @ 816930B
	textcolor 0
	playbgm MUS_RIVAL1, 0
	applymovement 8, Movement_WalkInPlaceFastestDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox gUnknown_818DDA4
	closemessage
	applymovement 4, Movement_FaceDown
	waitmovement 0
	compare VAR_STARTER_MON, 0
	goto_if_eq EventScript_1693D2
	compare VAR_STARTER_MON, 1
	goto_if_eq EventScript_16944D
	compare VAR_STARTER_MON, 2
	goto_if_eq EventScript_16935A
	end

EventScript_16935A:: @ 816935A
	compare VAR_TEMP_2, 1
	goto_if_eq EventScript_16937C
	compare VAR_TEMP_2, 2
	goto_if_eq EventScript_16938C
	compare VAR_TEMP_2, 3
	goto_if_eq EventScript_16939C
	end

EventScript_16937C:: @ 816937C
	applymovement 8, Movement_1693C0
	waitmovement 0
	goto EventScript_1693AC
	end

EventScript_16938C:: @ 816938C
	applymovement 8, Movement_1693C7
	waitmovement 0
	goto EventScript_1693AC
	end

EventScript_16939C:: @ 816939C
	applymovement 8, Movement_1693CD
	waitmovement 0
	goto EventScript_1693AC
	end

EventScript_1693AC:: @ 81693AC
	trainerbattle_tutorial TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, 3, Text_18DDEA, Text_18DE1A
	goto EventScript_1694C2
	end

Movement_1693C0:: @ 81693C0
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Movement_1693C7:: @ 81693C7
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Movement_1693CD:: @ 81693CD
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EventScript_1693D2:: @ 81693D2
	compare VAR_TEMP_2, 1
	goto_if_eq EventScript_1693F4
	compare VAR_TEMP_2, 2
	goto_if_eq EventScript_169404
	compare VAR_TEMP_2, 3
	goto_if_eq EventScript_169414
	end

EventScript_1693F4:: @ 81693F4
	applymovement 8, Movement_169438
	waitmovement 0
	goto EventScript_169424
	end

EventScript_169404:: @ 8169404
	applymovement 8, Movement_169440
	waitmovement 0
	goto EventScript_169424
	end

EventScript_169414:: @ 8169414
	applymovement 8, Movement_169447
	waitmovement 0
	goto EventScript_169424
	end

EventScript_169424:: @ 8169424
	trainerbattle_tutorial TRAINER_RIVAL_OAKS_LAB_CHARMANDER, 3, Text_18DDEA, Text_18DE1A
	goto EventScript_1694C2
	end

Movement_169438:: @ 8169438
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Movement_169440:: @ 8169440
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Movement_169447:: @ 8169447
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EventScript_16944D:: @ 816944D
	compare VAR_TEMP_2, 1
	goto_if_eq EventScript_16946F
	compare VAR_TEMP_2, 2
	goto_if_eq EventScript_16947F
	compare VAR_TEMP_2, 3
	goto_if_eq EventScript_16948F
	end

EventScript_16946F:: @ 816946F
	applymovement 8, Movement_1694B3
	waitmovement 0
	goto EventScript_16949F
	end

EventScript_16947F:: @ 816947F
	applymovement 8, Movement_1694B9
	waitmovement 0
	goto EventScript_16949F
	end

EventScript_16948F:: @ 816948F
	applymovement 8, Movement_1694BE
	waitmovement 0
	goto EventScript_16949F
	end

EventScript_16949F:: @ 816949F
	trainerbattle_tutorial TRAINER_RIVAL_OAKS_LAB_BULBASAUR, 3, Text_18DDEA, Text_18DE1A
	goto EventScript_1694C2
	end

Movement_1694B3:: @ 81694B3
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Movement_1694B9:: @ 81694B9
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Movement_1694BE:: @ 81694BE
	walk_left
	walk_down
	walk_down
	step_end

EventScript_1694C2:: @ 81694C2
	special HealPlayerParty
	msgbox gUnknown_818DE38
	closemessage
	playbgm MUS_RIVAL2, 0
	compare VAR_TEMP_2, 1
	call_if_eq EventScript_169504
	compare VAR_TEMP_2, 2
	call_if_eq EventScript_169516
	compare VAR_TEMP_2, 3
	call_if_eq EventScript_169528
	removeobject 8
	playse SE_KAIDAN
	fadedefaultbgm
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
	releaseall
	end

EventScript_169504:: @ 8169504
	applymovement 8, Movement_16953A
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169553
	waitmovement 8
	return

EventScript_169516:: @ 8169516
	applymovement 8, Movement_16954A
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169553
	waitmovement 8
	return

EventScript_169528:: @ 8169528
	applymovement 8, Movement_169542
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169559
	waitmovement 8
	return

Movement_16953A:: @ 816953A
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

Movement_169542:: @ 8169542
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

Movement_16954A:: @ 816954A
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	delay_8
	step_end

Movement_169553:: @ 8169553
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_down
	step_end

Movement_169559:: @ 8169559
	delay_16
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

PalletTown_ProfessorOaksLab_EventScript_16955F:: @ 816955F
	lock
	faceplayer
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
	goto_if_eq EventScript_16958B
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
	goto_if_eq EventScript_169581
	msgbox gUnknown_818DC67
	release
	end

EventScript_169581:: @ 8169581
	msgbox gUnknown_818DCE2
	release
	end

EventScript_16958B:: @ 816958B
	msgbox gUnknown_818DD75
	release
	end

PalletTown_ProfessorOaksLab_EventScript_169595:: @ 8169595
	lock
	faceplayer
	goto_if_set FLAG_TEMP_2, EventScript_169600
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9
	goto_if_eq EventScript_169903
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8
	goto_if_eq EventScript_169A6E
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_1699CE
	compare VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	goto_if_eq EventScript_169903
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6
	goto_if_eq EventScript_1698D6
	compare VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1
	goto_if_ge EventScript_16961E
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4
	goto_if_eq EventScript_169614
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
	goto_if_eq EventScript_16960A
	msgbox gUnknown_818E116
	release
	end

EventScript_169600:: @ 8169600
	msgbox gUnknown_81A72AD
	release
	end

EventScript_16960A:: @ 816960A
	msgbox gUnknown_818E330
	release
	end

EventScript_169614:: @ 8169614
	msgbox gUnknown_818E3AD
	release
	end

EventScript_16961E:: @ 816961E
	msgbox gUnknown_818E405
	textcolor 3
	playfanfare MUS_ME_WAZA
	message Text_18E4AF
	waitmessage
	waitfanfare
	call EventScript_1A6675
	removeitem ITEM_OAKS_PARCEL, 1
	msgbox gUnknown_818E4CA
	playbgm MUS_RIVAL1, 0
	msgbox gUnknown_818DE8D
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169A82
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_169AC1
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_169A9E
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169A9E
	fadedefaultbgm
	msgbox gUnknown_818DE99
	closemessage
	delay 30
	playse SE_PIN
	applymovement 4, Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Movement_Delay48
	waitmovement 0
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_169ADD
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_169B14
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169AF5
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169B86
	msgbox gUnknown_818E508
	closemessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169882
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_16988D
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_1698A6
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_1698B8
	msgbox gUnknown_818E536
	closemessage
	delay 40
	msgbox gUnknown_818E5C5
	closemessage
	applymovement 4, Movement_WalkInPlaceFastestUp
	waitmovement 0
	removeobject 9
	delay 10
	removeobject 10
	delay 25
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169845
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_169850
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_16985B
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_16986D
	delay 10
	textcolor 3
	playfanfare MUS_FAN5
	message Text_18E5EA
	waitmessage
	waitfanfare
	call EventScript_1A6675
	setflag FLAG_SYS_POKEDEX_GET
	special sub_810B810
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1
	msgbox gUnknown_818E612
	giveitem_msg gUnknown_818E6B3, ITEM_POKE_BALL, 5
	msgbox gUnknown_818E6D0
	famechecker FAMECHECKER_OAK, 1
	msgbox gUnknown_818E784
	msgbox gUnknown_818DEC8
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169B33
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_169B45
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_169B57
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169B57
	msgbox gUnknown_818DEF3
	closemessage
	playbgm MUS_RIVAL2, 0
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169B69
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_169B7B
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_169B7B
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169B7B
	removeobject 8
	fadedefaultbgm
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
	setvar VAR_MAP_SCENE_PALLET_TOWN_GARYS_HOUSE, 1
	setvar VAR_MAP_SCENE_ROUTE22, 1
	release
	end

EventScript_169845:: @ 8169845
	applymovement 4, Movement_16987C
	waitmovement 0
	return

EventScript_169850:: @ 8169850
	applymovement 4, Movement_16987F
	waitmovement 0
	return

EventScript_16985B:: @ 816985B
	applymovement 4, Movement_16987C
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169878
	waitmovement 0
	return

EventScript_16986D:: @ 816986D
	applymovement 4, Movement_16987C
	waitmovement 0
	return

Movement_169878:: @ 8169878
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

Movement_16987C:: @ 816987C
	walk_right
	walk_down
	step_end

Movement_16987F:: @ 816987F
	walk_down
	walk_right
	step_end

EventScript_169882:: @ 8169882
	applymovement 4, Movement_1698CB
	waitmovement 0
	return

EventScript_16988D:: @ 816988D
	applymovement 4, Movement_1698D0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1698C7
	applymovement 8, Movement_1698C7
	waitmovement 4
	return

EventScript_1698A6:: @ 81698A6
	applymovement 4, Movement_1698CB
	applymovement OBJ_EVENT_ID_PLAYER, Movement_1698C3
	waitmovement 4
	return

EventScript_1698B8:: @ 81698B8
	applymovement 4, Movement_1698CB
	waitmovement 0
	return

Movement_1698C3:: @ 81698C3
	delay_16
	delay_8
	walk_in_place_fastest_up
	step_end

Movement_1698C7:: @ 81698C7
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

Movement_1698CB:: @ 81698CB
	walk_up
	walk_left
	delay_16
	walk_in_place_fastest_down
	step_end

Movement_1698D0:: @ 81698D0
	walk_left
	walk_left
	walk_up
	delay_16
	walk_in_place_fastest_right
	step_end

EventScript_1698D6:: @ 81698D6
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, Special_GetPokedexCount
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	getnumberstring 0, VAR_0x8008
	getnumberstring 1, VAR_0x8009
	compare VAR_0x8009, 1
	goto_if_eq EventScript_1699FB
	goto EventScript_169903
	end

EventScript_169903:: @ 8169903
	call ProfOak_EventScript_RatePokedexInPerson
	goto_if_set FLAG_OAK_SAW_DEX_COMPLETION, EventScript_169913
	release
	end

EventScript_169913:: @ 8169913
	closemessage
	delay 40
	message Text_1A7291
	waitmessage
	compare VAR_FACING, DIR_NORTH
	call_if_eq EventScript_169964
	compare VAR_FACING, DIR_SOUTH
	call_if_eq EventScript_16996F
	compare VAR_FACING, DIR_EAST
	call_if_eq EventScript_16997A
	compare VAR_FACING, DIR_WEST
	call_if_eq EventScript_169985
	applymovement 4, Movement_FacePlayer
	waitmovement 0
	closemessage
	delay 70
	msgbox gUnknown_81A72AD
	setflag FLAG_TEMP_2
	release
	end

EventScript_169964:: @ 8169964
	applymovement 4, Movement_169990
	waitmovement 0
	return

EventScript_16996F:: @ 816996F
	applymovement 4, Movement_169997
	waitmovement 0
	return

EventScript_16997A:: @ 816997A
	applymovement 4, Movement_16999E
	waitmovement 0
	return

EventScript_169985:: @ 8169985
	applymovement 4, Movement_1699A5
	waitmovement 0
	return

Movement_169990:: @ 8169990
	walk_in_place_down
	walk_in_place_fast_down
	walk_in_place_down
	walk_in_place_down
	walk_in_place_fast_down
	walk_in_place_down
	step_end

Movement_169997:: @ 8169997
	walk_in_place_up
	walk_in_place_fast_up
	walk_in_place_up
	walk_in_place_up
	walk_in_place_fast_up
	walk_in_place_up
	step_end

Movement_16999E:: @ 816999E
	walk_in_place_left
	walk_in_place_fast_left
	walk_in_place_left
	walk_in_place_left
	walk_in_place_fast_left
	walk_in_place_left
	step_end

Movement_1699A5:: @ 81699A5
	walk_in_place_right
	walk_in_place_fast_right
	walk_in_place_right
	walk_in_place_right
	walk_in_place_fast_right
	walk_in_place_right
	step_end

Movement_1699AC:: @ 81699AC
	walk_left
	walk_in_place_fastest_down
	delay_8
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_left
	delay_8
	walk_in_place_fastest_down
	delay_8
	walk_right
	walk_right
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_left
	delay_8
	walk_in_place_fastest_down
	delay_8
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_up
	delay_8
	walk_left
	step_end

Movement_1699C5:
	walk_up
	walk_down
	walk_down
	walk_in_place_down
	walk_up
	delay_16
	delay_16
	delay_16
	step_end

EventScript_1699CE:: @ 81699CE
	call ProfOak_EventScript_RatePokedexInPerson
	closemessage
	compare VAR_0x8009, 60
	goto_if_lt EventScript_1699F9
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, EventScript_1699F9
	delay 30
	msgbox gUnknown_818EDF5
	goto EventScript_169035
	end

EventScript_1699F9:: @ 81699F9
	release
	end

EventScript_1699FB:: @ 81699FB
	special sub_8110AB4
	compare VAR_RESULT, 2
	goto_if_eq EventScript_1A7AE0
	special sub_8112364
	goto_if_set FLAG_OAK_SKIP_22_RIVAL_CHECK, EventScript_169A6E
	goto_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, EventScript_169A78
	checkitem ITEM_POKE_BALL, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_169A34
	goto EventScript_169A6E
	end

EventScript_169A34:: @ 8169A34
	compare VAR_MAP_SCENE_ROUTE22, 2
	goto_if_ge EventScript_169A45
	goto EventScript_169A6E
	end

EventScript_169A45:: @ 8169A45
	msgbox gUnknown_818E89C
	giveitem_msg gUnknown_818E6B3, ITEM_POKE_BALL, 5
	setflag FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL
	release
	end

EventScript_169A6E:: @ 8169A6E
	msgbox gUnknown_818E871
	release
	end

EventScript_169A78:: @ 8169A78
	msgbox gUnknown_818E98E
	release
	end

EventScript_169A82:: @ 8169A82
	setobjectxyperm 8, 5, 10
	addobject 8
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169B94
	applymovement 8, Movement_169B9D
	waitmovement 0
	return

EventScript_169A9E:: @ 8169A9E
	setobjectxyperm 8, 6, 10
	addobject 8
	applymovement 4, Movement_WalkInPlaceFastestDown
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169B91
	applymovement 8, Movement_169B9D
	waitmovement 0
	return

EventScript_169AC1:: @ 8169AC1
	setobjectxyperm 8, 6, 10
	addobject 8
	applymovement 4, Movement_WalkInPlaceFastestDown
	applymovement 8, Movement_169B9D
	waitmovement 0
	return

EventScript_169ADD:: @ 8169ADD
	applymovement 4, Movement_FacePlayer
	waitmovement 0
	delay 15
	applymovement 4, Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

EventScript_169AF5:: @ 8169AF5
	applymovement 4, Movement_FacePlayer
	waitmovement 0
	delay 15
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	applymovement 4, Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

EventScript_169B14:: @ 8169B14
	applymovement 4, Movement_FacePlayer
	waitmovement 0
	delay 15
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestRight
	applymovement 4, Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

EventScript_169B33:: @ 8169B33
	applymovement 8, Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestLeft
	waitmovement 0
	return

EventScript_169B45:: @ 8169B45
	applymovement 8, Movement_WalkInPlaceFastestUp
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

EventScript_169B57:: @ 8169B57
	applymovement 8, Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

EventScript_169B69:: @ 8169B69
	applymovement OBJ_EVENT_ID_PLAYER, Movement_169B91
	applymovement 8, Movement_169BA4
	waitmovement 0
	return

EventScript_169B7B:: @ 8169B7B
	applymovement 8, Movement_169BA4
	waitmovement 0
	return

EventScript_169B86:: @ 8169B86
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkInPlaceFastestUp
	waitmovement 0
	return

Movement_169B91:: @ 8169B91
	delay_4
	walk_in_place_fastest_down
	step_end

Movement_169B94:: @ 8169B94
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

Movement_169B9D:: @ 8169B9D
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Movement_169BA4:: @ 8169BA4
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

	.equ VAR_OAKSLAB_PLAYER_STARTER_NO,       VAR_TEMP_1
	.equ VAR_OAKSLAB_PLAYER_STARTER_SPECIES,  VAR_TEMP_2
	.equ VAR_OAKSLAB_RIVAL_STARTER_SPECIES,   VAR_TEMP_3
	.equ VAR_OAKSLAB_RIVAL_STARTER_OBJID,     VAR_TEMP_4

PalletTown_ProfessorOaksLab_EventScript_169BAB:: @ 8169BAB
	lock
	faceplayer
	setvar VAR_OAKSLAB_PLAYER_STARTER_NO, 0
	setvar VAR_OAKSLAB_PLAYER_STARTER_SPECIES, SPECIES_BULBASAUR
	setvar VAR_OAKSLAB_RIVAL_STARTER_SPECIES, SPECIES_CHARMANDER
	setvar VAR_OAKSLAB_RIVAL_STARTER_OBJID, 7
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
	goto_if_ge EventScript_169DE4
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
	goto_if_eq EventScript_169BE1
	msgbox gUnknown_818EA19
	release
	end

EventScript_169BE1:: @ 8169BE1
	applymovement 4, Movement_FaceRight
	waitmovement 0
	drawmonpic VAR_OAKSLAB_PLAYER_STARTER_SPECIES, 10, 3
	textcolor 0
	compare VAR_OAKSLAB_PLAYER_STARTER_NO, 0
	goto_if_eq EventScript_OakDescribesBulbasaur
	compare VAR_OAKSLAB_PLAYER_STARTER_NO, 1
	goto_if_eq EventScript_OakDescribesCharmander
	compare VAR_OAKSLAB_PLAYER_STARTER_NO, 2
	goto_if_eq EventScript_OakDescribesSquirtle
	end

EventScript_OakDescribesBulbasaur:: @ 8169C14
	msgbox gUnknown_818E272, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_ThisPokeIsRealyEnergetic
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DeclinedStarter
	end

EventScript_OakDescribesCharmander:: @ 8169C33
	msgbox gUnknown_818E207, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_ThisPokeIsRealyEnergetic
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DeclinedStarter
	end

EventScript_OakDescribesSquirtle:: @ 8169C52
	msgbox gUnknown_818E194, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_ThisPokeIsRealyEnergetic
	compare VAR_RESULT, NO
	goto_if_eq EventScript_DeclinedStarter
	end

EventScript_DeclinedStarter:: @ 8169C71
	erasemonpic
	release
	end

EventScript_ThisPokeIsRealyEnergetic:: @ 8169C74
	erasemonpic
	removeobject VAR_LAST_TALKED
	msgbox gUnknown_818E2E5
	call EventScript_1A6675
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
	givemon VAR_OAKSLAB_PLAYER_STARTER_SPECIES, 5, ITEM_NONE
	copyvar VAR_STARTER_MON, VAR_OAKSLAB_PLAYER_STARTER_NO
	getspeciesname 0, VAR_OAKSLAB_PLAYER_STARTER_SPECIES
	message Text_18E30D
	waitmessage
	playfanfare MUS_FAN5
	waitfanfare
	msgbox gUnknown_81A56A7, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_GiveNicknameToStarter
	compare VAR_RESULT, NO
	goto_if_eq EventScript_SkipGiveNicknameToStarter
	end

EventScript_GiveNicknameToStarter:: @ 8169CCC
	setvar VAR_0x8004, 0
	call EventScript_1A74EB
	goto EventScript_SkipGiveNicknameToStarter
	end

EventScript_SkipGiveNicknameToStarter:: @ 8169CDC
	closemessage
	compare VAR_OAKSLAB_PLAYER_STARTER_NO, 0
	goto_if_eq EventScript_RivalWalksToCharmander
	compare VAR_OAKSLAB_PLAYER_STARTER_NO, 1
	goto_if_eq EventScript_RivalWalksToSquirtle
	compare VAR_OAKSLAB_PLAYER_STARTER_NO, 2
	goto_if_eq EventScript_RivalWalksToBulbasaur
	end

EventScript_RivalWalksToCharmander:: @ 8169CFF
	applymovement 8, Movement_RivalWalksToCharmander
	waitmovement 0
	goto Movement_RivalTakesHisStarter
	end

EventScript_RivalWalksToBulbasaur:: @ 8169D0F
	applymovement 8, Movement_RivalWalksToBulbasaur
	waitmovement 0
	goto Movement_RivalTakesHisStarter
	end

EventScript_RivalWalksToSquirtle:: @ 8169D1F
	applymovement 8, Movement_RivalWalksToSquirtle
	waitmovement 0
	goto Movement_RivalTakesHisStarter
	end

Movement_RivalTakesHisStarter:: @ 8169D2F
	textcolor 0
	msgbox gUnknown_818DD34
	removeobject VAR_OAKSLAB_RIVAL_STARTER_OBJID
	textcolor 3
	getspeciesname 0, VAR_OAKSLAB_RIVAL_STARTER_SPECIES
	message Text_18DD52
	waitmessage
	playfanfare MUS_FAN5
	waitfanfare
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
	call_if_set FLAG_PALLET_TOWN_LADY_MOVED_FROM_SIGN, EventScript_169D5C
	release
	end

EventScript_169D5C:: @ 8169D5C
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
	return

Movement_RivalWalksToCharmander:: @ 8169D62
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

Movement_RivalWalksToBulbasaur:: @ 8169D6B
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

Movement_RivalWalksToSquirtle:: @ 8169D72
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

PalletTown_ProfessorOaksLab_EventScript_169D78:: @ 8169D78
	lock
	faceplayer
	setvar VAR_OAKSLAB_PLAYER_STARTER_NO, 1
	setvar VAR_OAKSLAB_PLAYER_STARTER_SPECIES, SPECIES_SQUIRTLE
	setvar VAR_OAKSLAB_RIVAL_STARTER_SPECIES, SPECIES_BULBASAUR
	setvar VAR_OAKSLAB_RIVAL_STARTER_OBJID, 5
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
	goto_if_ge EventScript_169DE4
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
	goto_if_eq EventScript_169BE1
	msgbox gUnknown_818EA19
	release
	end

PalletTown_ProfessorOaksLab_EventScript_169DAE:: @ 8169DAE
	lock
	faceplayer
	setvar VAR_OAKSLAB_PLAYER_STARTER_NO, 2
	setvar VAR_OAKSLAB_PLAYER_STARTER_SPECIES, SPECIES_CHARMANDER
	setvar VAR_OAKSLAB_RIVAL_STARTER_SPECIES, SPECIES_SQUIRTLE
	setvar VAR_OAKSLAB_RIVAL_STARTER_OBJID, 6
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
	goto_if_ge EventScript_169DE4
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
	goto_if_eq EventScript_169BE1
	msgbox gUnknown_818EA19
	release
	end

EventScript_169DE4:: @ 8169DE4
	msgbox gUnknown_818EA45
	release
	end

PalletTown_ProfessorOaksLab_EventScript_169DEE:: @ 8169DEE
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_169E03
	msgbox gUnknown_818EBE6
	release
	end

EventScript_169E03:: @ 8169E03
	famechecker FAMECHECKER_OAK, 5
	msgbox gUnknown_818ED15
	release
	end

PalletTown_ProfessorOaksLab_EventScript_169E1A:: @ 8169E1A
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_169E2F
	msgbox gUnknown_818EBE6
	release
	end

EventScript_169E2F:: @ 8169E2F
	famechecker FAMECHECKER_DAISY, 0
	msgbox gUnknown_818EC0B
	release
	end

PalletTown_ProfessorOaksLab_EventScript_169E46:: @ 8169E46
	lock
	faceplayer
	famechecker FAMECHECKER_OAK, 2
	msgbox gUnknown_818ED81
	release
	end

PalletTown_ProfessorOaksLab_EventScript_169E5F:: @ 8169E5F
	msgbox gUnknown_818E9E5, MSGBOX_NPC
	end

PalletTown_ProfessorOaksLab_EventScript_169E68:: @ 8169E68
	msgbox gUnknown_818EAF4, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_EventScript_169E71:: @ 8169E71
	msgbox gUnknown_818EA66, MSGBOX_SIGN
	end

PalletTown_ProfessorOaksLab_EventScript_169E7A:: @ 8169E7A
	lockall
	compare VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6
	goto_if_ge EventScript_169E90
	msgbox gUnknown_818EA84
	releaseall
	end

EventScript_169E90:: @ 8169E90
	msgbox gUnknown_818EAB6
	releaseall
	end
