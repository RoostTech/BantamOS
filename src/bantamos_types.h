/*
 * BantamOS - an RTOS targetted at the Atmel AVR family
 *
 * Copyright 2014 ZachWick <zach@zachwick.xxx>
 *
 * This file is part of BantamOS.
 *
 * BantamOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the license, or
 * (at you option) any later version.
 *
 * BantamOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULA PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BantamOS. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BANTAMOS_TYPES_H
#define BANTAMOS_TYPES_H

typedef unsigned short uint16_t;
typedef signed   short int16_t;
typedef unsigned char  uint8_t;
typedef signed   char  int8_t;
typedef unsigned int   uint32_t;
typedef signed   int   int32_t;


/**
 * A container for the 'ticks' used for timings
 *
 * A union is used for Tick_t so that we can get the efficiency of
 * seperate high and low bytes, but if need be, we can have the 
 * convenience of a full 16bit word.
 * NB: Tick_t is intended for use with standard, equidistant, tick
 * interrupts.
 */
typedef union
{
   uint16_t full;
   struct
   {
      uint8_t lowbyte;
      uint8_t highbyte;
   };
} Tick_t;



#endif
