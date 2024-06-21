#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct EnemyStats {
    int health, damage;
};

struct OurStats {
    int health, mana, shieldCounter, poisonCounter, rechargeCounter;
};

int getMinMana(OurStats ourStats, EnemyStats enemyStats, bool playerTurn) {
    if (ourStats.poisonCounter > 0) {
        enemyStats.health -= 3;
        ourStats.poisonCounter--;
        if (enemyStats.health <= 0) {
            return 0;
        }
    }
    if (ourStats.rechargeCounter > 0) {
        ourStats.mana += 101;
        ourStats.rechargeCounter--;
    }
    if (playerTurn) {
        playerTurn = 0;
        if (ourStats.shieldCounter > 0) {
           ourStats.shieldCounter--;
        }

        //Select Move
        //magicMissile
        if (mana >= 53) {
            EnemyStats enemyMagicMissile = enemyStats;
            OurStats ourMagicMissile = ourStats;

            ourMagicMissile.mana -= 53;
            enemyMagicMissile.health -= 4;

            if (enemyMagicMissile.health <= 0) {
                if (53 < minMana) {
                    minMana = 53;
                }
            } else {
                int missileMana = getMinMana(ourMagicMissile, enemyMagicMissile, playerTurn) + 53; 
                if (missileMana < minMana) {
                    minMana = missileMana;
                }
            }
        }
        //drain
        if (mana >= 73) {
            EnemyStats enemyDrain = enemyStats;
            OurStats ourDrain = ourStats;

            ourDrain.mana -= 73;
            ourDrain.health += 2;
            enemyDrain.health -= 2;

            if (enemyDrain.health <= 0) {
                if (73 < minMana) {
                    minMana = 73;
                }
            } else {
                int drainMana = getMinMana(ourDrain, enemyDrain, playerTurn) + 73; 
                if (drainMana < minMana) {
                    minMana = drainMana;
                }
            }
        }
        if (mana >= 113 && ourStats.shieldCounter == 0) {
            EnemyStats enemyShield = enemyStats;
            OurStats ourShield = ourStats;

            ourShield.mana -= 113;
            ourShield.shieldCounter = 6;

            if (enemyShield.health <= 0) {
                if (113 < minMana) {
                    minMana = 113;
                }
            } else {
                int drainMana = getMinMana(ourDrain, enemyDrain, playerTurn) + 113; 
                if (drainMana < minMana) {
                    minMana = drainMana;
                }
            }
        }
        
        playerTurn = 0;
        return minMana;
    } else {
        playerTurn = 1;
        int damage= enemyStats.damage;
        if (ourStats.shieldCounter > 0) {
            damage = damage - 7;
            if (damage < 1) {
                damage = 1;
            }    
            ourStats.shieldCounter--;
        } 
        ourStats.health -= 1;

        if (ourStats.health <= 0) {
            return 10000000;
        } else {
            return getMinMana(ourStats, enemyStats, playerTurn);
        }
    }
}

void AoC2015D22P1() {
    std::vector<std::string> input = getFileInput(".//src//Day22//Day22.txt");
    
    EnemyStats enemyStats;
    enemyStats.health = std::stoi(parseStringToString(input[0])[1]);
    enemyStats.damage = std::stoi(parseStringToString(input[1])[1]);

    OurStats ourStats;
    ourStats.health = 50;
    ourStats.mana = 500;
    ourStats.shieldCounter = 0; 
    ourStats.poisonCounter = 0; 
    ourStats.rechargeCounter = 0;

    int minMana;
    bool playerTurn = 1;

    minMana = getMinMana(ourStats, enemyStats, playerTurn);
        
    
    std::cout << to_string(minMana) << std::endl << std::endl;
}

void AoC2015D22P2() {
    std::vector<std::string> input = getFileInput(".//src//Day22//Day22.txt");
    
}
