#include "MeshLookup.h"

using namespace openblack;

MeshLookup<TreeInfo> openblack::treeMeshLookup {
    {TreeInfo::Beech, MeshId::TreeBeech},       {TreeInfo::Birch, MeshId::TreeBirch},
    {TreeInfo::Cedar, MeshId::TreeCedar},       {TreeInfo::Conifer, MeshId::TreeConifer},
    {TreeInfo::ConiferA, MeshId::TreeConiferA}, {TreeInfo::Oak, MeshId::TreeOak},
    {TreeInfo::OakA, MeshId::TreeOakA},         {TreeInfo::Olive, MeshId::TreeOlive},
    {TreeInfo::Palm, MeshId::TreePalm},         {TreeInfo::PalmA, MeshId::TreePalmA},
    {TreeInfo::PalmB, MeshId::TreePalmB},       {TreeInfo::PalmC, MeshId::TreePalmC},
    {TreeInfo::Pine, MeshId::TreePine},         {TreeInfo::Bush, MeshId::TreeBush},
    {TreeInfo::BushA, MeshId::TreeBushA},       {TreeInfo::BushB, MeshId::TreeBushB},
    {TreeInfo::Cypress, MeshId::TreeCypress},   {TreeInfo::CypressA, MeshId::TreeCypressA},
    {TreeInfo::Copse, MeshId::TreeCopse},       {TreeInfo::CopseA, MeshId::TreeCopseA},
    {TreeInfo::Hedge, MeshId::TreeHedge},       {TreeInfo::HedgeA, MeshId::TreeHedgeA},
    {TreeInfo::Burnt, MeshId::ObjectBurntTree}};

MeshLookup<AbodeInfo> openblack::abodeMeshLookup {// Norse
                                                  {AbodeInfo::NorseTownCentre, MeshId::BuildingNorseVillageCentre},
                                                  {AbodeInfo::NorseStoragePit, MeshId::BuildingNorseStoragePit},
                                                  {AbodeInfo::NorseGraveyard, MeshId::BuildingNorseGraveyard},
                                                  {AbodeInfo::NorseWorkshop, MeshId::BuildingNorseWorkshop},
                                                  {AbodeInfo::NorseCreche, MeshId::BuildingNorseCreche},
                                                  {AbodeInfo::NorseHut, MeshId::BuildingNorse1},
                                                  {AbodeInfo::NorseShackX, MeshId::BuildingNorse2},
                                                  {AbodeInfo::NorseShackY, MeshId::BuildingNorse3},
                                                  {AbodeInfo::NorseTent, MeshId::BuildingNorse4},
                                                  {AbodeInfo::NorseTempleX, MeshId::BuildingNorse5},
                                                  {AbodeInfo::NorseTempleY, MeshId::BuildingNorse2A},
                                                  {AbodeInfo::NorseWonder, MeshId::BuildingNorseWonder},
                                                  // Celtic
                                                  {AbodeInfo::CelticTownCentre, MeshId::BuildingCelticVillageCentre},
                                                  {AbodeInfo::CelticStoragePit, MeshId::BuildingCelticStoragePit},
                                                  {AbodeInfo::CelticGraveyard, MeshId::BuildingCelticGraveyard},
                                                  {AbodeInfo::CelticWorkshop, MeshId::BuildingCelticWorkshop},
                                                  {AbodeInfo::CelticCreche, MeshId::BuildingCelticCreche},
                                                  {AbodeInfo::CelticHut, MeshId::BuildingCeltic1},
                                                  {AbodeInfo::CelticShackX, MeshId::BuildingCeltic2},
                                                  {AbodeInfo::CelticShackY, MeshId::BuildingCeltic3},
                                                  {AbodeInfo::CelticTent, MeshId::BuildingCeltic4},
                                                  {AbodeInfo::CelticTempleX, MeshId::BuildingCeltic5},
                                                  {AbodeInfo::CelticWonder, MeshId::BuildingCelticWonder},
                                                  // Japanese
                                                  {AbodeInfo::JapaneseTownCentre, MeshId::BuildingJapaneseVillageCentre},
                                                  {AbodeInfo::JapaneseStoragePit, MeshId::BuildingJapaneseStoragePit},
                                                  {AbodeInfo::JapaneseGraveyard, MeshId::BuildingJapaneseGraveyard},
                                                  {AbodeInfo::JapaneseWorkshop, MeshId::BuildingJapaneseWorkshop},
                                                  {AbodeInfo::JapaneseCreche, MeshId::BuildingJapaneseCreche},
                                                  {AbodeInfo::JapaneseHut, MeshId::BuildingJapanese1},
                                                  {AbodeInfo::JapaneseShackX, MeshId::BuildingJapanese2},
                                                  {AbodeInfo::JapaneseShackY, MeshId::BuildingJapanese3},
                                                  {AbodeInfo::JapaneseTent, MeshId::BuildingJapanese4},
                                                  {AbodeInfo::JapaneseTempleX, MeshId::BuildingJapanese5},
                                                  {AbodeInfo::JapaneseWonder, MeshId::BuildingJapaneseWonder},
                                                  // Aztec
                                                  {AbodeInfo::AztecTownCentre, MeshId::BuildingAztecVillageCentre},
                                                  {AbodeInfo::AztecStoragePit, MeshId::BuildingAztecStoragePit},
                                                  {AbodeInfo::AztecGraveyard, MeshId::BuildingAztecGraveyard},
                                                  {AbodeInfo::AztecWorkshop, MeshId::BuildingAztecWorkshop},
                                                  {AbodeInfo::AztecCreche, MeshId::BuildingAztecCreche},
                                                  {AbodeInfo::AztecHut, MeshId::BuildingAztec1},
                                                  {AbodeInfo::AztecShackX, MeshId::BuildingAztec2},
                                                  {AbodeInfo::AztecShackY, MeshId::BuildingAztec3},
                                                  {AbodeInfo::AztecTent, MeshId::BuildingAztec4},
                                                  {AbodeInfo::AztecTempleX, MeshId::BuildingAztec5},
                                                  {AbodeInfo::AztecWonder, MeshId::BuildingAztecWonder},
                                                  // Tibetan
                                                  {AbodeInfo::TibetanTownCentre, MeshId::BuildingTibetanVillageCentre},
                                                  {AbodeInfo::TibetanStoragePit, MeshId::BuildingTibetanStoragePit},
                                                  {AbodeInfo::TibetanGraveyard, MeshId::BuildingTibetanGraveyard},
                                                  {AbodeInfo::TibetanWonder, MeshId::BuildingTibetanWorkshop},
                                                  {AbodeInfo::TibetanCreche, MeshId::BuildingTibetanCreche},
                                                  {AbodeInfo::TibetanHut, MeshId::BuildingTibetan1},
                                                  {AbodeInfo::TibetanShackX, MeshId::BuildingTibetan2},
                                                  {AbodeInfo::TibetanShackY, MeshId::BuildingTibetan3},
                                                  {AbodeInfo::TibetanTent, MeshId::BuildingTibetan4},
                                                  {AbodeInfo::TibetanTempleX, MeshId::BuildingTibetan5},
                                                  {AbodeInfo::TibetanWonder, MeshId::BuildingTibetanWonder},
                                                  // Indian
                                                  {AbodeInfo::IndianTownCentre, MeshId::BuildingAmericanVillageCentre},
                                                  {AbodeInfo::IndianStoragePit, MeshId::BuildingAmericanStoragePit},
                                                  {AbodeInfo::IndianGraveyard, MeshId::BuildingAmericanGraveyard},
                                                  {AbodeInfo::IndianWorkshop, MeshId::BuildingAmericanWorkshop},
                                                  {AbodeInfo::IndianCreche, MeshId::BuildingAmericanCreche},
                                                  {AbodeInfo::IndianHut, MeshId::BuildingAmerican1},
                                                  {AbodeInfo::IndianShackX, MeshId::BuildingAmerican2},
                                                  {AbodeInfo::IndianShackY, MeshId::BuildingAmerican3},
                                                  {AbodeInfo::IndianTent, MeshId::BuildingAmerican4},
                                                  {AbodeInfo::IndianTempleX, MeshId::BuildingAmerican5},
                                                  {AbodeInfo::IndianWonder, MeshId::BuildingAmericanWonder},
                                                  // Greek
                                                  {AbodeInfo::GreekTownCentre, MeshId::BuildingGreekVillageCentre},
                                                  {AbodeInfo::GreekStoragePit, MeshId::BuildingGreekStoragePit},
                                                  {AbodeInfo::GreekGraveyard, MeshId::BuildingGreekGraveyard},
                                                  {AbodeInfo::GreekWorkshop, MeshId::BuildingGreekWorkshop},
                                                  {AbodeInfo::GreekCreche, MeshId::BuildingGreekCreche},
                                                  {AbodeInfo::GreekHut, MeshId::BuildingGreek1},
                                                  {AbodeInfo::GreekShackX, MeshId::BuildingGreek2},
                                                  {AbodeInfo::GreekShackY, MeshId::BuildingGreek3},
                                                  {AbodeInfo::GreekTent, MeshId::BuildingGreek4},
                                                  {AbodeInfo::GreekTempleX, MeshId::BuildingGreek5},
                                                  {AbodeInfo::GreekTempleY, MeshId::BuildingGreek5A},
                                                  {AbodeInfo::GreekWonder, MeshId::BuildingGreekWonder}};

MeshLookup<VillagerType, VillagerTypeId> openblack::villagerMeshLookup {
    {{VillageEthnicities::AZTEC, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE}, MeshId::PersonAztecMaleA1},
    {{VillageEthnicities::AZTEC, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonAztecFemaleA1},
    {{VillageEthnicities::AZTEC, VillagerLifeStage::Child, VillagerSex::MALE, VillagerRoles::NONE}, MeshId::PersonBoyTan1},
    {{VillageEthnicities::AZTEC, VillagerLifeStage::Child, VillagerSex::FEMALE, VillagerRoles::NONE}, MeshId::PersonGirlTan1},
    {{VillageEthnicities::CELTIC, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE},
     MeshId::PersonCelticMaleA1},
    {{VillageEthnicities::CELTIC, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonCelticFemaleA1},
    {{VillageEthnicities::CELTIC, VillagerLifeStage::Child, VillagerSex::MALE, VillagerRoles::NONE}, MeshId::PersonBoyWhite},
    {{VillageEthnicities::CELTIC, VillagerLifeStage::Child, VillagerSex::FEMALE, VillagerRoles::NONE}, MeshId::PersonGirlWhite},
    {{VillageEthnicities::EGYPTIAN, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE},
     MeshId::PersonEgyptianMaleA1},
    {{VillageEthnicities::EGYPTIAN, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonEgyptianFemaleA1},
    {{VillageEthnicities::GREEK, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE}, MeshId::PersonGreekMaleA1},
    {{VillageEthnicities::GREEK, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonGreekFemaleA1},
    {{VillageEthnicities::INDIAN, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE},
     MeshId::PersonAmericanMaleA1},
    {{VillageEthnicities::INDIAN, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonAmericanFemaleA1},
    {{VillageEthnicities::JAPANESE, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE},
     MeshId::PersonJapaneseMaleA1},
    {{VillageEthnicities::JAPANESE, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonJapaneseFemaleA2},
    {{VillageEthnicities::NORSE, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE}, MeshId::PersonNorseMaleA1},
    {{VillageEthnicities::NORSE, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonNorseFemaleA1},
    {{VillageEthnicities::NORSE, VillagerLifeStage::Child, VillagerSex::MALE, VillagerRoles::NONE}, MeshId::PersonBoyWhite},
    {{VillageEthnicities::NORSE, VillagerLifeStage::Child, VillagerSex::FEMALE, VillagerRoles::NONE}, MeshId::PersonGirlWhite},
    {{VillageEthnicities::TIBETAN, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE},
     MeshId::PersonTibetanMaleA1},
    {{VillageEthnicities::TIBETAN, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonTibetanFemaleA2},
    {{VillageEthnicities::AFRICAN, VillagerLifeStage::Adult, VillagerSex::MALE, VillagerRoles::NONE},
     MeshId::PersonEgyptianMaleA1},
    {{VillageEthnicities::AFRICAN, VillagerLifeStage::Adult, VillagerSex::FEMALE, VillagerRoles::NONE},
     MeshId::PersonEgyptianFemaleA1}};

MeshLookup<MobileStaticInfo> openblack::mobileStaticMeshLookup {
    {MobileStaticInfo::Rock, MeshId::ObjectFlatRockChalk},
    {MobileStaticInfo::Bonfire, MeshId::BuildingCampfire},
    {MobileStaticInfo::Boulder1Chalk, MeshId::Boulder1Chalk},
    {MobileStaticInfo::Boulder1Lime, MeshId::Boulder1Lime},
    {MobileStaticInfo::Boulder1Sand, MeshId::Boulder1Sand},
    {MobileStaticInfo::Boulder1Volcanic, MeshId::Boulder1Volcanic},
    {MobileStaticInfo::Boulder2Chalk, MeshId::Boulder2Chalk},
    {MobileStaticInfo::Boulder2Lime, MeshId::Boulder2Lime},
    {MobileStaticInfo::Boulder2Sand, MeshId::Boulder2Sand},
    {MobileStaticInfo::Boulder2Volcanic, MeshId::Boulder2Volcanic},
    {MobileStaticInfo::Boulder3Chalk, MeshId::Boulder3Chalk},
    {MobileStaticInfo::Boulder3Lime, MeshId::Boulder3Lime},
    {MobileStaticInfo::Boulder3Sand, MeshId::Boulder3Sand},
    {MobileStaticInfo::Boulder3Volcanic, MeshId::Boulder3Volcanic},
    {MobileStaticInfo::CeltFenceShort, MeshId::BuildingCelticFenceShort},
    {MobileStaticInfo::CeltFenceTall, MeshId::BuildingCelticFenceTall},
    {MobileStaticInfo::CountryLantern, MeshId::ObjectTownLight},
    {MobileStaticInfo::DeadTree, MeshId::ObjectBurntTree},
    {MobileStaticInfo::ToyBall, MeshId::ObjectToyBall},
    {MobileStaticInfo::Idol, MeshId::FeatureIdol},
    {MobileStaticInfo::ToyDie, MeshId::ObjectToyDice},
    {MobileStaticInfo::ToyCuddly, MeshId::ObjectToyCuddly},
    {MobileStaticInfo::ToySkittle, MeshId::ObjectToySkittle},
    {MobileStaticInfo::Vortex, MeshId::SpellVortexCylinder},
    {MobileStaticInfo::GateTotemApe, MeshId::ObjectGateTotemApe},
    {MobileStaticInfo::GateTotemCow, MeshId::ObjectGateTotemCow},
    {MobileStaticInfo::GateTotemTiger, MeshId::ObjectGateTotemTiger},
    {MobileStaticInfo::GateTotemBlank, MeshId::ObjectGateTotemBlank},
    {MobileStaticInfo::LongrockChalk, MeshId::ObjectLongRockChalk},
    {MobileStaticInfo::LongrockLimestone, MeshId::ObjectLongRockLimeStone},
    {MobileStaticInfo::LongrockSandstone, MeshId::ObjectLongRockSandStone},
    {MobileStaticInfo::LongrockVolcanic, MeshId::ObjectLongRockVolcanic},
    {MobileStaticInfo::RockChalk, MeshId::ObjectRockChalk},
    {MobileStaticInfo::RockLimestone, MeshId::ObjectRockLimeStone},
    {MobileStaticInfo::RockSandstone, MeshId::ObjectRockSandStone},
    {MobileStaticInfo::RockVolcanic, MeshId::ObjectRockVolcanic},
    {MobileStaticInfo::SharprockChalk, MeshId::ObjectSharpRockChalk},
    {MobileStaticInfo::SharprockLimestone, MeshId::ObjectSharpRockLimeStone},
    {MobileStaticInfo::SharprockSandstone, MeshId::ObjectSharpRockSandStone},
    {MobileStaticInfo::SharprockVolcanic, MeshId::ObjectSharpRockVolcanic}};

MeshLookup<MobileObjectInfo> openblack::mobileObjectMeshLookup {
    {MobileObjectInfo::EgyptBarrel, MeshId::BuildingEgyptianBarrel},
    {MobileObjectInfo::EgyptCart, MeshId::BuildingEgyptianCart},
    {MobileObjectInfo::EgyptPotA, MeshId::BuildingEgyptianPotA},
    {MobileObjectInfo::EgyptPotB, MeshId::BuildingEgyptianPotB},
    {MobileObjectInfo::MagicFood, MeshId::Dummy},
    {MobileObjectInfo::LumpOfPoo, MeshId::ObjectCreatureTurd},
    {MobileObjectInfo::WaterJug, MeshId::Dummy},
    {MobileObjectInfo::Arrow, MeshId::Dummy},
    {MobileObjectInfo::Ball, MeshId::Dummy},
    {MobileObjectInfo::Cart, MeshId::BuildingEgyptianCart},
    {MobileObjectInfo::FoodPot, MeshId::BuildingEgyptianPotA},
    {MobileObjectInfo::WoodPot, MeshId::BuildingEgyptianPotA},
    {MobileObjectInfo::PileFood, MeshId::BuildingEgyptianPotA},
    {MobileObjectInfo::PileWood, MeshId::BuildingEgyptianPotA},
    {MobileObjectInfo::MagicWood, MeshId::BuildingWood00},
    {MobileObjectInfo::Crop, MeshId::TreeBush},
    {MobileObjectInfo::OldScaffold, MeshId::Dummy},
    {MobileObjectInfo::Champi, MeshId::ObjectChampi},
    {MobileObjectInfo::Toadstool, MeshId::ObjectToadstool},
    {MobileObjectInfo::MagicMushroom, MeshId::ObjectMagicMushroom},
    {MobileObjectInfo::CreatureSwapOrb, MeshId::Dummy},
    {MobileObjectInfo::Creed, MeshId::Creed},
    {MobileObjectInfo::Eyes, MeshId::Creed},
    {MobileObjectInfo::Ark, MeshId::ObjectArk},
    {MobileObjectInfo::Whale, MeshId::ObjectLargeFishDead},
    {MobileObjectInfo::OneOffSpellSeed, MeshId::Dummy},
    {MobileObjectInfo::HanoiPuzzleBase, MeshId::BuildingXandoBase},
    {MobileObjectInfo::HanoiPuzzlePart1, MeshId::Puzzle1},
    {MobileObjectInfo::HanoiPuzzlePart2, MeshId::Puzzle2},
    {MobileObjectInfo::HanoiPuzzlePart3, MeshId::Puzzle3},
    {MobileObjectInfo::HanoiPuzzlePart4, MeshId::Puzzle4},
};

MeshLookup<FeatureInfo> openblack::featureMeshLookup {{FeatureInfo::FatPilarSand, MeshId::FatPilarSand},
                                                      {FeatureInfo::Pilar2Sand, MeshId::Pilar2Sand},
                                                      {FeatureInfo::Pilar3Sand, MeshId::Pilar3Sand},
                                                      {FeatureInfo::FatPilarChalk, MeshId::FatPilarChalk},
                                                      {FeatureInfo::Pilar2Chalk, MeshId::Pilar2Chalk},
                                                      {FeatureInfo::Pilar3Chalk, MeshId::Pilar3Chalk},
                                                      {FeatureInfo::FatPilarLime, MeshId::FatPilarLime},
                                                      {FeatureInfo::Pilar2Lime, MeshId::Pilar2Lime},
                                                      {FeatureInfo::Pilar3Lime, MeshId::Pilar3Lime},
                                                      {FeatureInfo::PilarVolcanic, MeshId::PilarVolcanic},
                                                      {FeatureInfo::Pilar2Volcanic, MeshId::Pilar2Volcanic},
                                                      {FeatureInfo::Pilar3Volcanic, MeshId::Pilar3Volcanic},
                                                      {FeatureInfo::Ark, MeshId::ObjectArk},
                                                      {FeatureInfo::ArkWreck, MeshId::ObjectArkWreck},
                                                      {FeatureInfo::ArkDryDock, MeshId::ObjectArkDryDock},
                                                      {FeatureInfo::MagicMushroom, MeshId::ObjectMagicMushroom},
                                                      {FeatureInfo::Toadstool, MeshId::ObjectToadstool},
                                                      {FeatureInfo::AztcStatue, MeshId::BuildingAztecStatue},
                                                      {FeatureInfo::SpikeyPilarLime, MeshId::SpikeyPilarLime},
                                                      {FeatureInfo::SpikeyPilarChalk, MeshId::SpikeyPilarChalk},
                                                      {FeatureInfo::SpikeyPilarSand, MeshId::SpikeyPilarSand},
                                                      {FeatureInfo::SpikeyPilarVolcanic, MeshId::SpikeyPilarVolcanic}};
