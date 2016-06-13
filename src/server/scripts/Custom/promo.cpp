/*
-Creado por: Darthye
*/
 
#include "ScriptPCH.h"
 
class npc_promo : public CreatureScript
 
{
public:
    npc_promo() : CreatureScript("npc_promo") { }
 
    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(7, "Escoge tu promocion: ", GOSSIP_SENDER_MAIN, 99);
                switch (player->getClass())
                {
                                case CLASS_DRUID: player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Equilibrio", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30); player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Feral", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+44); player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+45); break;
                                case CLASS_SHAMAN: player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Elemental", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+31); player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Mejora", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+46); player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+47); break;
                                case CLASS_PALADIN: player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Represion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+32); player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Sagrado", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+40); player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Proteccion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+41); break;
                                case CLASS_WARRIOR: player->ADD_GOSSIP_ITEM(10, "Promocion de Guerrero Furia", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+33); player->ADD_GOSSIP_ITEM(10, "Promocion de Guerrero Proteccion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+48); break;
                                case CLASS_PRIEST: player->ADD_GOSSIP_ITEM(10, "Promocion de Sacerdote Sombras", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+34); player->ADD_GOSSIP_ITEM(10, "Promocion de Sacerdote Sagrado", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+42); break;
                                case CLASS_DEATH_KNIGHT: player->ADD_GOSSIP_ITEM(10, "Promocion de DK DPS", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+35); player->ADD_GOSSIP_ITEM(10, "Promocion de DK Tank", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+43); break;
                                case CLASS_ROGUE: player->ADD_GOSSIP_ITEM(10, "Promocion de Picaro", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+36); break;
                                case CLASS_HUNTER: player->ADD_GOSSIP_ITEM(10, "Promocion de Cazador", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+37); break;
                                case CLASS_MAGE: player->ADD_GOSSIP_ITEM(10, "Promocion de Mago", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+38); break;
                                case CLASS_WARLOCK: player->ADD_GOSSIP_ITEM(10, "Promocion de Brujo", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+39); break;
                }
        player->SEND_GOSSIP_MENU(1, creature->GetGUID());
        return true;
    }
 
    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 actions)
    {
           
                if (player->getLevel() == 80)
                {
            player->GetSession()->SendAreaTriggerMessage("No puedes recibir la promocion mas de una vez.");
                        player->CLOSE_GOSSIP_MENU();
                        return true;
        }
               
        if (player->getLevel() == 1)
        {
            uint32 accountID = player->GetSession()->GetAccountId();
            QueryResult result = CharacterDatabase.PQuery("SELECT COUNT(`guid`) FROM `characters` WHERE `account`=%u", accountID);
            Field *fields = result->Fetch();
            uint32 personajes = fields[0].GetUInt32();
 
            if (personajes == 1)               
                    {
                                            if (actions == 99)
                                                {
                                                    player->CLOSE_GOSSIP_MENU();
                                                    return false;
                                                }
                                                player->GetSession()->SendAreaTriggerMessage("Has recibido tu promocion satisfactoriamente.");
                        player->GiveLevel(90);
                                                player->SetMoney(250000000);
                                                switch(actions)
                              {                                                          
                                                                  case GOSSIP_ACTION_INFO_DEF+30: // Druida Equilibrio
                                                                  player->AddItem(72353, 1);
                                                                  player->AddItem(72354, 1);
                                                                  player->AddItem(72416, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72420, 1);
                                                                  player->AddItem(72355, 1);
                                                                  player->AddItem(72356, 1);
                                                                  player->AddItem(72357, 1);
                                                                  player->AddItem(72418, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+44: // Druida Feral
                                                                  player->AddItem(72420, 1);
                                                                  player->AddItem(72337, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72418, 1);
                                                                  player->AddItem(72339, 1);
                                                                  player->AddItem(72340, 1);
                                                                  player->AddItem(72416, 1);
                                                                  player->AddItem(72341, 1);
                                                                  player->AddItem(72342, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+45: // Druida Restauracion
                                                                  player->AddItem(72345, 1);
                                                                  player->AddItem(72346, 1);
                                                                  player->AddItem(72347, 1);
                                                                  player->AddItem(72420, 1);
                                                                  player->AddItem(72348, 1);
                                                                  player->AddItem(72418, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72416, 1);
                                                                  player->AddItem(72349, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+31: // Chaman Elemental
                                                                  player->AddItem(71301, 1);
                                                                  player->AddItem(71302, 1);
                                                                  player->AddItem(71303, 1);
                                                                  player->AddItem(71304, 1);
                                                                  player->AddItem(71305, 1);
                                                                  player->AddItem(72363, 1);
                                                                  player->AddItem(72364, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72367, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+46: // Chaman Mejora
                                                                  player->AddItem(72443, 1);
                                                                  player->AddItem(72444, 1);
                                                                  player->AddItem(72445, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72363, 1);
                                                                  player->AddItem(72364, 1);
                                                                  player->AddItem(72367, 1);
                                                                  player->AddItem(72446, 1);
                                                                  player->AddItem(72447, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+47: // Chaman Restauracion
                                                                  player->AddItem(72432, 1);
                                                                  player->AddItem(72433, 1);
                                                                  player->AddItem(72434, 1);
                                                                  player->AddItem(72435, 1);
                                                                  player->AddItem(72363, 1);
                                                                  player->AddItem(72364, 1);
                                                                  player->AddItem(72367, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72436, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+32: // Paladin Represion
                                                                  player->AddItem(72389, 1);
                                                                  player->AddItem(72390, 1);
                                                                  player->AddItem(72397, 1);
                                                                  player->AddItem(72398, 1);
                                                                  player->AddItem(72396, 1);
                                                                  player->AddItem(72391, 1);
                                                                  player->AddItem(72392, 1);
                                                                  player->AddItem(72393, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+40: // Paladin Tank Sagrado
                                                                  player->AddItem(72389, 1);
                                                                  player->AddItem(72390, 1);
                                                                  player->AddItem(72391, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72392, 1);
                                                                  player->AddItem(72393, 1);
                                                                  player->AddItem(72397, 1);
                                                                  player->AddItem(72398, 1);
                                                                  player->AddItem(72396, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+41: // Paladin Healer Proteccion
                                                                  player->AddItem(72378, 1);
                                                                  player->AddItem(72379, 1);
                                                                  player->AddItem(72397, 1);
                                                                  player->AddItem(72398, 1);
                                                                  player->AddItem(72396, 1);
                                                                  player->AddItem(72380, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72381, 1);
                                                                  player->AddItem(72382, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+33: // Guerrero Furia
                                                                  player->AddItem(72464, 1);
                                                                  player->AddItem(72465, 1);
                                                                  player->AddItem(72466, 1);
                                                                  player->AddItem(72397, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72398, 1);
                                                                  player->AddItem(72396, 1);
                                                                  player->AddItem(72467, 1);
                                                                  player->AddItem(72468, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+48: // Guerrero Proteccion
                                                                  player->AddItem(72464, 1);
                                                                  player->AddItem(72465, 1);
                                                                  player->AddItem(72466, 1);
                                                                  player->AddItem(72467, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72468, 1);
                                                                  player->AddItem(72397, 1);
                                                                  player->AddItem(72398, 1);
                                                                  player->AddItem(72396, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+34: // Sacerdote Sombras
                                                                  player->AddItem(72405, 1);
                                                                  player->AddItem(72316, 1);
                                                                  player->AddItem(72406, 1);
                                                                  player->AddItem(72407, 1);
                                                                  player->AddItem(72408, 1);
                                                                  player->AddItem(72409, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72314, 1);
                                                                  player->AddItem(72321, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+42: // Sacerdote Sagrado
                                                                  player->AddItem(72321, 1);
                                                                  player->AddItem(72316, 1);
                                                                  player->AddItem(72401, 1);
                                                                  player->AddItem(72314, 1);
                                                                  player->AddItem(72402, 1);
                                                                  player->AddItem(72405, 1);
                                                                  player->AddItem(72403, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72400, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+35: // DK DPS
                                                                  player->AddItem(72332, 1);
                                                                  player->AddItem(72333, 1);
                                                                  player->AddItem(72334, 1);
                                                                  player->AddItem(72335, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72336, 1);
                                                                  player->AddItem(72397, 1);
                                                                  player->AddItem(72398, 1);
                                                                  player->AddItem(72396, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+43: // DK Tank
                                                                  player->AddItem(72332, 1);
                                                                  player->AddItem(72333, 1);
                                                                  player->AddItem(72334, 1);
                                                                  player->AddItem(72335, 1);
                                                                  player->AddItem(33808, 1);
                                                                  player->AddItem(72397, 1);
                                                                  player->AddItem(72398, 1);
                                                                  player->AddItem(72396, 1);
                                                                  player->AddItem(72336, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;                                                                 
 
                                                                  case GOSSIP_ACTION_INFO_DEF+36: // Picaro
                                                                  player->AddItem(72423, 1);
                                                                  player->AddItem(72424, 1);
                                                                  player->AddItem(72425, 1);
                                                                  player->AddItem(72426, 1);
                                                                  player->AddItem(72427, 1);
                                                                  player->AddItem(72416, 1);
                                                                  player->AddItem(72420, 1);
                                                                  player->AddItem(72418, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+37: // Cazador
                                                                  player->AddItem(72368, 1);
                                                                  player->AddItem(72369, 1);
                                                                  player->AddItem(72370, 1);
                                                                  player->AddItem(72371, 1);
                                                                  player->AddItem(72372, 1);
                                                                  player->AddItem(72363, 1);
                                                                  player->AddItem(72364, 1);
                                                                  player->AddItem(72367, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+38: // Mago
                                                                  player->AddItem(72373, 1);
                                                                  player->AddItem(72321, 1);
                                                                  player->AddItem(72374, 1);
                                                                  player->AddItem(72375, 1);
                                                                  player->AddItem(72376, 1);
                                                                  player->AddItem(72377, 1);
                                                                  player->AddItem(72314, 1);
                                                                  player->AddItem(72316, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+39: // Brujo
                                                                  player->AddItem(72459, 1);
                                                                  player->AddItem(72460, 1);
                                                                  player->AddItem(72461, 1);
                                                                  player->AddItem(72321, 1);
                                                                  player->AddItem(72462, 1);
                                                                  player->AddItem(72463, 1);
                                                                  player->AddItem(72314, 1);
                                                                  player->AddItem(72316, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                  }
                    }                  
                       
                        if (personajes > 1)
                    {
                        player->GetSession()->SendAreaTriggerMessage("No puedes recibir la promocion teniendo mas de un personaje.");
                                                player->CLOSE_GOSSIP_MENU();
                                                return true;
                    }
                       
                    player->CLOSE_GOSSIP_MENU();
        }
        return true;
    }
};
 
void AddSC_npc_promo()
{
    new npc_promo();
}