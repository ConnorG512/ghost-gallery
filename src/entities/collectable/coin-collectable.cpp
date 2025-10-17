#include "coin-collectable.h"
#include "../../audio-manager.h"
#include "../../random-generation.h"
#include "../player.h"

CoinCollectable::CoinCollectable(const int x_pos, const int y_pos,
                                 const bool is_visible, const int coins_given)
    : Collectable{{"assets/image/entity/coin/coin.png"},
                  1,
                  1,
                  x_pos,
                  y_pos,
                  is_visible},
      m_score_given{coins_given} {}

void CoinCollectable::givePoweUp(Player &current_player) {
  if (RandomGeneration::HasHitThreshold(RandomGeneration::NumberBetween(),
                                        35)) {
    current_player.score_component.addToScoreMultiplier(1);
  }
  current_player.score_component.increaseScore(m_score_given);
}

void CoinCollectable::playSound(AudioManager &audio_manager) {
  audio_manager.playAudio(AudioManager::SoundId::coin_pickup);
}
