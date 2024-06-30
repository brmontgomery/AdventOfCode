#pragma once
#include <iostream>
#include "AoCUtilities.h"

struct EnemyStats {
    int health, damage;
};

struct OurStats {
    int health, mana, shieldCounter, poisonCounter, rechargeCounter, manaUsed;
};

//recursive function
void getMinMana(OurStats ourStats, EnemyStats enemyStats, bool playerTurn, int &overallMinMana, bool hardDifficulty) {
    //check whether we have reached an end condition
    if (enemyStats.health <= 0 || ourStats.health <= 0) {
        return;
    }

    //check if this is an invalid branch now
    if (ourStats.manaUsed > overallMinMana) {
        return;
    }
    
    //check whether this is problem 1 or two and implement the health -1 every two recursive calls rule.
    if (playerTurn && hardDifficulty) {
        ourStats.health -= 1;
        if (ourStats.health <= 0) {
            return;
        }
    }

    //inflict poison damage at start of every turn if it is active.
    if (ourStats.poisonCounter > 0) {
        enemyStats.health -= 3;
        ourStats.poisonCounter--;
        if (enemyStats.health <= 0) {
            if (overallMinMana > ourStats.manaUsed) {
                overallMinMana = ourStats.manaUsed;
            }
        }
    }
    //recharge mana at start of turn when the recharge effect is active
    if (ourStats.rechargeCounter > 0) {
        ourStats.mana += 101;
        ourStats.rechargeCounter--;
    }

    if (playerTurn) {
        //if it is player turn and shield is active, make sure the counter still goes down.
        playerTurn = 0;
        if (ourStats.shieldCounter > 0) {
           ourStats.shieldCounter--;
        }

        //Select Move
        //magicMissile
        //create a new branch if we have enough mana for if we were to try using magic missile. Also implement its effects
        if (ourStats.mana >= 53) {
            EnemyStats enemyMagicMissile = enemyStats;
            OurStats ourMagicMissile = ourStats;

            ourMagicMissile.mana -= 53;
            ourMagicMissile.manaUsed += 53;
            enemyMagicMissile.health -= 4;

            //check for end condition
            if (enemyMagicMissile.health <= 0) {
                //in event of end condition, check if this is branch is out new frontrunner.
                if (overallMinMana > ourMagicMissile.manaUsed) {
                    overallMinMana = ourMagicMissile.manaUsed;
                }
            }
            else {
                //otherwise, check further down the branch
                getMinMana(ourMagicMissile, enemyMagicMissile, playerTurn, overallMinMana, hardDifficulty);
            }
        }
        //drain
        //create a new branch if we have enough mana for if we were to try using Drain. Also implement its effects
        if (ourStats.mana >= 73) {
            EnemyStats enemyDrain = enemyStats;
            OurStats ourDrain = ourStats;

            ourDrain.mana -= 73;
            ourDrain.manaUsed += 73;
            ourDrain.health += 2;
            enemyDrain.health -= 2;

            //check for end condition
            if (enemyDrain.health <= 0) {
                //in event of end condition, check if this is branch is out new frontrunner.
                if (overallMinMana > ourDrain.manaUsed) {
                    overallMinMana = ourDrain.manaUsed;
                }
            }
            else {
                //otherwise, check further down the branch
                getMinMana(ourDrain, enemyDrain, playerTurn, overallMinMana, hardDifficulty);
            }
        }
        //create a new branch if we have enough mana for if we were to try using Shield and whether it is already active. Also implement its effects
        if (ourStats.mana >= 113 && ourStats.shieldCounter == 0) {
            EnemyStats enemyShield = enemyStats;
            OurStats ourShield = ourStats;

            ourShield.mana -= 113;
            ourShield.manaUsed += 113;
            ourShield.shieldCounter = 6;

            //check end condition (might be redundant)
            if (enemyShield.health <= 0) {
                if (overallMinMana > ourShield.manaUsed) {
                    overallMinMana = ourShield.manaUsed;
                }
            }
            else {
                getMinMana(ourShield, enemyShield, playerTurn, overallMinMana, hardDifficulty);
            }
        }
        //create a new branch if we have enough mana for if we were to try using Poison and whether it is already active. Also implement its effects
        if (ourStats.mana >= 173 && ourStats.poisonCounter == 0) {
            EnemyStats enemyPoison = enemyStats;
            OurStats ourPoison = ourStats;

            ourPoison.mana -= 173;
            ourPoison.manaUsed += 173;
            ourPoison.poisonCounter = 6;

            getMinMana(ourPoison, enemyPoison, playerTurn, overallMinMana, hardDifficulty);
            
        }
        //create a new branch if we have enough mana for if we were to try using Recharge and whether it is already active. Also implement its effects
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
        //if it is the enemy turn, inflict appropriate damage and check for a losing condition
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
            //if no losing consition found, keep going down this branch
            getMinMana(ourStats, enemyStats, playerTurn, overallMinMana, hardDifficulty);
        }
    }
}

void AoC2015D22P1() {
    std::vector<std::string> input = getFileInput(".//src//Day22//Day22.txt");
    
    //set enemy stats
    EnemyStats enemyStats;
    enemyStats.health = std::stoi(parseStringToString(input[0], ' ')[2]);
    enemyStats.damage = std::stoi(parseStringToString(input[1], ' ')[1]);

    //set player stats
    OurStats ourStats;
    ourStats.health = 50;
    ourStats.mana = 500;
    ourStats.shieldCounter = 0; 
    ourStats.poisonCounter = 0; 
    ourStats.rechargeCounter = 0;
    ourStats.manaUsed = 0;

    int minMana = 10000000;
    bool playerTurn = 1;

    //recursively find the solution that requires the least mana based upon the rules provided
    getMinMana(ourStats, enemyStats, playerTurn, minMana, false);
        
    std::cout << std::to_string(minMana) << std::endl << std::endl;
}

void AoC2015D22P2() {
    std::vector<std::string> input = getFileInput(".//src//Day22//Day22.txt");

    //set enemy stats
    EnemyStats enemyStats;
    enemyStats.health = std::stoi(parseStringToString(input[0], ' ')[2]);
    enemyStats.damage = std::stoi(parseStringToString(input[1], ' ')[1]);

    //set player stats
    OurStats ourStats;
    ourStats.health = 50;
    ourStats.mana = 500;
    ourStats.shieldCounter = 0;
    ourStats.poisonCounter = 0;
    ourStats.rechargeCounter = 0;
    ourStats.manaUsed = 0;

    int minMana = 10000000;
    bool playerTurn = 1;

    //recursively find the solution that requires the least mana based upon the rules provided
    getMinMana(ourStats, enemyStats, playerTurn, minMana, true);


    std::cout << std::to_string(minMana) << std::endl << std::endl;
}