#include "entity/candy-collectable.h"
#include "manager/audio-manager.h"
#include "entity/player.h"
#include "entity/collectable.h"

CandyCollectable::CandyCollectable(const int x_pos, const int y_pos, const int multiplier_amount)
    : Collectable({"assets/image/entity/candy/candy.png"}, x_pos, y_pos), m_multiplier_to_give{multiplier_amount}
{
}

void CandyCollectable::givePowerUp(Player& current_player)
{
    current_player.score_component.addToScoreMultiplier(m_multiplier_to_give);
}
void CandyCollectable::playSound(AudioManager& audio_manager)
{
    audio_manager.playAudio(AudioManager::SoundId::candy_pickup);
}
