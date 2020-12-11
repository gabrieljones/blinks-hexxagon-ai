#ifndef GAME_MAP_H_
#define GAME_MAP_H_

#include <blinklib.h>

#include "game_player.h"
#include "src/blinks-position/position.h"

#define GAME_MAP_MAX_BLINKS 85

namespace game {

namespace map {

struct Data {
  int16_t x : 6;
  int16_t y : 6;
  uint16_t player : 4;
};

struct Statistics {
  byte player_count;
  struct {
    byte blink_count : 7;
    bool can_move : 1;
  } player[GAME_PLAYER_MAX_PLAYERS + 1];
  bool local_blink_empty_space_in_range;
};

void ComputeMapStats();

void SetMoveOrigin(int8_t x, int8_t y);
position::Coordinates GetMoveOrigin();

void SetMoveTarget(int8_t x, int8_t y);
position::Coordinates GetMoveTarget();

// Computes the player move from origin to destination, updating the game
// map accordingly.
void CommitMove();

const Statistics& GetStatistics();

bool ValidState();

bool MaybeDownload();
bool Downloaded();

// Sets all map data to invalid values.
void Reset();

}  // namespace map

}  // namespace game

#endif