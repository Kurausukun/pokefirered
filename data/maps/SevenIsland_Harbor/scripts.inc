SevenIsland_Harbor_MapScripts:: @ 8170BE4
	.byte 0

SevenIsland_Harbor_EventScript_170BE5:: @ 8170BE5
	lock
	faceplayer
	message Text_WhereDoYouWantToSail
	waitmessage
	setvar VAR_0x8004, SEAGALLOP_SEVEN_ISLAND
	goto EventScript_1A900F
	end
