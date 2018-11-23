/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#include <game/server/entities/character.h>
#include <game/server/gamecontext.h>
#include <game/server/player.h>

#include "fng.h"


CGameControllerFNG::CGameControllerFNG(CGameContext *pGameServer)
: IGameController(pGameServer)
{
	m_pGameType = "FNG";
}


void CGameControllerFNG::OnCharacterSpawn(CCharacter *pChr)
{
    // default health
    pChr->IncreaseHealth(1);

    // give default weapons
    pChr->GiveWeapon(WEAPON_HAMMER, -1);
    pChr->GiveWeapon(WEAPON_LASER, -1);
    pChr->SetWeapon(WEAPON_LASER);
}

// event
int CGameControllerFNG::OnCharacterDeath(CCharacter *pVictim, CPlayer *pKiller, int Weapon)
{
	// do scoreing
	if(!pKiller || Weapon == WEAPON_GAME)
		return 0;

	if(Weapon == WEAPON_SELF)
		pVictim->GetPlayer()->m_RespawnTick = Server()->Tick()+Server()->TickSpeed()*3.0f;

    if(Weapon == WEAPON_NINJA)
        pKiller->m_Score += 10;

	return 0; 
}