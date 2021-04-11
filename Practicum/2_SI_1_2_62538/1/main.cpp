/**
*	Solution to homework assignment 2
*	Object Oriented Programming Course
*	Faculty of Mathematics and Informatics of Sofia University
*	Summer semester 2020/2021 *
*	@author Teodora Petkova
*	@idnumber 62538
*	@task 1
*	@compiler VC
*/

#include <assert.h>
#include <iostream>

#include "Inventory.h"

using namespace std;

void runTestForBackpack(){
    Money money=Money();
    assert(money.getBronzeCoins() == 0);
    money.addMoney(20);
    money.addSilver(2);
    money.addGold(1);
    assert(money.getBronzeCoins() == 20);
    assert(money.getSilverCoins() == 2);
    assert(money.getGoldCoins()==1);

    Materials material1=Materials();
    assert(material1.getType()==MaterialType::none);
    assert(material1.getQuantityPerSlot()==0);

    Materials materialEss=Materials(MaterialType::essence,12);
    assert(materialEss.getType()==MaterialType::essence);
    assert(materialEss.getQuantityPerSlot()==10);
    assert(materialEss.getQuantity()==12);

    Materials materialCL=Materials(MaterialType::cloth,10);
    assert(materialCL.getType()==MaterialType::cloth);
    assert(materialCL.getQuantityPerSlot()==20);
    assert(materialCL.getQuantity()==10);

    Backpack<Money> moneyPoch =Backpack<Money>();
    assert(moneyPoch.isEmpty()==true);
    assert(moneyPoch.isFull()==false);
    //moneyPoch.addToBackpack(money);
    assert(moneyPoch.addToBackpack(money)==1);
    assert(moneyPoch.numOfFullSlots()==1);
    assert(moneyPoch.removeFromBackpack(Money(23))==1);
    Inventory<Backpack<Money>> forMoneyPoch=Inventory<Backpack<Money>>(moneyPoch);

    Backpack<Materials> backpackMat=Backpack<Materials>();
    assert(backpackMat.isFull()==false);
    assert(backpackMat.isEmpty()==true);
    Materials toAdd=Materials(MaterialType::cloth,23);
    assert(backpackMat.addToBackpack(toAdd)==4);
    assert(backpackMat.isEmpty()== false);
    assert(backpackMat.numOfFullSlots()==2);
    assert(backpackMat.addToBackpack(materialEss)==4);
    assert(backpackMat.numOfFullSlots()==4);
    assert(backpackMat.addToBackpack(materialEss)==1);
    assert(backpackMat.numOfFullSlots()==5);
    assert(backpackMat.removeFromBackpack(materialEss)==3);
    assert(backpackMat.numOfFullSlots()==4);
}

void runTestForEquipment(){
    Weapon nullWeapon=Weapon();
    assert(nullWeapon.getHitDamage()[0]== 0 && nullWeapon.getHitDamage()[1]==0);
    assert(nullWeapon.getNumOfEffects()==0);
    assert(nullWeapon.getWeaponForm()==WeaponForm::null);
    assert(nullWeapon.getWeaponType()==WeaponType::zero);
    assert(nullWeapon.getWeaponScore()==0);

    unsigned int newDam[]={50,200};
    Weapon newWeapon=Weapon("Assassin's blade",WeaponType::one_handed,WeaponForm::dagger,newDam);
    assert(newWeapon.getHitDamage()[0]== 50 && newWeapon.getHitDamage()[1]==200);
    assert(newWeapon.getNumOfEffects()==0);
    assert(newWeapon.getWeaponForm()==WeaponForm::dagger);
    assert(newWeapon.getWeaponType()==WeaponType::one_handed);
    assert(newWeapon.getWeaponScore()==93.75);
    newWeapon.addEffect("Swash",100);
    assert(newWeapon.getNumOfEffects()==1);
    assert(newWeapon.getWeaponScore()==168.75);
    newWeapon.changePowerOfEffect("Swash",200);
    assert(newWeapon.getWeaponScore()==243.75);
    newWeapon.addEffect("Swash",100);
    assert(newWeapon.getWeaponScore()==168.75);
    newWeapon.removeEffect("Swash");
    assert(newWeapon.getNumOfEffects()==0);
    assert(newWeapon.getWeaponScore()==93.75);
    newWeapon.changeWeaponForm(WeaponForm::lance);
    assert(newWeapon.getWeaponForm()==WeaponForm::lance);
    assert(newWeapon.getWeaponType()==WeaponType::two_handed);
    newWeapon.changeWeaponType(WeaponType::one_handed);
    assert(newWeapon.getWeaponType()==WeaponType::two_handed);
    assert(newWeapon.getSlots()==2);
    assert(newWeapon==newWeapon);

    Armor nullArmor=Armor();
    assert(nullArmor.getNumOfEffects()==0);
    assert(nullArmor.getArmorType()==ArmorType::Null);
    assert(nullArmor.getDefense()==0);
    assert(nullArmor.getGearScore()==0);

    Armor newArmor=Armor("Weightless vest",ArmorType::Leather,200);
    assert(newArmor.getNumOfEffects()==0);
    assert(newArmor.getArmorType()==ArmorType::Leather);
    assert(newArmor.getDefense()==200);
    assert(newArmor.getGearScore()==0);
    assert(newArmor.getName()=="Weightless vest");
    newArmor.addEffect("Wall",300);
    assert(newArmor.getNumOfEffects()==1);
    assert(newArmor.getGearScore()==300);
    newArmor.changePowerOfEffect("Wall",350);
    assert(newArmor.getNumOfEffects()==1);
    assert(newArmor.getGearScore()==350);
    newArmor.changeType(ArmorType::Mail);
    assert(newArmor.getArmorType()==ArmorType::Mail);
    assert(newArmor==newArmor);

    Equipment<Armor> nullArmorChest=Equipment<Armor>();
    assert(nullArmorChest.isEquipmentEmpty()==true);
    assert(nullArmorChest.isEquipmentFull()==false);
    assert(nullArmorChest.numOfFullSlots()==0);

    Equipment<Weapon > nullWeaponChest=Equipment<Weapon>();
    assert(nullWeaponChest.isEquipmentEmpty()==true);
    assert(nullWeaponChest.isEquipmentFull()==false);
    assert(nullWeaponChest.numOfFullSlots()==0);

    Equipment<Armor> armorChest=Equipment<Armor>();
    armorChest.addToEquipment(nullArmor);
    armorChest.addToEquipment(newArmor);
    assert(armorChest.isEquipmentEmpty()== false);
    assert(armorChest.isEquipmentFull()==false);
    assert(armorChest.numOfFullSlots()==1);
    assert(armorChest.theBestEquipment()==newArmor);

    Armor kirishima=Armor("Eijiro Kirishima",ArmorType::Leather,300);
    kirishima.addEffect("Rock",400);
    kirishima.addEffect("Love Katsuki Bakugou",600);
    armorChest.addToEquipment(kirishima);
    assert(armorChest.theBestEquipment()==kirishima);
    assert(armorChest.numOfFullSlots()==2);
    armorChest.removeFromEquipment(newArmor);
    assert(armorChest.numOfFullSlots()==1);

    assert(kirishima!=newArmor);

    Equipment<Weapon> weaponChest=Equipment<Weapon>();
    weaponChest.addToEquipment(nullWeapon);
    weaponChest.addToEquipment(newWeapon);
    weaponChest.addToEquipment(newWeapon);

    assert(weaponChest.isEquipmentEmpty()== false);
    assert(weaponChest.isEquipmentFull()==false);
    assert(weaponChest.numOfFullSlots()==4);
    assert(weaponChest.theBestEquipment()==newWeapon);

    weaponChest.removeFromEquipment(newWeapon);
    assert(weaponChest.numOfFullSlots()==0);

    unsigned int dam[]={100,350};
    Weapon wire=Weapon("Wire of death", WeaponType::two_handed, WeaponForm::garroteWire, dam);
    weaponChest.addToEquipment(wire);
    dam[0]=200;
    dam[1]=400;
    Weapon artur=Weapon("Artur's sword", WeaponType::one_handed, WeaponForm::sword, dam);
    weaponChest.addToEquipment(artur);
    assert(weaponChest.numOfFullSlots()==3);
    assert(weaponChest.theBestEquipment()==wire);


    assert(weaponChest!=nullWeaponChest);
    assert(weaponChest==weaponChest);

    assert(armorChest!=nullArmorChest);
    assert(armorChest==armorChest);


}

void runTestForInventory(){
    Inventory<Backpack<Money>> money=Inventory<Backpack<Money>>();

}
int main() {

    runTestForBackpack();
    runTestForEquipment();
    runTestForInventory();
    cout << "End Successfully" <<endl;
    return 0;
}
