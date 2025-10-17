#include "enemy.h"
#include "../audio-manager.h"
#include "../random-generation.h"
#include "components/user-input-component.h"
#include "entity.h"
#include "player.h"

#include <array>

namespace {
constexpr std::array<int, 2> score_range{25, 75};
}

Enemy::Enemy(const int x_pos, const int y_pos)
    : Entity{{"assets/image/entity/enemy/ghost/ghost-1.png"},
             2,
             2,
             x_pos,
             y_pos},
      score_to_give{RandomGeneration::NumberBetween(score_range.at(0),
                                                    score_range.at(1))} {}

void Enemy::respawnEnemy() {
  moveSprite(RandomGeneration::NumberBetween(100, 1400),
             RandomGeneration::NumberBetween(200, 750));
  changeEnemyGivenScore();
  m_tick_component.resetTickCount();
}

void Enemy::collidedWithPlayer(Player &current_player,
                               AudioManager &audio_manager) {
  if (collision.isCollidingWith(current_player.collision.m_collision_shape)) {
    current_player.drawPlayerCursor(Player::CursorType::enemy);
    if (current_player.user_input.UserAction() ==
        UserInput::InputAction::fire) {
      respawnEnemy();
      current_player.score_component.increaseScore(score_to_give);
      playSound(audio_manager);
    }
  }
}

void Enemy::changeEnemyGivenScore() {
  score_to_give =
      RandomGeneration::NumberBetween(score_range.at(0), score_range.at(1));
}

void Enemy::playSound(AudioManager &audio_manager) {
  audio_manager.playAudio(AudioManager::SoundId::ghost_death);
}

int Enemy::InitiateAttack() {
  if (m_tick_component.IncrementAndCheckThreshold()) {
    return damage_component.CalculateDamage();
  }
  return 0;
}
