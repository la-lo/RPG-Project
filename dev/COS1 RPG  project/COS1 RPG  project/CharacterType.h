#pragma once
#include<string>
enum class CharacterType
{
	Warrior,
	Tank,
	Mage,
	Rouge,
};

inline std::string getClassName(CharacterType type)
{
	switch(type)
	{
	case CharacterType::Warrior:
		return"Warrior";
	case CharacterType::Tank:
		return"Tank";
	case CharacterType::Mage:
		return"Mage";
	case CharacterType::Rouge:
		return"Rouge";
	default:
		return"Uknown";
	}
}