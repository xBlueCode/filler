
rm logs/*
cp ../abbesbes.filler players/abbesbes.filler
./filler_vm -f maps/map00 -p1 players/abbesbes.filler -p2 $1 | ../filler_display
./filler_vm -f maps/map01 -p1 players/abbesbes.filler -p2 $1 | ../filler_display
./filler_vm -f maps/map02 -p1 players/abbesbes.filler -p2 $1 | ../filler_display
