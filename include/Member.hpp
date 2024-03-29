#ifndef MEMBER_HPP
#define MEMBER_HPP
#include <utility>
#include "Stone.hpp"
class Enchant;
class Enemy;
class Member{
public:
    virtual void Skill()=0;
    Type::Element_type GetType(){return m_type;}
    int GetAtk(){return m_attack;}
    int GetLife(){return m_life;}
    int GetHeal(){return m_heal;}
    void Strike(bool onlyone,int damage,bool defence);
    void SetEnemy(std::vector<std::shared_ptr<Enemy>> target){
        m_enemies = target;}
    Member(Type::Element_type type,int attack,int life,int heal,std::shared_ptr<Enchant> Enchant):m_type(type),m_attack(attack),m_life(life),m_heal(heal),m_Enchant(Enchant){};
private:
    std::shared_ptr<Enchant> m_Enchant;
    std::vector<std::shared_ptr<Member>> m_team;
    std::vector<std::shared_ptr<Enemy>> m_enemies;
    Type::Element_type m_type;
    int m_attack;
    int m_life;
    int m_heal;
};

class Enemy{
public:
    Enemy(Type::Element_type type,int life,int attack,int defence,int CD);
    Type::Element_type GetType(){return m_type;}
    int GetAtk(){return m_attack;}
    int GetLife(){return m_life;}
    int GetCD(){return m_CD;}
    void AddCD(int num){m_CD += num;}
    int GetDefence(){return m_defence;}
    void DealtDamage(int Damage,bool Defence);
    virtual bool Skills(){return true;}
private:
    bool EffectiveDamage;
    Type::Element_type m_type;
    int m_life;
    int m_attack;
    int m_defence;
    int m_CD;
};


//skill
class Boom{
public:
    explicit Boom(std::shared_ptr<Enchant> target):m_Enchant(std::move(target)){};
    int StoneBreak(Type::Element_type Lvalue,bool powerup);
private:
    std::shared_ptr<Enchant> m_Enchant;
};

class StoneTurn{
public:
    explicit StoneTurn(std::shared_ptr<Enchant> target):m_Enchant(std::move(target)){};
    void Turn(Type::Element_type Lvalue,Type::Element_type Rvalue,bool powerup);
private:
    std::shared_ptr<Enchant> m_Enchant;
};

class Dio{
    Dio(std::shared_ptr<Enchant> target):m_Enchant(std::move(target)){};
    void TheWorld(int seconds);
private:
    std::shared_ptr<Enchant> m_Enchant;
};


//Charctor
//MainCharacter
class Mori:public Member,Boom{
public:
    explicit Mori(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,1035,1881,364,target),
          Boom(std::move(target)){};
    void Skill() override{

        StoneBreak(Type::Element_type::Grass,true);
    }
};

class Sean:public Member,Boom{
public:
    explicit Sean(std::shared_ptr<Enchant> target): Member(Type::Element_type::Fire,1107,1980,324,target),
          Boom(std::move(target)){};
    void Skill() override{
        StoneBreak(Type::Element_type::Water,true);
    }
};
class Dunkan:public Member,Boom{
public:
    explicit Dunkan(std::shared_ptr<Enchant> target): Member(Type::Element_type::Grass,953,2176,340,target),
          Boom(std::move(target)){};
    void Skill() override{
        StoneBreak(Type::Element_type::Fire,true);
    }
};
class Nathaniel:public Member,Boom{
public:
    explicit Nathaniel(std::shared_ptr<Enchant> target): Member(Type::Element_type::Light,963,1960,374,target),
          Boom(std::move(target)){};
    void Skill() override{
        StoneBreak(Type::Element_type::Dark,true);
    }
};
class Ando:public Member,Boom{
public:
    explicit Ando(std::shared_ptr<Enchant> target): Member(Type::Element_type::Dark,1137,1843,337,target),
          Boom(std::move(target)){};
    void Skill() override{
        StoneBreak(Type::Element_type::Light,true);
    }
};

//ChineseBeast
class WaterBeast:public Member,StoneTurn{
public:
    explicit WaterBeast(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,979,3199,78,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Heart,Type::Element_type::Water, false);
    }
};
class FireBeast:public Member,StoneTurn{
    explicit FireBeast(std::shared_ptr<Enchant> target): Member(Type::Element_type::Fire,1105,2684,305,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Grass,Type::Element_type::Heart, false);
    }
};
class GrassBeast:public Member,StoneTurn{
    explicit GrassBeast(std::shared_ptr<Enchant> target): Member(Type::Element_type::Grass,952,2949,322,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Heart,Type::Element_type::Grass, false);
    }
};
class LightBeast:public Member,StoneTurn{
    explicit LightBeast(std::shared_ptr<Enchant> target): Member(Type::Element_type::Light,874,2416,321,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        //Todo
    }
};
class DarkBeast:public Member,StoneTurn{
    explicit DarkBeast(std::shared_ptr<Enchant> target): Member(Type::Element_type::Dark,1033,2271,289,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Light,Type::Element_type::Heart, false);
    }
};

/*DefentDragon
class WDefentDragon:public Member{
    explicit WDefentDragon(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,1068,3489,30,target),
          DealDamage(std::move(target), this->GetAtk(), this.){};
    void Skill() override{
        Strike()
    }
};
*/

//Titan
class WaterTitan:public Member,StoneTurn{
public:
    explicit WaterTitan(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,799,1971,104,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Fire,Type::Element_type::Water, false);
    }
};
class FireTitan:public Member,StoneTurn{
public:
    explicit FireTitan(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,970,2471,21,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Grass,Type::Element_type::Fire, false);
    }
};
class GrassTitan:public Member,StoneTurn{
public:
    explicit GrassTitan(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,810,1849,288,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Water,Type::Element_type::Grass, false);
    }
};
class LightTitan:public Member,StoneTurn{
public:
    explicit LightTitan(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,744,2053,107,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Dark,Type::Element_type::Light, false);
    }
};
class DarkTitan:public Member,StoneTurn{
public:
    explicit DarkTitan(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,831,2420,20,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Light,Type::Element_type::Dark, false);
    }
};

//WestBeast
class Cthulhu:public Member,StoneTurn{
public:
    explicit Cthulhu(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,940,2319,123,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Fire,Type::Element_type::Heart, false);
    }
};
class Cerberus:public Member,StoneTurn{
public:
    explicit Cerberus(std::shared_ptr<Enchant> target): Member(Type::Element_type::Fire,1005,2440,109,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Heart,Type::Element_type::Fire, false);
    }
};
class Medusa:public Member,StoneTurn{
public:
    explicit Medusa(std::shared_ptr<Enchant> target): Member(Type::Element_type::Grass,865,2681,115,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        //Todo
    }
};
class Griffin:public Member,StoneTurn{
public:
    explicit Griffin(std::shared_ptr<Enchant> target): Member(Type::Element_type::Light,874,2416,126,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Dark,Type::Element_type::Heart, false);
    }
};
class Baphomet:public Member,StoneTurn{
public:
    explicit Baphomet(std::shared_ptr<Enchant> target): Member(Type::Element_type::Dark,1033,2271,114,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Heart,Type::Element_type::Dark, false);
    }
};

//Norse Mythology
class Freyr:public Member,StoneTurn{
public:
    explicit Freyr(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,1402,3161,442,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Water,Type::Element_type::Water, true);
    }
};
class Tyr:public Member,StoneTurn{
public:
    explicit Tyr(std::shared_ptr<Enchant> target): Member(Type::Element_type::Fire,1499,3326,392,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Fire,Type::Element_type::Fire, true);
    }
};
class Freyja:public Member,StoneTurn{
public:
    explicit Freyja(std::shared_ptr<Enchant> target): Member(Type::Element_type::Grass,1291,3655,412,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Grass,Type::Element_type::Grass, true);
    }
};
class Thor:public Member,StoneTurn{
public:
    explicit Thor(std::shared_ptr<Enchant> target): Member(Type::Element_type::Light,1305,3293,453,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Light,Type::Element_type::Light, true);
    }
};
class Loki:public Member,StoneTurn{
public:
    explicit Loki(std::shared_ptr<Enchant> target): Member(Type::Element_type::Dark,1540,3096,409,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Dark,Type::Element_type::Dark, true);
    }
};
//Slime
class WaterSlime:public Member,StoneTurn{
public:
    explicit WaterSlime(std::shared_ptr<Enchant> target): Member(Type::Element_type::Water,1107,1980,384,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Fire,Type::Element_type::Heart,true);
    }
};
class FireSlime:public Member,StoneTurn{
public:
    explicit FireSlime(std::shared_ptr<Enchant> target): Member(Type::Element_type::Fire,1107,1980,384,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Grass,Type::Element_type::Heart,true);
    }
};
class GrassSlime:public Member,StoneTurn{
public:
    explicit GrassSlime(std::shared_ptr<Enchant> target): Member(Type::Element_type::Grass,1107,1980,384,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Water,Type::Element_type::Heart,true);
    }
};
class LightSlime:public Member,StoneTurn{
public:
    explicit LightSlime(std::shared_ptr<Enchant> target): Member(Type::Element_type::Light,1107,1980,384,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Dark,Type::Element_type::Heart,true);
    }
};
class DarkSlime:public Member,StoneTurn{
public:
    explicit DarkSlime(std::shared_ptr<Enchant> target): Member(Type::Element_type::Light,1107,1980,384,target),
          StoneTurn(std::move(target)){};
    void Skill() override{
        Turn(Type::Element_type::Light,Type::Element_type::Heart,true);
    }
};
#endif
