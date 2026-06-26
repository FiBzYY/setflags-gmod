require("setflags")

-- Example:
local cl_sidespeed = GetConVar("cl_sidespeed")

cl_sidespeed:SetFlags(bit.band(cl_sidespeed:GetFlags(), bit.bnot(FCVAR_CHEAT)))