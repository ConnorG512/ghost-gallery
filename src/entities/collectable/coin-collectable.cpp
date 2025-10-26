#include "entity/coin-collectable.h"
#include "manager/audio-manager.h"
#include "util/random-generation.h"
#include "entity/player.h"

CoinCollectable::CoinCollectable(const int x_pos, const int y_pos, const int coins_given)
    : Collectable{{"assets/image/entity/coin/coin.png"}, x_pos, y_pos}, m_score_given{coins_given}
{
}

void CoinCollectable::givePowerUp(Player& current_player)
{
    if (RandomGeneration::HasHitRandomNumberThreshold(RandomGeneration::GenerateRandomNumber(), 35))
    {
        current_player.score_component.addToScoreMultiplier(1);
    }
    current_player.score_component.increaseScore(m_score_given);
}

void CoinCollectable::playSound(AudioManager& audio_manager)
{
    audio_manager.playAudio(AudioManager::SoundId::coin_pickup);
}
