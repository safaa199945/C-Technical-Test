/**
 * Copyright (c) 2019 eBikeLabs. All Rights Reserved.
 */

#include "pedaling_mgt.h"

#include "time_mgt.h"
# define MGT_PER_REVOLUTION 12

static uint32_t last_magnet_timestamp = 0; // Timestamp du dernier passage de l'aimant
static uint32_t time_since_last_magnet = 0;
static float current_pedaling_speed = 0; //vitesse de pédalage actuelle en RPM
static float average_pedaling_speed = 0; //vitesse de pédalagemoyenne sur la dernière révolution de pédale
static float speed_buffer[MGT_PER_REVOLUTION]; // Circular buffer pour stocker les dernières vitesses de pédalage.
static uint8_t buffer_index = 0;

/**** Public API ****/

float get_pedaling_speed(void)
{
    // WRITE YOUR CODE HERE
    return current_pedaling_speed;
}

float get_average_pedaling_speed(void)
{
    // WRITE YOUR CODE HERE
    speed_buffer[buffer_index] = current_pedaling_speed;
    buffer_index = (buffer_index + 1) % MGT_PER_REVOLUTION; // se deplacer vers la position suivante du tableau

    // calculer la bitesse moyenne de pedalage
    float sum = 0;
    for (uint8_t i = 0; i < MGT_PER_REVOLUTION; i++) {
        sum += speed_buffer[i];
    }
    average_pedaling_speed = sum / MGT_PER_REVOLUTION;
    return average_pedaling_speed;
}

void new_magnet_cb(void)
{
    // WRITE YOUR CODE HERE
    // Calculer le temps coule depuis le dernier passage de l'aimant.
    uint32_t current_timestamp = get_timestamp();
    uint32_t time_since_last_magnet = current_timestamp - last_magnet_timestamp;

    // Mettre à jour le timestamp du dernier passage de l'aimant.
    last_magnet_timestamp = current_timestamp;

    // Calculer la vitesse de pedalage en fonction du temps ecoule depuis le dernier passage de l'aimant.
    //convertir time_since_last_magnet en minutes et calculer les RPM.
    if (time_since_last_magnet != 0) {
        current_pedaling_speed = 10000000.0 / (2 * time_since_last_magnet);
    } else {
        current_pedaling_speed = 0; //pour gerer la division par 0.
    }

}
