#include <GarrysMod/Lua/Interface.h>

using namespace GarrysMod::Lua;

LUA_FUNCTION(SetFlags)
{
    LUA->CheckType(1, Type::ConVar);

    auto *cv = reinterpret_cast<unsigned char *>(
        LUA->GetUserType<void>(1, Type::ConVar)
    );

    if (cv == nullptr)
    {
        LUA->ThrowError("Invalid ConVar");
        return 0;
    }

    *reinterpret_cast<int *>(cv + 0x00) = static_cast<int>(LUA->CheckNumber(2));

    return 0;
}

GMOD_MODULE_OPEN()
{
    if (!LUA->PushMetaTable(Type::ConVar))
    {
        Msg("Failed to find ConVar metatable\n");
        return 0;
    }

    LUA->PushString("SetFlags");
    LUA->PushCFunction(SetFlags);
    LUA->SetTable(-3);

    LUA->Pop();

    return 0;
}

GMOD_MODULE_CLOSE()
{
    return 0;
}