/*
Copyright (C) 1994-1995  Apogee Software, Ltd.
Copyright (C) 2002-2015  icculus.org, GNU/Linux port
Copyright (C) 2017-2018  Steven LeVesque

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
//***************************************************************************
//
//                  RT_MAIN.H
//
//***************************************************************************

#ifndef _rt_main_public
#define _rt_main_public

#include "develop.h"
#include "rt_def.h"
#include "rottnet.h"
#include "rt_battl.h"

#if (SHAREWARE==0)
#define  STANDARDGAMELEVELS   (DATADIR "darkwar.rtl")
#define  STANDARDBATTLELEVELS (DATADIR "darkwar.rtc")
#define  SUPERROTTBATTLELEVELS (DATADIR "ROTTCD.RTC")
#define  SITELICENSEBATTLELEVELS (DATADIR "ROTTSITE.RTC")
#else
#define  STANDARDGAMELEVELS   (DATADIR "HUNTBGIN.RTL")
#define  STANDARDBATTLELEVELS (DATADIR "HUNTBGIN.RTC")
#endif

enum
{   vl_low,
    vl_medium,
    vl_high,
    vl_excessive
};

// Enum for each version of the game
typedef enum
{
    ROTT_SHAREWARE,
    ROTT_REGISTERED,
    ROTT_SUPERCD,
    ROTT_SITELICENSE
} version_type;

typedef struct
{
    int GodModeTime;
    int DogModeTime;
    int ShroomsModeTime;
    int ElastoModeTime;
    int AsbestosVestTime;
    int BulletProofVestTime;
    int GasMaskTime;
    int MercuryModeTime;

    int GodModeRespawnTime;
    int DogModeRespawnTime;
    int ShroomsModeRespawnTime;
    int ElastoModeRespawnTime;
    int AsbestosVestRespawnTime;
    int BulletProofVestRespawnTime;
    int GasMaskRespawnTime;
    int MercuryModeRespawnTime;

} specials;


typedef struct
{
    unsigned Version;
    // Variable for which version of the game can be played
    version_type Product;

    int     TimeCount;
    int     frame;
    int     secrettotal,treasuretotal,killtotal;
    int     secretcount,treasurecount,killcount;
    int     supertotal,healthtotal,missiletotal;
    int     supercount,healthcount,missilecount;
    int     democratictotal,planttotal;
    int     democraticcount,plantcount;
    int     dipballs;
    int     difficulty;
    int     violence;
    int     mapon;
    int     score;
    int     episode;
    int     battlemode;
    int     battleoption;
    int     randomseed;
    boolean teamplay;
    boolean DODEMOCRATICBONUS1;
    boolean DOGROUNDZEROBONUS;
    int     autorun;

    // Battle Options
    battle_type BattleOptions;

    boolean SpawnCollectItems;
    boolean SpawnEluder;
    boolean SpawnDeluder;
    boolean ShowScores;
    boolean PlayerHasGun[ MAXPLAYERS ];
    specials SpecialsTimes;
    
} gametype;


extern  int      doublestep;
extern  boolean  tedlevel;
extern  int      tedlevelnum;
extern  int      tedx;
extern  int      tedy;
extern  boolean  fizzlein;
extern  int      pheight;
extern  int      NoSound;
extern  int      timelimit;
extern  boolean  timelimitenabled;
extern  boolean  noecho;
extern  boolean  demoexit;
extern  boolean  quiet;

extern gametype  gamestate;
extern boolean DebugOk;
extern  boolean newlevel;

void QuitGame( void );
void PlayCinematic (void);
void InitCharacter(void);
void ShutDown ( void );
void UpdateGameObjects ( void );

extern  int polltime;
extern  int oldpolltime;
extern  volatile int oldtime;
void PauseLoop ( void );
#if SAVE_SCREEN
extern boolean inhmenu;
void SaveScreen (boolean saveLBM);
#endif
void SetupWads( void );

extern boolean SCREENSHOTS;
extern boolean COMPUTELEVELSIZE;
extern boolean MONOPRESENT;
extern boolean MAPSTATS;
extern boolean TILESTATS;
extern boolean HUD;

extern char CWD[40];

#endif
