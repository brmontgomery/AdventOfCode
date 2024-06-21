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
    if (enemyStats.health <= 0 || ourStats.health <= 0) {
        return 0;
    }
            
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
        int minMana = 0;
        playerTurn = 0;
        if (ourStats.shieldCounter > 0) {
           ourStats.shieldCounter--;
        }

        //Select Move
        //magicMissile
        if (ourStats.mana >= 53) {
            EnemyStats enemyMagicMissile = enemyStats;
            OurStats ourMagicMissile = ourStats;

            ourMagicMissile.mana -= 53;
            enemyMagicMissile.health -= 4;

            if (enemyMagicMissile.health <= 0) {
                if (53 < minMana) {
                    minMana = getMinMana(ourMagicMissile, enemyMagicMissile, playerTurn) + 53;
                }
            } else {
                int missileMana = getMinMana(ourMagicMissile, enemyMagicMissile, playerTurn) + 53; 
                if (missileMana < minMana) {
                    minMana = missileMana;
                }
            }
        }
        //drain
        if (ourStats.mana >= 73) {
            EnemyStats enemyDrain = enemyStats;
            OurStats ourDrain = ourStats;

            ourDrain.mana -= 73;
            ourDrain.health += 2;
            enemyDrain.health -= 2;

            if (enemyDrain.health <= 0) {
                if (73 < minMana) {
                    minMana = getMinMana(ourDrain, enemyDrain, playerTurn) + 73;
                }
            } else {
                int drainMana = getMinMana(ourDrain, enemyDrain, playerTurn) + 73; 
                if (drainMana < minMana) {
                    minMana = drainMana;
                }
            }
        }
        if (ourStats.mana >= 113 && ourStats.shieldCounter == 0) {
            EnemyStats enemyShield = enemyStats;
            OurStats ourShield = ourStats;

            ourShield.mana -= 113;
            ourShield.shieldCounter = 6;

            int shieldMana = getMinMana(ourShield, enemyShield, playerTurn) + 113;
            if (shieldMana < minMana) {
                minMana = shieldMana;
            }
        }
        if (ourStats.mana >= 173 && ourStats.poisonCounter == 0) {
            EnemyStats enemyPoison = enemyStats;
            OurStats ourPoison = ourStats;

            ourPoison.mana -= 173;
            ourPoison.poisonCounter = 6;

            int poisonMana = getMinMana(ourPoison, enemyPoison, playerTurn) + 173;
            if (poisonMana < minMana) {
                minMana = poisonMana;
            }
        }
        if (ourStats.mana >= 229 && ourStats.rechargeCounter == 0) {
            EnemyStats enemyRecharge = enemyStats;
            OurStats ourRecharge = ourStats;

            ourRecharge.mana -= 229;
            ourRecharge.rechargeCounter = 6;

            int rechargeMana = getMinMana(ourRecharge, enemyRecharge, playerTurn) + 229;
            if (rechargeMana < minMana) {
                minMana = rechargeMana;
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
    enemyStats.health = std::stoi(parseStringToString(input[0], ' ')[2]);
    enemyStats.damage = std::stoi(parseStringToString(input[1], ' ')[1]);

    OurStats ourStats;
    ourStats.health = 50;
    ourStats.mana = 500;
    ourStats.shieldCounter = 0; 
    ourStats.poisonCounter = 0; 
    ourStats.rechargeCounter = 0;

    int minMana;
    bool playerTurn = 1;

    minMana = getMinMana(ourStats, enemyStats, playerTurn);
        
    
    std::cout << std::to_string(minMana) << std::endl << std::endl;
}

void AoC2015D22P2() {
    std::vector<std::string> input = getFileInput(".//src//Day22//Day22.txt");
    
}