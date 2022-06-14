#include "CollisionHandling.h"
#include "TerritoryEater.h"
#include "Player.h"
#include "Life.h"
#include "AddTime.h"
#include "FreezeEnemies.h"
#include "KillEnemy.h"
#include "ImmunetyGift.h"
#include "Graphics.h"

namespace // anonymous namespace — the standard way to make function "static"
{
    void playerEnemy(Object& enemy,Object& player)
    {
        Enemies& anEnemy= static_cast<Enemies&>(enemy);
        anEnemy.reduceLife();
        anEnemy.updateFailure(true);
    }
    void playerLife(Object& life, Object& player)
    {
        Life& lifeGift = static_cast<Life&>(life);
        lifeGift.addLife();
        lifeGift.deleted();
    }
    void playerAddTime(Object& addTime, Object& player)
    {
        AddTime& addTimeGift = static_cast<AddTime&>(addTime);
        addTimeGift.addTime();
        addTimeGift.deleted();
    }
    void playerKillEnemy(Object& killEnemy, Object& player)
    {
        KillEnemy& killEnemyGift = static_cast<KillEnemy&>(killEnemy);
        killEnemyGift.kill();
        killEnemyGift.deleted();
    }
    void playerImmunetyGift(Object& Immunety, Object& player)
    {
        ImmunetyGift& immunetyGift = static_cast<ImmunetyGift&>(Immunety);
        immunetyGift.immune();
        immunetyGift.deleted();
    }
    void playerFreezeEnemies(Object& freezeEnemies, Object& player)
    {
        FreezeEnemies& freezeEnemiesGift = static_cast<FreezeEnemies&>(freezeEnemies);
        freezeEnemiesGift.freezeEnemies();
        freezeEnemiesGift.deleted();
    }

    void KillPlayerEnemy(Object& enemy, Object& KillPlayer)
    {
        Enemies& anEnemy = static_cast<Enemies&>(enemy);
        anEnemy.deleted();
    }
    void ImmuneplayerEnemy(Object& enemy, Object& ImmunePlayer) { return; }
   
    using HitFunctionPtr = void (*)(Object&, Object&);
    // typedef void (*HitFunctionPtr)(GameObject&, GameObject&);
    using Key = std::pair<std::type_index, std::type_index>;
    // std::unordered_map is better, but it requires defining good hash function for pair
    using HitMap = std::map<Key, HitFunctionPtr>;

    HitMap initializeCollisionMap()
    {
        HitMap phm;
        phm[Key(typeid(Enemies), typeid(KillingPlayer))] = &KillPlayerEnemy;
        phm[Key(typeid(Enemies), typeid(ImmunePlayer))] = &ImmuneplayerEnemy;
        phm[Key(typeid(Enemies), typeid(Player))] = &playerEnemy;
        phm[Key(typeid(Life), typeid(Player))] = &playerLife;
        phm[Key(typeid(Life), typeid(ImmunePlayer))] = &playerLife;
        phm[Key(typeid(Life), typeid(KillingPlayer))] = &playerLife;
        phm[Key(typeid(AddTime), typeid(Player))] = &playerAddTime;
        phm[Key(typeid(AddTime), typeid(ImmunePlayer))] = &playerAddTime;
        phm[Key(typeid(AddTime), typeid(KillingPlayer))] = &playerAddTime;
        phm[Key(typeid(FreezeEnemies), typeid(Player))] = &playerFreezeEnemies;
        phm[Key(typeid(FreezeEnemies), typeid(ImmunePlayer))] = &playerFreezeEnemies;
        phm[Key(typeid(FreezeEnemies), typeid(KillingPlayer))] = &playerFreezeEnemies;
        phm[Key(typeid(KillEnemy), typeid(Player))] = &playerKillEnemy;
        phm[Key(typeid(KillEnemy), typeid(ImmunePlayer))] = &playerKillEnemy;
        phm[Key(typeid(KillEnemy), typeid(KillingPlayer))] = &playerKillEnemy;
        phm[Key(typeid(ImmunetyGift), typeid(Player))] = &playerImmunetyGift;
        phm[Key(typeid(ImmunetyGift), typeid(ImmunePlayer))] = &playerImmunetyGift;
        phm[Key(typeid(ImmunetyGift), typeid(KillingPlayer))] = &playerImmunetyGift;

        
        //...
        return phm;
    }

    HitFunctionPtr lookup(const std::type_index& class1, const std::type_index& class2)
    {
        static HitMap collisionMap = initializeCollisionMap();
        auto mapEntry = collisionMap.find(std::make_pair(class1, class2));
        if (mapEntry == collisionMap.end())
        {
            return nullptr;
        }
        return mapEntry->second;
    }

} // end namespace

void processCollision(Object& object1,Object& object2)
{
    auto phf = lookup(typeid(object1), typeid(object2));
   /* if (!phf)
    {
        throw UnknownCollision(object1, object2);
    }*/
    phf(object1, object2);
}

