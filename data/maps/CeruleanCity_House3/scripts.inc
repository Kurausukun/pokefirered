CeruleanCity_House3_MapScripts:: @ 816A9A7
	.byte 0

CeruleanCity_House3_EventScript_16A9A8:: @ 816A9A8
	msgbox gUnknown_8191F80, MSGBOX_NPC
	end

CeruleanCity_House3_EventScript_16A9B1:: @ 816A9B1
	lock
	faceplayer
	setvar VAR_0x8008, 1
	call EventScript_1A8CAD
	goto_if_set FLAG_DID_ZYNX_TRADE, EventScript_16AA23
	msgbox gUnknown_81A59FE, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_16AA0B
	call EventScript_1A8CBD
	compare VAR_0x8004, 6
	goto_if_ge EventScript_16AA0B
	call EventScript_1A8CC9
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne EventScript_16AA15
	call EventScript_1A8CD9
	msgbox gUnknown_81A5A9D
	setflag FLAG_DID_ZYNX_TRADE
	release
	end

EventScript_16AA0B:: @ 816AA0B
	msgbox gUnknown_81A5A4E
	release
	end

EventScript_16AA15:: @ 816AA15
	getspeciesname 0, VAR_0x8009
	msgbox gUnknown_81A5A6A
	release
	end

EventScript_16AA23:: @ 816AA23
	msgbox gUnknown_81A5AA5
	release
	end
