Route12_FishingHouse_MapScripts:: @ 816FF0B
	.byte 0

Route12_FishingHouse_EventScript_16FF0C:: @ 816FF0C
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, EventScript_16FF7F
	msgbox gUnknown_819EFE0, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq EventScript_16FF34
	msgbox gUnknown_819F1FA
	release
	end

EventScript_16FF34:: @ 816FF34
	checkitemspace ITEM_SUPER_ROD, 1
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_16FF75
	additem ITEM_SUPER_ROD
	msgbox gUnknown_819F05B
	msgreceiveditem gUnknown_819F0B2, ITEM_SUPER_ROD
	setflag FLAG_GOT_SUPER_ROD
	msgbox gUnknown_819F0EB
	release
	end

EventScript_16FF75:: @ 816FF75
	msgbox gUnknown_819F494
	release
	end

EventScript_16FF7F:: @ 816FF7F
	special sub_8110AB4
	compare VAR_RESULT, 2
	goto_if_eq EventScript_1A7AE0
	special sub_8112364
	setvar VAR_0x8004, SPECIES_MAGIKARP
	specialvar VAR_RESULT, Special_PlayerPartyContainsSpecies
	compare VAR_RESULT, 0
	goto_if_eq EventScript_16FFF5
	special GetMagikarpSizeRecordInfo
	msgbox gUnknown_819F2DB
	special Special_ChooseMonFromParty
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	compare VAR_RESULT, 6
	goto_if_ge EventScript_16FFFF
	special CompareMagikarpSize
	compare VAR_RESULT, 1
	goto_if_eq EventScript_170001
	compare VAR_RESULT, 2
	goto_if_eq EventScript_17000B
	compare VAR_RESULT, 3
	goto_if_eq EventScript_170031
	compare VAR_RESULT, 4
	goto_if_eq EventScript_17001E
	release
	end

EventScript_16FFF5:: @ 816FFF5
	msgbox gUnknown_819F217
	release
	end

EventScript_16FFFF:: @ 816FFFF
	release
	end

EventScript_170001:: @ 8170001
	msgbox gUnknown_819F468
	release
	end

EventScript_17000B:: @ 817000B
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, EventScript_170031
	msgbox gUnknown_819F40A
	release
	end

EventScript_17001E:: @ 817001E
	goto_if_unset FLAG_GOT_RECORD_SETTING_MAGIKARP, EventScript_170031
	msgbox gUnknown_819F3CB
	release
	end

EventScript_170031:: @ 8170031
	setflag FLAG_GOT_RECORD_SETTING_MAGIKARP
	msgbox gUnknown_819F31B
	giveitem ITEM_NET_BALL
	compare VAR_RESULT, 0
	goto_if_eq EventScript_17005D
	msgbox gUnknown_819F395
	release
	end

EventScript_17005D:: @ 817005D
	msgbox gUnknown_819F494
	release
	end

Route12_FishingHouse_EventScript_170067:: @ 8170067
	lockall
	goto_if_set FLAG_GOT_RECORD_SETTING_MAGIKARP, EventScript_17007B
	msgbox gUnknown_819F50C
	releaseall
	end

EventScript_17007B:: @ 817007B
	special GetMagikarpSizeRecordInfo
	msgbox gUnknown_819F4CF
	releaseall
	end
