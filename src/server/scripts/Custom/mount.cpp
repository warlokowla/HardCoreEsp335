//SCRIPT MAESTRO DE MONTURAS DEVELOPED BY WILLDEVS FOR HARDCORE & ARK WOW
//WORK IN 3.3.5A, 4.3.4, 5.4.8 & 6.2.3
#include "ScriptMgr.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GameEventMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Unit.h"
#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "InstanceScript.h"
#include "CombatAI.h"
#include "PassiveAI.h"
#include "Chat.h"
#include "DBCStructure.h"
#include "DBCStores.h"
#include "ObjectMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
 
class All_Mounts_Npc : public CreatureScript
{
public:
    All_Mounts_Npc() : CreatureScript("All_Mounts_Npc") {}
 
    bool OnGossipHello(Player* player, Creature* creature) override
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "enseñame monturas porfavor :v", GOSSIP_SENDER_MAIN, 1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "adios 7u7r SCRIPT BY WILLDEVS 2016", GOSSIP_SENDER_MAIN, 2);
        player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
        return true;
    }
 
    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action) override
    {
        if (action == 2)
        {
            player->PlayerTalkClass->SendCloseGossip();
            return false;
        }
 
		player->learnSpell(33388);     //aprendiz jinete :v
		player->learnSpell(33391);     //oficial jinete :v
		player->learnSpell(34090);     //experto jinete :v
		player->learnSpell(34091);     //artesano jinete :v
		player->learnSpell(54197);     //vuelo en clima frio
		player->learnSpell(71810);     //Wrathful Gladiator's Frost Wyrm
		player->learnSpell(65917);     //gashina
		player->learnSpell(24252);     //tigre zulian presto gg
		return true;
    }
};
 
void AddSC_All_Mounts_Npc()
{
    new All_Mounts_Npc;
}