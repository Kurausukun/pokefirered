ViridianForest_MapScripts:: @ 816051F
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
	.byte 0

ViridianForest_OnTransition:: @ 8160525
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
	end

ViridianForest_EventScript_160529:: @ 8160529
	msgbox gUnknown_8172255, MSGBOX_NPC
	end

ViridianForest_EventScript_160532:: @ 8160532
	msgbox gUnknown_8172559, MSGBOX_NPC
	end

ViridianForest_EventScript_16053B:: @ 816053B
	msgbox gUnknown_81725C7, MSGBOX_SIGN
	end

ViridianForest_EventScript_160544:: @ 8160544
	msgbox gUnknown_8172629, MSGBOX_SIGN
	end

ViridianForest_EventScript_16054D:: @ 816054D
	msgbox gUnknown_817265C, MSGBOX_SIGN
	end

ViridianForest_EventScript_160556:: @ 8160556
	msgbox gUnknown_81726A3, MSGBOX_SIGN
	end

ViridianForest_EventScript_16055F:: @ 816055F
	msgbox gUnknown_817271D, MSGBOX_SIGN
	end

ViridianForest_EventScript_160568:: @ 8160568
	msgbox gUnknown_8172773, MSGBOX_SIGN
	end

ViridianForest_EventScript_160571:: @ 8160571
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, Text_1722C7, Text_1722F9
	msgbox gUnknown_8172315, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_160588:: @ 8160588
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, Text_17234A, Text_17237D
	msgbox gUnknown_8172398, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_16059F:: @ 816059F
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, Text_1723D4, Text_172402
	msgbox gUnknown_817241F, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_1605B6:: @ 81605B6
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, Text_172482, Text_1724BF
	msgbox gUnknown_81724DC, MSGBOX_AUTOCLOSE
	end

ViridianForest_EventScript_1605CD:: @ 81605CD
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, Text_1724F9, Text_17251B
	msgbox gUnknown_8172527, MSGBOX_AUTOCLOSE
	end
