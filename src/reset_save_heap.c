#include "global.h"
#include "main.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "overworld.h"
#include "malloc.h"

void ResetSaveHeap(void)
{
    u16 imeBackup = REG_IME;
    
    REG_IME = 0;
    RegisterRamReset(RESET_EWRAM);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_FORCED_BLANK);
    REG_IME = imeBackup;
    gMain.inBattle = FALSE;
    SetSaveBlocksPointers();
    ResetMenuAndMonGlobals();
    Save_ResetSaveCounters();
    Save_LoadGameData(SAVE_NORMAL);
    if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_INVALID)
        Sav2_ClearSetDefault();
    SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
    InitHeap(gHeap, HEAP_SIZE);
    SetMainCallback2(CB2_ContinueSavedGame);
}
