
rm logs/*
cp ../abbesbes.filler players/abbesbes.filler
./filler_vm -f maps/map01 -p1 players/abbesbes.filler -p2 $1
