#!/bin/bash

if [ "$1" == "firered" ] || [ "$1" == "leafgreen" ] || [ "$1" == "firered_rev1" ] || [ "$1" == "leafgreen_rev1" ]; then
  buildname="$1"
  shift
else
  buildname=firered
fi

if [ "$buildname" == "firered" ]; then
  baserom=baserom
elif [ "$buildname" == "leafgreen" ]; then
  baserom=baserom_lg
elif [ "$buildname" == "firered_rev1" ]; then
  baserom=baserom_fr_rev1
elif [ "$buildname" == "leafgreen_rev1" ]; then
  baserom=baserom_lg_rev1
else
  echo unknown buildname $buildname
  exit 1
fi

if [[ -d "$DEVKITARM/bin/" ]]; then
    OBJDUMP_BIN="$DEVKITARM/bin/arm-none-eabi-objdump"
else
    OBJDUMP_BIN="arm-none-eabi-objdump"
fi

OBJDUMP="$OBJDUMP_BIN -D -bbinary -marmv4t -Mforce-thumb"

if [ $(($1)) -ge $((0x8000000)) ]; then
    OPTIONS="--adjust-vma=0x8000000 --start-address=$(($1)) --stop-address=$(($1 + $2))"
else
    OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
fi
$OBJDUMP $OPTIONS ${baserom}.gba > ${baserom}.dump || exit 1
$OBJDUMP $OPTIONS poke${buildname}.gba > poke${buildname}.dump
diff -u ${baserom}.dump poke${buildname}.dump
