#include <gtest/gtest.h>
#include "../JSON.h"
#include "../character.h"
#include "../Hero.h"
#include "../Monster.h"

//Name test
TEST(Character_test, getName) {
    Character nametest("CMPunk", 48, 12, 7.9);
    std::string name = nametest.getName();
    std::string exp = "CMPunk";
    ASSERT_EQ(exp, name);
}

//DMG test
TEST(Character_test, getDmg) {
    Character DMGtest("CMPunk", 48, 12, 7.9);
    int DMG = DMGtest.getDmg();
    int exp = 12;
    ASSERT_EQ(exp, DMG);
}
//Hp test
TEST(Character_test, getMAXHp) {
    Character Hptest("CMPunk", 48, 12, 7.9);
    int HP = HPtest.getHp();
    int exp = 48;
    ASSERT_EQ(exp, HP);
}
//Cooldown test
TEST(Character_test, getAttackCoolDown) {
    Character Cooldown("CMPunk", 48, 12, 7.9);
    double ACD = Cooldown.getAttackCoolDown();
    double exp = 7.9;
    ASSERT_EQ(expected, ACD);
}

//LVL test
TEST(Character_test, getLevel) {
    Hero* hero = new Hero("RandomHero", 200, 350, 1.2, 10, 8, 19, 1.9);
    int LVL = hero->getLevel();
    int exp = 1;
    ASSERT_EQ(expected, LVL);
}

// XP test
TEST(Character_test, getXp) {
    Hero* hero = new Hero("RandomHero", 200, 350, 1.2, 10, 8, 19, 1.9);
    int XP = hero->getXp();
    int exp = 0;
    ASSERT_EQ(exp, XP);
}


//isAlive test
TEST(Character_test, isAlive) {
    Character alive("CMPunk", 48, 12, 7.9);
    bool test = alive.isAlive();
    bool exp = true;
    ASSERT_EQ(expected, test);
}

//rHp test
TEST(TestfightHP, ResultHP)
{
    Hero* hero= new Hero("RandomHero", 100, 35, 4.2, 20, 5, 18, 0.9);
    Monster* monster = new Monster("RandomMonster", 110, 45, 3.8);
    hero->fightTilDeath(*monster);
    ASSERT_EQ(player->getHp(), 125);
}

//Win test
TEST(TestfightNAME, ResultNAME)
{
    Hero* hero = new Hero("RandomHero", 100, 35, 4.2, 20, 5, 18, 0.9);
    Monster* monster = new Monster("RandomMonster", 110, 45, 3.8);
    hero->fightTilDeath(*monster);
    std::string name;
    if (hero->isAlive()) {
        name = player->getName();
    }
    ASSERT_EQ(name, "RandomHero");
}

//lUP
TEST(Character_test, levelUp) {
    Hero* hero = new Hero("RandomHero", 200, 70, 8.4, 40, 10, 36, 1.8);
    Monster* monster = new Monster("RandomMonster", 60, 4, 14.2);
    hero->fightTilDeath(*monster);
    int levelUp;
    if (player->isAlive()) {
        levelUp = hero->getLevel();
    }
    int exp = 2;
    ASSERT_EQ(expected, levelUp);
}







//parser test file
TEST(ParseUnit_test, fileParser) {
    JSON parsedCreature = JSON::parseFromFile("../Zombie.json");
    Monster zombie(parsedCreature.get<std::string>("name"),
        parsedCreature.get<int>("health_points"),
        parsedCreature.get<int>("damage"),
        parsedCreature.get<double>("attack_cooldown"));

    std::string expname = "Zombie";
    int exphp = 10;
    int expdmg = 1;
    double expcooldown = 2.8;
    ASSERT_EQ(expname, zombie.getName());
    ASSERT_EQ(exphp, zombie.getHp());
    ASSERT_EQ(expdmg, zombie.getDmg());
    ASSERT_EQ(expatc, zombie.getAttackCoolDown());
}

//parser test string
TEST(ParseUnit_test, stringParser) {
    JSON parsedCreature = JSON::loadInputFromString("{\"name\": \"Zombie\",\"health_points\": 10,\"damage\": 1, \"attack_cooldown\": 2.8 }");
    Monster zombie(parsedCreature.get<std::string>("name"),
        parsedCreature.get<int>("health_points"),
        parsedCreature.get<int>("damage"),
        parsedCreature.get<double>("attack_cooldown"));
    std::string expname = "Zombie";
    int exphp = 10;
    int expdmg = 1;
    double expcooldown = 2.8;
    ASSERT_EQ(expname, zombie.getName());
    ASSERT_EQ(exphp, zombie.getHp());
    ASSERT_EQ(expdmg, zombie.getDmg());
    ASSERT_EQ(expatc, zombie.getAttackCoolDown());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
