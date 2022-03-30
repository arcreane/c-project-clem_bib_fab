#include<raylib.h>
#include <string>
#include "../entities/Tower.h"
#include "../entities/Monster.h"
#include "../tile/TileMapManager.h"
#include "../controller/Waves.h"


int main() {
    TileMapManager tileMapManager = TileMapManager("../resources/tower_defense.xml");
    tileMapManager.launch();
}

