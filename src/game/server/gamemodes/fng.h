/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_SERVER_GAMEMODES_FNG_H
#define GAME_SERVER_GAMEMODES_FNG_H
#include <game/server/gamecontroller.h>

class CGameControllerFNG : public IGameController
{
public:
	CGameControllerFNG(class CGameContext *pGameServer);
    virtual void OnCharacterSpawn(class CCharacter *pChr);
    virtual int OnCharacterDeath(class CCharacter *pVictim, class CPlayer *pKiller, int Weapon);
};

#endif
