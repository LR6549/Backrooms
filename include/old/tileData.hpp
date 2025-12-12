
namespace TILES {
    namespace BLOCKS {
        enum class ID : uint16_t {
            NOCHANGE,

            //++ Atmosphere
            AIR,
            CLOUD,

            //++ Surface
            GRASS,
            JUNGLEGRASS,
            SNOWGRASS,
            DIRT,
            SNOWDIRT,
            CLAY,
            MUD,
            STONE,
            SAND,
            ICEBLOCK,
            GRAVEL,
            SANDSTONE,
             //-> Trees
             TREESEED,

            //++ Ground
                //-> Rocks
                CHALK,
                SHALE,
                LIMESTONE,

                //-> Ores / Minerals
                COAL,
                COALORE,
                LEAD,
                LEADORE,
                BISMUTH,
                BISMUTHORE,

                //-> Gemstones
                QUARTZ,
                AMETHYST,

            //++ Caves Layer
                //-> Rocks
                ANDESITE,
                DIORITE,
                GRANITE,

                //-> Ores / Minerals
                ZINC,
                ZINCORE,
                COPPER,
                COPPERORE,
                ALUMINIUM,
                ALUMINIUMORE,
                BRONZE,
                BRONZEORE,
                IRON,
                IRONORE,

                //-> Gemstones
                ONYX,

            //++ Deep Caves Layer
                //-> Rocks
                SLATE,
                MARBLE,
                SERPENTINITE,

                //-> Ores / Minerals
                SILVER,
                SILVERORE,
                TUNGSTEN,
                TUNGSTENORE,
                GOLD,
                GOLDORE,
                PLATINUM,
                PLATINUMORE,

                //-> Gemstones
                AQUAMARINE,
                TOPAZ,

            //++ Compression Layer
                //-> Rocks
                QUARTZITE,
                GNEISS,

                //-> Ores / Minerals
                GALENA,
                GALENAORE,
                HEMATITE,
                HEMATITEORE,
                COBALT,
                COBALTORE,
                TITANIUM,
                TITANIUMORE,

                //-> Gemstones
                SAPPHIRE,
                RUBY,
                EMERALD,

            //++ Outer Core Layer
                //-> Rocks
                BASALT,

                //-> Ores / Minerals
                ADAMANTITE,
                ADAMANTITEORE,
                MITHRILITE,
                MITHRILITEORE,
                ORICHALCUM,
                ORICHALCUMORE,

                //-> Gemstones
                TANZANITE,

            //++ Inner Core Layer
                //-> Rocks
                KIMBERLITE,

                //-> Ores / Minerals
                OSMIUM,
                OSMIUMORE,
                IRIDIUM,
                IRIDIUMORE,
                URANIUM,
                URANIUMORE,
                PLUTONIUM,
                PLUTONIUMORE,

                //-> Gemstones
                DIAMOND,

            COUNT,
            BEDROCK = UINT16_MAX
        };
    }


    namespace WALLS {
        enum class ID : uint16_t {
            NOCHANGE,

            //++ Atmosphere
            AIR,
            CLOUD,

            //++ Surface
            GRASS,
            JUNGLEGRASS,
            SNOWGRASS,
            DIRT,
            SNOWDIRT,
            CLAY,
            MUD,
            STONE,
            SAND,
            ICEBLOCK,
            GRAVEL,
            SANDSTONE,

            //++ Ground
                //-> Rocks
                CHALK,
                SHALE,
                LIMESTONE,

                //-> Ores / Minerals
                COAL,
                COALORE,
                LEAD,
                LEADORE,
                BISMUTH,
                BISMUTHORE,

                //-> Gemstones
                QUARTZ,
                AMETHYST,

            //++ Caves Layer
                //-> Rocks
                ANDESITE,
                DIORITE,
                GRANITE,

                //-> Ores / Minerals
                ZINC,
                ZINCORE,
                COPPER,
                COPPERORE,
                ALUMINIUM,
                ALUMINIUMORE,
                BRONZE,
                BRONZEORE,
                IRON,
                IRONORE,

                //-> Gemstones
                ONYX,

            //++ Deep Caves Layer
                //-> Rocks
                SLATE,
                MARBLE,
                SERPENTINITE,

                //-> Ores / Minerals
                SILVER,
                SILVERORE,
                TUNGSTEN,
                TUNGSTENORE,
                GOLD,
                GOLDORE,
                PLATINUM,
                PLATINUMORE,

                //-> Gemstones
                AQUAMARINE,
                TOPAZ,

            //++ Compression Layer
                //-> Rocks
                QUARTZITE,
                GNEISS,

                //-> Ores / Minerals
                GALENA,
                GALENAORE,
                HEMATITE,
                HEMATITEORE,
                COBALT,
                COBALTORE,
                TITANIUM,
                TITANIUMORE,

                //-> Gemstones
                SAPPHIRE,
                RUBY,
                EMERALD,

            //++ Outer Core Layer
                //-> Rocks
                BASALT,

                //-> Ores / Minerals
                ADAMANTITE,
                ADAMANTITEORE,
                MITHRILITE,
                MITHRILITEORE,
                ORICHALCUM,
                ORICHALCUMORE,

                //-> Gemstones
                TANZANITE,

            //++ Inner Core Layer
                //-> Rocks
                KIMBERLITE,

                //-> Ores / Minerals
                OSMIUM,
                OSMIUMORE,
                IRIDIUM,
                IRIDIUMORE,
                URANIUM,
                URANIUMORE,
                PLUTONIUM,
                PLUTONIUMORE,

                //-> Gemstones
                DIAMOND,

            COUNT,
            BEDROCK = UINT16_MAX
        };
    }


    namespace LIQUIDS {
        enum class ID : uint16_t{
            NOCHANGE,
            AIR,
            WATER,
            LAVA,
            COUNT
        };
    }

    namespace COLORVALUES {
        std::unordered_map<uint16_t, Color> COLORS = {
            // Atmosphere
            {static_cast<uint16_t>(BLOCKS::ID::AIR),          Color(255, 255, 255,   0)},
            {static_cast<uint16_t>(BLOCKS::ID::CLOUD),        Color(200, 200, 200, 255)},

            // Surface
            {static_cast<uint16_t>(BLOCKS::ID::GRASS),        Color(34, 139, 34, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::TREESEED),     Color(130, 130, 30, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::JUNGLEGRASS),  Color(17, 69, 17, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::SNOWGRASS),    Color(225, 225, 255, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::DIRT),         Color(139, 69, 19, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::SNOWDIRT),     Color(255, 140, 80, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::CLAY),         Color(190, 110, 60, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::MUD),          Color(60, 30, 10, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::STONE),        Color(128, 128, 128, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::SAND),         Color(237, 201, 175, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::ICEBLOCK),     Color(125, 125, 200, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::GRAVEL),       Color(150, 150, 150, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::SANDSTONE),    Color(216, 180, 130, 255)},

            // Ground - Rocks
            {static_cast<uint16_t>(BLOCKS::ID::CHALK),        Color(245, 245, 235, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::SHALE),        Color(70, 70, 60, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::LIMESTONE),    Color(200, 200, 180, 255)},

            // Ground - Ores / Minerals
            {static_cast<uint16_t>(BLOCKS::ID::COAL),         Color(20, 20, 20, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::LEAD),         Color(90, 90, 110, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::BISMUTH),      Color(190, 125, 180, 255)},

            // Ground - Gemstones
            {static_cast<uint16_t>(BLOCKS::ID::QUARTZ),       Color(230, 230, 255, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::AMETHYST),     Color(153, 102, 204, 255)},

            // Cave Layer - Rocks
            {static_cast<uint16_t>(BLOCKS::ID::ANDESITE),     Color(112, 128, 144, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::DIORITE),      Color(220, 220, 220, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::GRANITE),      Color(169, 130, 110, 255)},

            // Cave Layer - Minerals
            {static_cast<uint16_t>(BLOCKS::ID::ZINC),         Color(180, 180, 200, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::COPPER),       Color(184, 115, 51, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::ALUMINIUM),    Color(200, 200, 210, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::BRONZE),       Color(180, 130, 60, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::IRON),         Color(155, 90, 60, 255)},

            // Cave Layer - Gemstones
            {static_cast<uint16_t>(BLOCKS::ID::ONYX),         Color(30, 30, 30, 255)},

            // Deep Caves - Rocks
            {static_cast<uint16_t>(BLOCKS::ID::SLATE),        Color(70, 70, 80, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::MARBLE),       Color(240, 240, 240, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::SERPENTINITE), Color(60, 120, 80, 255)},

            // Deep Caves - Minerals
            {static_cast<uint16_t>(BLOCKS::ID::SILVER),       Color(210, 210, 220, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::TUNGSTEN),     Color(50, 50, 60, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::GOLD),         Color(255, 215, 0, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::PLATINUM),     Color(225, 225, 235, 255)},

            // Deep Caves - Gemstones
            {static_cast<uint16_t>(BLOCKS::ID::AQUAMARINE),   Color(70, 200, 200, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::TOPAZ),        Color(255, 180, 50, 255)},

            // Compression Layer - Rocks
            {static_cast<uint16_t>(BLOCKS::ID::QUARTZITE),    Color(200, 190, 200, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::GNEISS),       Color(160, 150, 140, 255)},

            // Compression Layer - Minerals
            {static_cast<uint16_t>(BLOCKS::ID::GALENA),       Color(110, 110, 130, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::HEMATITE),     Color(150, 30, 30, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::TITANIUM),     Color(180, 180, 190, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::COBALT),       Color(0, 70, 140, 255)},

            // Compression Layer - Gemstones
            {static_cast<uint16_t>(BLOCKS::ID::SAPPHIRE),     Color(15, 65, 160, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::RUBY),         Color(180, 20, 20, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::EMERALD),      Color(20, 150, 80, 255)},

            // Outer Core Layer - Rocks
            {static_cast<uint16_t>(BLOCKS::ID::BASALT),       Color(40, 40, 50, 255)},

            // Outer Core Layer - Minerals
            {static_cast<uint16_t>(BLOCKS::ID::ADAMANTITE),   Color(255, 20, 20, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::MITHRILITE),   Color(110, 240, 190, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::ORICHALCUM),   Color(255, 140, 0, 255)},

            // Outer Core - Gemstones
            {static_cast<uint16_t>(BLOCKS::ID::TANZANITE),    Color(75, 60, 140, 255)},

            // Inner Core Layer - Rocks
            {static_cast<uint16_t>(BLOCKS::ID::KIMBERLITE),   Color(105, 105, 105, 255)},

            // Inner Core Layer - Minerals
            {static_cast<uint16_t>(BLOCKS::ID::OSMIUM),       Color(30, 60, 120, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::IRIDIUM),      Color(200, 200, 220, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::URANIUM),      Color(140, 255, 60, 255)},
            {static_cast<uint16_t>(BLOCKS::ID::PLUTONIUM),    Color(40, 255, 100, 255)},

            // Inner Core - Gemstones
            {static_cast<uint16_t>(BLOCKS::ID::DIAMOND),      Color(180, 240, 255, 255)},

            // Bedrock
            {static_cast<uint16_t>(BLOCKS::ID::BEDROCK),      Color(0, 0, 0, 255)}
        };
    }

    struct TileArray {
        TILES::BLOCKS::ID  block    = TILES::BLOCKS::ID::NOCHANGE;
        TILES::WALLS::ID   wall     = TILES::WALLS::ID::NOCHANGE;
        TILES::LIQUIDS::ID liquid   = TILES::LIQUIDS::ID::NOCHANGE;

        TileArray(TILES::BLOCKS::ID pBlock = TILES::BLOCKS::ID::NOCHANGE, TILES::WALLS::ID pWall = TILES::WALLS::ID::NOCHANGE, TILES::LIQUIDS::ID pLiquid = TILES::LIQUIDS::ID::NOCHANGE) {
            block  = pBlock;
            wall   = pWall;
            liquid = pLiquid;
        }
    };
}