#pragma once

class ScoreManager;

class DamageComponent
{
  public: 
    DamageComponent();
    DamageComponent( const int base_damage, const int critical_chance, const int critical_multiplier );

    int CalculateDamage();
    int CalculateDamage( const ScoreManager& score_component );

  private:
    int m_base_damage { 2 };
    int m_critical_chance { 0 };
    int m_critical_multiplier { 1 };
};
