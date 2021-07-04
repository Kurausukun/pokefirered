#include "global.h"
#include "event_data.h"
#include "rtc.h"
#include "field_specials.h"
#include "field_weather.h"
#include "berry.h"
#include "main.h"
#include "overworld.h"
#include "wallclock.h"
#include "quest_log.h"

static void UpdatePerDay(struct Time *localTime);

static void InitTimeBasedEvents(void)
{
    FlagSet(FLAG_SYS_CLOCK_SET);
    RtcCalcLocalTime();
    VarSet(VAR_DAYS, gLocalTime.days);
}

void DoTimeBasedEvents(void)
{
    if (FlagGet(FLAG_SYS_CLOCK_SET) && !InPokemonCenter())
    {
        RtcCalcLocalTime();
        UpdatePerDay(&gLocalTime);
    }
}

static void UpdatePerDay(struct Time *localTime)
{
    u16 *days = GetVarPointer(VAR_DAYS);
    u16 daysSince;

    if (*days != localTime->days && *days <= localTime->days)
    {
        daysSince = localTime->days - *days;
        *days = localTime->days;
    }
}

static void ReturnFromStartWallClock(void)
{
    InitTimeBasedEvents();
    TrySetUpQuestLogScenes_ElseContinueFromSave();
}

void StartWallClock(void)
{
    SetMainCallback2(CB2_StartWallClock);
    gMain.savedCallback = ReturnFromStartWallClock;
}
