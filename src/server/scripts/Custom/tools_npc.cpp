 /*
    <--------------------------------------------------------------------------->
	 - 2016 HARDCORE
     - Developer(s): Willdevs
     - Edited by: willdevs
     - Complete: %100
     - ScriptName: 'Tools_NPC'
     - Comment: funcionando
     - Shared for: Private ;)
    <--------------------------------------------------------------------------->
    */
 
#include "ScriptPCH.h"
 
class Tools_NPC : public CreatureScript
{
public:
        Tools_NPC() : CreatureScript("Tools_NPC") { }
 
        bool OnGossipHello(Player *player, Creature *creature)
        {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Restaurar mana y vida! :v", GOSSIP_SENDER_MAIN, 1);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Reiniciar Cooldowns", GOSSIP_SENDER_MAIN, 3);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "resetear combate :v", GOSSIP_SENDER_MAIN, 4);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Quitar enfermedad", GOSSIP_SENDER_MAIN, 5);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "reparar objetos", GOSSIP_SENDER_MAIN, 6);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "otros", GOSSIP_SENDER_MAIN, 7);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Script BY Willdevs 2016", GOSSIP_SENDER_MAIN, 8);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                return true;
        }
        bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 action)
        {
                player->PlayerTalkClass->ClearMenus();
                switch(action)
                {
                case 1: // Restore HP and MP
                        if(player->IsInCombat())
                        {
							player->GetSession()->SendAreaTriggerMessage("estas en combate :'v.");
                                player->CLOSE_GOSSIP_MENU();
                                return false;
                        }
                        else if(player->getPowerType() == POWER_MANA)
                                player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
 
                        player->SetHealth(player->GetMaxHealth());
                        player->CLOSE_GOSSIP_MENU();
                        break;
                
                case 3: // Reset Cooldowns
                        if(player->IsInCombat())
                        {
							player->GetSession()->SendAreaTriggerMessage("ESTAS EN COMBATE :v.");
                                player->CLOSE_GOSSIP_MENU();
                                return false;
                        }
 
                        player->RemoveAllSpellCooldown();
                        player->CLOSE_GOSSIP_MENU();
                        break;
                case 4: // Reset Combat
                        player->CombatStop();
                        player->CLOSE_GOSSIP_MENU();
                        break;
                case 5: // Remove Sickness
                        if(player->HasAura(15007))
                                player->RemoveAura(15007);
 
                        player->CLOSE_GOSSIP_MENU();
                        break;
                case 6: // Repair Items
                        player->DurabilityRepairAll(false, 0, false);
                        player->CLOSE_GOSSIP_MENU();
                        break;
                case 7: // Others
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "resetear talentos :'v", GOSSIP_SENDER_MAIN, 71);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "resetear hechizos :v", GOSSIP_SENDER_MAIN, 72);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "<-Atras", GOSSIP_SENDER_MAIN, 73);
                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                        break;
                case 8:
                        player->CLOSE_GOSSIP_MENU();
                        break;
                case 71: // Reset Talents
                        player->resetTalents(true);
                        player->SendTalentsInfoData(false);
                        player->CLOSE_GOSSIP_MENU();
                        break;
                case 72: // Reset Spells
                        player->resetSpells();
                        player->CLOSE_GOSSIP_MENU();
                        break;
                case 73: // ...Back
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Restaurar mana y vida! :v", GOSSIP_SENDER_MAIN, 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Resetear Cooldowns :v", GOSSIP_SENDER_MAIN, 3);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "resetear combate :v", GOSSIP_SENDER_MAIN, 4);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "quitar enfermedad", GOSSIP_SENDER_MAIN, 5);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "reparar objetos", GOSSIP_SENDER_MAIN, 6);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "otros", GOSSIP_SENDER_MAIN, 7);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Script By willdevs 2016", GOSSIP_SENDER_MAIN, 8);
                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                        break;
                }
                return true;
        }
};
 
void AddSC_Tools_NPC()
{
        new Tools_NPC();
}