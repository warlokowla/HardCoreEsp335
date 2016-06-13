/*********************
*  Made by: KuSaNaGy *
*********************/
/*
//#include "ScriptPCH.h" este script include no se debe usar en los scritp custom 
*/

#include "Player.h"
#include "PlayerDump.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"

/*
cualquier inquietud comunicate conmigo
karlos kaxtilla tkd
https://www.facebook.com/carlos.castilla.79
*/

class npc_promo_ali : public CreatureScript 

{
public:
    npc_promo_ali() : CreatureScript("npc_promo_ali") { } 
 
    bool OnGossipHello(Player* player, Creature* creature) 
    {
      player->ADD_GOSSIP_ITEM(7, "SeleccionA tu Promo: Recuerda que es Obligatorio Tener ya creado tus 2 personajes que recibiran la promocion, El sistema necesita reconocer a 2 personajes nivel 1 antes de darte la Promoción! :D", GOSSIP_SENDER_MAIN, 99); //7 igual nuemero restringido del menu
		switch (player->getClass()) 
		{
 				case CLASS_DRUID: player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Equilibrio", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+30); player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Feral", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+44); player->ADD_GOSSIP_ITEM(10, "Promocion de Druida Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+45); break;
                case CLASS_SHAMAN: player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Elemental", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+31); player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Mejora", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+46); player->ADD_GOSSIP_ITEM(10, "Promocion de Chaman Restauracion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+47); break;
                case CLASS_PALADIN: player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Represion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+32); player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Proteccion", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+40); player->ADD_GOSSIP_ITEM(10, "Promocion de Paladin Sagrado", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+41); break;
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
        if (player->getLevel() <= 1)  //confirmamos si player es lvl igual o estricto a 1 continuamos
        {
            uint32 accountID = player->GetSession()->GetAccountId();
            QueryResult result = CharacterDatabase.PQuery("SELECT COUNT(`guid`) FROM `characters` WHERE `account`=%u", accountID);
            Field *fields = result->Fetch();
            uint32 personajes = fields[0].GetUInt32();

            if (personajes == 2)		//aqui damos la instruciones para cuantos player necesitamos que reciban promocion
               {
					    if (actions == 99) //condicional de actuacion de casos 
						{
						    player->CLOSE_GOSSIP_MENU(); 
						    return false;
						}
						player->GetSession()->SendAreaTriggerMessage("Felicidades!! has obtenido tu Promoción!.");
						//aca podemos colocar que el npc de a cualquier player que venga por promo para no repetir en cada uno estas instruciones
						player->GiveLevel(80);
						player->SetMoney(100000000);
						//podemos colocar spell, dinero, item, emblemas lo que deses 
						switch(actions)
                          {								  
																  case GOSSIP_ACTION_INFO_DEF+30: // Druida Equilibrio
                                                                  player->AddItem(48168, 1);
                                                                  player->AddItem(48169, 1);
                                                                  player->AddItem(48170, 1);
                                                                  player->AddItem(48171, 1);
                                                                  player->AddItem(48172, 1);



                                                                  player->AddItem(41327, 1);
                                                                  player->AddItem(41281, 1);
                                                                  player->AddItem(41316, 1);
                                                                  player->AddItem(41293, 1);
                                                                  player->AddItem(41304, 1);
                                                                  player->AddItem(41631, 1);
                                                                  player->AddItem(41636, 1);
                                                                  player->AddItem(41641, 1);
                                                                  player->AddItem(42043, 1);
                                                                  player->AddItem(42076, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+44: // Druida Feral
                                                                  player->AddItem(48203, 1);
                                                                  player->AddItem(48204, 1);
                                                                  player->AddItem(48205, 1);
                                                                  player->AddItem(48206, 1);
                                                                  player->AddItem(48207, 1);
                                                                                                                                                                                                      player->AddItem(41678, 1);
                                                                  player->AddItem(41715, 1);
                                                                  player->AddItem(41661, 1);
                                                                  player->AddItem(41773, 1);
                                                                  player->AddItem(41667, 1); 
                                                                  player->AddItem(41833, 1);
                                                                  player->AddItem(41837, 1);
                                                                  player->AddItem(41841, 1);
                                                                  player->AddItem(42042, 1);
                                                                  player->AddItem(42081, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+45: // Druida Restauracion
                                                                  player->AddItem(48138, 1);
                                                                  player->AddItem(48139, 1);
                                                                  player->AddItem(48140, 1);
                                                                  player->AddItem(48141, 1);
                                                                  player->AddItem(48142, 1);

                                                                  player->AddItem(41321, 1);
                                                                  player->AddItem(41275, 1);
                                                                  player->AddItem(41310, 1);
                                                                  player->AddItem(41287, 1);
                                                                  player->AddItem(41298, 1);
                                                                  player->AddItem(41618, 1);
                                                                  player->AddItem(41622, 1);
                                                                  player->AddItem(41626, 1);
                                                                  player->AddItem(42046, 1);
                                                                  player->AddItem(42079, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+31: // Chaman Elemental
                                                                  player->AddItem(48321, 1);
                                                                  player->AddItem(48322, 1);
                                                                  player->AddItem(48323, 1);
                                                                  player->AddItem(48324, 1);
                                                                  player->AddItem(48325, 1);

                                                                  player->AddItem(41019, 1);
                                                                  player->AddItem(41044, 1);
                                                                  player->AddItem(40993, 1);
                                                                  player->AddItem(41007, 1);
                                                                  player->AddItem(41033, 1);
                                                                  player->AddItem(41066, 1);
                                                                  player->AddItem(41071, 1);
                                                                  player->AddItem(41076, 1);
                                                                  player->AddItem(42043, 1);
                                                                  player->AddItem(42076, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+46: // Chaman Mejora
                                                                  player->AddItem(48351, 1);
                                                                  player->AddItem(48352, 1);
                                                                  player->AddItem(48353, 1);
                                                                  player->AddItem(48354, 1);
                                                                  player->AddItem(48355, 1);

                                                                  player->AddItem(41151, 1);
                                                                  player->AddItem(41211, 1);
                                                                  player->AddItem(41081, 1);
                                                                  player->AddItem(41137, 1);
                                                                  player->AddItem(41199, 1);
                                                                  player->AddItem(41226, 1);
                                                                  player->AddItem(41231, 1);
                                                                  player->AddItem(41236, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42082, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+47: // Chaman Restauracion
                                                                  player->AddItem(48290, 1);
                                                                  player->AddItem(48291, 1);
                                                                  player->AddItem(48292, 1);
                                                                  player->AddItem(48293, 1);
                                                                  player->AddItem(48294, 1);

                                                                  player->AddItem(41013, 1);
                                                                  player->AddItem(41038, 1);
                                                                  player->AddItem(40992, 1);
                                                                  player->AddItem(41001, 1);
                                                                  player->AddItem(41027, 1);                                                                 
                                                                  player->AddItem(41052, 1);
                                                                  player->AddItem(41056, 1);
                                                                  player->AddItem(41061, 1);
                                                                  player->AddItem(42044, 1);
                                                                  player->AddItem(42077, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+32: // Paladin Represion
                                                                  player->AddItem(48612, 1);
                                                                  player->AddItem(48614, 1);
                                                                  player->AddItem(48615, 1);
                                                                  player->AddItem(48616, 1);
                                                                  player->AddItem(48617, 1);

                                                                  player->AddItem(40828, 1);
                                                                  player->AddItem(40869, 1);
                                                                  player->AddItem(40788, 1);
                                                                  player->AddItem(40808, 1);
                                                                  player->AddItem(40849, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42082, 1);
                                                                  player->AddItem(40890, 1);
                                                                  player->AddItem(40883, 1);
                                                                  player->AddItem(40884, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+40: // Paladin Tank Sagrado
                                                                  player->AddItem(48642, 1);
                                                                  player->AddItem(48643, 1);
                                                                  player->AddItem(48644, 1);
                                                                  player->AddItem(48645, 1);
                                                                  player->AddItem(48646, 1);

                                                                  player->AddItem(40828, 1);
                                                                  player->AddItem(40869, 1);
                                                                  player->AddItem(40788, 1);
                                                                  player->AddItem(40808, 1);
                                                                  player->AddItem(40849, 1);                                                                 
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42082, 1);
                                                                  player->AddItem(40890, 1);
                                                                  player->AddItem(40883, 1);
                                                                  player->AddItem(40884, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+41: // Paladin Healer Proteccion
                                                                  player->AddItem(48580, 1);
                                                                  player->AddItem(48581, 1);
                                                                  player->AddItem(48582, 1);
                                                                  player->AddItem(48583, 1);
                                                                  player->AddItem(48584, 1);

                                                                  player->AddItem(40933, 1);
                                                                  player->AddItem(40963, 1);
                                                                  player->AddItem(40907, 1);
                                                                  player->AddItem(40927, 1);
                                                                  player->AddItem(40939, 1);
                                                                  player->AddItem(42044, 1);
                                                                  player->AddItem(42077, 1);
                                                                  player->AddItem(40984, 1);
                                                                  player->AddItem(40978, 1);
                                                                  player->AddItem(40979, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+33: // Guerrero Furia
                                                                  player->AddItem(48381, 1);
                                                                  player->AddItem(48382, 1);
                                                                  player->AddItem(48383, 1);
                                                                  player->AddItem(48384, 1);
                                                                  player->AddItem(48385, 1);

                                                                  player->AddItem(40826, 1);
                                                                  player->AddItem(40866, 1);
                                                                  player->AddItem(40789, 1);
                                                                  player->AddItem(40807, 1);
                                                                  player->AddItem(40847, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42081, 1);
                                                                  player->AddItem(40890, 1);
                                                                  player->AddItem(40883, 1);
                                                                  player->AddItem(40884, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+48: // Guerrero Proteccion
                                                                  player->AddItem(48433, 1);
                                                                  player->AddItem(48447, 1);
                                                                  player->AddItem(48451, 1);
                                                                  player->AddItem(48453, 1);
                                                                  player->AddItem(48455, 1);

                                                                  player->AddItem(40826, 1);
                                                                  player->AddItem(40866, 1);
                                                                  player->AddItem(40789, 1);
                                                                  player->AddItem(40807, 1);
                                                                  player->AddItem(40847, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42081, 1);
                                                                  player->AddItem(40890, 1);
                                                                  player->AddItem(40883, 1);
                                                                  player->AddItem(40884, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+34: // Sacerdote Sombras
                                                                  player->AddItem(48082, 1);
                                                                  player->AddItem(48083, 1);
                                                                  player->AddItem(48084, 1);
                                                                  player->AddItem(48085, 1);
                                                                  player->AddItem(48086, 1);

                                                                  player->AddItem(41915, 1);
                                                                  player->AddItem(41934, 1);
                                                                  player->AddItem(41921, 1);
                                                                  player->AddItem(41940, 1);
                                                                  player->AddItem(41927, 1);
                                                                  player->AddItem(41899, 1);
                                                                  player->AddItem(41904, 1);
                                                                  player->AddItem(41910, 1);
                                                                  player->AddItem(42043, 1);
                                                                  player->AddItem(42076, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+42: // Sacerdote Sagrado
                                                                  player->AddItem(48029, 1);
                                                                  player->AddItem(48031, 1);
                                                                  player->AddItem(48033, 1);
                                                                  player->AddItem(48035, 1);
                                                                  player->AddItem(48037, 1);

                                                                  player->AddItem(41854, 1);
                                                                  player->AddItem(41869, 1);
                                                                  player->AddItem(41859, 1);
                                                                  player->AddItem(41874, 1);
                                                                  player->AddItem(41864, 1);
                                                                  player->AddItem(41882, 1);
                                                                  player->AddItem(41886, 1);
                                                                  player->AddItem(41894, 1);
                                                                  player->AddItem(42046, 1);
                                                                  player->AddItem(42079, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+35: // DK DPS
                                                                  player->AddItem(48482, 1);
                                                                  player->AddItem(48484, 1);
                                                                  player->AddItem(48486, 1);
                                                                  player->AddItem(48488, 1);
                                                                  player->AddItem(48490, 1);

                                                                  player->AddItem(40787, 1);
                                                                  player->AddItem(40868, 1);
                                                                  player->AddItem(40827, 1);
                                                                  player->AddItem(40809, 1);
                                                                  player->AddItem(40848, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42082, 1);
                                                                  player->AddItem(40890, 1);
                                                                  player->AddItem(40883, 1);
                                                                  player->AddItem(40884, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
                                                                 
                                                                  case GOSSIP_ACTION_INFO_DEF+43: // DK Tank
                                                                  player->AddItem(48539, 1);
                                                                  player->AddItem(48541, 1);
                                                                  player->AddItem(48543, 1);
                                                                  player->AddItem(48545, 1);
                                                                  player->AddItem(48547, 1);

                                                                  player->AddItem(40787, 1);
                                                                  player->AddItem(40868, 1);
                                                                  player->AddItem(40827, 1);
                                                                  player->AddItem(40809, 1);
                                                                  player->AddItem(40848, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42082, 1);
                                                                  player->AddItem(40890, 1);
                                                                  player->AddItem(40883, 1);
                                                                  player->AddItem(40884, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;                                                                 
 
                                                                  case GOSSIP_ACTION_INFO_DEF+36: // Picaro
                                                                  player->AddItem(48228, 1);
                                                                  player->AddItem(48229, 1);
                                                                  player->AddItem(48230, 1);
                                                                  player->AddItem(48231, 1);
                                                                  player->AddItem(48232, 1);

                                                                  player->AddItem(41672, 1);
                                                                  player->AddItem(41683, 1);
                                                                  player->AddItem(41650, 1);
                                                                  player->AddItem(41767, 1);
                                                                  player->AddItem(41655, 1);
                                                                  player->AddItem(41833, 1);
                                                                  player->AddItem(41837, 1);
                                                                  player->AddItem(41841, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42082, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+37: // Cazador
                                                                  player->AddItem(48260, 1);
                                                                  player->AddItem(48261, 1);
                                                                  player->AddItem(48262, 1);
                                                                  player->AddItem(48263, 1);
                                                                  player->AddItem(48264, 1);

                                                                  player->AddItem(41157, 1);
                                                                  player->AddItem(41217, 1);
                                                                  player->AddItem(41087, 1);
                                                                  player->AddItem(41143, 1);
                                                                  player->AddItem(41205, 1);
                                                                  player->AddItem(41226, 1);
                                                                  player->AddItem(41231, 1);
                                                                  player->AddItem(41236, 1);
                                                                  player->AddItem(42041, 1);
                                                                  player->AddItem(42082, 1);
                                                                  player->AddItem(42119, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+38: // Mago
                                                                  player->AddItem(47758, 1);
                                                                  player->AddItem(47759, 1);
                                                                  player->AddItem(47760, 1);
                                                                  player->AddItem(47761, 1);
                                                                  player->AddItem(47762, 1);

                                                                  player->AddItem(41946, 1);
                                                                  player->AddItem(41965, 1);
                                                                  player->AddItem(41953, 1);
                                                                  player->AddItem(41971, 1);
                                                                  player->AddItem(41959, 1);
                                                                  player->AddItem(41899, 1);
                                                                  player->AddItem(41904, 1);
                                                                  player->AddItem(41910, 1);
                                                                  player->AddItem(42043, 1);
                                                                  player->AddItem(42076, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
 
                                                                  case GOSSIP_ACTION_INFO_DEF+39: // Brujo
                                                                  player->AddItem(47788, 1);
                                                                  player->AddItem(47789, 1);
                                                                  player->AddItem(47790, 1);
                                                                  player->AddItem(47791, 1);
                                                                  player->AddItem(47792, 1);
                                                                  
                                                                  player->AddItem(41993, 1);
                                                                  player->AddItem(42011, 1);
                                                                  player->AddItem(41998, 1);
                                                                  player->AddItem(42017, 1);
                                                                  player->AddItem(42005, 1);
                                                                  player->AddItem(41899, 1);
                                                                  player->AddItem(41904, 1);
                                                                  player->AddItem(41910, 1);
                                                                  player->AddItem(42043, 1);
                                                                  player->AddItem(42076, 1);
                                                                  player->AddItem(42118, 1);
                                                                  player->CLOSE_GOSSIP_MENU();
                                                                  break;
	                       }
               }
					
			           if (personajes > 2) //si el personaje es mayor a 1 entonce diga tal mensaje 
                    {
                        player->GetSession()->SendAreaTriggerMessage("La promoción solo es para 2 Personaje por Cuenta.");
						      return true;
                    }
			
		    player->CLOSE_GOSSIP_MENU(); //cierro el menu completo
        }
        return true;
    }
};
 
void AddSC_npc_promo_ali() 
{
    new npc_promo_ali(); 
}