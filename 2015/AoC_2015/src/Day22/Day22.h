#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct EnemyStats {
    int health, damage;
};

struct OurStats {
    int health, mana, shieldCounter, poisonCounter, rechargeCounter, manaUsed;
};

void getMinMana(OurStats ourStats, EnemyStats enemyStats, bool playerTurn, int &overallMinMana, bool hardDifficulty) {
    if (enemyStats.health <= 0 || ourStats.health <= 0) {
        return;
    }
    if (ourStats.manaUsed > overallMinMana) {
        return;
    }
            
    if (playerTurn && hardDifficulty) {
        ourStats.health -= 1;
        if (ourStats.health <= 0) {
            return;
        }
    }

    if (ourStats.poisonCounter > 0) {
        enemyStats.health -= 3;
        ourStats.poisonCounter--;
        if (enemyStats.health <= 0) {
            if (overallMinMana > ourStats.manaUsed) {
                overallMinMana = ourStats.manaUsed;
            }
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
        if (ourStats.mana >= 53) {
            EnemyStats enemyMagicMissile = enemyStats;
            OurStats ourMagicMissile = ourStats;

            ourMagicMissile.mana -= 53;
            ourMagicMissile.manaUsed += 53;
            enemyMagicMissile.health -= 4;

            if (enemyMagicMissile.health <= 0) {
                if (overallMinMana > ourMagicMissile.manaUsed) {
                    overallMinMana = ourMagicMissile.manaUsed;
                }
            }
            else {
                getMinMana(ourMagicMissile, enemyMagicMissile, playerTurn, overallMinMana, hardDifficulty);
            }
        }
        //drain
        if (ourStats.mana >= 73) {
            EnemyStats enemyDrain = enemyStats;
            OurStats ourDrain = ourStats;

            ourDrain.mana -= 73;
            ourDrain.manaUsed += 73;
            ourDrain.health += 2;
            enemyDrain.health -= 2;

            if (enemyDrain.health <= 0) {
                if (overallMinMana > ourDrain.manaUsed) {
                    overallMinMana = ourDrain.manaUsed;
                }
            }
            else {
                getMinMana(ourDrain, enemyDrain, playerTurn, overallMinMana, hardDifficulty);
            }
        }
        if (ourStats.mana >= 113 && ourStats.shieldCounter == 0) {
            EnemyStats enemyShield = enemyStats;
            OurStats ourShield = ourStats;

            ourShield.mana -= 113;
            ourShield.manaUsed += 113;
            ourShield.shieldCounter = 6;

            if (enemyShield.health <= 0) {
                if (overallMinMana > ourShield.manaUsed) {
                    overallMinMana = ourShield.manaUsed;
                }
            }
            else {
                getMinMana(ourShield, enemyShield, playerTurn, overallMinMana, hardDifficulty);
            }
        }
        if (ourStats.mana >= 173 && ourStats.poisonCounter == 0) {
            EnemyStats enemyPoison = enemyStats;
            OurStats ourPoison = ourStats;

            ourPoison.mana -= 173;
            ourPoison.manaUsed += 173;
            ourPoison.poisonCounter = 6;

            getMinMana(ourPoison, enemyPoison, playerTurn, overallMinMana, hardDifficulty);
            
        }
        if (ourStats.mana >= 229 && ourStats.rechargeCounter == 0) {
            EnemyStats enemyRecharge = enemyStats;
            OurStats ourRecharge = ourStats;

            ourRecharge.mana -= 229;
            ourRecharge.manaUsed += 229;
            ourRecharge.rechargeCounter = 5;

            getMinMana(ourRecharge, enemyRecharge, playerTurn, overallMinMana, hardDifficulty);
        }
        
        playerTurn = 0;

    } else {
        playerTurn = 1;
        int damage = enemyStats.damage;
        if (ourStats.shieldCounter > 0) {
            damage = damage - 7;
            if (damage < 1) {
                damage = 1;
            }    
            ourStats.shieldCounter--;
        } 
        ourStats.health -= damage;

        if (ourStats.health <= 0) {
            return;
        } else {
            getMinMana(ourStats, enemyStats, playerTurn, overallMinMana, hardDifficulty);
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
    ourStats.manaUsed = 0;

    int minMana = 10000000;
    bool playerTurn = 1;

    getMinMana(ourStats, enemyStats, playerTurn, minMana, false);
        
    
    std::cout << std::to_string(minMana) << std::endl << std::endl;
}

void AoC2015D22P2() {
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
    ourStats.manaUsed = 0;

    int minMana = 10000000;
    bool playerTurn = 1;

    getMinMana(ourStats, enemyStats, playerTurn, minMana, true);


    std::cout << std::to_string(minMana) << std::endl << std::endl;
}